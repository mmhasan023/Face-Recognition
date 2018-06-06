// VidCapDlg.cpp : implementation file
//

//////////////////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� : VidCapDlg.cpp
// ��    �� : Webcam�� �̿��� �ǽð� Sobel edge ��� ���α׷�
// �� �� �� : �� �� �� <miryu17@khu.ac.kr>
// �� �� �� : 2010�� 5�� 25��
// ��    �� : KYUNGHEE UNIV IMAGE PROCESSING LAB
// ���ǻ��� : DirectX 9.0b �Ǵ� Mircosoft Windows Platform SDK/DirectX SDK �� ��ġ�Ǿ� �־�� ��
// �������� : iSobelEdgesUint8.h
// �������� : 
// �������� : 
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <vector>
#include <fstream>
using namespace std;
#include "IntImage.h"
#include "SimpleClassifier.h"
#include "AdaBoostClassifier.h"
#include "Global.h"
#include "CascadeClassifier.h"
#include "learn.h"

#include "VidCap.h"
#include "VidCapDlg.h"

#include "capture.h"
#include "samplegrab.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CVidCapDlg dialog
CVidCapDlg::CVidCapDlg(CWnd* pParent /*=NULL*/)
: CDialog(CVidCapDlg::IDD, pParent)
, m_ResizeRatio(0.125)
, m_Width(WIDTH), m_Height(HEIGHT), m_Channels(3)
, m_nTimer(0), m_TimerInterval(30)
, m_fDetectionTime(_T(""))
, m_TakeSnapshot(false)
, pBmpEncoder(GUID_NULL)
, s_Img(NULL)
, d_Img(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	s_Img=new KScScalarImage2dUint8(m_Width,m_Height);
	d_Img=new KScScalarImage2dUint8();
	int	dx = s_Img->GetXSize();
	int	dy = s_Img->GetYSize();
	d_Img->Alloc(dx, dy);
	m_nWidth = WIDTH;
	m_nHeight = HEIGHT;
}

void CVidCapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRV_STATIC, m_PrvStatic);
	DDX_Control(pDX, IDC_ADAPTORS_COMBO, m_AdapterCombo);
	DDX_Text(pDX, IDC_SAMPLEINTERVAL_EDIT, m_TimerInterval);
	DDV_MinMaxUInt(pDX, m_TimerInterval, 10, 10000);
	DDX_Control(pDX, IDC_RUN_BUTTON, m_RunButton);
	DDX_Control(pDX, IDC_CAPIMG_STATIC, m_CapImgStatic);
	DDX_Control(pDX, IDC_VIDINFO_STATIC, m_VideoFormat);
	DDX_Text(pDX, IDC_DETECTIONMS_STATIC, m_fDetectionTime);
}

BEGIN_MESSAGE_MAP(CVidCapDlg, CDialog)
	ON_MESSAGE(WM_GRAPHNOTIFY, OnGraphMessage)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ENUMADAPTORS_BUTTON, &CVidCapDlg::OnBnClickedEnumadaptorsButton)
	ON_BN_CLICKED(IDC_RUN_BUTTON, &CVidCapDlg::OnBnClickedRunButton)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_WINDOWPOSCHANGED()
	ON_STN_DBLCLK(IDC_CAPIMG_STATIC, &CVidCapDlg::OnStnDblclickCapimgStatic)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_TRAIN_BUTTON, &CVidCapDlg::OnBnClickedTrainButton)
END_MESSAGE_MAP()


// CVidCapDlg message handlers
LRESULT CVidCapDlg::OnGraphMessage(WPARAM wParam, LPARAM lParam)
{
	HRESULT hr = vcHandleGraphEvent();
	TRACE(L" WM_GRAPH 0x%X\n", hr);
	return 0;
}

BOOL CVidCapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// Initialize COM
	if (FAILED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED))) {
		MessageBox(L"CoInitialize Failed!", L"COM error");
		m_RunButton.EnableWindow(FALSE);
		return TRUE;
	}

	if (GetEncoderClsid(L"image/jpeg", &pBmpEncoder) < 0) {
		MessageBox(L"Failed to get image/bmp encoder", L"warning");
	}

	// Jaeyoung
	InitGlobalData();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVidCapDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(m_nTimer);			// Timer ����
	vcStopCaptureVideo();			// webcam ������ ���´�
	CoUninitialize();				
	FreeLibrary(hDll);				// library ����
	s_Img->Free();					// �޸� ����
	d_Img->Free();

	CDialog::OnClose();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVidCapDlg::OnPaint()
{
	if (IsIconic()) {
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialog::OnPaint();
	}
}


int CVidCapDlg::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j) {
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVidCapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVidCapDlg::OnBnClickedEnumadaptorsButton()
{
	//Enum adaptors
	vcGetCaptureDevices(m_AdapterCombo);
}


//=================================================================================================
// Function		:	OnBnClickedRunButton()
// Return		:	none
// Parameter	:	none
// Processing	:	ȭ�鿡 ��ķ���� �޾ƿ� ȭ���� �ǽð����� ����Ѵ�
//					- Run�� ���
//					1) ��ķ���� ������ ���� �� �ֵ��� �ʱ�ȭ�Ѵ�
//					2) ��ư�� ǥ�õǾ� �ִ� ���� Run �� Stop ���� �����Ѵ�
//					3) Timer�� �����Ѵ�
//					- Stop�� ���
//					1) Timer�� �����Ѵ�
//					2) ��ư�� ǥ�õǾ� �ִ� ���� Stop �� Run ���� �����Ѵ�
//					3) ��ķ ������ �����Ѵ�
// Pre			:	Dialog�� Run button�� Ŭ���Ǹ� �߻��ϴ� �Լ�
// Post			:	- Run �� ���
//					1) ȭ�鿡 ��ķ���� ���� ȭ���� ��µȴ�.
//					- Stop �� ���
//					1) ȭ�� ����� �ߴܵȴ�.
//=================================================================================================
void CVidCapDlg::OnBnClickedRunButton()
{
	UpdateData();

	HRESULT hr;
	if (m_nTimer == 0) 
	{
		// Run capture
		// ��ķ���� ������ ���� �� �ֵ��� �����Ѵ�
		hr = vcCaptureVideo(m_hWnd, m_PrvStatic.m_hWnd, m_AdapterCombo.GetCurSel() + 1);

		if (hr != S_OK) 
		{
			vcStopCaptureVideo();
			return;
		}

		// ���� ����
		CString str;
		str.Format(L"Video output: %dx%d %dbpp", sgGetDataWidth(), sgGetDataHeight(), 8 * sgGetDataChannels()); 
		m_VideoFormat.SetWindowTextW(str);

		//Setup Timer
		if (sgGetDataWidth() == m_Width && sgGetDataHeight() == m_Height && sgGetDataChannels() == m_Channels)
		{

			//Timer�� �����Ͽ� �����ð����� �Լ��� ȣ���� �� �ֵ��� �����Ѵ�
			m_nTimer = SetTimer(1, m_TimerInterval, 0);
			m_FpsRate = 0.0;
			m_Ms = 0;
			m_MsPerFrame = 0;
			m_FramesProcessed = 0;
			m_TotalFrames = 1000 / m_TimerInterval;
			if (m_TotalFrames == 0)
				m_TotalFrames = 1;
		}

		// ��ư�� ���ڸ� Stop���� �����Ѵ�
		m_RunButton.SetWindowTextW(L"Stop");
	} 

	else 
	{
		//Close Timer
		KillTimer(m_nTimer);
		m_nTimer = 0;

		// ��ư�� ���ڸ� Run���� �����Ѵ�
		m_RunButton.SetWindowTextW(L"Run");

		m_VideoFormat.SetWindowTextW(L"Video output");

		// Close Capture
		// ��ķ�� �����Ѵ�
		vcStopCaptureVideo();
	}
}

//=================================================================================================
// Function		:	OnTimer(UINT_PTR nIDEvent)
// Return		:	none
// Parameter	:	UINT_PTR nIDEvent - Timer ������ �־��� �̺�Ʈ ��ȣ
// Processing	:	Timer ������ �־��� �ð����� ȣ��Ǹ�, ȣ��� ��ķ���� ������ �޾ƿ� ����ó���� �Ѵ�
//					1) pData�� Raw ����Ÿ�� ������ ����� ������ ���� �������̴�.
//					2) DrawData()�� ȣ���Ͽ� ����ó���Ѵ�
// Pre			:	Timer ������ �Ǿ��־�� �Ѵ�
// Post			:	���� ������ ����ó���ȴ�.
//=================================================================================================
void CVidCapDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);
	TRACE(L" %d:%d:%d\n", SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);

	// �Ϲ������� nIDEvent�� ���� �̺�Ʈ�� ���ÿ� �Ͼ��
	// ������ �̺�Ʈ ���� �ٸ� �ൿ�� �����ϱ� ���� ������� ���Ǵ� �����̴�
	// ������ �� ���α׷������� �̺�Ʈ�� �ϳ��̹Ƿ� ������� �ʴ´�

	// ��ķ���� �޾ƿ� ���� ���� ������ ���� �����͸� ��´�
	unsigned char* pData = sgGrabData();

	// ���� ���� ������ NULL�� �ƴϸ�
	if (pData != 0)
	{
		// ����ó�� �Ѵ�
		DrawData(pData);
	}

	CDialog::OnTimer(nIDEvent);
}


void CVidCapDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialog::OnWindowPosChanged(lpwndpos);

	// TODO: Add your message handler code here
	vcChangePreviewState(!IsIconic());
}

//=================================================================================================
// Function		:	DrawData(unsigned char *pData)
// Return		:	none
// Parameter	:	unsigned char *pData - ����ó���� ������ �̹��� ����
// Processing	:	DLL �Լ��� ȣ���Ͽ� ����ó�� �Ѵ�.
// Pre			:	pData�� ������ �־�� �Ѵ�.
// Post			:	����ó���� ����� ȭ�鿡 ��µȴ�.
//=================================================================================================
void CVidCapDlg::DrawData(unsigned char *pData)
{
	//BGR�̹����� �׷��̷� �ٲٰ�, ������ ��´�.
	GrayToEdg(IN OUT pData );

	// ����ó��
	Gdiplus::Bitmap* pBitmap = sgGetBitmap();
	if (pBitmap == 0)
		return;        

	RECT r;
	m_CapImgStatic.GetClientRect(&r);
	Gdiplus::Graphics g(m_CapImgStatic.GetDC()->m_hDC);

	g.DrawImage(pBitmap, Gdiplus::Rect(0, 0, (r.right), r.bottom));
	UpdateData(FALSE);
}

void CVidCapDlg::OnStnDblclickCapimgStatic()
{
	m_TakeSnapshot = true;
}

//=================================================================================================
// Function		:	OnCreate(LPCREATESTRUCT lpCreateStruct)
// Return		:	none
// Parameter	:	none
// Processing	:	MFC ���� �����ڿ� ������ ������ �Ѵ�. ���⼭ DLL�� �ҷ��´�.
// Pre			:	none
// Post			:	�ʱ�ȭ�ȴ�
//=================================================================================================
int CVidCapDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	// MTES���� �ۼ��� dll ������ �ҷ��´�.
	if((hDll=LoadLibrary(L"iSobelEdgesUint8.dll"))==NULL)
	{
		MessageBox(L"Dll���� �ε� ����",L"");
	}

	// �ҷ��� dll�� �Լ��� ���� �� �� �ִ� �Լ������͸� �����Ѵ�.
	Edg = (LPFNDLLEDG)GetProcAddress(hDll, "iSobelEdgesUint8");	

	return 0;
}

//=================================================================================================
// Function		:	GrayToEdg(IN OUT unsigned char* src_Img)
// Return		:	none
// Parameter	:	unsigned char* src_Img - ����ó���� ������ �̹��� ����
// Processing	:	�Է¹��� 640*480 3ä�� �̹����� 1ä�� �׷��� �̹����� �ٲٰ�, ����ó�� ��
//					�ٽ� ����� ���� 3ä���̹����κ�ȯ
//					1) ������ Grayscale �������� ��ȯ�Ѵ�.
//					2) Edge ���� �Լ��� ȣ���Ѵ�.
//					3) ��� ������ ��� ���ۿ� �����Ѵ�.
// Pre			:	src_Img�� ������ �־�� �Ѵ�.
// Post			:	����ó���� ����� ȭ�鿡 ��µȴ�.
//=================================================================================================
void CVidCapDlg::GrayToEdg(IN OUT unsigned char* src_Img)//src_Img=BGR 3channel image
{
	// Grayscale�� ������ ������ �����͸� ��´�.
	BYTE *psrc = s_Img->GetBuffer();

	// RGB������ Grayscale �������� ��ȯ�Ѵ�.
	RGBToGray(src_Img, psrc);

	
	
	CSize img_size;
	//img_size.SetSize(s_Img->GetMainXSize(),s_Img->GetMainYSize());


	img_size.SetSize(s_Img->GetMainYSize(),s_Img->GetMainXSize());
	image.SetSize(img_size);

	for(int n=0;n<m_nWidth*m_nHeight;n++)
	{
		image.buf[n] = (REAL)psrc[n];	
	}
	
	if(cascade->count>0)
	{
		cascade->ApplyOriginalSize(image);
	}
	
	LPBYTE lpSrc = d_Img->GetBuffer();	// 
	LPBYTE lpDst = src_Img;				// 
	
	for(int n=0;n<m_nWidth*m_nHeight;n++)
	{
		*lpDst++ = image.buf[n];
		*lpDst++ = image.buf[n];
		*lpDst++ = image.buf[n];
	}
	
}

//=================================================================================================
// Function		:	RGBToGray(IN unsigned char* pSrc, OUT unsigned char* pDst)
// Return		:	none
// Parameter	:	unsigned char* pSrc - ���� ����, unsigned char* pDst - ��� ����
// Processing	:	�Է¹��� 640*480 3ä�� �̹����� 1ä�� �׷��� �̹����� ����
// Pre			:	pSrc�� pDst�� �Ҵ�Ǿ� �־�� �Ѵ�.
// Post			:	pSrc�� Į�� ������ ������� ��ȯ�Ǿ� pDst�� ����ȴ�.
//=================================================================================================
void CVidCapDlg::RGBToGray(IN unsigned char* pSrc, OUT unsigned char* pDst)
{
	LPBYTE lpSrc = pSrc;
	LPBYTE lpDst = pDst;
	for( int x, y=0 ; y<m_nWidth ; y++ )
	{
		for( x=0; x<m_nHeight ; x++ )
		{
			// �ܼ��ϰ� ��հ��� ���Ͽ� �����Ѵ�.
			*lpDst ++= ( *(lpSrc) + *(lpSrc+1) + *(lpSrc+2) )  / 3;	
			lpSrc += 3;
		}
	}
}

void CVidCapDlg::OnBnClickedTrainButton()
{
	// TODO: Add your control notification handler code here
	InitTrain();
}

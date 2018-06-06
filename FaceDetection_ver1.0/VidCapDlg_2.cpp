// VidCapDlg.cpp : implementation file
//

//////////////////////////////////////////////////////////////////////////////////////////////
//
// 파 일 명 : VidCapDlg.cpp
// 설    명 : Webcam을 이용한 실시간 Sobel edge 출력 프로그램
// 작 성 자 : 임 동 선 <miryu17@khu.ac.kr>
// 작 성 일 : 2010년 5월 25일
// 소    속 : KYUNGHEE UNIV IMAGE PROCESSING LAB
// 주의사항 : DirectX 9.0b 또는 Mircosoft Windows Platform SDK/DirectX SDK 가 설치되어 있어야 함
// 참조파일 : iSobelEdgesUint8.h
// 수정일자 : 
// 수정내용 : 
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
	KillTimer(m_nTimer);			// Timer 삭제
	vcStopCaptureVideo();			// webcam 연결을 끊는다
	CoUninitialize();				
	FreeLibrary(hDll);				// library 해제
	s_Img->Free();					// 메모리 해제
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
// Processing	:	화면에 웹캠에서 받아온 화면을 실시간으로 출력한다
//					- Run일 경우
//					1) 웹캠에서 영상을 받을 수 있도록 초기화한다
//					2) 버튼에 표시되어 있는 글자 Run 을 Stop 으로 변경한다
//					3) Timer를 설정한다
//					- Stop일 경우
//					1) Timer를 해제한다
//					2) 버튼에 표시되어 있는 글자 Stop 을 Run 으로 변경한다
//					3) 웹캠 설정을 종료한다
// Pre			:	Dialog에 Run button이 클릭되면 발생하는 함수
// Post			:	- Run 일 경우
//					1) 화면에 웹캠에서 받은 화면이 출력된다.
//					- Stop 일 경우
//					1) 화면 출력이 중단된다.
//=================================================================================================
void CVidCapDlg::OnBnClickedRunButton()
{
	UpdateData();

	HRESULT hr;
	if (m_nTimer == 0) 
	{
		// Run capture
		// 웹캠에서 영상을 받을 수 있도록 설정한다
		hr = vcCaptureVideo(m_hWnd, m_PrvStatic.m_hWnd, m_AdapterCombo.GetCurSel() + 1);

		if (hr != S_OK) 
		{
			vcStopCaptureVideo();
			return;
		}

		// 정보 설정
		CString str;
		str.Format(L"Video output: %dx%d %dbpp", sgGetDataWidth(), sgGetDataHeight(), 8 * sgGetDataChannels()); 
		m_VideoFormat.SetWindowTextW(str);

		//Setup Timer
		if (sgGetDataWidth() == m_Width && sgGetDataHeight() == m_Height && sgGetDataChannels() == m_Channels)
		{

			//Timer를 설정하여 일정시간마다 함수를 호출할 수 있도록 설정한다
			m_nTimer = SetTimer(1, m_TimerInterval, 0);
			m_FpsRate = 0.0;
			m_Ms = 0;
			m_MsPerFrame = 0;
			m_FramesProcessed = 0;
			m_TotalFrames = 1000 / m_TimerInterval;
			if (m_TotalFrames == 0)
				m_TotalFrames = 1;
		}

		// 버튼의 글자를 Stop으로 변경한다
		m_RunButton.SetWindowTextW(L"Stop");
	} 

	else 
	{
		//Close Timer
		KillTimer(m_nTimer);
		m_nTimer = 0;

		// 버튼의 글자를 Run으로 변경한다
		m_RunButton.SetWindowTextW(L"Run");

		m_VideoFormat.SetWindowTextW(L"Video output");

		// Close Capture
		// 웹캠을 종료한다
		vcStopCaptureVideo();
	}
}

//=================================================================================================
// Function		:	OnTimer(UINT_PTR nIDEvent)
// Return		:	none
// Parameter	:	UINT_PTR nIDEvent - Timer 설정시 주어진 이벤트 번호
// Processing	:	Timer 설정시 주어진 시간마다 호출되며, 호출시 웹캠에서 영상을 받아와 영상처리를 한다
//					1) pData는 Raw 데이타로 원본이 저장된 버퍼의 시작 포인터이다.
//					2) DrawData()를 호출하여 영상처리한다
// Pre			:	Timer 설정이 되어있어야 한다
// Post			:	원본 영상이 영상처리된다.
//=================================================================================================
void CVidCapDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);
	TRACE(L" %d:%d:%d\n", SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);

	// 일반적으로 nIDEvent는 여러 이벤트가 동시에 일어날때
	// 각각의 이벤트 마다 다른 행동을 지정하기 위한 방법으로 사용되는 변수이다
	// 하지만 이 프로그램에서는 이벤트가 하나이므로 사용하지 않는다

	// 웹캠에서 받아온 원본 영상 버퍼의 시작 포인터를 얻는다
	unsigned char* pData = sgGrabData();

	// 만약 원본 영상이 NULL이 아니면
	if (pData != 0)
	{
		// 영상처리 한다
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
// Parameter	:	unsigned char *pData - 영상처리를 수행할 이미지 파일
// Processing	:	DLL 함수를 호출하여 영상처리 한다.
// Pre			:	pData에 영상이 있어야 한다.
// Post			:	영상처리된 결과가 화면에 출력된다.
//=================================================================================================
void CVidCapDlg::DrawData(unsigned char *pData)
{
	//BGR이미지를 그레이로 바꾸고, 엣지를 얻는다.
	GrayToEdg(IN OUT pData );

	// 영상처리
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
// Processing	:	MFC 에서 생성자와 동일한 역할을 한다. 여기서 DLL을 불러온다.
// Pre			:	none
// Post			:	초기화된다
//=================================================================================================
int CVidCapDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	// MTES에서 작성한 dll 파일을 불러온다.
	if((hDll=LoadLibrary(L"iSobelEdgesUint8.dll"))==NULL)
	{
		MessageBox(L"Dll파일 로드 오류",L"");
	}

	// 불러온 dll의 함수에 접근 할 수 있는 함수포인터를 선언한다.
	Edg = (LPFNDLLEDG)GetProcAddress(hDll, "iSobelEdgesUint8");	

	return 0;
}

//=================================================================================================
// Function		:	GrayToEdg(IN OUT unsigned char* src_Img)
// Return		:	none
// Parameter	:	unsigned char* src_Img - 영상처리를 수행할 이미지 파일
// Processing	:	입력받은 640*480 3채널 이미지를 1채널 그레이 이미지로 바꾸고, 영상처리 후
//					다시 출력을 위해 3채널이미지로변환
//					1) 영상을 Grayscale 영상으로 변환한다.
//					2) Edge 생성 함수를 호출한다.
//					3) 결과 영상을 출력 버퍼에 저장한다.
// Pre			:	src_Img에 영상이 있어야 한다.
// Post			:	영상처리된 결과가 화면에 출력된다.
//=================================================================================================
void CVidCapDlg::GrayToEdg(IN OUT unsigned char* src_Img)//src_Img=BGR 3channel image
{
	// Grayscale을 저장할 버퍼의 포인터를 얻는다.
	BYTE *psrc = s_Img->GetBuffer();

	// RGB영상을 Grayscale 영상으로 변환한다.
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
// Parameter	:	unsigned char* pSrc - 원본 영상, unsigned char* pDst - 출력 영상
// Processing	:	입력받은 640*480 3채널 이미지를 1채널 그레이 이미지로 변경
// Pre			:	pSrc와 pDst가 할당되어 있어야 한다.
// Post			:	pSrc의 칼라 영상이 흑백으로 변환되어 pDst에 저장된다.
//=================================================================================================
void CVidCapDlg::RGBToGray(IN unsigned char* pSrc, OUT unsigned char* pDst)
{
	LPBYTE lpSrc = pSrc;
	LPBYTE lpDst = pDst;
	for( int x, y=0 ; y<m_nWidth ; y++ )
	{
		for( x=0; x<m_nHeight ; x++ )
		{
			// 단순하게 평균값을 구하여 저장한다.
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

// VidCapDlg.h : header file
//

//////////////////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� : VidCapDlg.h
// ��    �� : Webcam�� �̿��� �ǽð� Sobel edge ��� ���α׷�
// �� �� �� : �� �� �� <miryu17@khu.ac.kr>
// �� �� �� : 2010�� 5�� 25��
// ��    �� : KYUNGHEE UNIV IMAGE PROCESSING LAB
// ���ǻ��� : 1) DirectX 9.0b �Ǵ� Mircosoft Windows Platform SDK/DirectX SDK �� ��ġ�Ǿ� �־�� ��
// �������� : iSobelEdgesUint8.h
// �������� : 
// �������� : 
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "afxwin.h"

#include "IntImage.h"
#include "SimpleClassifier.h"
#include "AdaBoostClassifier.h"
#include "Global.h"
#include "CascadeClassifier.h"
#include "iSobelEdgesUint8.h"												// dll�� ȣ���ϱ� ���� ������� ���
typedef int (*LPFNDLLEDG)(KScScalarImage2dUint8*,KScScalarImage2dUint8*);	// dll�� �Լ��� ȣ���ϱ� ���� �Լ������� ������

// CVidCapDlg dialog
class CVidCapDlg : public CDialog
{
// Construction
public:

		LPFNDLLEDG Edg;					// type �����ǵ� �Լ� �����͸� ��ȯ�ϴ� �Լ� ����(���� dll�� edge�� ��� �Լ�)
		HINSTANCE hDll;					// dll ȣ�� ����� Ȯ���ϱ� ���� ����
		KScScalarImage2dUint8* s_Img;	// ���� Į�� ������ ������� ��ȯ�Ͽ� ������ ����
		KScScalarImage2dUint8* d_Img;	// edge�� ���� ����� ������ ����
        CVidCapDlg(CWnd* pParent = NULL);	// standard constructor
		IntImage image;					// Jaeyoung

// Dialog Data
        enum { IDD = IDD_VIDCAP_DIALOG };

protected:
        virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
        HICON m_hIcon;

        // Generated message map functions
        virtual BOOL OnInitDialog();
        afx_msg void OnPaint();
        afx_msg HCURSOR OnQueryDragIcon();
        DECLARE_MESSAGE_MAP()

private:
        double m_ResizeRatio;
        unsigned int m_Width;
        unsigned int m_Height;
        unsigned int m_Channels;

        UINT_PTR m_nTimer;
        double m_FpsRate;
        unsigned int m_MsPerFrame;
        unsigned int m_TotalFrames;
        unsigned int m_FramesProcessed;
        unsigned int m_Ms;        

        CStatic m_PrvStatic;
        CStatic m_CapImgStatic;
        CComboBox m_AdapterCombo;
        UINT m_TimerInterval;
        CButton m_RunButton;
        CStatic m_VideoFormat;
        bool m_TakeSnapshot;
	
		int m_nWidth;
		int m_nHeight;
        
        Gdiplus::Bitmap* m_CapturedFace;

        CLSID pBmpEncoder;
        int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);

        void DrawData(unsigned char* pData);        
  
        afx_msg LRESULT OnGraphMessage(WPARAM wParam, LPARAM lParam);
        afx_msg void OnBnClickedEnumadaptorsButton();
        afx_msg void OnBnClickedRunButton();
        afx_msg void OnTimer(UINT_PTR nIDEvent);
        afx_msg void OnClose();
        afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);

private:
        CString m_fDetectionTime;
        afx_msg void OnStnDblclickCapimgStatic();
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		void GrayToEdg(unsigned char* src_Img);
		void RGBToGray(unsigned char* pSrc, unsigned char* pDst);
public:
	afx_msg void OnBnClickedTrainButton();
};

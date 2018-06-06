// VidCapDlg.h : header file
//

//////////////////////////////////////////////////////////////////////////////////////////////
//
// 파 일 명 : VidCapDlg.h
// 설    명 : Webcam을 이용한 실시간 Sobel edge 출력 프로그램
// 작 성 자 : 임 동 선 <miryu17@khu.ac.kr>
// 작 성 일 : 2010년 5월 25일
// 소    속 : KYUNGHEE UNIV IMAGE PROCESSING LAB
// 주의사항 : 1) DirectX 9.0b 또는 Mircosoft Windows Platform SDK/DirectX SDK 가 설치되어 있어야 함
// 참조파일 : iSobelEdgesUint8.h
// 수정일자 : 
// 수정내용 : 
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "afxwin.h"

#include "IntImage.h"
#include "SimpleClassifier.h"
#include "AdaBoostClassifier.h"
#include "Global.h"
#include "CascadeClassifier.h"
#include "iSobelEdgesUint8.h"												// dll을 호출하기 위한 헤더파일 등록
typedef int (*LPFNDLLEDG)(KScScalarImage2dUint8*,KScScalarImage2dUint8*);	// dll의 함수를 호출하긴 위한 함수포인터 재정의

// CVidCapDlg dialog
class CVidCapDlg : public CDialog
{
// Construction
public:

		LPFNDLLEDG Edg;					// type 재정의된 함수 포인터를 반환하는 함수 선언(실제 dll의 edge를 얻는 함수)
		HINSTANCE hDll;					// dll 호출 결과를 확인하기 위한 변수
		KScScalarImage2dUint8* s_Img;	// 원본 칼라 영상을 흑백으로 변환하여 저장한 변수
		KScScalarImage2dUint8* d_Img;	// edge를 얻은 결과를 저장할 변수
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

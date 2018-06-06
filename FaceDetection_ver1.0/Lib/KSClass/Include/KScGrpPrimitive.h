#ifndef _KSCPRIMITIVE_H_
#define _KSCPRIMITIVE_H_

#include <windows.h>
#include <stdio.h>
#include "KScList.h"

// 현재 작업하고 있는 모드를 나타냄
enum ModeState {none, selection, Move, size, draw, range, reflect, rotate, shear };
// 각 프리미티브의 형태
enum PrimitiveType { KScTypePoint, line, polyline, rectangle, roundrect, ellipse, arc, 
					 pie, chord, polygon, spline, region, spray, Edgelist, Linelist,
			    	 image, group };


///////////////////////////////////////////////////////
//
//   데이타 클래스  
//
///////////////////////////////////////////////////////
class KS_CLASS KScPrimitiveBase
{
public:
    int  ShapeID;
	int  CtrlPntNum;
	RECT m_currRect;	
	RECT m_prevRect;	
	COLORREF attrib_color;
	int      attrib_width;

protected:
	KScPrimitiveBase();
	virtual	~KScPrimitiveBase();
	
// Implementation
public:
	void SetColor(COLORREF clr);
	void SetColor(int r, int g, int b);
	void SetWidth(int w);

    virtual BOOL SetData(int left, int top, int rihgt, int bottom);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int left, int top, int rihgt, int bottom);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();

	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


////////////////////////////////////////////////////////
// Point 객체
////////////////////////////////////////////////////////
class KS_CLASS KScPrimitivePoint : public KScPrimitiveBase
{
public :
	LONG xpos;
	LONG ypos;
	
public:
	KScPrimitivePoint();
	KScPrimitivePoint(int x, int y);
	KScPrimitivePoint(const POINT& point);
	~KScPrimitivePoint();

// Implementation
public:

	virtual int  GetID();
	virtual RECT GetData();

	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


////////////////////////////////////////////////////////
// 직선 그림 객체
////////////////////////////////////////////////////////
class KS_CLASS KScPrimitiveLine : public KScPrimitiveBase 
{
public:
//  int  ShapeID;
	int  CtrlPntNum;
	RECT m_currRect;	
	RECT m_prevRect;	

public:
	KScPrimitiveLine();
	KScPrimitiveLine(RECT pos);
	~KScPrimitiveLine();
	
// Implementation
public:

    virtual BOOL SetData(int left, int top, int rihgt, int bottom);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int left, int top, int rihgt, int bottom);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();

	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////////////
// 사각형 그림 객체
///////////////////////////////////////////////////////
class KS_CLASS KScPrimitiveRectangle  : public KScPrimitiveBase
{
public :
//  int  ShapeID;
	int  CtrlPntNum;
	RECT m_currRect;	
	RECT m_prevRect;
	
public:
	KScPrimitiveRectangle();
	KScPrimitiveRectangle(RECT pos);
	~KScPrimitiveRectangle();

// Implementation
public:

    virtual BOOL SetData(int, int, int, int);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int, int, int, int);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();


	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////////////
// ellipse 그림 객체
///////////////////////////////////////////////////////
class KS_CLASS KScPrimitiveEllipse  : public KScPrimitiveBase
{
public :
//    int  ShapeID;
	int  CtrlPntNum;
	RECT m_currRect;	
	RECT m_prevRect;
	
public:
	KScPrimitiveEllipse();
	KScPrimitiveEllipse(RECT pos);
	~KScPrimitiveEllipse();

// Implementation
public:

    virtual BOOL SetData(int, int, int, int);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int, int, int, int);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();


	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////////////
// RoundRect 그림 객체
///////////////////////////////////////////////////////
class KS_CLASS KScPrimitiveRoundRect  : public KScPrimitiveBase
{
public :
//    int   ShapeID;
	int   CtrlPntNum;
	POINT pnt;
	RECT  m_currRect;	
	RECT  m_prevRect;

public:
	KScPrimitiveRoundRect();
	KScPrimitiveRoundRect(RECT pos, POINT pt);
	~KScPrimitiveRoundRect();

// Implementation
public:

			BOOL  SetPnt(int x, int y);
			BOOL  SetPnt(POINT pt);
    virtual BOOL  SetData(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual BOOL  SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL  SetData(RECT pos, POINT pt);
	virtual BOOL  SetDataTopLeft(POINT lefttop);
	virtual BOOL  SetDataBottomRight(POINT rightbottom);
	virtual BOOL  SetPrevData(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual BOOL  SetPrevData(RECT pos, POINT pt);
	virtual int   GetID();
			POINT GetPnt();
	virtual RECT  GetData();
	virtual RECT  GetPrevData();
	virtual int   GetCtrlPntNum();


	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};

///////////////////////////////////////////////////////
// Arc 그림 객체
///////////////////////////////////////////////////////
class KS_CLASS KScPrimitiveArc  : public KScPrimitiveBase
{
public :
//  int   ShapeID;
	int   CtrlPntNum;
	POINT startpnt;
	RECT  m_currRect;	
	RECT  m_prevRect;

public:
	KScPrimitiveArc();
	KScPrimitiveArc(RECT pos, POINT pt);
	~KScPrimitiveArc();

// Implementation
public:

	BOOL  SetPnt(int x, int y);
	BOOL  SetPnt(POINT pt);
    virtual BOOL  SetData(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual BOOL  SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL  SetData(RECT pos, POINT pt);
	virtual BOOL  SetDataTopLeft(POINT lefttop);
	virtual BOOL  SetDataBottomRight(POINT rightbottom);
	virtual BOOL  SetPrevData(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual BOOL  SetPrevData(RECT pos, POINT pt);
	virtual int   GetID();
	virtual POINT GetPnt();
	virtual RECT  GetData();
	virtual RECT  GetPrevData();
	virtual int   GetCtrlPntNum();


	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////
// Edge Segment를 위한 클래스
///////////////////////////////////////////////
class KS_CLASS KScGrpEdgeSegment 
{
public :
	POINT startpoint;
	POINT endpoint;
	KScPrimitivePoint* Pointarray;
	RECT  m_MinRect;

	BOOL  hideflag; // hide의 여부
	BOOL  selectflag;
	BOOL  closedflag;

	// point를 저장하고 있는 배열의 index
	int array_index;

    //Color Model에서의 Edge 관련
	int total_plane_number; // GrayScale, RGB, YIQ, HSI, CMYK등 plane의 수
	int plane; // 여러개의 plane중 어떤 plane인지
	int intensity_of_plane; // plane에서 intensity의 값

	COLORREF segcolor; // 세그먼트내 포인트의 색
	int pixel_width;   // 픽셀의 두께

public :
	KScGrpEdgeSegment();
	KScGrpEdgeSegment(KScPrimitivePoint* parray);
	~KScGrpEdgeSegment();

	void SetSegmentColor(COLORREF clr);
    void SetSegmentWidth(int w);
    void SetSegmentHide(BOOL flag);
	BOOL IsHide();
	BOOL IsClosed();
	RECT Calculation_MinRect();

	void LoadFromFile(FILE* fp);  
	void SaveToFile(FILE* fp);
};


///////////////////////////////////////
// EdgeList를 위한 Class
///////////////////////////////////////
class KS_CLASS KScGrpEdgeList : public KScPrimitiveBase
{
public :

	int   CtrlPntNum;

	RECT  m_currRect;	
	RECT  m_prevRect;

	// edge를 가지는 Segment를 list로 연결하기 위한 변수
	KScList KScEdgeSegmentList;
	
	// opensegment or closesegment 상태인지 
	BOOL IsOpenSegment; 
	BOOL closedflag;

	// 실제적인 픽셀의 위치값들을 저장하고 있는 버퍼들
	KScPrimitivePoint* PntArray, *temp;
	KScGrpEdgeSegment* currPos;

	// 저장된 에지 세그먼트의 수
	int SegmentCnt;
	int inx;
 
//	ByteImg* srcImg; // 원본 이미지에 대한 포인터 

public:
	KScGrpEdgeList();
	~KScGrpEdgeList();
//	KScGrpEdgeList(ByteImg* input_image); // 원본이미지를 파라메타로 취하는 생성자 

	KScGrpEdgeSegment* CreateNewEdgeSegment();
	KScGrpEdgeSegment* CreateNewEdgeSegment(long size);
    KScGrpEdgeSegment* AddSegmentToEdgeList(KScGrpEdgeSegment* newElement);
    void OpenEdgeSegment();
	void OpenEdgeSegment(POINT ps);
    void CloseEdgeSegment();
	void CloseEdgeSegment(POINT ep);
    BOOL AddPointToEdgeSegment(POINT pt);
	int  GetCount();
	BOOL IsClosed();
	RECT GetMinRect();
	void SetMinRect(int left, int top, int right, int bottom);
	void SetMinRect(RECT rect);
	void DeleteCurrentSegment();

//	void MoveList(POINT delta);

	void Bresenham_Algorithm(POINT sp, POINT ep);
	
	void SetCurrentSegmentColor(COLORREF clr);
    void SetCurrentSegmentWidth(int w);
    void SetCurrentSegmentHide(BOOL flag);

    virtual BOOL SetData(int, int, int, int);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int, int, int, int);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();

	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////
// 직선의 방정식을 표현하기 위한 클래스
///////////////////////////////////////////
class KS_CLASS KScGrpLineEquInfo
{
public :
	float slope;
	float ydiff;
	BOOL  flag;

public :
	KScGrpLineEquInfo();
	~KScGrpLineEquInfo();
};


////////////////////////////////////////////
// Line Segment를 위한 클래스
////////////////////////////////////////////
class KS_CLASS KScGrpLineSegment
{
public :
	POINT startpoint;
	POINT endpoint;
	KScPrimitivePoint* Pointarray;
	RECT  m_MinRect;
	
	long GradientAngle;
	BOOL  hideflag; // hide의 여부
	BOOL  closedflag;

	// point를 저장하고 있는 배열의 index
	int array_index;

    //Color Model에서의 Edge 관련
	int total_plane_number; // GrayScale, RGB, YIQ, HSI, CMYK등 plane의 수
	int plane; // 여러개의 plane중 어떤 plane인지
	int intensity_of_plane; // plane에서 intensity의 값

	COLORREF segcolor; // 세그먼트내 포인트의 색
	int pixel_width;   // 픽셀의 두께

    KScGrpLineEquInfo* line_equation;

public :
	KScGrpLineSegment();
	~KScGrpLineSegment();

 	void SetSegmentColor(COLORREF clr);
    void SetSegmentWidth(int w);
    void SetSegmentHide(BOOL flag);

	long GetGradientAngle(POINT sx, POINT sy);
	void SetLineEquInfo(POINT sx, POINT y);
	KScGrpLineEquInfo* GetLineEquInfo(POINT sx, POINT sy);
	BOOL IsHide();
	BOOL IsClosed();
	RECT Calculation_MinRect();

	void SaveToFile(FILE* fp);
	void LoadFromFile(FILE* fp);  
};


///////////////////////////////////////
// LineList를 위한 Class
///////////////////////////////////////
class KS_CLASS KScGrpLineList : public KScPrimitiveBase
{
public :
	int   CtrlPntNum;

	RECT  m_currRect;	
	RECT  m_prevRect;

	// LineSegment를 가지는 Segment를 list로 연결하기 위한 변수
	KScList KScLineSegmentList;

	// opensegment or closesegment 상태인지 
	BOOL IsOpenSegment; 
	BOOL closedflag;

	// 실제적인 픽셀의 위치값들을 저장하고 있는 버퍼들
	KScPrimitivePoint* PntArray,* temp;
	KScGrpLineSegment* currPos;

	// 라인리스트(Polyline)를 표현할때 필요한 변수들
	POINT currentPoint;
	POINT prevPoint;

	// PolyLine인지의 여부를 표현하는 플래그
	BOOL Polylineflag;

	// 저장된 에지 세그먼트의 수
	int SegmentCnt;
	int inx;

	//	ByteImg* srcImg; // 원본 이미지에 대한 포인터 

public:
//	KScGrpLineList(ByteImg* input_image); // 원본이미지를 파라메타로 취하는 생성자 
	KScGrpLineList();
	~KScGrpLineList();

    KScGrpLineSegment* CreateNewLineSegment();
	KScGrpLineSegment* CreateNewLineSegment(long size);
	KScGrpLineSegment* AddSegmentToLineList(KScGrpLineSegment* newElement);
    BOOL AddPointToLineSegment(POINT pt);
    void OpenLineSegment();
	void OpenLineSegment(POINT ps);
    void CloseLineSegment();
	void CloseLineSegment(POINT ep);
	int  GetCount();
	BOOL IsClosed();
	RECT GetMinRect();
	void SetMinRect(int left, int top, int right, int bottom);
	void SetMinRect(RECT rect);
	    
	void Bresenham_Algorithm(POINT sp, POINT ep);
	
	void SetCurrentSegmentColor(COLORREF clr);
    void SetCurrentSegmentWidth(int w);
    void SetCurrentSegmentHide(BOOL flag);

    virtual BOOL SetData(int, int, int, int);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int, int, int, int);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();

	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);	
};


/////////////////////////////////////////////////////////////////////////////////////////
// 프리미티브의 형태가 일정치 않을때 사용하기 위한 region 클래스
//
//  여러개의 패턴을 만들어 놓은 다음 그것을 사용할 수 있도록 - 즉, 폴리곤의 형태를 정의
//
//   패턴
//      1. free type - 사용자가 임의대로 형태를 만듬
//		2. rectangle
//		3. triangle
//		4. star
//		5. pentagon
/////////////////////////////////////////////////////////////////////////////////////////
class KS_CLASS KScGrpRegion : public KScPrimitiveBase
{
public :
	int   CtrlPntNum;

	KScPrimitivePoint*        Pnt;    // boundary들을 저장하기 위한 변수 
	RECT              boundRect;      // 이미지의 외곽을 표시하기 위한 사각형
	int               Width, Height;  // 이미지의 크기
	BOOL              Isendtoend;       // 시작점과 끝점이 만나서 region을 형성하는지
	BOOL              RLEflag;          // RLE의 여부
	BOOL              fbackground;
	int               Pattern_Num;      // 이미 만들어진 패턴을 선택시 번호     
	int               Array_Index;
	int				  patter_or_bitmap_flag; // pattern = 0; bitmap =1; 	
	char              srcFileName[256];      // 이미지의 경로(화일명)
	
	unsigned char*    regionbuffer;     // region의 버퍼
	int               rWidth, rHeight;  // region의 크기
	//ByteImg*          srcImg;

	COLORREF color; // 세그먼트내 포인트의 색
	int pixel_width;   // 픽셀의 두께
	
public :
	KScGrpRegion();                        // 생성자
	KScGrpRegion(char* fName);                        // 생성자
	KScGrpRegion(int sx, int sy);          // 생성자 오버로딩
	~KScGrpRegion();                       // 생성자
	
	// 배경으로 사용할 이미지를 읽어들임
	void SetSize(int sx, int sy, int ex, int ey);
	void SetSize(int width, int height);
	void SetSize(RECT rect);
	void SetBufferFromSrc(unsigned char * buffer);  // regionbuffer로 이미지 값을 얻어옴
    void AllocPnt();           // boundary를 저장할 버퍼를 할당- 크기를 모를때
    void AllocPnt(int inx);   // boundary를 저장할 버퍼를 할당
	void AddPoint(KScPrimitivePoint pt); // boundary 버퍼에 값을 저장
	void AddPoint(POINT pt); // boundary 버퍼에 값을 저장
	void CopyPoint(KScPrimitivePoint* src, int inx); // 소스로부터 inx 만큼 픽셀의 위치값들을 얻어옴
	RECT GetMinRect(); // boundary를 포함하는 최소사각형을 얻어냄
	void SetRegionFromEdgeList(KScGrpEdgeList* list);
	void SetRegionFromEdgeList(KScGrpEdgeSegment* tSeg);
	void SetRegionFromEdgeList(KScPrimitivePoint* tPnt);
	void SetColor(COLORREF clr);
	void SetWidth(int w);
	//void RLE_Coding();

    virtual BOOL SetData(int, int, int, int);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int, int, int, int);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();

	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);	
};

/////////////////////////////////////////////////////////////////////////////////////////
// Image를 위한 클래스 - 단순히 비트맵 형태를 띈다.
/////////////////////////////////////////////////////////////////////////////////////////
class KS_CLASS KScGrpImage : public KScPrimitiveBase
{
public :
	int   CtrlPntNum;

	RECT              boundRect;      // 이미지의 외곽을 표시하기 위한 사각형
	int               Width, Height;  // 이미지의 크기
	BOOL              RLEflag;          // RLE의 여부
	char              srcFileName[256];      // 이미지의 경로(화일명)
	BOOL              fBackFlag;

	void*             srcImg;  // 원본 이미지의 포인터

public :
	KScGrpImage();                        // 생성자
	KScGrpImage(char* srcfName);          // 생성자
	KScGrpImage(int sx, int sy, char* srcfName); // 생성자 오버로딩
	~KScGrpImage();                       // 소멸자
	
	// 배경으로 사용할 이미지를 읽어들임
	void SetSize(int sx, int sy, int ex, int ey);
	void SetSize(int width, int height);
	void SetSize(RECT rect);
	void SetName(char* srcfName);
	RECT GetMinRect(); // boundary를 포함하는 최소사각형을 얻어냄

	//void RLE_Coding();

    virtual BOOL SetData(int, int, int, int);
	virtual BOOL SetData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetData(RECT pos);
	virtual BOOL SetDataTopLeft(POINT lefttop);
	virtual BOOL SetDataBottomRight(POINT rightbottom);
	virtual BOOL SetPrevData(int, int, int, int);
	virtual BOOL SetPrevData(POINT lefttop, POINT rightbottom);
	virtual BOOL SetPrevData(RECT pos);
	virtual int  GetID();
	virtual RECT GetData();
	virtual RECT GetPrevData();
	virtual int  GetCtrlPntNum();


	// 화일로부터 읽고 쓴다.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);	
};


#endif
#ifndef _KSCPRIMITIVE_H_
#define _KSCPRIMITIVE_H_

#include <windows.h>
#include <stdio.h>
#include "KScList.h"

// ���� �۾��ϰ� �ִ� ��带 ��Ÿ��
enum ModeState {none, selection, Move, size, draw, range, reflect, rotate, shear };
// �� ������Ƽ���� ����
enum PrimitiveType { KScTypePoint, line, polyline, rectangle, roundrect, ellipse, arc, 
					 pie, chord, polygon, spline, region, spray, Edgelist, Linelist,
			    	 image, group };


///////////////////////////////////////////////////////
//
//   ����Ÿ Ŭ����  
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

	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


////////////////////////////////////////////////////////
// Point ��ü
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

	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


////////////////////////////////////////////////////////
// ���� �׸� ��ü
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

	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////////////
// �簢�� �׸� ��ü
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


	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////////////
// ellipse �׸� ��ü
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


	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////////////
// RoundRect �׸� ��ü
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


	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};

///////////////////////////////////////////////////////
// Arc �׸� ��ü
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


	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////////
// Edge Segment�� ���� Ŭ����
///////////////////////////////////////////////
class KS_CLASS KScGrpEdgeSegment 
{
public :
	POINT startpoint;
	POINT endpoint;
	KScPrimitivePoint* Pointarray;
	RECT  m_MinRect;

	BOOL  hideflag; // hide�� ����
	BOOL  selectflag;
	BOOL  closedflag;

	// point�� �����ϰ� �ִ� �迭�� index
	int array_index;

    //Color Model������ Edge ����
	int total_plane_number; // GrayScale, RGB, YIQ, HSI, CMYK�� plane�� ��
	int plane; // �������� plane�� � plane����
	int intensity_of_plane; // plane���� intensity�� ��

	COLORREF segcolor; // ���׸�Ʈ�� ����Ʈ�� ��
	int pixel_width;   // �ȼ��� �β�

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
// EdgeList�� ���� Class
///////////////////////////////////////
class KS_CLASS KScGrpEdgeList : public KScPrimitiveBase
{
public :

	int   CtrlPntNum;

	RECT  m_currRect;	
	RECT  m_prevRect;

	// edge�� ������ Segment�� list�� �����ϱ� ���� ����
	KScList KScEdgeSegmentList;
	
	// opensegment or closesegment �������� 
	BOOL IsOpenSegment; 
	BOOL closedflag;

	// �������� �ȼ��� ��ġ������ �����ϰ� �ִ� ���۵�
	KScPrimitivePoint* PntArray, *temp;
	KScGrpEdgeSegment* currPos;

	// ����� ���� ���׸�Ʈ�� ��
	int SegmentCnt;
	int inx;
 
//	ByteImg* srcImg; // ���� �̹����� ���� ������ 

public:
	KScGrpEdgeList();
	~KScGrpEdgeList();
//	KScGrpEdgeList(ByteImg* input_image); // �����̹����� �Ķ��Ÿ�� ���ϴ� ������ 

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

	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);
};


///////////////////////////////////////////
// ������ �������� ǥ���ϱ� ���� Ŭ����
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
// Line Segment�� ���� Ŭ����
////////////////////////////////////////////
class KS_CLASS KScGrpLineSegment
{
public :
	POINT startpoint;
	POINT endpoint;
	KScPrimitivePoint* Pointarray;
	RECT  m_MinRect;
	
	long GradientAngle;
	BOOL  hideflag; // hide�� ����
	BOOL  closedflag;

	// point�� �����ϰ� �ִ� �迭�� index
	int array_index;

    //Color Model������ Edge ����
	int total_plane_number; // GrayScale, RGB, YIQ, HSI, CMYK�� plane�� ��
	int plane; // �������� plane�� � plane����
	int intensity_of_plane; // plane���� intensity�� ��

	COLORREF segcolor; // ���׸�Ʈ�� ����Ʈ�� ��
	int pixel_width;   // �ȼ��� �β�

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
// LineList�� ���� Class
///////////////////////////////////////
class KS_CLASS KScGrpLineList : public KScPrimitiveBase
{
public :
	int   CtrlPntNum;

	RECT  m_currRect;	
	RECT  m_prevRect;

	// LineSegment�� ������ Segment�� list�� �����ϱ� ���� ����
	KScList KScLineSegmentList;

	// opensegment or closesegment �������� 
	BOOL IsOpenSegment; 
	BOOL closedflag;

	// �������� �ȼ��� ��ġ������ �����ϰ� �ִ� ���۵�
	KScPrimitivePoint* PntArray,* temp;
	KScGrpLineSegment* currPos;

	// ���θ���Ʈ(Polyline)�� ǥ���Ҷ� �ʿ��� ������
	POINT currentPoint;
	POINT prevPoint;

	// PolyLine������ ���θ� ǥ���ϴ� �÷���
	BOOL Polylineflag;

	// ����� ���� ���׸�Ʈ�� ��
	int SegmentCnt;
	int inx;

	//	ByteImg* srcImg; // ���� �̹����� ���� ������ 

public:
//	KScGrpLineList(ByteImg* input_image); // �����̹����� �Ķ��Ÿ�� ���ϴ� ������ 
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

	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);	
};


/////////////////////////////////////////////////////////////////////////////////////////
// ������Ƽ���� ���°� ����ġ ������ ����ϱ� ���� region Ŭ����
//
//  �������� ������ ����� ���� ���� �װ��� ����� �� �ֵ��� - ��, �������� ���¸� ����
//
//   ����
//      1. free type - ����ڰ� ���Ǵ�� ���¸� ����
//		2. rectangle
//		3. triangle
//		4. star
//		5. pentagon
/////////////////////////////////////////////////////////////////////////////////////////
class KS_CLASS KScGrpRegion : public KScPrimitiveBase
{
public :
	int   CtrlPntNum;

	KScPrimitivePoint*        Pnt;    // boundary���� �����ϱ� ���� ���� 
	RECT              boundRect;      // �̹����� �ܰ��� ǥ���ϱ� ���� �簢��
	int               Width, Height;  // �̹����� ũ��
	BOOL              Isendtoend;       // �������� ������ ������ region�� �����ϴ���
	BOOL              RLEflag;          // RLE�� ����
	BOOL              fbackground;
	int               Pattern_Num;      // �̹� ������� ������ ���ý� ��ȣ     
	int               Array_Index;
	int				  patter_or_bitmap_flag; // pattern = 0; bitmap =1; 	
	char              srcFileName[256];      // �̹����� ���(ȭ�ϸ�)
	
	unsigned char*    regionbuffer;     // region�� ����
	int               rWidth, rHeight;  // region�� ũ��
	//ByteImg*          srcImg;

	COLORREF color; // ���׸�Ʈ�� ����Ʈ�� ��
	int pixel_width;   // �ȼ��� �β�
	
public :
	KScGrpRegion();                        // ������
	KScGrpRegion(char* fName);                        // ������
	KScGrpRegion(int sx, int sy);          // ������ �����ε�
	~KScGrpRegion();                       // ������
	
	// ������� ����� �̹����� �о����
	void SetSize(int sx, int sy, int ex, int ey);
	void SetSize(int width, int height);
	void SetSize(RECT rect);
	void SetBufferFromSrc(unsigned char * buffer);  // regionbuffer�� �̹��� ���� ����
    void AllocPnt();           // boundary�� ������ ���۸� �Ҵ�- ũ�⸦ �𸦶�
    void AllocPnt(int inx);   // boundary�� ������ ���۸� �Ҵ�
	void AddPoint(KScPrimitivePoint pt); // boundary ���ۿ� ���� ����
	void AddPoint(POINT pt); // boundary ���ۿ� ���� ����
	void CopyPoint(KScPrimitivePoint* src, int inx); // �ҽ��κ��� inx ��ŭ �ȼ��� ��ġ������ ����
	RECT GetMinRect(); // boundary�� �����ϴ� �ּһ簢���� ��
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

	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);	
};

/////////////////////////////////////////////////////////////////////////////////////////
// Image�� ���� Ŭ���� - �ܼ��� ��Ʈ�� ���¸� ���.
/////////////////////////////////////////////////////////////////////////////////////////
class KS_CLASS KScGrpImage : public KScPrimitiveBase
{
public :
	int   CtrlPntNum;

	RECT              boundRect;      // �̹����� �ܰ��� ǥ���ϱ� ���� �簢��
	int               Width, Height;  // �̹����� ũ��
	BOOL              RLEflag;          // RLE�� ����
	char              srcFileName[256];      // �̹����� ���(ȭ�ϸ�)
	BOOL              fBackFlag;

	void*             srcImg;  // ���� �̹����� ������

public :
	KScGrpImage();                        // ������
	KScGrpImage(char* srcfName);          // ������
	KScGrpImage(int sx, int sy, char* srcfName); // ������ �����ε�
	~KScGrpImage();                       // �Ҹ���
	
	// ������� ����� �̹����� �о����
	void SetSize(int sx, int sy, int ex, int ey);
	void SetSize(int width, int height);
	void SetSize(RECT rect);
	void SetName(char* srcfName);
	RECT GetMinRect(); // boundary�� �����ϴ� �ּһ簢���� ��

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


	// ȭ�Ϸκ��� �а� ����.
	virtual void LoadFromFile(FILE* fp);
	virtual void SaveToFile(FILE* fp);	
};


#endif
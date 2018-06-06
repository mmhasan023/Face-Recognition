#ifndef _KSC_GRAPHIC_
#define _KSC_GRAPHIC_

#define NEWDOC  0
#define OPENDOC 1

// 2002.05.21. - Younghyun Ha
//#include "KScHistogram.h"
#include "KScObject.h"
// 2002.05.21. - Younghyun Ha - End

#include "KScList.h"

////////////////////////////////////////////////////////
// KScGraphic Class

// 2002.05.21. - Younghyun Ha
//class KS_CLASS KScGraphic : public KScHistogram
class KS_CLASS KScGraphic : public KScObject
// 2002.05.21. - Younghyun Ha - End
{

public:

	KScList SegmentList;  // 세그먼트의 리스트

	int     xSize;
	int     ySize;

// 2002.05.21. - Younghyun Ha
/*	char    title[256];
    int     sr, sg, sb; //COLORREF set_color;
	int     set_width;
*/
	char    pathname[256];

	int     primitive_red; //COLORREF set_color;
	int     primitive_green;
	int     primitive_blue;

	int     primitive_width;
// 2002.05.21. - Younghyun Ha - End

	void    *Manage;      // 메모리 메니지먼트를 위한 변수.
	int     Dllflag;

public:

	KScGraphic();
	KScGraphic(char *name);
	KScGraphic(char *name, int xSize, int ySize);

	virtual	~KScGraphic();

// 2002.05.21. - Younghyun Ha
/*
	int  SetSize(int xSize, int ySize);
	
	int  GetSizeX();
	int  GetSizeY();

	int  SetColor(int red, int green, int blue);
	int  SetWidth(int width);

	int  DrawLine     (int left, int top, int rihgt, int bottom);
	int  DrawRectangle(int left, int top, int rihgt, int bottom);
	int  DrawEllipse  (int left, int top, int rihgt, int bottom);
	int  DrawRoundRect(int left, int top, int rihgt, int bottom, int ax=20, int ay=20);
	int  DrawArc      (int left, int top, int rihgt, int bottom, int ax=20, int ay=20);
	int  DrawImage    (int left, int top, int rihgt, int bottom, char* name);

	int  ReadGraphic(char*filename);
	int  WriteGraphic(char*filename);
*/
	void SetSize(int xSize, int ySize);

	void SetXSize(int xSize);
	void SetYSize(int ySize);

	int  GetXSize();
	int  GetYSize();

	void SetColor(int red, int green, int blue);
	void SetWidth(int width);

	int  AddLine     (int left, int top, int rihgt, int bottom);
	int  AddRectangle(int left, int top, int rihgt, int bottom);
	int  AddRoundRect(int left, int top, int rihgt, int bottom, int ax=20, int ay=20);
	int  AddEllipse  (int left, int top, int rihgt, int bottom);
	int  AddArc      (int left, int top, int rihgt, int bottom, int ax=20, int ay=20);
	int  AddImage    (int left, int top, int rihgt, int bottom, char* name);

	int  ReadFromFile(char*filename);
	int  WriteToFile (char*filename);
// 2002.05.21. - Younghyun Ha - End  

	KScGraphic& operator=(KScGraphic &p);
};

#endif // _GRAPHIC_	

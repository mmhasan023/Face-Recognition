#ifndef _KSC_GRAPHIC_
#define _KSC_GRAPHIC_

#define NEWDOC  0
#define OPENDOC 1

#include "KScHistogram.h"
#include "KScList.h"

////////////////////////////////////////////////////////
// H_Graphic Class

class KS_CLASS KScGraphic : public KScHistogram
{

public:

	int  xSize;
	int  ySize;

	char    title[256];

	KScList SegmentList;  // 세그먼트의 리스트

	void    *Manage;      // 메모리 메니지먼트를 위한 변수.

	int   Dllflag;

	int   sr, sg, sb; //COLORREF set_color;
	int   set_width;

public:

	KScGraphic();
	KScGraphic(char *name);
	KScGraphic(char *name, int dx, int dy);

	virtual	~KScGraphic();

	int  ReadGraphic(char*);
	int  WriteGraphic(char*);    
	KScGraphic& operator=(KScGraphic &p);

	int  SetColor(int r, int g, int b);
	int  SetWidth(int w);
	int  SetSize(int dx, int dy);
	int  GetSizeX();
	int  GetSizeY();

	int  DrawLine     (int left, int top, int rihgt, int bottom);
	int  DrawRectangle(int left, int top, int rihgt, int bottom);
	int  DrawEllipse  (int left, int top, int rihgt, int bottom);
	int  DrawRoundRect(int left, int top, int rihgt, int bottom, int ax=20, int ay=20);
	int  DrawArc      (int left, int top, int rihgt, int bottom, int ax=20, int ay=20);
	int  DrawImage    (int left, int top, int rihgt, int bottom, char* name);
	
};

#endif // _GRAPHIC_	

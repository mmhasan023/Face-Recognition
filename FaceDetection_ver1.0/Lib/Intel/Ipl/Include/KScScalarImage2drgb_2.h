#ifndef __KSC_SCALARIMAGE2DRGB_H__
#define __KSC_SCALARIMAGE2DRGB_H__

#include "KScScalarImage2d.h"

#ifndef DIRECTION
#define DIRECTION

    // buffer order
	#define BOTTOM_UP  0x01 // general DIB type (default)
	#define TOP_DOWN   0x00 // buffer pointer start at top - reverse DIB

    // RGB order
	#define SCALAR_BGR 0x10 // BGR order(default)
	#define SCALAR_RGB 0x00 // RGB order


#endif

class KScRgbImage2d;

class KS_CLASS KScScalarImage2dRgb : public KScScalarImage2d
{

// attribute
public:
	KScData2dRgb* pRealData; // original image pointer
	KScData2dRgb* pRealRoi;	 // roi image pointer for copy mode
	KSdRgb*       pData;	 // access image pointer
	KSdRgb**      p2dArray;	 // 2d Array
	KSdRgb**      pRoiData;	 // roi image pointer

	int           direction; // BOTTOM_UP(default) or TOP_DOWN

// methods
public:

	KScScalarImage2dRgb(void);
	KScScalarImage2dRgb(char *szName);
	KScScalarImage2dRgb(int xSize, int ySize);
	KScScalarImage2dRgb(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dRgb(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);
	KSdRgb*  GetBuffer     (void);
	KSdRgb*  GetMainBuffer (void);
	KSdRgb** Get2dArray    (void);
	KSdRgb** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	
	void   SetPixel(KSdRgb pixel, KS_2D_POINT &point);
	void   SetPixel(KSdRgb pixel, int x, int y);
	void   GetPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdRgb &pixel, int x, int y);
	KSdRgb GetPixel(KS_2D_POINT &point);
	KSdRgb GetPixel(int x, int y);
	
	void PutRow(KSdRgb* row, int y, int x, int len);
	void GetRow(KSdRgb* row, int y, int x, int len);

	void SetSection(KSdRgb* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdRgb* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdRgb value);

	void CopyToObject (KScScalarImage2dRgb *dst);
	void SetFromObject(KScScalarImage2dRgb *src);

	// 컬러 클래스와의 인터페이스를 위해 rgb image만의 변경 루틴을 넣는다.
	void ConvertToRgbImage(KScRgbImage2d *dst);

	KScScalarImage2dRgb& operator=(KScScalarImage2dRgb &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

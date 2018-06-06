#ifndef __KSC_SCALARIMAGE2DCOMPLEX_H__
#define __KSC_SCALARIMAGE2DCOMPLEX_H__

#include "KScScalarImage2d.h"

class KS_CLASS KScScalarImage2dComplex : public KScScalarImage2d
{

// attribute
public:
	KScData2dComplex* pRealData; // original image pointer
	KScData2dComplex* pRealRoi;  // roi image pointer for copy mode
	KSdComplex*       pData;     // access image pointer
	KSdComplex**      p2dArray;  // 2d Array
	KSdComplex**      pRoiData;  // roi image pointer

// methods
public:

	KScScalarImage2dComplex(void);
	KScScalarImage2dComplex(char *name);
	KScScalarImage2dComplex(int xSize, int ySize);
	KScScalarImage2dComplex(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dComplex(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KSdComplex*  GetBuffer     (void);
	KSdComplex*  GetMainBuffer (void);
	KSdComplex** Get2dArray    (void);
	KSdComplex** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize(void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize(void);
	int        GetXSize(void);
	int        GetYSize(void);
	
	void       SetPixel(KSdComplex pixel, KS_2D_POINT &point);
	void       SetPixel(KSdComplex pixel, int x, int y);
	void       GetPixel(KSdComplex &pixel, KS_2D_POINT &point);
	void       GetPixel(KSdComplex &pixel, int x, int y);
	KSdComplex GetPixel(KS_2D_POINT &point);
	KSdComplex GetPixel(int x, int y);
	
	void PutRow(KSdComplex* row, int y, int x, int len);
	void GetRow(KSdComplex* row, int y, int x, int len);

	void SetSection(KSdComplex* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdComplex* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdComplex value);

	void CopyToObject(KScScalarImage2dComplex *dst);
	void SetFromObject(KScScalarImage2dComplex *src);
	// 컬러 클래스와의 인터페이스를 위해 rgb image만의 변경 루틴을 넣는다.

	KScScalarImage2dComplex& operator=(KScScalarImage2dComplex &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

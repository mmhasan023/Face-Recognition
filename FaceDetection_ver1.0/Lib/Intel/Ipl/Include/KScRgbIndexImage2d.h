#ifndef __KSC_RGBINDEXIMAGE2DUINT8_H__
#define __KSC_RGBINDEXIMAGE2DUINT8_H__

#include "KScColorImage2d.h"
#include "KScScalarImage2dUint8.h"
#include "KScRgbImage2d.h"

class KS_CLASS KScRgbIndexImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dUint8* pRealData; // original image pointer
	KScData2dUint8* pRealRoi;  // roi image pointer for copy mode
	KSdUint8*       pData;	   // access image pointer
	KSdUint8**      p2dArray;  // 2d Array
	KSdUint8**      pRoiData;  // roi image pointer

	int     lktNum;		       // lookup table number
	KSdRgb* lookupTable;	   // lookup table pointer

// methods
public:

	KScRgbIndexImage2d(void);
	KScRgbIndexImage2d(char *name);
	KScRgbIndexImage2d(int xSize, int ySize);
	KScRgbIndexImage2d(char *name, int xSize, int ySize);
	virtual	~KScRgbIndexImage2d(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);
	
	void ResetLookupTable(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);

	int     GetLktNumber(void);
	KSdRgb  GetLktValue(int i);
	KSdRgb* GetLktBuffer(void);

	// single-plane operation -----------------------------------------------------------
	KSdUint8*  GetBuffer(void);
	KSdUint8*  GetMainBuffer(void);
	KSdUint8** Get2dArray(void);
	KSdUint8** GetMain2dArray();

	void     SetPixel(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixel(KSdUint8 pixel, int x, int y);
	void     GetPixel(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdUint8 &pixel, int x, int y);
	KSdUint8 GetPixel(KS_2D_POINT &point);
	KSdUint8 GetPixel(int x, int y);

	void PutRow(KSdUint8* row, int y, int x, int len);
	void GetRow(KSdUint8* row, int y, int x, int len);

	void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdUint8 value=0);

	void CopyToScalarImage(KScScalarImage2dUint8 *dst);
	void SetFromScalarImage(KScScalarImage2dUint8 *dst);

	void ConvertToRgbImage(KScRgbImage2d *dst);

	// multi-plane operation -----------------------------------------------------------
	void   GetLktPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void   GetLktPixel(KSdRgb &pixel, int x, int y);
	KSdRgb GetLktPixel(KS_2D_POINT &point);
	KSdRgb GetLktPixel(int x, int y);
	
	void GetLktRow(KSdRgb* row, int y, int x, int len);
	
	void GetLktSection(KSdRgb* section, int x, int y, int xSize, int ySize);

	void CopyToObject(KScRgbIndexImage2d *dst);
	void SetFromObject(KScRgbIndexImage2d *src);

	KScRgbIndexImage2d& operator=(KScRgbIndexImage2d &p);

	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);

protected:

	void SetLktNumber(int num) { lktNum=num; }
};

#endif

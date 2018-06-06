#ifndef __KSC_SCALARIMAGE2DBIT_H__
#define __KSC_SCALARIMAGE2DBIT_H__

#include "KScScalarImage2d.h"

class KScScalarImage2dUint8;

class KS_CLASS KScScalarImage2dBit : public KScScalarImage2d
{

// attribute
public:
	KScData2dUint8* pRealData; // original image pointer
	KScData2dUint8* pRealRoi;  // roi image pointer for copy mode
	KSdUint8*       pData;	   // access image pointer
	KSdUint8**      p2dArray;  // 2d Array
	KSdUint8**      pRoiData;  // roi image pointer

// methods
public:

	KScScalarImage2dBit(void);
	KScScalarImage2dBit(char *name);
	KScScalarImage2dBit(int xSize, int ySize);
	KScScalarImage2dBit(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dBit(void);

	virtual int  Alloc(int xSize, int ySize);
	virtual void Free(void);
	
	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KSdUint8*  GetBuffer(void);
	KSdUint8*  GetMainBuffer(void);
	KSdUint8** Get2dArray(void);
	KSdUint8** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize(void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize(void);
	int        GetXSize(void);
	int        GetYSize(void);
	
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

	void InitTo(KSdUint8 value);

	void CopyToObject(KScScalarImage2dBit *dst);
	void SetFromObject(KScScalarImage2dBit *src);
	
	void ConvertToScalarImage2dUint8(KScScalarImage2dUint8 *dst);

	KScScalarImage2dBit& operator=(KScScalarImage2dBit &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

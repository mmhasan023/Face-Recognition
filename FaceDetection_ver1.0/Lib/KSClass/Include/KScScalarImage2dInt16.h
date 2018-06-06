#ifndef __KSC_SCALARIMAGE2DINT16_H__
#define __KSC_SCALARIMAGE2DINT16_H__

#include "KScScalarImage2d.h"

class KS_CLASS KScScalarImage2dInt16 : public KScScalarImage2d
{

// attribute
public:
	KScData2dInt16* pRealData; // original image pointer
	KScData2dInt16* pRealRoi;  // roi image pointer for copy mode
	KSdInt16*       pData;     // access image pointer
	KSdInt16**      p2dArray;  // 2d Array
	KSdInt16**      pRoiData;  // roi image pointer

// methods
public:

	KScScalarImage2dInt16(void);
	KScScalarImage2dInt16(int xSize, int ySize);
	KScScalarImage2dInt16(char *name);
	KScScalarImage2dInt16(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dInt16(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KSdInt16*  GetBuffer     (void);
	KSdInt16*  GetMainBuffer (void);
	KSdInt16** Get2dArray    (void);
	KSdInt16** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	
	void     SetPixel(KSdInt16 pixel, KS_2D_POINT &point);
	void     SetPixel(KSdInt16 pixel, int x, int y);
	void     GetPixel(KSdInt16 &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdInt16 &pixel, int x, int y);
	KSdInt16 GetPixel(KS_2D_POINT &point);
	KSdInt16 GetPixel(int x, int y);
	
	void GetRow(KSdInt16* row, int y, int x, int len);
	void PutRow(KSdInt16* row, int y, int x, int len);

	void GetSection(KSdInt16* section, int x, int y, int xSize, int ySize);
	void SetSection(KSdInt16* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdInt16 value=0);

	void CopyToObject (KScScalarImage2dInt16 *dst);
	void SetFromObject(KScScalarImage2dInt16 *src);

	KScScalarImage2dInt16& operator=(KScScalarImage2dInt16 &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

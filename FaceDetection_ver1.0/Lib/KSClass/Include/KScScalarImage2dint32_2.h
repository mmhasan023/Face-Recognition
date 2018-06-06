#ifndef __KSC_SCALARIMAGE2DINT32_H__
#define __KSC_SCALARIMAGE2DINT32_H__

#include "KScScalarImage2d.h"

class KS_CLASS KScScalarImage2dInt32 : public KScScalarImage2d
{

// attribute
public:
	KScData2dInt32* pRealData; // original image pointer
	KScData2dInt32* pRealRoi;  // roi image pointer for copy mode
	KSdInt32*       pData;	   // access image pointer
	KSdInt32**      p2dArray;  // 2d Array
	KSdInt32**      pRoiData;  // roi image pointer

// methods
public:

	KScScalarImage2dInt32(void);
	KScScalarImage2dInt32(char *name);
	KScScalarImage2dInt32(int xSize, int ySize);
	KScScalarImage2dInt32(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dInt32(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KSdInt32*  GetBuffer     (void);
	KSdInt32*  GetMainBuffer (void);
	KSdInt32** Get2dArray    (void);
	KSdInt32** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	
	void     SetPixel(KSdInt32 pixel, KS_2D_POINT &point);
	void     SetPixel(KSdInt32 pixel, int x, int y);
	void     GetPixel(KSdInt32 &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdInt32 &pixel, int x, int y);
	KSdInt32 GetPixel(KS_2D_POINT &point);
	KSdInt32 GetPixel(int x, int y);
	
	void PutRow(KSdInt32* row, int y, int x, int len);
	void GetRow(KSdInt32* row, int y, int x, int len);

	void SetSection(KSdInt32* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdInt32* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdInt32 value=0);

	void CopyToObject (KScScalarImage2dInt32 *dst);
	void SetFromObject(KScScalarImage2dInt32 *src);

	KScScalarImage2dInt32& operator=(KScScalarImage2dInt32 &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

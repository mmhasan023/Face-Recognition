#ifndef __KSC_SCALARIMAGE2DDOUBLE_H__
#define __KSC_SCALARIMAGE2DDOUBLE_H__

#include "KScScalarImage2d.h"

class KS_CLASS KScScalarImage2dDouble : public KScScalarImage2d
{

// attribute
public:
	KScData2dDouble* pRealData; // original image pointer
	KScData2dDouble* pRealRoi;  // roi image pointer for copy mode
	KSdDouble*       pData;     // access image pointer
	KSdDouble**      p2dArray;  // 2d Array
	KSdDouble**      pRoiData;  // roi image pointer

// methods
public:

	KScScalarImage2dDouble(void);
	KScScalarImage2dDouble(char *name);
	KScScalarImage2dDouble(int xSize, int ySize);
	KScScalarImage2dDouble(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dDouble(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KSdDouble*  GetBuffer     (void);
	KSdDouble*  GetMainBuffer (void);
	KSdDouble** Get2dArray    (void);
	KSdDouble** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	
	void      SetPixel(KSdDouble pixel, KS_2D_POINT &point);
	void      SetPixel(KSdDouble pixel, int x, int y);
	void      GetPixel(KSdDouble &pixel, KS_2D_POINT &point);
	void      GetPixel(KSdDouble &pixel, int x, int y);
	KSdDouble GetPixel(KS_2D_POINT &point);
	KSdDouble GetPixel(int x, int y);

	void PutRow(KSdDouble* row, int y, int x, int len);
	void GetRow(KSdDouble* row, int y, int x, int len);

	void SetSection(KSdDouble* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdDouble* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdDouble value=0.0);

	void CopyToObject (KScScalarImage2dDouble *dst);
	void SetFromObject(KScScalarImage2dDouble *src);

	KScScalarImage2dDouble& operator=(KScScalarImage2dDouble &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

#ifndef __KSC_SCALARIMAGE2DFLOAT_H__
#define __KSC_SCALARIMAGE2DFLOAT_H__

#include "KScScalarImage2d.h"

class KS_CLASS KScScalarImage2dFloat : public KScScalarImage2d
{

// attribute
public:
	KScData2dFloat* pRealData; // original image pointer
	KScData2dFloat* pRealRoi;  // roi image pointer for copy mode
	KSdFloat*       pData;     // access image pointer
	KSdFloat**      p2dArray;  // 2d Array
	KSdFloat**      pRoiData;  // roi image pointer

public:
								   
// methods
public:

	KScScalarImage2dFloat(void);
	KScScalarImage2dFloat(char *name);
	KScScalarImage2dFloat(int xSize, int ySize);
	KScScalarImage2dFloat(char *name, int xSize, int ySize);
	virtual	~KScScalarImage2dFloat(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KSdFloat*  GetBuffer     (void);
	KSdFloat*  GetMainBuffer (void);
	KSdFloat** Get2dArray    (void);
	KSdFloat** GetMain2dArray(void);
	
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);
	
	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	
	void     SetPixel(KSdFloat pixel, KS_2D_POINT &point);
	void     SetPixel(KSdFloat pixel, int x, int y);
	void     GetPixel(KSdFloat &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdFloat &pixel, int x, int y);
	KSdFloat GetPixel(KS_2D_POINT &point);
	KSdFloat GetPixel(int x, int y);
	
	void PutRow(KSdFloat* row, int y, int x, int len);
	void GetRow(KSdFloat* row, int y, int x, int len);

	void SetSection(KSdFloat* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdFloat* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdFloat value=0.0f);

	void CopyToObject (KScScalarImage2dFloat *dst);
	void SetFromObject(KScScalarImage2dFloat *src);

	KScScalarImage2dFloat& operator=(KScScalarImage2dFloat &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

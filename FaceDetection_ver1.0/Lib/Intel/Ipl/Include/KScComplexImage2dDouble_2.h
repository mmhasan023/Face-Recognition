#ifndef __KSC_COMPLEXIMAGE2DDOUBLE_H__
#define __KSC_COMPLEXIMAGE2DDOUBLE_H__

#include "KScComplexImage2d.h"
#include "KScScalarImage2dDouble.h"

class KS_CLASS KScComplexImage2dDouble : public KScComplexImage2d
{

// attribute
public:
	KScData2dDouble* pRealData[COMPLEX_PLANE_NUM]; // original image pointer
	KScData2dDouble* pRealRoi [COMPLEX_PLANE_NUM]; // ROI image pointer
	KSdDouble*       pData    [COMPLEX_PLANE_NUM]; // access image pointer
	KSdDouble**      p2dArray [COMPLEX_PLANE_NUM]; // 2d Array
	KSdDouble**      pRoiData [COMPLEX_PLANE_NUM]; // roi image pointer

// methods
public:

	KScComplexImage2dDouble(void);
	KScComplexImage2dDouble(char *name);
	KScComplexImage2dDouble(int xSize, int ySize);
	KScComplexImage2dDouble(char *name, int xSize, int ySize);
	virtual	~KScComplexImage2dDouble(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);
	
	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	virtual void SetRoiMode   (int mode);

	KS_2D_SIZE GetMainSize(void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize(void);
	int        GetXSize(void);
	int        GetYSize(void);

	// single-plane operation -----------------------------------------------------------
	KSdDouble* GetBuffer         (int planeNum);
	KSdDouble* GetRealBuffer     (void);
	KSdDouble* GetImaginaryBuffer(void);

	KSdDouble* GetMainBuffer         (int planeNum);
	KSdDouble* GetMainRealBuffer     (void);
	KSdDouble* GetMainImaginaryBuffer(void);

	KSdDouble** Get2dArray         (int planeNum);
	KSdDouble** GetReal2dArray     (void);
	KSdDouble** GetImaginary2dArray(void);

	KSdDouble** GetMain2dArray         (int planeNum);
	KSdDouble** GetMainReal2dArray     (void);
	KSdDouble** GetMainImaginary2dArray(void);

	void      SetPixel(KSdDouble pixel, KS_2D_POINT &point, int planeNum);
	void      SetPixel(KSdDouble pixel, int x, int y, int planeNum);
	void      GetPixel(KSdDouble &pixel, KS_2D_POINT &point, int planeNum);
	void      GetPixel(KSdDouble &pixel, int x, int y, int planeNum);
	KSdDouble GetPixel(KS_2D_POINT &point, int planeNum);
	KSdDouble GetPixel(int x, int y, int planeNum);

	void PutRow(KSdDouble* row, int y, int x, int len, int planeNum);
	void GetRow(KSdDouble* row, int y, int x, int len, int planeNum);

	void SetSection(KSdDouble* section, int x, int y, int xSize, int ySize, int planeNum);
	void GetSection(KSdDouble* section, int x, int y, int xSize, int ySize, int planeNum);

	void InitTo(KSdDouble value, int planeNum);

	KSdDouble GetPixelMagnitude(KS_2D_POINT &point);
	KSdDouble GetPixelMagnitude(int x, int y);
	void      GetPixelMagnitude(KSdDouble &value, KS_2D_POINT &point);
	void      GetPixelMagnitude(KSdDouble &value, int x, int y);

	KSdDouble GetPixelPhase(KS_2D_POINT &point);
	KSdDouble GetPixelPhase(int x, int y);
	void      GetPixelPhase(KSdDouble &value, KS_2D_POINT &point);
	void      GetPixelPhase(KSdDouble &value, int x, int y);

	void SetPixelByPolar(KSdDouble mag, KSdDouble pha, int x, int y);

	void CopyToScalarImage (int planeNum, KScScalarImage2dDouble *dst);
	void SetFromScalarImage(int planeNum, KScScalarImage2dDouble *dst);

	void SplitPlane         (int planeNum, KScScalarImage2dDouble *dst);
	void SplitAllPlane      (KScScalarImage2dDouble *R, KScScalarImage2dDouble *I);
	void SplitRealPlane     (KScScalarImage2dDouble *dst);
	void SplitImaginaryPlane(KScScalarImage2dDouble *dst);

	void MergePlane         (int planeNum, KScScalarImage2dDouble *src);
	void MergeAllPlane      (KScScalarImage2dDouble *R, KScScalarImage2dDouble *I);
	void MergeRealPlane     (KScScalarImage2dDouble *dst);
	void MergeImaginaryPlane(KScScalarImage2dDouble *dst);

	// multi-plane operation -----------------------------------------------------------
	void             SetPixel(KSdComplexDouble pixel, KS_2D_POINT &point);
	void             SetPixel(KSdComplexDouble pixel, int x, int y);
	void             GetPixel(KSdComplexDouble &pixel, KS_2D_POINT &point);
	void             GetPixel(KSdComplexDouble &pixel, int x, int y);
	KSdComplexDouble GetPixel(KS_2D_POINT &point);
	KSdComplexDouble GetPixel(int x, int y);

	void PutRow(KSdComplexDouble* row, int y, int x, int len);
	void GetRow(KSdComplexDouble* row, int y, int x, int len);

	void SetSection(KSdComplexDouble* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdComplexDouble* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdComplexDouble value);

	void CopyToObject (KScComplexImage2dDouble *dst);
	void SetFromObject(KScComplexImage2dDouble *src);

	void CopyToMagnitude(KScScalarImage2dDouble *dst);
	void CopyToPhase    (KScScalarImage2dDouble *dst);
	void CopyToSpectrum (KScScalarImage2dDouble *dst, float c=1.0f);

	void SetFromPolarObject(KScScalarImage2dDouble *mag, KScScalarImage2dDouble *pha);

	KScComplexImage2dDouble& operator=(KScComplexImage2dDouble &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

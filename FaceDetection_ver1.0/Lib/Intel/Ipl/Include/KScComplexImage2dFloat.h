#ifndef __KSC_COMPLEXIMAGE2DFLOAT_H__
#define __KSC_COMPLEXIMAGE2DFLOAT_H__

#include "KScComplexImage2d.h"
#include "KScScalarImage2dFloat.h"

class KS_CLASS KScComplexImage2dFloat : public KScComplexImage2d
{

// attribute
public:
	KScData2dFloat* pRealData[COMPLEX_PLANE_NUM]; // original image pointer
	KScData2dFloat* pRealRoi [COMPLEX_PLANE_NUM]; // Roi image pointer
	KSdFloat*       pData    [COMPLEX_PLANE_NUM]; // access image pointer
	KSdFloat**      p2dArray [COMPLEX_PLANE_NUM]; // 2d Array
	KSdFloat**      pRoiData [COMPLEX_PLANE_NUM]; // roi image pointer

// methods
public:

	KScComplexImage2dFloat(void);
	KScComplexImage2dFloat(char *name);
	KScComplexImage2dFloat(int xSize, int ySize);
	KScComplexImage2dFloat(char *name,int xSize, int ySize);
	virtual	~KScComplexImage2dFloat(void);

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
	KSdFloat* GetBuffer         (int planeNum);
	KSdFloat* GetRealBuffer     (void);
	KSdFloat* GetImaginaryBuffer(void);

	KSdFloat* GetMainBuffer         (int planeNum);
	KSdFloat* GetMainRealBuffer     (void);
	KSdFloat* GetMainImaginaryBuffer(void);

	KSdFloat** Get2dArray         (int planeNum);
	KSdFloat** GetReal2dArray     (void);
	KSdFloat** GetImaginary2dArray(void);

	KSdFloat** GetMain2dArray         (int planeNum);
	KSdFloat** GetMainReal2dArray     (void);
	KSdFloat** GetMainImaginary2dArray(void);

	void     SetPixel(KSdFloat pixel, KS_2D_POINT &point, int planeNum);
	void     SetPixel(KSdFloat pixel, int x, int y, int planeNum);
	void     GetPixel(KSdFloat &pixel, KS_2D_POINT &point, int planeNum);
	void     GetPixel(KSdFloat &pixel, int x, int y, int planeNum);
	KSdFloat GetPixel(KS_2D_POINT &point, int planeNum);
	KSdFloat GetPixel(int x, int y, int planeNum);

	void PutRow(KSdFloat* row, int y, int x, int len, int planeNum);
	void GetRow(KSdFloat* row, int y, int x, int len, int planeNum);

	void SetSection(KSdFloat* section, int x, int y, int xSize, int ySize, int planeNum);
	void GetSection(KSdFloat* section, int x, int y, int xSize, int ySize, int planeNum);

	void InitTo(KSdFloat value, int planeNum);

	KSdFloat GetPixelMagnitude(KS_2D_POINT &point);
	KSdFloat GetPixelMagnitude(int x, int y);
	void     GetPixelMagnitude(KSdFloat &value, KS_2D_POINT &point);
	void     GetPixelMagnitude(KSdFloat &value, int x, int y);

	KSdFloat GetPixelPhase(KS_2D_POINT &point);
	KSdFloat GetPixelPhase(int x, int y);
	void     GetPixelPhase(KSdFloat &value, KS_2D_POINT &point);
	void     GetPixelPhase(KSdFloat &value, int x, int y);

	void SetPixelByPolar(KSdFloat mag, KSdFloat pha, int x, int y);

	void CopyToScalarImage (int planeNum, KScScalarImage2dFloat *dst);
	void SetFromScalarImage(int planeNum, KScScalarImage2dFloat *dst);

	void SplitPlane         (int planeNum, KScScalarImage2dFloat *dst);
	void SplitAllPlane      (KScScalarImage2dFloat *R, KScScalarImage2dFloat *I);
	void SplitRealPlane     (KScScalarImage2dFloat *dst);
	void SplitImaginaryPlane(KScScalarImage2dFloat *dst);

	void MergePlane         (int planeNum, KScScalarImage2dFloat *src);
	void MergeAllPlane      (KScScalarImage2dFloat *R, KScScalarImage2dFloat *I);
	void MergeRealPlane     (KScScalarImage2dFloat *dst);
	void MergeImaginaryPlane(KScScalarImage2dFloat *dst);

	// multi-plane operation -----------------------------------------------------------
	void            SetPixel(KSdComplexFloat pixel, KS_2D_POINT &point);
	void            SetPixel(KSdComplexFloat pixel, int x, int y);
	void            GetPixel(KSdComplexFloat &pixel, KS_2D_POINT &point);
	void            GetPixel(KSdComplexFloat &pixel, int x, int y);
	KSdComplexFloat GetPixel(KS_2D_POINT &point);
	KSdComplexFloat GetPixel(int x, int y);

	void PutRow(KSdComplexFloat* row, int y, int x, int len);
	void GetRow(KSdComplexFloat* row, int y, int x, int len);

	void SetSection(KSdComplexFloat* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdComplexFloat* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdComplexFloat value);

	void CopyToObject (KScComplexImage2dFloat *dst);
	void SetFromObject(KScComplexImage2dFloat *src);

	void SetFromPolarObject(KScScalarImage2dFloat *mag, KScScalarImage2dFloat *pha);

	void CopyToMagnitude(KScScalarImage2dFloat *dst);
	void CopyToPhase    (KScScalarImage2dFloat *dst);
	void CopyToSpectrum (KScScalarImage2dFloat *dst, float c=1.0f);

	KScComplexImage2dFloat& operator=(KScComplexImage2dFloat &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

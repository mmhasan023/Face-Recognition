#ifndef __KSC_YCbCr_IMAGE2D_H__
#define __KSC_YCbCr_IMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScScalarImage2dFloat.h"

class KScRgbImage2d;

class KS_CLASS KScYCbCrImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dFloat* pRealData[KS_HSI_PLANE_NUM]; // original image pointer
	KScData2dFloat* pRealRoi [KS_HSI_PLANE_NUM]; // roi image pointer for copy mode
	KSdFloat*       pData    [KS_HSI_PLANE_NUM]; // access image pointer
	KSdFloat**      p2dArray [KS_HSI_PLANE_NUM]; // 2d Array
	KSdFloat**      pRoiData [KS_HSI_PLANE_NUM]; // roi image pointer

// methods
public:

	KScYCbCrImage2d(void);
	KScYCbCrImage2d(char *name);
	KScYCbCrImage2d(int xSize, int ySize);
	KScYCbCrImage2d(char *name, int xSize, int ySize);
	virtual	~KScYCbCrImage2d(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);
	
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

	void RgbToYCbCr(KSdFloat r, KSdFloat g, KSdFloat b, KSdFloat *y, KSdFloat *Cb, KSdFloat *Cr);
	void YCbCrToRgb(KSdFloat y, KSdFloat Cb, KSdFloat Cr, KSdFloat *r, KSdFloat *g, KSdFloat *b);

	// single-plane operation -----------------------------------------------------------
	KSdFloat* GetBuffer  (int planeNum);
	KSdFloat* GetYBuffer (void);
	KSdFloat* GetCbBuffer(void);
	KSdFloat* GetCrBuffer(void);

	KSdFloat* GetMainBuffer  (int planeNum);
	KSdFloat* GetMainYBuffer (void);
	KSdFloat* GetMainCbBuffer(void);
	KSdFloat* GetMainCrBuffer(void);

	KSdFloat** Get2dArray  (int planeNum);
	KSdFloat** GetY2dArray (void);
	KSdFloat** GetCb2dArray(void);
	KSdFloat** GetCr2dArray(void);

	KSdFloat** GetMain2dArray  (int planeNum);
	KSdFloat** GetMainY2dArray (void);
	KSdFloat** GetMainCb2dArray(void);
	KSdFloat** GetMainCr2dArray(void);

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

	void CopyToScalarImage(int planeNum, KScScalarImage2dFloat *dst);
	void SetFromScalarImage(int planeNum, KScScalarImage2dFloat *dst);

	void SplitPlane   (int planeNum, KScScalarImage2dFloat *dst);
	void SplitAllPlane(KScScalarImage2dFloat *H, KScScalarImage2dFloat *S, KScScalarImage2dFloat *I);
	void SplitYPlane  (KScScalarImage2dFloat *dst);
	void SplitCbPlane (KScScalarImage2dFloat *dst);
	void SplitCrPlane (KScScalarImage2dFloat *dst);

	void MergePlane   (int planeNum, KScScalarImage2dFloat *src);
	void MergeAllPlane(KScScalarImage2dFloat *R, KScScalarImage2dFloat *G, KScScalarImage2dFloat *B);
	void MergeYPlane  (KScScalarImage2dFloat *dst);
	void MergeCbPlane (KScScalarImage2dFloat *dst);
	void MergeCrPlane (KScScalarImage2dFloat *dst);

	// multi-plane operation -----------------------------------------------------------
	void     SetPixel(KSdYCbCr pixel, KS_2D_POINT &point);
	void     SetPixel(KSdYCbCr pixel, int x, int y);
	void     GetPixel(KSdYCbCr &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdYCbCr &pixel, int x, int y);
	KSdYCbCr GetPixel(KS_2D_POINT &point);
	KSdYCbCr GetPixel(int x, int y);

	void PutRow(KSdYCbCr* row, int y, int x, int len);
	void GetRow(KSdYCbCr* row, int y, int x, int len);

	void SetSection(KSdYCbCr* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdYCbCr* section, int x, int y, int xSize, int ySize);

 	void InitTo(KSdYCbCr value);

	void CopyToObject (KScYCbCrImage2d *dst);
	void SetFromObject(KScYCbCrImage2d *src);
	
	void ConvertToRgbImage(KScRgbImage2d *dst);

	KScYCbCrImage2d& operator=(KScYCbCrImage2d &p);

	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

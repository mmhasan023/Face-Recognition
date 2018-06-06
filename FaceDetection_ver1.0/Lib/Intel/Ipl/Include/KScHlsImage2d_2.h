#ifndef __KSC_HLS_IMAGE2D_H__
#define __KSC_HLS_IMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScData2d.h"

class KScScalarImage2dFloat;
class KScRgbImage2d;

class KS_CLASS KScHlsImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dFloat* pRealData[KS_HLS_PLANE_NUM]; // original image pointer
	KScData2dFloat* pRealRoi [KS_HLS_PLANE_NUM]; // roi image pointer for copy mode
	KSdFloat*       pData    [KS_HLS_PLANE_NUM]; // access image pointer
	KSdFloat**      p2dArray [KS_HLS_PLANE_NUM]; // 2d Array
	KSdFloat**      pRoiData [KS_HLS_PLANE_NUM]; // roi image pointer

// methods
public:

	KScHlsImage2d(void);
	KScHlsImage2d(char *name);
	KScHlsImage2d(int xSize, int ySize);
	KScHlsImage2d(char *name, int xSize, int ySize);
	virtual	~KScHlsImage2d(void);

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


	void RgbToHls(KSdFloat r, KSdFloat g, KSdFloat b, KSdFloat *h, KSdFloat *l, KSdFloat *s);
	void HlsToRgb(KSdFloat h, KSdFloat l, KSdFloat s, KSdFloat *r, KSdFloat *g, KSdFloat *b);

	// single-plane operation -----------------------------------------------------------
	KSdFloat* GetBuffer          (int planeNum);
	KSdFloat* GetHueBuffer       (void);
	KSdFloat* GetLightnessBuffer (void);
	KSdFloat* GetSaturationBuffer(void);

	KSdFloat* GetMainBuffer          (int planeNum);
	KSdFloat* GetMainHueBuffer       (void);
	KSdFloat* GetMainLightnessBuffer (void);
	KSdFloat* GetMainSaturationBuffer(void);

	KSdFloat** Get2dArray          (int planeNum);
	KSdFloat** GetHue2dArray       (void);
	KSdFloat** GetLightness2dArray (void);
	KSdFloat** GetSaturation2dArray(void);

	KSdFloat** GetMain2dArray          (int planeNum);
	KSdFloat** GetMainHue2dArray       (void);
	KSdFloat** GetMainLightness2dArray (void);
	KSdFloat** GetMainSaturation2dArray(void);

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

	void SplitPlane          (int planeNum, KScScalarImage2dFloat *dst);
	void SplitAllPlane       (KScScalarImage2dFloat *H, KScScalarImage2dFloat *S, KScScalarImage2dFloat *I);
	void SplitHuePlane       (KScScalarImage2dFloat *dst);
	void SplitLightnessPlane (KScScalarImage2dFloat *dst);
	void SplitSaturationPlane(KScScalarImage2dFloat *dst);

	void MergePlane          (int planeNum, KScScalarImage2dFloat *src);
	void MergeAllPlane       (KScScalarImage2dFloat *R, KScScalarImage2dFloat *G, KScScalarImage2dFloat *B);
	void MergeHuePlane       (KScScalarImage2dFloat *dst);
	void MergeLightnessPlane (KScScalarImage2dFloat *dst);
	void MergeSaturationPlane(KScScalarImage2dFloat *dst);

	// multi-plane operation -----------------------------------------------------------
	void   SetPixel(KSdHls pixel, KS_2D_POINT &point);
	void   SetPixel(KSdHls pixel, int x, int y);
	void   GetPixel(KSdHls &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdHls &pixel, int x, int y);
	KSdHls GetPixel(KS_2D_POINT &point);
	KSdHls GetPixel(int x, int y);

	void PutRow(KSdHls* row, int y, int x, int len);
	void GetRow(KSdHls* row, int y, int x, int len);

	void SetSection(KSdHls* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdHls* section, int x, int y, int xSize, int ySize);
	
	void InitTo(KSdHls value);

	void CopyToObject(KScHlsImage2d *dst);
	void SetFromObject(KScHlsImage2d *src);

	void ConvertToRgbImage(KScRgbImage2d *dst);

	KScHlsImage2d& operator=(KScHlsImage2d &p);

	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

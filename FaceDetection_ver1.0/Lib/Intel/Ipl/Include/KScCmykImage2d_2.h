#ifndef __KSC_CMYK_IMAGE2D_H__
#define __KSC_CMYK_IMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScData2d.h"

class KScScalarImage2dUint8;
class KScRgbImage2d;

class KS_CLASS KScCmykImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dUint8* pRealData[KS_CMYK_PLANE_NUM]; // original image pointer
	KScData2dUint8* pRealRoi [KS_CMYK_PLANE_NUM]; // roi image pointer for copy mode
	KSdUint8*       pData    [KS_CMYK_PLANE_NUM]; // access image pointer
	KSdUint8**      p2dArray [KS_CMYK_PLANE_NUM]; // 2d Array
	KSdUint8**      pRoiData [KS_CMYK_PLANE_NUM]; // roi image pointer

// methods
public:

	KScCmykImage2d(void);
	KScCmykImage2d(char *name);
	KScCmykImage2d(int xSize, int ySize);
	KScCmykImage2d(char *name, int xSize, int ySize);
	virtual	~KScCmykImage2d(void);

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
	KSdUint8* GetBuffer       (int planeNum);
	KSdUint8* GetCyanBuffer   (void);
	KSdUint8* GetMagentaBuffer(void);
	KSdUint8* GetYellowBuffer (void);
	KSdUint8* GetBlackBuffer  (void);

	KSdUint8* GetMainBuffer       (int planeNum);
	KSdUint8* GetMainCyanBuffer   (void);
	KSdUint8* GetMainMagentaBuffer(void);
	KSdUint8* GetMainYellowBuffer (void);
	KSdUint8* GetMainBlackBuffer  (void);

	KSdUint8** Get2dArray       (int planeNum);
	KSdUint8** GetCyan2dArray   (void);
	KSdUint8** GetMagenta2dArray(void);
	KSdUint8** GetYellow2dArray (void);
	KSdUint8** GetBlack2dArray (void);

	KSdUint8** GetMain2dArray       (int planeNum);
	KSdUint8** GetMainCyan2dArray   (void);
	KSdUint8** GetMainMagenta2dArray(void);
	KSdUint8** GetMainYellow2dArray (void);
	KSdUint8** GetMainBlack2dArray (void);

	void     SetPixel(KSdUint8 pixel, KS_2D_POINT &point, int planeNum);
	void     SetPixel(KSdUint8 pixel, int x, int y, int planeNum);
	void     GetPixel(KSdUint8 &pixel, KS_2D_POINT &point, int planeNum);
	void     GetPixel(KSdUint8 &pixel, int x, int y, int planeNum);
	KSdUint8 GetPixel(KS_2D_POINT &point, int planeNum);
	KSdUint8 GetPixel(int x, int y, int planeNum);

	void PutRow(KSdUint8* row, int y, int x, int len, int planeNum);
	void GetRow(KSdUint8* row, int y, int x, int len, int planeNum);

	void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);
	void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);

	void InitTo(KSdUint8 value, int planeNum);

	void CopyToScalarImage (int planeNum, KScScalarImage2dUint8 *dst);
	void SetFromScalarImage(int planeNum, KScScalarImage2dUint8 *dst);

	void SplitPlane       (int planeNum, KScScalarImage2dUint8 *dst);
	void SplitAllPlane    (KScScalarImage2dUint8 *C, KScScalarImage2dUint8 *M, KScScalarImage2dUint8 *Y, KScScalarImage2dUint8 *K);
	void SplitCyanPlane   (KScScalarImage2dUint8 *dst);
	void SplitMagentaPlane(KScScalarImage2dUint8 *dst);
	void SplitYellowPlane (KScScalarImage2dUint8 *dst);
	void SplitBlackPlane  (KScScalarImage2dUint8 *dst);

	void MergePlane       (int planeNum, KScScalarImage2dUint8 *src);
	void MergeAllPlane    (KScScalarImage2dUint8 *C, KScScalarImage2dUint8 *M, KScScalarImage2dUint8 *Y, KScScalarImage2dUint8 *K);
	void MergeCyanPlane   (KScScalarImage2dUint8 *dst);
	void MergeMagentaPlane(KScScalarImage2dUint8 *dst);
	void MergeYellowPlane (KScScalarImage2dUint8 *dst);

	// multi-plane operation -----------------------------------------------------------
	void    SetPixel(KSdCmyk pixel, KS_2D_POINT &point);
	void    SetPixel(KSdCmyk pixel, int x, int y);
	void    GetPixel(KSdCmyk &pixel, KS_2D_POINT &point);
	void    GetPixel(KSdCmyk &pixel, int x, int y);
	KSdCmyk GetPixel(KS_2D_POINT &point);
	KSdCmyk GetPixel(int x, int y);

	void    SetRgbPixel(KSdRgb pixel, KS_2D_POINT &point);
	void    SetRgbPixel(KSdRgb pixel, int x, int y);
	void    GetRgbPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void    GetRgbPixel(KSdRgb &pixel, int x, int y);
	KSdRgb  GetRgbPixel(KS_2D_POINT &point);
	KSdRgb  GetRgbPixel(int x, int y);

	void PutRow(KSdCmyk* row, int y, int x, int len);
	void GetRow(KSdCmyk* row, int y, int x, int len);

	void SetSection(KSdCmyk* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdCmyk* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdCmyk value);
	void InitTo(KSdRgb value);

	void CopyToObject(KScCmykImage2d *dst);
	void SetFromObject(KScCmykImage2d *src);

	void ConvertToRgbImage(KScRgbImage2d *dst);

	KScCmykImage2d& operator=(KScCmykImage2d &p);

	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

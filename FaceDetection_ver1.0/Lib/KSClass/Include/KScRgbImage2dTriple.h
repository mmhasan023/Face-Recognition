#ifndef __KSC_RGBIMAGE2D_TRIPLE_H__
#define __KSC_RGBIMAGE2D_TRIPLE_H__

#include "KScColorImage2d.h"

class KScScalarImage2dUint8;
class KScHsiImage2d;

class KScRgbImage2dTriple : public KScColorImage2d
{

// attribute
public:
	KSdRgb *pRealData;	// original image pointer
	KSdRgb *pRealRoi;	// roi image pointer for copy mode
	KSdRgb *pData;	    // access image pointer
	KSdRgb **p2dArray;	// 2d Array
	KSdRgb **pRoiData;	// roi image pointer

public:
								   
// methods
public:

	KScRgbImage2dTriple(void);
	KScRgbImage2dTriple(char *name);
	KScRgbImage2dTriple(int xSize, int ySize);
	KScRgbImage2dTriple(char *name, int xSize, int ySize);
	~KScRgbImage2dTriple(void);

	int Alloc(int xSize, int ySize);
	void Free(void);
	
	void SetRoiRect(KS_RECT &rect);
	void SetRoiRect(int sx, int sy, int ex, int ey);
	KS_RECT GetRoiRect(void);
	void CalcRoiSize(void);
	void InitRoiRect(void);
	void ResetRoiRect(void);

	void SetDefaultRoiMode(void);
	void SetRemapRoiMode(void);
	void SetCopyRoiMode(void);
	void SetRoiMode(int mode);

	KS_2D_SIZE GetMainSize(void);
	int GetMainXSize(void);
	int GetMainYSize(void);
	KS_2D_SIZE GetSize(void);
	int GetXSize(void);
	int GetYSize(void);
//	int IsRoi(void);

	// single-plane operation -----------------------------------------------------------
	KSdRgb*    GetBuffer          (int planeNum);
	KSdUint8*  GetRedBuffer       (void);
	KSdUint8*  GetGreenBuffer     (void);
	KSdUint8*  GetBlueBuffer      (void);

	KSdRgb*    GetMainBuffer      (int planeNum);
	KSdUint8*  GetMainRedBuffer   (void);
	KSdUint8*  GetMainGreenBuffer (void);
	KSdUint8*  GetMainBlueBuffer  (void);

	KSdRgb**   Get2dArray         (int planeNum);
	KSdUint8** GetRed2dArray      (void);
	KSdUint8** GetGreen2dArray    (void);
	KSdUint8** GetBlue2dArray     (void);

	KSdRgb**   GetMain2dArray     (int planeNum);
	KSdUint8** GetMainRed2dArray  (void);
	KSdUint8** GetMainGreen2dArray(void);
	KSdUint8** GetMainBlue2dArray (void);

	KSdRgb     GetPixel(KS_2D_POINT &point, int planeNum);
	KSdRgb     GetPixel(int x, int y, int planeNum);
	void       GetPixel(KSdUint8 &pixel, KS_2D_POINT &point, int planeNum);
	void       GetPixel(KSdUint8 &pixel, int x, int y, int planeNum);
	void       SetPixel(KSdUint8 pixel, KS_2D_POINT &point, int planeNum);
	void       SetPixel(KSdUint8 pixel, int x, int y, int planeNum);
	void       GetRow(KSdUint8* row, int y, int x, int len, int planeNum);
	void       PutRow(KSdUint8* row, int y, int x, int len, int planeNum);
	void       GetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);
	void       SetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);
	
	void InitTo(KSdUint8 value=0, int planeNum=0);

	void CopyToScalarImage (int planeNum, KScScalarImage2dUint8 *dst);
	void SetFromScalarImage(int planeNum, KScScalarImage2dUint8 *dst);

	void SplitPlane     (int planeNum, KScScalarImage2dUint8 *dst);
	void SplitAllPlane  (KScScalarImage2dUint8 *R, KScScalarImage2dUint8 *G, KScScalarImage2dUint8 *B);
	void SplitRedPlane  (KScScalarImage2dUint8 *dst);
	void SplitGreenPlane(KScScalarImage2dUint8 *dst);
	void SplitBluePlane (KScScalarImage2dUint8 *dst);

	void MergePlane     (int planeNum, KScScalarImage2dUint8 *src);
	void MergeAllPlane  (KScScalarImage2dUint8 *R, KScScalarImage2dUint8 *G, KScScalarImage2dUint8 *B);
	void MergeRedPlane  (KScScalarImage2dUint8 *dst);
	void MergeGreenPlane(KScScalarImage2dUint8 *dst);
	void MergeBluePlane (KScScalarImage2dUint8 *dst);

	// multi-plane operation -----------------------------------------------------------
	KSdRgb GetPixel(KS_2D_POINT &point);
	KSdRgb GetPixel(int x, int y);
	void   GetPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdRgb &pixel, int x, int y);
	void   SetPixel(KSdRgb pixel, KS_2D_POINT &point);
	void   SetPixel(KSdRgb pixel, int x, int y);
	void   GetRow(KSdRgb* row, int y, int x, int len);
	void   PutRow(KSdRgb* row, int y, int x, int len);
	void   GetSection(KSdRgb* section, int x, int y, int xSize, int ySize);
	void   SetSection(KSdRgb* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdRgb value);

	void CopyToObject        (KScRgbImage2dTriple   *dst);
	void SetFromObject       (KScRgbImage2dTriple   *src);
	void ConvertToScalarImage(KScScalarImage2dUint8 *dst);
	void ConvertToHsiImage   (KScHsiImage2d         *dst);
	void RgbToHsi            (KSdFloat r,  KSdFloat g,  KSdFloat b, 
		                      KSdFloat *h, KSdFloat *s, KSdFloat *i );

	KScRgbImage2dTriple& operator=(KScRgbImage2dTriple &p);

	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);
	void WriteToContents (FILE* fp);
	void WriteToHeader   (FILE* fp);
	void ReadFromContents(FILE* fp);
	void ReadFromHeader  (FILE* fp);
};

#endif

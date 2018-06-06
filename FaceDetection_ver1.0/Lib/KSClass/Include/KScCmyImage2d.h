#ifndef __KSC_CMY_IMAGE2D_H__
#define __KSC_CMY_IMAGE2D_H__

#include "KScCmykImage2d.h"

class KScScalarImage2dUint8;
class KScRgbImage2d;

class KS_CLASS KScCmyImage2d : public KScCmykImage2d
{

// attribute
public:
								   
// methods
public:

	KScCmyImage2d(void);
	KScCmyImage2d(char *name);
	KScCmyImage2d(int xSize, int ySize);
	KScCmyImage2d(char *name, int xSize, int ySize);
	virtual	~KScCmyImage2d(void);

	// ROI
	virtual int  IsRoi        (void);

	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	virtual void ResetRoiRect (void);
	virtual int  MakeRoiBuffer(void);

	// multi-plane operation -----------------------------------------------------------
	void   SetPixel(KSdCmy pixel, KS_2D_POINT &point);
	void   SetPixel(KSdCmy pixel, int x, int y);
	void   GetPixel(KSdCmy &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdCmy &pixel, int x, int y);
	KSdCmy GetPixel(KS_2D_POINT &point);
	KSdCmy GetPixel(int x, int y);

	KSdUint8 GetPixel(int x, int y, int planeNum);
	
	void   SetRgbPixel(KSdRgb pixel, KS_2D_POINT &point);
	void   SetRgbPixel(KSdRgb pixel, int x, int y);
	void   GetRgbPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void   GetRgbPixel(KSdRgb &pixel, int x, int y);
	KSdRgb GetRgbPixel(KS_2D_POINT &point);
	KSdRgb GetRgbPixel(int x, int y);

	void PutRow(KSdCmy* row, int y, int x, int len);
	void GetRow(KSdCmy* row, int y, int x, int len);

	void SetSection(KSdCmy* section, int x, int y, int xSize, int ySize);
	void GetSection(KSdCmy* section, int x, int y, int xSize, int ySize);

	void InitTo(KSdCmy value);
	void InitTo(KSdRgb value);

//	void CopyToScalarImage(int planeNum, KScScalarImage2dUint8 *dst);
	//void SetFromScalarImage(int planeNum, KScScalarImage2dUint8 *dst);

	void SplitAllPlane(KScScalarImage2dUint8 *C,
		               KScScalarImage2dUint8 *M,
					   KScScalarImage2dUint8 *Y);
	void MergeAllPlane(KScScalarImage2dUint8 *C,
		               KScScalarImage2dUint8 *M,
					   KScScalarImage2dUint8 *Y);
	void CopyToObject(KScCmyImage2d *dst);
	void SetFromObject(KScCmyImage2d *src);

	void ConvertToRgbImage(KScRgbImage2d *dst);

	KScCmyImage2d& operator=(KScCmyImage2d &p);

	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

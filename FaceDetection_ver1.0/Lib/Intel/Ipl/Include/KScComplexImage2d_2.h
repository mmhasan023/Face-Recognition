#ifndef __KSC_COMPLEXIMAGE2D_H__
#define __KSC_COMPLEXIMAGE2D_H__

#include "KScComplexImage.h"
#include "KScData.h"

#include <stdio.h> // NULL

class KS_CLASS KScComplexImage2d : public KScComplexImage
{

// attribute
public:

public:
								   
// methods
public:

	KScComplexImage2d(void);
	KScComplexImage2d(char *szName);
	virtual	~KScComplexImage2d(void);

	virtual int  Alloc(int xSize, int ySize);
	virtual void Free(void);

	virtual KS_2D_SIZE GetMainSize(void);
	virtual int        GetMainXSize(void);
	virtual int        GetMainYSize(void);
	
	virtual KS_2D_SIZE GetSize(void);
	virtual int        GetXSize(void);
	virtual int        GetYSize(void);

	// for COMPLEX float ...
	virtual void SetPixel(KSdComplex pixel, KS_2D_POINT &point);
	virtual void SetPixel(KSdComplex pixel, int x, int y);
	virtual void GetPixel(KSdComplex &pixel, KS_2D_POINT &point);
	virtual void GetPixel(KSdComplex &pixel, int x, int y);

	virtual void GetPixelMagnitude(KSdFloat &value, KS_2D_POINT &point);
	virtual void GetPixelMagnitude(KSdFloat &value, int x, int y);
	virtual void GetPixelPhase    (KSdFloat &value, KS_2D_POINT &point);
	virtual void GetPixelPhase    (KSdFloat &value, int x, int y);
	
	virtual void PutRow(KSdComplex* row, int y, int x, int len);
	virtual void GetRow(KSdComplex* row, int y, int x, int len);

	virtual void SetSection(KSdComplex* section, int x, int y, int xSize, int ySize);
	virtual void GetSection(KSdComplex* section, int x, int y, int xSize, int ySize);

	virtual void InitTo(KSdComplex value);

	virtual void CopyToObject (KScComplexImage2d *dst);
	virtual void SetFromObject(KScComplexImage2d *src);

	KScComplexImage2d& operator=(KScComplexImage2d &p);

	virtual void LoadFromFile(char *fileName);
	virtual void SaveToFile  (char *fileName);

	virtual void ReadFromContents(FILE* fp);
	virtual void WriteToContents (FILE* fp);

	virtual void ReadFromHeader  (FILE* fp);
	virtual void WriteToHeader   (FILE* fp);
};

#endif

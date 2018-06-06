#ifndef __KSC_COLORIMAGE2D_H__
#define __KSC_COLORIMAGE2D_H__

#include "KScColorImage.h"

#include <stdio.h> // FILE

#define   KS_UNDEFINED			0
#define   KS_MINIMUM(a, b, c)	__min(__min(a, b), c)
#define   KS_MAXIMUM(a, b, c)   __max(__max(a, b), c)

class KS_CLASS KScColorImage2d : public KScColorImage
{

// attribute
public:

public:
								   
// methods
public:

	KScColorImage2d(void);
	KScColorImage2d(char *szName);

	virtual	~KScColorImage2d(void);

	virtual int  Alloc(int xSize, int ySize);
	virtual void Free(void);

	virtual KS_2D_SIZE GetMainSize(void);
	virtual int        GetMainXSize(void);
	virtual int        GetMainYSize(void);
	
	virtual KS_2D_SIZE GetSize(void);
	virtual int        GetXSize(void);
	virtual int        GetYSize(void);
	
	// for RGB ...
	virtual void SetPixel(KSdRgb pixel, KS_2D_POINT &point);
	virtual void SetPixel(KSdRgb pixel, int x, int y);
	virtual void GetPixel(KSdRgb &pixel, KS_2D_POINT &point);
	virtual void GetPixel(KSdRgb &pixel, int x, int y);
	virtual void GetRow(KSdRgb* row, int y, int x, int len);
	virtual void PutRow(KSdRgb* row, int y, int x, int len);
	virtual void SetSection(KSdRgb* section, int x, int y, int xSize, int ySize);
	virtual void GetSection(KSdRgb* section, int x, int y, int xSize, int ySize);

	virtual void InitTo(KSdRgb value);

	virtual void CopyToObject(KScColorImage2d *dst);
	virtual void SetFromObject(KScColorImage2d *src);

	KScColorImage2d& operator=(KScColorImage2d &p);

	virtual void LoadFromFile(char *fileName);
	virtual void SaveToFile  (char *fileName);

	virtual void WriteToContents(FILE* fp);
	virtual void WriteToHeader  (FILE* fp);

	virtual void ReadFromContents(FILE* fp);
	virtual void ReadFromHeader  (FILE* fp);
};

#endif

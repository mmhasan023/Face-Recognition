#ifndef __KSC_SCALARIMAGE2D_H__
#define __KSC_SCALARIMAGE2D_H__

#include "KScScalarImage.h"
#include "KScData2d.h"

class KS_CLASS KScScalarImage2d : public KScScalarImage
{

// attribute
public:

public:
								   
// methods
public:

	KScScalarImage2d(void);
	KScScalarImage2d(char *szName);

	virtual	~KScScalarImage2d(void);

	virtual int  Alloc(int xSize, int ySize);
	virtual void Free(void);

	virtual KS_2D_SIZE GetMainSize(void);
	virtual int        GetMainXSize(void);
	virtual int        GetMainYSize(void);
	
	virtual KS_2D_SIZE GetSize(void);
	virtual int        GetXSize(void);
	virtual int        GetYSize(void);
	
	// for Uint8 ...
	virtual void SetPixel(KSdUint8 pixel, KS_2D_POINT &point) { }
	virtual void SetPixel(KSdUint8 pixel, int x, int y) { }
	virtual void GetPixel(KSdUint8 &pixel, KS_2D_POINT &point) { }
	virtual void GetPixel(KSdUint8 &pixel, int x, int y) { }

	virtual void PutRow(KSdUint8* row, int y, int x, int len) { }
	virtual void GetRow(KSdUint8* row, int y, int x, int len) { }

	virtual void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize) { }
	virtual void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize) { }

	virtual void InitTo(KSdUint8 value=0) { }

	// for Int16 ...
	virtual void SetPixel(KSdInt16 pixel, KS_2D_POINT &point) { }
	virtual void SetPixel(KSdInt16 pixel, int x, int y) { }
	virtual void GetPixel(KSdInt16 &pixel, KS_2D_POINT &point) { }
	virtual void GetPixel(KSdInt16 &pixel, int x, int y) { }

	virtual void PutRow(KSdInt16* row, int y, int x, int len) { }
	virtual void GetRow(KSdInt16* row, int y, int x, int len) { }

	virtual void SetSection(KSdInt16* section, int x, int y, int xSize, int ySize) { }
	virtual void GetSection(KSdInt16* section, int x, int y, int xSize, int ySize) { }

	virtual void InitTo(KSdInt16 value=0) { }

	// for Int32 ...
	virtual void SetPixel(KSdInt32 pixel, KS_2D_POINT &point) { }
	virtual void SetPixel(KSdInt32 pixel, int x, int y) { }
	virtual void GetPixel(KSdInt32 &pixel, KS_2D_POINT &point) { }
	virtual void GetPixel(KSdInt32 &pixel, int x, int y) { }

	virtual void PutRow(KSdInt32* row, int y, int x, int len) { }
	virtual void GetRow(KSdInt32* row, int y, int x, int len) { }

	virtual void SetSection(KSdInt32* section, int x, int y, int xSize, int ySize) { }
	virtual void GetSection(KSdInt32* section, int x, int y, int xSize, int ySize) { }

	virtual void InitTo(KSdInt32 value=0) { }

	// for Float ...
	virtual void SetPixel(KSdFloat pixel, KS_2D_POINT &point) { }
	virtual void SetPixel(KSdFloat pixel, int x, int y) { }
	virtual void GetPixel(KSdFloat &pixel, KS_2D_POINT &point) { }
	virtual void GetPixel(KSdFloat &pixel, int x, int y) { }

	virtual void PutRow(KSdFloat* row, int y, int x, int len) { }
	virtual void GetRow(KSdFloat* row, int y, int x, int len) { }

	virtual void SetSection(KSdFloat* section, int x, int y, int xSize, int ySize) { }
	virtual void GetSection(KSdFloat* section, int x, int y, int xSize, int ySize) { }

	virtual void InitTo(KSdFloat value=0) { }

	// for Double ...
	virtual void SetPixel(KSdDouble pixel, KS_2D_POINT &point) { }
	virtual void SetPixel(KSdDouble pixel, int x, int y) { }
	virtual void GetPixel(KSdDouble &pixel, KS_2D_POINT &point) { }
	virtual void GetPixel(KSdDouble &pixel, int x, int y) { }

	virtual void PutRow(KSdDouble* row, int y, int x, int len) { }
	virtual void GetRow(KSdDouble* row, int y, int x, int len) { }

	virtual void SetSection(KSdDouble* section, int x, int y, int xSize, int ySize) { }
	virtual void GetSection(KSdDouble* section, int x, int y, int xSize, int ySize) { }

	virtual void InitTo(KSdDouble value=0) { }

	KScScalarImage2d& operator=(KScScalarImage2d &p);

	virtual void LoadFromFile    (char *fileName);
	virtual void SaveToFile      (char *fileName);

	virtual void ReadFromContents(FILE* fp);
	virtual void WriteToContents (FILE* fp);

	virtual void ReadFromHeader  (FILE* fp);
	virtual void WriteToHeader   (FILE* fp);
};

#endif

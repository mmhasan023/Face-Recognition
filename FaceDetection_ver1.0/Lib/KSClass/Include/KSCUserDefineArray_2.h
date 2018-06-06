#ifndef __KSC_USER_DEFINE_ARRAY_H__
#define __KSC_USER_DEFINE_ARRAY_H__

#include "KScObject.h"
#include "KScObjectId.h"
#include "KScData1d.h"

class KS_CLASS KScUserDefineArray : public KScObject
{

// attribute
public:
	KScData1dUint8 *pData;	// array pointer

// methods
public:

	KScUserDefineArray(void);
	KScUserDefineArray(char *name);
	KScUserDefineArray(char *name, int dx);
	virtual	~KScUserDefineArray(void);

	virtual int  Alloc(int size);
	virtual void Free();

	virtual int  GetSize();

	KSdUint8* GetBuffer(void);

	KScUserDefineArray& operator=(KScUserDefineArray &p);

	virtual void LoadFromFile    (char *fileName);
	virtual void SaveToFile      (char *fileName);

	virtual void WriteToContents (FILE* fp);
	virtual void WriteToHeader   (FILE* fp);

	virtual void ReadFromContents(FILE* fp);
	virtual void ReadFromHeader  (FILE* fp);
};

#endif

#ifndef __KSC_STRING_H__
#define __KSC_STRING_H__

#include "KScUserDefineArray.h"

class KS_CLASS KScString : public KScUserDefineArray
{

// attribute
public:

// methods
public:

	KScString(void);
	KScString(char *name);
	KScString(char *name, int dx);	// 19991223 ªÛ«Â
	virtual	~KScString(void);

	KScString& operator=(KScString &p);
};

#endif

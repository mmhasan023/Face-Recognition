#ifndef __KSC_HISTOGRAM_H__
#define __KSC_HISTOGRAM_H__

#include "KScSimpleImage.h"

class KS_CLASS KScHistogram : public KScSimpleImage 
{

// attribute
public:
	unsigned long int hstCount;

// methods
public:

	KScHistogram(void);
	KScHistogram(char *szName);
	virtual	~KScHistogram(void);

	unsigned long int GetTotalCount();
	void              ResetTotalCount();
	void              IncreaseTotalCount();

private:
	KScHistogram& operator=(const KScHistogram&  rhs);
};

#endif

#ifndef __KSC_SIGNAL_H__
#define __KSC_SIGNAL_H__

#ifndef __SIGNAL_SOURCE__
#define __SIGNAL_SOURCE__
	#define SIGNAL_SOURCE_OTHER  0
	#define SIGNAL_SOURCE_WAVE   1
	#define SIGNAL_SOURCE_DSP    2
#endif // __SIGNAL_SOURCE__

#ifndef __SIGNAL_MODE__
#define __SIGNAL_MODE__
	#define SIGNAL_MODE_TIME     0 // time domain
	#define SIGNAL_MODE_FREQ     1 // frequency domain
	#define SIGNAL_MODE_MAG      2 // magintude
	#define SIGNAL_MODE_PHASE    3 // phase
#endif // __SIGNAL_MODE__

#include "KScGenericImage.h"
#include "KScWave.h"

class KS_CLASS KScSignal : public KScGenericImage 
{
// attributes
public:
	// buffers
	void *realBuff;
	void *realBuff2;
	void *imagBuff;
	void *imagBuff2;

	double time;

	// size for the Data
	long sampleSize;       // # of signal elements = buffer size / size of type

	// flag for the Check
	int/*BOOL*/ allocFlag; // which memory allocation successed, nor

	// mode flag
	int sgnlFlag;          // signal generation type - refer to the __SIGNAL_SOURCE__
	int TypeFlag;          // current signal type    - refer to the __SIGNAL_MODE__

	// information to play or save for wave file
	KScWave wave;

// methods
public:

	KScSignal();
	KScSignal(char *szName);

	virtual	~KScSignal();

	virtual int  Alloc(long);
	virtual int  Alloc(long, long);
	virtual int  Alloc(long, int, int, int);
	virtual void Free (void);

	double GetTime(void);

	long  GetSampleSize(void);
	void  SetSampleSize(long);

	long  GetRealSize(void);

	WORD  GetFormatTag        (void);
	void  SetFormatTag        (WORD);
    WORD  GetChannel          (void);
    void  SetChannel          (WORD);
    DWORD GetSamplingRate     (void);
    void  SetSamplingRate     (DWORD);
    WORD  GetQuantizationLevel(void);
    void  SetQuantizationLevel(WORD);

    DWORD GetAvgBytesPerSec   (void);
    WORD  GetBlockAlign       (void);

    /* Signal copy operator : use the pointer
		KScSignal *pSrc, *pDst;
		...
		...
		pDst = pSrc; // *pDst = *pSrc; X
		...
		...
	*/
	virtual KScSignal* operator=(const KScSignal* src);
	virtual KScSignal& operator=(const KScSignal& src);
};

#endif

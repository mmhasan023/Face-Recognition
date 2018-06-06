// 1차원 클래스 Header File
#ifndef __KSC_SIGNALFLOAT_H__
#define __KSC_SIGNALFLOAT_H__

#include "KScSignal.h"

class KS_CLASS KScSignalFloat : public KScSignal
{
public:

	KScSignalFloat(void);
	KScSignalFloat(char *name);
	KScSignalFloat(long size);
	KScSignalFloat(char *name, long size);
	KScSignalFloat(char *name, long size, int channel, unsigned int samplingrate, unsigned int bitspersample);
	virtual	~KScSignalFloat(void);

	virtual int  Alloc(long realSize );
	virtual int  Alloc(long realSize, int nChannel, int nSamplingRate, int nBitsPerSample );
	virtual void Free (void );

	float* GetRealBuff (void);
	float* GetRealBuff2(void);
	float* GetImagBuff (void);
	float* GetImagBuff2(void);

	void RealToByte ( unsigned char *byteBuff, long byteSize );
	void ByteToReal ( unsigned char *byteBuff, long byteSize );

	// refer to KScSignal* KScSignal::operator=(KScSignal*);
	virtual KScSignalFloat* operator=(const KScSignalFloat* src);
	virtual KScSignalFloat& operator=(const KScSignalFloat& src);
};

#endif
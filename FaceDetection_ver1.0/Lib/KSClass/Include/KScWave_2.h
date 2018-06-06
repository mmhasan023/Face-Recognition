#ifndef __KSC_WAVE_H__
#define __KSC_WAVE_H__

#include "KScObject.h"

#ifndef _WAVEFORMATEX_ // mmsystem.h
#define _WAVEFORMATEX_

typedef unsigned short      WORD;
typedef unsigned long       DWORD;
#define WAVE_FORMAT_PCM     1

/* 
 *  extended waveform format structure used for all non-PCM formats. this
 *  structure is common to all non-PCM formats.
 */
typedef struct tWAVEFORMATEX
{
    WORD        wFormatTag;         /* format type */
    WORD        nChannels;          /* number of channels (i.e. mono, stereo...) */
    DWORD       nSamplesPerSec;     /* sample rate */
    DWORD       nAvgBytesPerSec;    /* for buffer estimation */
    WORD        nBlockAlign;        /* block size of data */
    WORD        wBitsPerSample;     /* number of bits per sample of mono data */
    WORD        cbSize;             /* the count in bytes of the size of */
				    /* extra information (after cbSize) */
} WAVEFORMATEX;//, *PWAVEFORMATEX, NEAR *NPWAVEFORMATEX, FAR *LPWAVEFORMATEX;
//typedef const WAVEFORMATEX FAR *LPCWAVEFORMATEX;

#endif /* _WAVEFORMATEX_ */ 

class KS_CLASS KScWave : public KScObject
{
// attributes
	WAVEFORMATEX wave;

// methods
public:
	KScWave();
	KScWave(char *szName);
	virtual	~KScWave();

	void Init(void);

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
    WORD  GetCbSize           (void);
    void  SetCbSize           (WORD);

	KScWave* operator=(const KScWave*);
	KScWave& operator=(const KScWave&);
};

#endif // __KSC_WAVE_H__

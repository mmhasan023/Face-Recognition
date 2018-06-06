#ifndef __KSC_SEQUENCE_BASE_H__
#define __KSC_SEQUENCE_BASE_H__

#include "KScObject.h"

#include <stdio.h>

#define INDEX_SAMPLE 0
#define INDEX_TIME   1

#ifndef DWORD

	typedef unsigned long  DWORD;
	typedef unsigned char  BYTE;

#endif

#ifndef MAKEFOURCC // in mmsystem.h

	/* MMIO macros */
	#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
		((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
		((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))

	#define mmioFOURCC(ch0, ch1, ch2, ch3)  MAKEFOURCC(ch0, ch1, ch2, ch3)

#endif

// Codec type 순서와 Stream type 순서를 같이 하며
// Codec type이 늘어날수록 Stream type도 함께 늘린다.

// Codec type
#ifndef _INC_AVIFMT // in avifmt.h

	/*
	** Stream types for the <fccType> field of the stream header.
	*/
	#define streamtypeVIDEO         mmioFOURCC('v', 'i', 'd', 's')
	#define streamtypeAUDIO         mmioFOURCC('a', 'u', 'd', 's')
	#define streamtypeMIDI			mmioFOURCC('m', 'i', 'd', 's')
	#define streamtypeTEXT          mmioFOURCC('t', 'x', 't', 's')

#endif

// Other Stream type
#ifndef STREAM_TYPE
#define STREAM_TYPE
/*
	#define STREAM_VIDEO 0
	#define SEQUENCE_AUDIO 1
	#define SEQUENCE_MIDI  2
	#define SEQUENCE_TEXT  3
*/
#endif

// Scalabilty Coding Constants
#ifdef SCALABILITY

	#define SPATIAL 0
	#define TIME    1 
	#define SNR     2

#endif

class KS_CLASS KScSequenceBase : public KScObject 
{

// attribute
public:

	unsigned long  type;         // sequence type

	int     scalableCodingType;  // spatial, time, SNR
	double  scalableCodingValue; // real value is ????

	double  scale;               // zoom value

// methods
public:

	KScSequenceBase(void);
	KScSequenceBase(char *name);

	virtual	~KScSequenceBase(void);

	KScSequenceBase& operator=(KScSequenceBase& source);

	// Get/Set sequence type
	unsigned int GetType(void);
	void         SetType(unsigned int type);

	// Get/Set scalable coding type and value
	int  GetScalableCodingType(void);
	void SetScalableCodingType(int type);

	double GetScalableCodingValue(void);
	void   SetScalableCodingValue(double value);

	// Get/Set scale
	double GetScale(void);
	void   SetScale(double value);

	// Get/Put Block
	virtual void *GetBlock(unsigned long start, unsigned long end);
	virtual int /*BOOL*/ PutBlock (unsigned long start, unsigned long end, void *pBuffer);
/*
	// Convert
	
	// Time

	// 

	// File
	int /*BOOL* / Open(FILE *fp);
	void Close(void);
	int /*BOOL* / Save(FILE *fp);
	int /*BOOL* / Save(FILE *fp, unsigned long lStartTime, unsigned lEndTime);

	// Device
	int /*BOOL* / OpenDevice(...);
	void CloseDevice(void);

	// Play
	int /*BOOL* / Play (void);
	int /*BOOL* / Stop (void);
	int /*BOOL* / Pause(void);

	// Seek
	int /*BOOL* / Seek(unsigned long lTime); // lTime is Seek method constants or time.
*/
};

#endif

#ifndef __KSC_SEQUENCE_BLOCK_H__
#define __KSC_SEQUENCE_BLOCK_H__

#include "KScObject.h"

class KS_CLASS KScSequenceBlock : public KScObject
{

// attribute
public:

	unsigned long start, current;       // start, current index in current stream
	unsigned long length;               // stream length
	void          *stream;              // real stream or frame buffer

// methods
public:

	KScSequenceBlock(void);
	KScSequenceBlock(char *name);

	virtual	~KScSequenceBlock(void);

	KScSequenceBlock& operator=(KScSequenceBlock& source);

	// Get/Set start/current/end
	unsigned long GetStart(void);
	void		  SetStart(unsigned long index);

	unsigned long GetCurrent(void);
	void		  SetCurrent(unsigned long index);

	unsigned long GetLength(void);
	void		  SetLength(unsigned long index);

	// Get/Set the point of Stream
	void *GetStream(void);
	void  SetStream(void *pStream);
/*
	// File
	virtual /*BOOL* / Open(FILE *fp);
	virtual void Close(void);
	virtual /*BOOL* / Save(FILE *fp);
	virtual /*BOOL* / Save(FILE *fp, unsigned long strat, unsigned long end);
*/
};

#endif

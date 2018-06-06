#ifndef __KS_OBJECT_H__
#define __KS_OBJECT_H__

// exports and imports the KS Class
#ifdef KS_CLASS_EXPORTS
    #define KS_CLASS __declspec(dllexport)
#else
    #define KS_CLASS __declspec(dllimport)
#endif

// Constants
#include "KSConstant.h"

// Error Codes
#include "KScStatusCode.h"

// Class IDs
#include "KScObjectId.h"

#define CLASS_NAME_LENGTH	 256
#define CLASS_COMMENT_LENGTH 1024

class KS_CLASS KScObject 
{
// attribute
protected:

	int  id;           // class id of a current object
	char *className;   // class name of a current object
	int  statusCode;   // error_code is dependent class_id;
	char *m_szComment; // history and comment
	void *connect;     // for connection object manage operation...

// methods
protected:

	void SetId    (int newId);
	void SetStatus(int code);

public:
	
	KScObject (void);
	KScObject (char *name);
	virtual	~KScObject(void);

	void Attach(void);
	
	void ResetClass(void);
	
	int  GetId(void);

	char *GetName (void);
	void SetName  (char *name);
	void ClearName(void);

	int  GetStatus  (void);
	void ResetStatus(void);

	char *GetStatusMessage(void);

	char *GetComment  (void);
	void ResetComment (void);
	void AppendComment(char *notice);

	
	virtual int  Alloc(int size){return 0;};
	virtual int  Alloc(int xSize,int ySize){return 0;};
	virtual void Free(){};

};

#endif

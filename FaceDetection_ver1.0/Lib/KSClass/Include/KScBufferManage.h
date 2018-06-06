#ifndef __KSC_BUFFER_MANAGE_H__
#define __KSC_BUFFER_MANAGE_H__

#include "KScObject.h"
#include "KScBase.h"

#pragma warning (disable : 4251) // ���� �߰� 0827 ��� �޼��� �ȳ�������...

#define KS_MAX_PARAMETER_NUM	100

typedef struct tagKS_ClassInfo
{
	int classId;						// class �ĺ��� ���� �ĺ��� ����.
	KScArray<void*, void*> *bucket;		// ���۸� �����ϱ� ���� �迭 ����.
										// ����� ������ ���� Array�� count�� �ȴ�.
										// �Լ� ����� ������ �� casting�� �Ͽ��� �Ѵ�.
} KS_CLASS_INFO;

class KS_CLASS KScBufferManage : public KScObject
{
private:
	
	unsigned int bufCount; // �Ҵ�� ��ü ������ ��.
	int          newCount; // ���� �Ҵ�� ��� ����.

	void ResetTotalCount(void);

public:
	
	KScArray<KS_CLASS_INFO*, KS_CLASS_INFO*> data;

	KScBufferManage(void);
	KScBufferManage(char *szName);

	virtual	~KScBufferManage(void);

	unsigned int GetTotalCount     (void);
	void         IncreaseTotalCount(void);
	void         DecreaseTotalCount(void);

	int          GetNewCount     (void);
	void         IncreaseNewCount(void);

	KScObject* AllocBuffer(int bufferId, char *name);
	// 1D Mode
	KScObject* AllocBuffer(int bufferId, char *name, int dx);
	// 1D Signal
	KScObject* AllocBuffer(int bufferId, char *name, long m_lSignalSize, int  m_nChannel, unsigned int m_nSamplingRate, unsigned int m_nBitsPerSample );
	// 2D Mode
	KScObject* AllocBuffer(int bufferId, char *name, int dx, int dy);
	KScObject* AllocBuffer(int bufferId, char *name, int dx, int dy, int ax, int ay);
	KScObject* AllocBuffer(int bufferId, char *name, int dx, int dy, int ax, int ay, int sr);
	// returns the buffer has the same size
	
	//void* AllocBuffer(void* object, char *name);	//SH
	KScObject* AllocBuffer(KScObject* object, char *name);



	// 3D Mode - not complete
	//void *AllocBuffer(int bufferId, char *name, int dx, int dy, int dz);

	void  FreeBuffer(void);
	void  FreeBuffer(KS_CLASS_INFO *info);

	KScObject* AddBuffer(KScObject *buf);
	int   AddBufferPointer(KS_CLASS_INFO *info, KScObject *p);

	int   GetBufferIndex     (int bufferId, char *name);
	int   GetBufferIndex     (KScObject* pObject);
	KScObject* GetBufferPointer   (int bufferId, char *name);
	KScObject* GetBufferPointer   (int bufferId, int index);

	int   DelBuffer          (KScObject *buf);
	int   DelBufferPointer   (int bufferId, KScObject *KScObject);
	int   DelBufferPointer   (int bufferId, char *name);
	int   DelBufferPointer   (KS_CLASS_INFO *info, KScObject *KScObject);
	int   DelBufferPointer   (KS_CLASS_INFO *info, char *name);

	KS_CLASS_INFO* AllocClassInfo    (int bufferId);
	KS_CLASS_INFO* GetClassInfo      (int bufferId);
	void           AddClassInfo      (KS_CLASS_INFO *info);
	int            GetClassNumber    (int bufferId);
	char*          GetBufferClassName(int bufferId, int index);
};

extern KS_CLASS KScBufferManage theBufferManager, *pTheBufferManager;

#endif 

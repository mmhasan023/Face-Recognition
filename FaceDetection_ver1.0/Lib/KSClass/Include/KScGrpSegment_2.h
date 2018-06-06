#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "KScGrpPrimitive.h"

/////////////////////////////////////////////////////////
// Segment Class
class KS_CLASS KScSegment 
{

public:
	// ������
	KScSegment();

// ������
public :
	int fSeg;            // -2�� ���� �־� Ȥ�� �ٸ� ������ ���׸�Ʈ ���� 

	KScList m_PrimitiveList;
	KScList m_DataPrimitiveList;

	int m_nCount;        // ����� ������Ƽ���� ��
	int Priority;        // �켱������ ���� ���� 
    RECT m_MinRect;      // ���׸�Ʈ�� �����ϴ� ������Ƽ�� ������ �ּ� �簢��
	BOOL m_fHide;        // �� ���׸�Ʈ�� ���� ���ΰ��� ����  
	BOOL m_fModified;    // ���׸�Ʈ�� ������ ��ȭ�Ǿ��°�?
	BOOL m_DllToGrphic;      // DLL������ ����Ÿ Ŭ������ �̿��Ͽ� ������Ƽ�� ����Ʈ�� �����ϰ�
	                         // DLL�ܿ����� �� �÷��׸� ���� �ٽ� Dsp* �� ���·� ��ȯ�Ͽ� ����Ѵ�.
	BOOL m_GrphicToDll;  // DLL�� �ƴ� ���¸� Dll���� ����ϱ� ���� ��ȯ ���θ� ����

public :
	BOOL AddPrimitive(KScPrimitiveBase* prm);
	
	void ConvertDll2Graphic(); // DLL������ ������Ƽ����� Dsp���·� �ٲ�  
	void ConvertGraphic2Dll(); // ������Ƽ����� DLL ���·� �ٲ�

	// �����ִ� ������Ƽ���� ���� ����
	int GetCount() { return m_nCount; }
	// ���׸�Ʈ�� ��� �ִ����� ���� 
	BOOL IsEmptySegment() { return m_PrimitiveList.IsEmpty(); }
	// �켱������ �����Ѵ�.
	void SetPriority(int pro) { Priority = pro; }
	void BackWardPosition(H_POSITION currPos);
	void FrontWardPosition(H_POSITION currPos);
	void SetHide() { m_fHide = TRUE; }
	void ReleaseHide() { m_fHide = FALSE; }
	BOOL IsHide() { return m_fHide; }
	BOOL GetModifiedSegment() { return m_fModified; } // � ��ȭ�� �־������� ����
	void SetMinRect(KScPrimitiveBase * prm);
	RECT GetMinRect() { return m_MinRect; }

	void LoadFromFile(FILE* fp);
	void WriteToFile(FILE* fp);

	// �Ҹ��� 
public:
	virtual	~KScSegment();
};


#endif // #define __SEGMENT_H__
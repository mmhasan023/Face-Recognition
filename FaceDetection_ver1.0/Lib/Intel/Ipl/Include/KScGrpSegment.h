#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "KScGrpPrimitive.h"

/////////////////////////////////////////////////////////
// Segment Class
class KS_CLASS KScSegment 
{

public:
	// 생성자
	KScSegment();

// 변수들
public :
	int fSeg;            // -2의 값을 넣어 혹은 다른 값으로 세그먼트 구분 

	KScList m_PrimitiveList;
	KScList m_DataPrimitiveList;

	int m_nCount;        // 연결된 프리미티브의 수
	int Priority;        // 우선순위를 위한 변수 
    RECT m_MinRect;      // 세그먼트내 존재하는 프리미티브 결합의 최소 사각형
	BOOL m_fHide;        // 이 세그먼트를 숨길 것인가의 여부  
	BOOL m_fModified;    // 세그먼트의 내용이 변화되었는가?
	BOOL m_DllToGrphic;      // DLL에서는 데이타 클래스를 이용하여 프리미티브 리스트를 구성하고
	                         // DLL외에서는 이 플래그를 보고 다시 Dsp* 의 형태로 변환하여 사용한다.
	BOOL m_GrphicToDll;  // DLL이 아닌 형태를 Dll에서 사용하기 위해 변환 여부를 지정

public :
	BOOL AddPrimitive(KScPrimitiveBase* prm);
	
	void ConvertDll2Graphic(); // DLL형태의 프리미티브들을 Dsp형태로 바꿈  
	void ConvertGraphic2Dll(); // 프리미티브들을 DLL 형태로 바꿈

	// 속해있는 프리미티브의 수를 얻어옴
	int GetCount() { return m_nCount; }
	// 세그먼트가 비어 있는지의 여부 
	BOOL IsEmptySegment() { return m_PrimitiveList.IsEmpty(); }
	// 우선순위를 설정한다.
	void SetPriority(int pro) { Priority = pro; }
	void BackWardPosition(H_POSITION currPos);
	void FrontWardPosition(H_POSITION currPos);
	void SetHide() { m_fHide = TRUE; }
	void ReleaseHide() { m_fHide = FALSE; }
	BOOL IsHide() { return m_fHide; }
	BOOL GetModifiedSegment() { return m_fModified; } // 어떤 변화가 있었는지의 여부
	void SetMinRect(KScPrimitiveBase * prm);
	RECT GetMinRect() { return m_MinRect; }

	void LoadFromFile(FILE* fp);
	void WriteToFile(FILE* fp);

	// 소멸자 
public:
	virtual	~KScSegment();
};


#endif // #define __SEGMENT_H__
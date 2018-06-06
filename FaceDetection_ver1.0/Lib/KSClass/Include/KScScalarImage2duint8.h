#ifndef __KSC_SCALARIMAGE2DUINT8_H__
#define __KSC_SCALARIMAGE2DUINT8_H__

#include "KScScalarImage2d.h"
#include "KScBitmapRoi2d.h"

class KScRgbImage2d;

class KS_CLASS KScScalarImage2dUint8 : public KScScalarImage2d
{

// attribute
public:
	KScData2dUint8* pRealData; // original image pointer
	KScData2dUint8* pRealRoi;  // roi image pointer for copy mode
	KSdUint8*       pData;     // access image pointer
	KSdUint8**      p2dArray;  // 2d Array
	KSdUint8**      pRoiData;  // roi image pointer
	
// methods
public:

	////////////////////////////////////////////////////////////////////////////
	// 클래스 생성자
	////////////////////////////////////////////////////////////////////////////

	KScScalarImage2dUint8(void);

	// 이름
	KScScalarImage2dUint8(char *name);
	
	// 가로 크기, 세로 크기
	KScScalarImage2dUint8(int xSize, int ySize);

	// 이름, 가로 크기, 세로 크기
	KScScalarImage2dUint8(char *name, int xSize, int ySize);


	////////////////////////////////////////////////////////////////////////////
	// 클래스 파괴자
	////////////////////////////////////////////////////////////////////////////

	virtual	~KScScalarImage2dUint8(void);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 할당 및 해제
	////////////////////////////////////////////////////////////////////////////
	// 버퍼 할당
	// 인자 : 가로 크기, 세로 크기
	// 반환 : 성공 - NO_ERROR or KS_OK
	//        실패 - NO_ERROR or KS_OK 외의 값, KScStatusCode.h 참조
	int  Alloc(int xSize, int ySize);
	
	// 버퍼 해제
	// 인자 : 없음
	// 반환 : 없음
	void Free(void);


	////////////////////////////////////////////////////////////////////////////
	// ROI(Region Of Interest) 관련 함수
	////////////////////////////////////////////////////////////////////////////
	
	// ROI 설정 확인
	// 인자 : 없음
	// 반환 : TRUE  - ROI가 설정됨
	//        FALSE - ROI가 설정이 안됨
	virtual int  IsRoi        (void);

	// ROI 설정
	// 인자 : ROI 영역
	// 반환 : 성공 - NO_ERROR or KS_OK
	//        실패 - NO_ERROR or KS_OK 외의 값, KScStatusCode.h 참조
	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	// ROI 설정 해제
	// 인자 : 없음
	// 반환 : 없음
	virtual void ResetRoiRect (void);

	// ROI 설정 영역에 해당하는 버퍼 할당
	// 인자 : 없음
	// 반환 : 성공 - NO_ERROR or KS_OK
	//        실패 - NO_ERROR or KS_OK 외의 값, KScStatusCode.h 참조
	virtual int  MakeRoiBuffer(void);

	// ROI Mode 설정
	// 인자 : ROI Mode - KS_COPY_MODE, KS_REMAP_MODE, KS_BITMAP_MODE
	// 반환 : 없음
	virtual void SetRoiMode   (int mode);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 억세스 함수
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// ROI 설정시   : GetMainBuffer()  - ROI 영역이 아닌 전체 이미지에 대한 1 차원 포인터
	//                GetMain2dArray() - ROI 영역이 아닌 전체 이미지에 대한 2 차원 포인터
	//                GetBuffer()      - ROI 영역 이미지에 대한 1 차원 포인터
	//                Get2dArray()     - ROI 영역 이미지에 대한 2 차원 포인터
	//
	// ROI 미설정시 : GetMainBuffer(),  GetBuffer()  - 전체 이미지에 대한 1 차원 포인터
	//                GetMain2dArray(), Get2dArray() - 전체 이미지에 대한 2 차원 포인터
	////////////////////////////////////////////////////////////////////////////
	KSdUint8*  GetMainBuffer (void);
	KSdUint8** GetMain2dArray(void);

	KSdUint8*  GetBuffer     (void);
	KSdUint8** Get2dArray    (void);
	

	////////////////////////////////////////////////////////////////////////////
	// 이미지 크기 획득 함수
	////////////////////////////////////////////////////////////////////////////
	// 주의 1
	//
	// ROI 설정시   : GetMainSize()  - ROI 영역이 아닌 전체 이미지에 대한 크기 획득
	//                GetMainXSize() - ROI 영역이 아닌 전체 이미지에 대한 가로 크기 획득
	//                GetMainYSize() - ROI 영역이 아닌 전체 이미지에 대한 세로 크기 획득
	//                GetSize()      - ROI 영역 이미지에 대한 크기 획득
	//                GetXSize()     - ROI 영역 이미지에 대한 가로 크기 획득
	//                GetYSize()     - ROI 영역 이미지에 대한 세로 크기 획득
	//
	// ROI 미설정시 : GetMainSize(),  GetSize()  - 전체 이미지에 대한 크기 획득
	//                GetMainXSize(), GetXSize() - 전체 이미지에 대한 가로 크기 획득
	//                GetMainYSize(), GetYSize() - 전체 이미지에 대한 세로 크기 획득
	////////////////////////////////////////////////////////////////////////////
	// 주의 1
	//
	// Windows 내부에서는 이미지 출력시 버퍼의 가로 크기가 4의 배수로 사용된다.
	// 위의 함수 중 가로 크기 획득 함수의 반환값은 4의 배수이다.
	// 원래의 크기가 4의 배수가 아닌 값을 획득하기  위해서는 다음의 함수를 사용한다.
	////////////////////////////////////////////////////////////////////////////
	// int KScGenericImage::GetRealXSize();
	// int KScGenericImage::GetRealYSize();
	// int KScGenericImage::GetRealZSize();
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	

	////////////////////////////////////////////////////////////////////////////
	// 포인트 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 지점의 값 변경
	// 인자 : 값, 위치
	// 반환 : 없음
	void     SetPixel(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixel(KSdUint8 pixel, int x, int y);

	// 버퍼 상의 특정 지점의 값 획득
	// 인자 : 획득된 값 저장 버퍼, 위치
	// 반환 : 없음
	void     GetPixel(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdUint8 &pixel, int x, int y);
	// 인자 : 위치
	// 반환 : 획득된 값
	KSdUint8 GetPixel(KS_2D_POINT &point);
	KSdUint8 GetPixel(int x, int y);
	

	////////////////////////////////////////////////////////////////////////////
	// 행 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 행에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 세로 위치, 가로 위치, 변경할 길이
	// 반환 : 없음
	void PutRow(KSdUint8* row, int y, int x, int len);

	// 버퍼 상의 특정 행에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 세로 위치, 가로 위치, 획득할 길이
	// 반환 : 없음
	void GetRow(KSdUint8* row, int y, int x, int len);


	////////////////////////////////////////////////////////////////////////////
	// 영역 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 영역에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기
	// 반환 : 없음
	void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize);

	// 버퍼 상의 특정 영역에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기
	// 반환 : 없음
	void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 초기화
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 전체를 주어진 값으로 초기화
	// 인자 : 초기화 할 값(기본값 : 0)
	// 반환 : 없음
	void InitTo(KSdUint8 value=0);

	
	////////////////////////////////////////////////////////////////////////////
	// 버퍼 복사
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// 버퍼 복사시 메모리가 할당이 되어 있지 않거나 크기가 서로 틀릴 경우는
	// 복사가 되지 않음.
	// 복사시 버퍼 내용만 복사되며, 클래스의 다른 정보는 복사 되지 않음
	////////////////////////////////////////////////////////////////////////////

	// 다른 클래스에 버퍼를 복사
	// 인자 : 버퍼가 복사되어질 클래스 포인터
	// 반환 : 없음
	void CopyToObject (KScScalarImage2dUint8 *dst);

	// 다른 클래스로부터 버퍼를 복사
	// 인자 : 버퍼를 가져올 클래스 포인터
	// 반환 : 없음
	void SetFromObject(KScScalarImage2dUint8 *src);


	////////////////////////////////////////////////////////////////////////////
	// KScRgbImage2d로 버퍼 복사
	////////////////////////////////////////////////////////////////////////////
	// 버퍼의 내용을 KScRgbImage2d용으로 변환하여 복사
	// KScRgbImage2d는 각 플레인을 독립적으로 관리(RRR..., GGG..., BBB...)하며,
	// 버퍼상의 특정 점의 각 플레인의 값은 동일하다.
	// 인자 : 버퍼를 복사할 KScRgbImage2d 클래스 포인터
	// 반환 : 없음
	void ConvertToRgbImage(KScRgbImage2d *dst);


	////////////////////////////////////////////////////////////////////////////
	// 다른 KScScalarImage2dUint8 클래스로부터 정보 복사
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// 버퍼 복사시 인자로 전달되는 클래스의 모든 정보를 복사
	////////////////////////////////////////////////////////////////////////////
	// 다른 클래스에서 모든 정보를 복사
	// 인자 : 버퍼를 복사할 클래스 포인터
	// 반환 : 현재 클래스의 Reference
	KScScalarImage2dUint8& operator=(KScScalarImage2dUint8 &p);

	////////////////////////////////////////////////////////////////////////////
	//
	////////////////////////////////////////////////////////////////////////////
	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

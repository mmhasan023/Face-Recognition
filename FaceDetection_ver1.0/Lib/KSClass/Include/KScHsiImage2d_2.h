#ifndef __KSC_HSIIMAGE2D_H__
#define __KSC_HSIIMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScScalarImage2dFloat.h"

class KScRgbImage2d;

class KS_CLASS KScHsiImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dFloat* pRealData[KS_HSI_PLANE_NUM]; // original image pointer
	KScData2dFloat* pRealRoi [KS_HSI_PLANE_NUM]; // roi image pointer for copy mode
	KSdFloat*       pData    [KS_HSI_PLANE_NUM]; // access image pointer
	KSdFloat**      p2dArray [KS_HSI_PLANE_NUM]; // 2d Array
	KSdFloat**      pRoiData [KS_HSI_PLANE_NUM]; // roi image pointer

// methods
public:

	////////////////////////////////////////////////////////////////////////////
	// 클래스 생성자
	////////////////////////////////////////////////////////////////////////////

	KScHsiImage2d(void);

	// 이름
	KScHsiImage2d(char *name);

	// 가로 크기, 세로 크기
	KScHsiImage2d(int xSize, int ySize);

	// 이름, 가로 크기, 세로 크기
	KScHsiImage2d(char *name, int xSize, int ySize);


	////////////////////////////////////////////////////////////////////////////
	// 클래스 파괴자
	////////////////////////////////////////////////////////////////////////////

	virtual	~KScHsiImage2d(void);


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
	KS_2D_SIZE GetMainSize(void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize(void);
	int        GetXSize(void);
	int        GetYSize(void);

	void RgbToHsi(KSdFloat r, KSdFloat g, KSdFloat b, KSdFloat *h, KSdFloat *s, KSdFloat *i);
	void HsiToRgb(KSdFloat h, KSdFloat s, KSdFloat i, KSdFloat *r, KSdFloat *g, KSdFloat *b);

////////////////////////////////////////////////////////////////////////////
// 플레인 별 처리
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 초기화
	////////////////////////////////////////////////////////////////////////////

	// 지정된 플레인 버퍼 주어진 값으로 초기화
	// 인자 : 초기화 할 값, 플레인
	// 반환 : 없음
	void InitTo(KSdFloat value, int planeNum);

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 억세스 함수
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// ROI 설정시   : GetMain??Buffer()  - ROI 영역이 아닌 전체 이미지에 대한 1 차원 포인터
	//                GetMain??2dArray() - ROI 영역이 아닌 전체 이미지에 대한 2 차원 포인터
	//                Get??Buffer()      - ROI 영역 이미지에 대한 1 차원 포인터
	//                Get??2dArray()     - ROI 영역 이미지에 대한 2 차원 포인터
	//
	// ROI 미설정시 : GetMain??Buffer(),  Get??Buffer()  - 전체 이미지에 대한 1 차원 포인터
	//                GetMain??2dArray(), Get??2dArray() - 전체 이미지에 대한 2 차원 포인터
	////////////////////////////////////////////////////////////////////////////
	KSdFloat* GetBuffer          (int planeNum);
	KSdFloat* GetHueBuffer       (void);
	KSdFloat* GetSaturationBuffer(void);
	KSdFloat* GetIntensityBuffer (void);

	KSdFloat* GetMainBuffer          (int planeNum);
	KSdFloat* GetMainHueBuffer       (void);
	KSdFloat* GetMainSaturationBuffer(void);
	KSdFloat* GetMainIntensityBuffer (void);

	KSdFloat** Get2dArray          (int planeNum);
	KSdFloat** GetHue2dArray       (void);
	KSdFloat** GetSaturation2dArray(void);
	KSdFloat** GetIntensity2dArray (void);

	KSdFloat** GetMain2dArray          (int planeNum);
	KSdFloat** GetMainHue2dArray       (void);
	KSdFloat** GetMainSaturation2dArray(void);
	KSdFloat** GetMainIntensity2dArray (void);

	////////////////////////////////////////////////////////////////////////////
	// 포인트 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 지점의 값 변경
	// 인자 : 값, 위치, 플레인
	// 반환 : 없음
	void     SetPixel(KSdFloat pixel, KS_2D_POINT &point, int planeNum);
	void     SetPixel(KSdFloat pixel, int x, int y, int planeNum);

	// 버퍼 상의 특정 지점의 값 획득
	// 인자 : 획득된 값 저장 버퍼, 위치, 플레인
	// 반환 : 없음
	void     GetPixel(KSdFloat &pixel, KS_2D_POINT &point, int planeNum);
	void     GetPixel(KSdFloat &pixel, int x, int y, int planeNum);
	// 인자 : 위치, 플레인
	// 반환 : 획득된 값
	KSdFloat GetPixel(KS_2D_POINT &point, int planeNum);
	KSdFloat GetPixel(int x, int y, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// 행 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 행에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 세로 위치, 가로 위치, 변경할 길이, 플레인
	// 반환 : 없음
	void PutRow(KSdFloat* row, int y, int x, int len, int planeNum);

	// 버퍼 상의 특정 행에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 세로 위치, 가로 위치, 획득할 길이, 플레인
	// 반환 : 없음
	void GetRow(KSdFloat* row, int y, int x, int len, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// 영역 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 영역에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기, 플레인
	// 반환 : 없음
	void SetSection(KSdFloat* section, int x, int y, int xSize, int ySize, int planeNum);

	// 버퍼 상의 특정 영역에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기, 플레인
	// 반환 : 없음
	void GetSection(KSdFloat* section, int x, int y, int xSize, int ySize, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 복사
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// 버퍼 복사시 메모리가 할당이 되어 있지 않거나 크기가 서로 틀릴 경우는
	// 복사가 되지 않음.
	// 복사시 버퍼 내용만 복사되며, 클래스의 다른 정보는 복사 되지 않음
	////////////////////////////////////////////////////////////////////////////

	// 지정 플레인을 KScScalarImage2dFloat 클래스의 버퍼로 복사
	// 인자 : 플레인, 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void CopyToScalarImage(int planeNum, KScScalarImage2dFloat *dst);

	// KScScalarImage2dFloat 클래스로부터 지정 플레인으로 버퍼를 복사
	// 인자 : 플레인, 버퍼를 가져올 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void SetFromScalarImage(int planeNum, KScScalarImage2dFloat *dst);
	

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 분리
	////////////////////////////////////////////////////////////////////////////

	// 지정 플레인을 KScScalarImage2dFloat 클래스의 버퍼로 복사, CopyToScalarImage 동일
	// 인자 : 플레인, 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void SplitPlane          (int planeNum, KScScalarImage2dFloat *dst);


	// 모든 플레인을 3 개의 KScScalarImage2dFloat 클래스의 버퍼로 복사
	// 인자 : Hue        플레인 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터,
	//        Saturation 플레인 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터,
	//        Intensity  플레인 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void SplitAllPlane       (KScScalarImage2dFloat *H,
		                      KScScalarImage2dFloat *S,
							  KScScalarImage2dFloat *I);

	// Hue 플레인을 KScScalarImage2dFloat 클래스의 버퍼로 복사
	// 인자 : 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void SplitHuePlane       (KScScalarImage2dFloat *dst);

	// Saturation 플레인을 KScScalarImage2dFloat 클래스의 버퍼로 복사
	// 인자 : 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void SplitSaturationPlane(KScScalarImage2dFloat *dst);

	// Intensity 플레인을 KScScalarImage2dFloat 클래스의 버퍼로 복사
	// 인자 : 버퍼가 복사되어질 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void SplitIntensityPlane (KScScalarImage2dFloat *dst);
	

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 병합
	////////////////////////////////////////////////////////////////////////////

	// KScScalarImage2dFloat 클래스 버퍼를 지정된 플레인에 복사
	// 인자 : 플레인, 복사할 버퍼를 가진 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void MergePlane          (int planeNum, KScScalarImage2dFloat *src);


	// KScScalarImage2dFloat 클래스 버퍼를 지정된 각 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 3 개의 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void MergeAllPlane       (KScScalarImage2dFloat *H,
		                      KScScalarImage2dFloat *S,
							  KScScalarImage2dFloat *I);

	// KScScalarImage2dFloat 클래스 버퍼를 지정된 Hue 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void MergeHuePlane       (KScScalarImage2dFloat *dst);

	// KScScalarImage2dFloat 클래스 버퍼를 지정된 Saturation 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void MergeSaturationPlane(KScScalarImage2dFloat *dst);

	// KScScalarImage2dFloat 클래스 버퍼를 지정된 Intensity 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 KScScalarImage2dFloat 클래스 포인터
	// 반환 : 없음
	void MergeIntensityPlane (KScScalarImage2dFloat *dst);

////////////////////////////////////////////////////////////////////////////
// 다수의 플레인 별 처리
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 초기화
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 전체를 주어진 값으로 초기화
	// 인자 : 초기화 할 값
	// 반환 : 없음
	void InitTo(KSdHsi value);

	// 버퍼 상의 특정 지점의 값 변경
	// 인자 : 값, 위치
	// 반환 : 없음
	void   SetPixel(KSdHsi pixel, KS_2D_POINT &point);
	void   SetPixel(KSdHsi pixel, int x, int y);


	// 버퍼 상의 특정 지점의 값 획득
	// 인자 : 획득된 값 저장 버퍼, 위치
	// 반환 : 없음
	void   GetPixel(KSdHsi &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdHsi &pixel, int x, int y);
	// 인자 : 위치
	// 반환 : 획득된 값
	KSdHsi GetPixel(KS_2D_POINT &point);
	KSdHsi GetPixel(int x, int y);


	////////////////////////////////////////////////////////////////////////////
	// 행 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 행에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 세로 위치, 가로 위치, 변경할 길이
	// 반환 : 없음
	void PutRow(KSdHsi* row, int y, int x, int len);

	// 버퍼 상의 특정 행에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 세로 위치, 가로 위치, 획득할 길이
	// 반환 : 없음
	void GetRow(KSdHsi* row, int y, int x, int len);


	////////////////////////////////////////////////////////////////////////////
	// 영역 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 영역에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기
	// 반환 : 없음
	void SetSection(KSdHsi* section, int x, int y, int xSize, int ySize);

	// 버퍼 상의 특정 영역에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기
	// 반환 : 없음
	void GetSection(KSdHsi* section, int x, int y, int xSize, int ySize);


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
	void CopyToObject(KScHsiImage2d *dst);

	// 다른 클래스로부터 버퍼를 복사
	// 인자 : 버퍼를 가져올 클래스 포인터
	// 반환 : 없음
	void SetFromObject(KScHsiImage2d *src);

	
	////////////////////////////////////////////////////////////////////////////
	// 버퍼 변환
	////////////////////////////////////////////////////////////////////////////

	// KScHsiImage2d -> KScRgbImage2d 변환
	void ConvertToRgbImage(KScRgbImage2d *dst);


	////////////////////////////////////////////////////////////////////////////
	// 다른 KScHsiImage2d 클래스로부터 정보 복사
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// 버퍼 복사시 인자로 전달되는 클래스의 모든 정보를 복사
	////////////////////////////////////////////////////////////////////////////
	// 다른 클래스에서 모든 정보를 복사
	// 인자 : 버퍼를 복사할 클래스 포인터
	// 반환 : 현재 클래스의 Reference
	KScHsiImage2d& operator=(KScHsiImage2d &p);

	////////////////////////////////////////////////////////////////////////////
	//
	////////////////////////////////////////////////////////////////////////////
	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif

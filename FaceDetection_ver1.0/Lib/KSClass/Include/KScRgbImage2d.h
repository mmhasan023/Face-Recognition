#ifndef __KSC_RGBIMAGE2D_H__
#define __KSC_RGBIMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScScalarImage2dUint8.h"

class KScHsiImage2d;

class KS_CLASS KScRgbImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dUint8 *pRealData[KS_RGB_PLANE_NUM]; // original image pointer
	KScData2dUint8 *pRealRoi [KS_RGB_PLANE_NUM]; // roi image pointer for copy mode

	KSdUint8       *pData    [KS_RGB_PLANE_NUM]; // access image pointer
	KSdUint8       **p2dArray[KS_RGB_PLANE_NUM]; // 2d Array
	KSdUint8       **pRoiData[KS_RGB_PLANE_NUM]; // roi image pointer

// methods
public:

	////////////////////////////////////////////////////////////////////////////
	// 클래스 생성자
	////////////////////////////////////////////////////////////////////////////

	// 플레인 수(기본값 : KS_RGB_PLANE_NUM)
	KScRgbImage2d(                                  int plane=KS_RGB_PLANE_NUM);

	// 이름, 플레인 수(기본값 : KS_RGB_PLANE_NUM)
	KScRgbImage2d(char *name,                       int plane=KS_RGB_PLANE_NUM);

	// 크기, 플레인 수(기본값 : KS_RGB_PLANE_NUM)
	KScRgbImage2d(            int xSize, int ySize, int plane=KS_RGB_PLANE_NUM);

	// 이름, 크기, 플레인 수(기본값 : KS_RGB_PLANE_NUM)
	KScRgbImage2d(char *name, int xSize, int ySize, int plane=KS_RGB_PLANE_NUM);


	////////////////////////////////////////////////////////////////////////////
	// 클래스 파괴자
	////////////////////////////////////////////////////////////////////////////
	
	virtual	~KScRgbImage2d(void);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 할당 및 해제
	////////////////////////////////////////////////////////////////////////////
	// 버퍼 할당
	// 인자 : 가로 크기, 세로 크기
	// 반환 : 성공 - NO_ERROR or KS_OK
	//        실패 - NO_ERROR or KS_OK 외의 값, KScStatusCode.h 참조
	int  Alloc(int xSize, int ySize, int plane=KS_RGB_PLANE_NUM);

	// 버퍼 해제
	// 인자 : 없음
	// 반환 : 없음
	void Free (void);


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
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize     (void);
	int        GetXSize    (void);
	int        GetYSize    (void);


////////////////////////////////////////////////////////////////////////////
// 플레인 별 처리
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 초기화
	////////////////////////////////////////////////////////////////////////////

	// 지정된 플레인 버퍼 주어진 값으로 초기화
	// 인자 : 초기화 할 값(기본값 : 0), 플레인(기본값 : R_PLANE)
	// 반환 : 없음
	void InitTo(KSdUint8 value=0, int planeNum=R_PLANE);


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
	KSdUint8* GetBuffer     (int planeNum);
	KSdUint8* GetRedBuffer  (void);
	KSdUint8* GetGreenBuffer(void);
	KSdUint8* GetBlueBuffer (void);

	KSdUint8* GetMainBuffer     (int planeNum);
	KSdUint8* GetMainRedBuffer  (void);
	KSdUint8* GetMainGreenBuffer(void);
	KSdUint8* GetMainBlueBuffer (void);

	KSdUint8** Get2dArray     (int planeNum);
	KSdUint8** GetRed2dArray  (void);
	KSdUint8** GetGreen2dArray(void);
	KSdUint8** GetBlue2dArray (void);

	KSdUint8** GetMain2dArray     (int planeNum);
	KSdUint8** GetMainRed2dArray  (void);
	KSdUint8** GetMainGreen2dArray(void);
	KSdUint8** GetMainBlue2dArray (void);

	////////////////////////////////////////////////////////////////////////////
	// 포인트 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 지점의 값 변경
	// 인자 : 값, 위치, 플레인
	// 반환 : 없음
	void     SetPixel(KSdUint8 pixel,  KS_2D_POINT &point, int planeNum);
	void     SetPixel(KSdUint8 pixel,  int x, int y,       int planeNum);

	// 버퍼 상의 특정 지점의 값 획득
	// 인자 : 획득된 값 저장 버퍼, 위치, 플레인
	// 반환 : 없음
	void     GetPixel(KSdUint8 &pixel, KS_2D_POINT &point, int planeNum);
	void     GetPixel(KSdUint8 &pixel, int x, int y,       int planeNum);
	// 인자 : 위치, 플레인
	// 반환 : 획득된 값
	KSdUint8 GetPixel(                 KS_2D_POINT &point, int planeNum);
	KSdUint8 GetPixel(                 int x, int y,       int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// 행 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 행에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 세로 위치, 가로 위치, 변경할 길이, 플레인
	// 반환 : 없음
	void PutRow(KSdUint8* row, int y, int x, int len, int planeNum);	

	// 버퍼 상의 특정 행에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 세로 위치, 가로 위치, 획득할 길이, 플레인
	// 반환 : 없음
	void GetRow(KSdUint8* row, int y, int x, int len, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// 영역 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 영역에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기, 플레인
	// 반환 : 없음
	void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);

	// 버퍼 상의 특정 영역에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기, 플레인
	// 반환 : 없음
	void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 복사
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// 버퍼 복사시 메모리가 할당이 되어 있지 않거나 크기가 서로 틀릴 경우는
	// 복사가 되지 않음.
	// 복사시 버퍼 내용만 복사되며, 클래스의 다른 정보는 복사 되지 않음
	////////////////////////////////////////////////////////////////////////////

	// 지정 플레인을 KScScalarImage2dUint8 클래스의 버퍼로 복사
	// 인자 : 플레인, 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void CopyToScalarImage (int planeNum, KScScalarImage2dUint8 *dst);

	// KScScalarImage2dUint8 클래스로부터 지정 플레인으로 버퍼를 복사
	// 인자 : 플레인, 버퍼를 가져올 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void SetFromScalarImage(int planeNum, KScScalarImage2dUint8 *dst);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 분리
	////////////////////////////////////////////////////////////////////////////

	// 지정 플레인을 KScScalarImage2dUint8 클래스의 버퍼로 복사, CopyToScalarImage와 동일
	// 인자 : 플레인, 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void SplitPlane     (int planeNum, KScScalarImage2dUint8 *dst);

	// 모든 플레인을 3 개의 KScScalarImage2dUint8 클래스의 버퍼로 복사
	// 인자 : Red   플레인 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터,
	//        Green 플레인 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터,
	//        Blue  플레인 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void SplitAllPlane  (KScScalarImage2dUint8 *R,
		                 KScScalarImage2dUint8 *G,
						 KScScalarImage2dUint8 *B);

	// Red 플레인을 KScScalarImage2dUint8 클래스의 버퍼로 복사
	// 인자 : 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void SplitRedPlane  (KScScalarImage2dUint8 *dst);
	
	// Green 플레인을 KScScalarImage2dUint8 클래스의 버퍼로 복사
	// 인자 : 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void SplitGreenPlane(KScScalarImage2dUint8 *dst);

	// Blue 플레인을 KScScalarImage2dUint8 클래스의 버퍼로 복사
	// 인자 : 버퍼가 복사되어질 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void SplitBluePlane (KScScalarImage2dUint8 *dst);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 병합
	////////////////////////////////////////////////////////////////////////////

	// KScScalarImage2dUint8 클래스 버퍼를 지정된 플레인에 복사
	// 인자 : 플레인, 복사할 버퍼를 가진 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void MergePlane     (int planeNum, KScScalarImage2dUint8 *src);

	// KScScalarImage2dUint8 클래스 버퍼를 지정된 각 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 3 개의 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void MergeAllPlane  (KScScalarImage2dUint8 *R,
		                 KScScalarImage2dUint8 *G,
						 KScScalarImage2dUint8 *B);

	// KScScalarImage2dUint8 클래스 버퍼를 지정된 Red 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void MergeRedPlane  (KScScalarImage2dUint8 *dst);
	
	// KScScalarImage2dUint8 클래스 버퍼를 지정된 Green 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void MergeGreenPlane(KScScalarImage2dUint8 *dst);
	
	// KScScalarImage2dUint8 클래스 버퍼를 지정된 Blue 플레인에 복사
	// 인자 : 복사할 버퍼를 가진 KScScalarImage2dUint8 클래스 포인터
	// 반환 : 없음
	void MergeBluePlane (KScScalarImage2dUint8 *dst);


////////////////////////////////////////////////////////////////////////////
// 다수의 플레인 별 처리
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// 버퍼 초기화
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 전체를 주어진 값으로 초기화
	// 인자 : 초기화 할 값
	// 반환 : 없음
	void InitTo(KSdRgb value);
	
	// 버퍼 상의 특정 지점의 값 변경
	// 인자 : 값, 위치
	// 반환 : 없음
	void   SetPixel(KSdRgb pixel,  KS_2D_POINT &point);
	void   SetPixel(KSdRgb pixel,  int x, int y);

	// 버퍼 상의 특정 지점의 값 획득
	// 인자 : 획득된 값 저장 버퍼, 위치
	// 반환 : 없음
	void   GetPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdRgb &pixel, int x, int y);
	// 인자 : 위치
	// 반환 : 획득된 값
	KSdRgb GetPixel(               KS_2D_POINT &point);
	KSdRgb GetPixel(               int x, int y);


	////////////////////////////////////////////////////////////////////////////
	// 행 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 행에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 세로 위치, 가로 위치, 변경할 길이
	// 반환 : 없음
	void PutRow(KSdRgb* row, int y, int x, int len);

	// 버퍼 상의 특정 행에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 세로 위치, 가로 위치, 획득할 길이
	// 반환 : 없음
	void GetRow(KSdRgb* row, int y, int x, int len);


	////////////////////////////////////////////////////////////////////////////
	// 영역 단위 처리 함수
	////////////////////////////////////////////////////////////////////////////

	// 버퍼 상의 특정 영역에 대한 값 변경
	// 인자 : 변경할 값을 저장하고 있는 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기
	// 반환 : 없음
	void SetSection(KSdRgb* section, int x, int y, int xSize, int ySize);

	// 버퍼 상의 특정 영역에 대한 값 획득
	// 인자 : 획득할 값을 저장할 버퍼 포인터, 가로 위치, 세로 위치, 가로 크기, 세로 크기
	// 반환 : 없음
	void GetSection(KSdRgb* section, int x, int y, int xSize, int ySize);


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
	void CopyToObject(KScRgbImage2d *dst);

	// 다른 클래스로부터 버퍼를 복사
	// 인자 : 버퍼를 가져올 클래스 포인터
	// 반환 : 없음
	void SetFromObject(KScRgbImage2d *src);


	////////////////////////////////////////////////////////////////////////////
	// 버퍼 변환
	////////////////////////////////////////////////////////////////////////////

	// KScRgbImage2d -> KScScalarImage2dUint8로 변환
	// Gray = R * 0.333 + G * 0.333 + B * 0.333
	void ConvertToScalarImage(KScScalarImage2dUint8 *dst);

	// KScRgbImage2d -> KScHsiImage2d로 변환
	void ConvertToHsiImage   (KScHsiImage2d *dst);

	// R,G,B의 값을 H, S, I로 변환
	void RgbToHsi            (KSdFloat r,  KSdFloat g,  KSdFloat b,
		                      KSdFloat *h, KSdFloat *s, KSdFloat *i );

	////////////////////////////////////////////////////////////////////////////
	// 다른 KScRgbImage2d 클래스로부터 정보 복사
	////////////////////////////////////////////////////////////////////////////
	// 주의
	//
	// 버퍼 복사시 인자로 전달되는 클래스의 모든 정보를 복사
	////////////////////////////////////////////////////////////////////////////
	// 다른 클래스에서 모든 정보를 복사
	// 인자 : 버퍼를 복사할 클래스 포인터
	// 반환 : 현재 클래스의 Reference
	KScRgbImage2d& operator=(KScRgbImage2d &p);

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

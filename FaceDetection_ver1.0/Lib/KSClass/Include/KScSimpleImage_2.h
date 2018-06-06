#ifndef __KSSIMPLEIMAGE_H__
#define __KSSIMPLEIMAGE_H__

#include "KScGenericImage.h"
#include "KScData.h"         // KS_RECT
#include "KScBase.h"         // KScArray
#include "KScBitmapRoi2d.h"  // KScBitmapRoi2d

#pragma warning (disable : 4251) // 대일 추가 0827 경고 메세지 안나오게함...

class KS_CLASS KScSimpleImage : public KScGenericImage 
{

// attribute
public :

	double scale;     // use to calculate the real length.

	// ralated to ROI
	KS_RECT roiRect;  // current ROI dimension
	int     roiMode;  // current ROI mode
	int     rDx, rDy; // current ROI size

	// ralated to multiple ROI
	KScArray<KS_RECT*, KS_RECT*> roiRectBucket;
	int curRoiPos;    // current ROI position in bucket

	// related to bitmap ROI
	// - An arbitrary ROI except to rectangular is available with KScBitmapRoi
	KScBitmapRoi2d<unsigned char> *pBitmapRoi;

// methods
public:

	KScSimpleImage();
	KScSimpleImage(char *szName);

	virtual	~KScSimpleImage();

	double GetScale(void);
	void   SetScale(double s);

	// ralated to ROI
	virtual int     IsRoi(void);
	
	virtual int     SetRoiRect(KS_RECT &rect);
	virtual int     SetRoiRect(int sx, int sy, int ex, int ey);
	virtual KS_RECT GetRoiRect(void);
	virtual void    ValidateRect(KS_RECT *pRect);
	virtual void    ValidateRect(int *sx, int *sy, int *ex, int *ey);

	virtual void    InitRoiRect  (void);
	virtual void    ResetRoiRect (void);
	virtual void    CalcRoiSize  (void);
	virtual int     MakeRoiBuffer(void);

	virtual void    SetDefaultRoiMode(void);
	virtual void    SetCopyRoiMode   (void);
	virtual void    SetRemapRoiMode  (void);
	virtual void    SetRoiMode       (int mode);
	virtual int     GetRoiMode       (void);

	// ralated to multiple ROI
	void     InitRoiRectBucket(void);
	int      SetPosRoiRect    (int pos);
	int      GetSizeRoiRect   (void);
	KS_RECT* GetRoiRect       (int pos);
	
    // append to bucket
	int      AddRoiRect       (int sx, int sy, int ex, int ey);
	int      AddRoiRect       (KS_RECT* pRect);
	// insert to bucket
	int      InsertRoiRect    (int pos, int sx, int sy, int ex, int ey);
	int      InsertRoiRect    (int pos, KS_RECT *pRect);

	int      RemoveRoiRect    (int pos); // 지정된 위치의 요소를 삭제
	int      RemoveAllRoiRect (void);    // 전체 버켓 내용 삭제
	int      ResetRoiBucket   (void);    // 전체 버켓 내용 삭제 및 변수 초기화

	// 영상과 비트맵과의 연산으로 픽셀 가져오기는 GetPixel(), SetPixel() 참조

/*	// Bitmap 에서 픽셀 넣기/가져오기
	void     SetPixelToBitmap(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixelToBitmap(KSdUint8 pixel, int x, int y);

	KSdUint8 GetPixelFromBitmap(KS_2D_POINT &point);
	KSdUint8 GetPixelFromBitmap(int x, int y);
	void     GetPixelFromBitmap(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixelFromBitmap(KSdUint8 &pixel, int x, int y);

	// 영상에서 픽셀 넣기/가져오기
	void     SetPixelToImage(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixelToImage(KSdUint8 pixel, int x, int y);

	KSdUint8 GetPixelFromImage(KS_2D_POINT &point);
	KSdUint8 GetPixelFromImage(int x, int y);
	void     GetPixelFromImage(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixelFromImage(KSdUint8 &pixel, int x, int y);
*/
	// - 출력용.....
	void SetBitmapRoiMode(void);
	// - 모드가 바뀔 때
	//     copy<->remap
	//     bitmap<->copy : 비트맵 삭제/생성
	//     bitmap<->remap: 비트맵 삭제/생성
	void MakeBitmapRoi(int dx, int dy);
	KScBitmapRoi2d<unsigned char> *GetBitmapRoi(void);
	void RemoveBitmapRoi(void);

	virtual void    LoadFromFile(char *fileName);
	virtual void    SaveToFile  (char *fileName);
};

#endif

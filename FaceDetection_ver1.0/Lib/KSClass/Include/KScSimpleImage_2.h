#ifndef __KSSIMPLEIMAGE_H__
#define __KSSIMPLEIMAGE_H__

#include "KScGenericImage.h"
#include "KScData.h"         // KS_RECT
#include "KScBase.h"         // KScArray
#include "KScBitmapRoi2d.h"  // KScBitmapRoi2d

#pragma warning (disable : 4251) // ���� �߰� 0827 ��� �޼��� �ȳ�������...

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

	int      RemoveRoiRect    (int pos); // ������ ��ġ�� ��Ҹ� ����
	int      RemoveAllRoiRect (void);    // ��ü ���� ���� ����
	int      ResetRoiBucket   (void);    // ��ü ���� ���� ���� �� ���� �ʱ�ȭ

	// ����� ��Ʈ�ʰ��� �������� �ȼ� ��������� GetPixel(), SetPixel() ����

/*	// Bitmap ���� �ȼ� �ֱ�/��������
	void     SetPixelToBitmap(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixelToBitmap(KSdUint8 pixel, int x, int y);

	KSdUint8 GetPixelFromBitmap(KS_2D_POINT &point);
	KSdUint8 GetPixelFromBitmap(int x, int y);
	void     GetPixelFromBitmap(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixelFromBitmap(KSdUint8 &pixel, int x, int y);

	// ���󿡼� �ȼ� �ֱ�/��������
	void     SetPixelToImage(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixelToImage(KSdUint8 pixel, int x, int y);

	KSdUint8 GetPixelFromImage(KS_2D_POINT &point);
	KSdUint8 GetPixelFromImage(int x, int y);
	void     GetPixelFromImage(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixelFromImage(KSdUint8 &pixel, int x, int y);
*/
	// - ��¿�.....
	void SetBitmapRoiMode(void);
	// - ��尡 �ٲ� ��
	//     copy<->remap
	//     bitmap<->copy : ��Ʈ�� ����/����
	//     bitmap<->remap: ��Ʈ�� ����/����
	void MakeBitmapRoi(int dx, int dy);
	KScBitmapRoi2d<unsigned char> *GetBitmapRoi(void);
	void RemoveBitmapRoi(void);

	virtual void    LoadFromFile(char *fileName);
	virtual void    SaveToFile  (char *fileName);
};

#endif

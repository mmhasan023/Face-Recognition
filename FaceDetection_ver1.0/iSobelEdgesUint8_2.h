//////////////////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� : iSobelEdgesUint8.h
// ��    �� : 1�� �̺� ����ũ�� �����Ͽ� ��� ���
//			  ����ũ�� �����Ͽ� Uint8 Ÿ������ ����� ���
// �� �� �� : �� �� ȯ <loveme97@mg.co.kr>
// �� �� �� : 1999�� 7�� 9��
// ��    �� : M&G Systems <master@mg.co.kr>
// ���ǻ��� : 
// �������� : iRobertsEdges, iPrewittEdges, iDoGEdges, iLoGEdges
// �������� : 
// �������� : 
//
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __I_SOBEL_EDGES_UINT_8_H__
#define __I_SOBEL_EDGES_UINT_8_H__

// KSClass�鿡 ���� ���
//#include "KSClass.h" 
#include "./Lib/KSClass/Include/KSClass.h"

// DLL �ܺο��� ȣ���ϱ� ���ؼ� �ʿ��� �κ� ...
extern "C" __declspec( dllexport )
int CDECL iSobelEdgesUint8(KScScalarImage2dUint8 *sourceImage,
						   KScScalarImage2dUint8 *destinationImage);

#endif

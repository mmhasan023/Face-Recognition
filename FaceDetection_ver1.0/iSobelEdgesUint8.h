//////////////////////////////////////////////////////////////////////////////////////////////
//
// 파 일 명 : iSobelEdgesUint8.h
// 설    명 : 1차 미분 마스크를 적용하여 결과 출력
//			  마스크를 적용하여 Uint8 타입으로 결과를 출력
// 작 성 자 : 이 태 환 <loveme97@mg.co.kr>
// 작 성 일 : 1999년 7월 9일
// 소    속 : M&G Systems <master@mg.co.kr>
// 주의사항 : 
// 참조파일 : iRobertsEdges, iPrewittEdges, iDoGEdges, iLoGEdges
// 수정일자 : 
// 수정내용 : 
//
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __I_SOBEL_EDGES_UINT_8_H__
#define __I_SOBEL_EDGES_UINT_8_H__

// KSClass들에 대한 헤더
//#include "KSClass.h" 
#include "./Lib/KSClass/Include/KSClass.h"

// DLL 외부에서 호출하기 위해서 필요한 부분 ...
extern "C" __declspec( dllexport )
int CDECL iSobelEdgesUint8(KScScalarImage2dUint8 *sourceImage,
						   KScScalarImage2dUint8 *destinationImage);

#endif

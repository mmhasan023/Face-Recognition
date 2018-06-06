#ifndef __KSSTATUSCODE_H_
#define __KSSTATUSCODE_H_

#define	KS_OK											0L
#define	NO_ERROR										0L
#define NO_ALLOC_MEMORY									1L
#define FAIL_ALLOC_MEMORY								2L
#define	NO_SUITABLE_VALUE								3L
#define ALREADY_ALLOC_MEMORY							4L
#define NO_ALLOC_MEMORY_MAP								5L
#define FAIL_ALLOC_MEMORY_MAP							6L
#define ALREADY_ALLOC_MEMORY_MAP						7L
#define OUT_OF_RANGE									8L
#define NO_SUITABLE_RANGE								9L
#define NO_SIZE_CONFORMANCE								10L
#define NO_SUITABLE_ROI_TYPE							11L
#define SAME_ROI_TYPE									12L
#define INVALID_REGION_ROI								13L
#define INVALID_INPUT_BUFFER							14L
#define FILE_OPEN_ERROR									15L
#define FILE_CLOSE_ERROR								16L
#define INVALID_BUFFER_POINT							17L
#define INVALID_PLANE_NUM								18L
#define NOT_DEFINABLE									19L
//"assignment not definable at this level in the hierarchy"
#define FAIL_ALLOC_HISTOGRAM							20L
#define OUT_OF_BOUND_HISTOGRAM							21L
#define INVALID_DATA_TYPE								22L
#define SAME_BUFFER_NAME								23L
#define ALREADY_ROI_DATA								24L
#define INVALID_ROIRECT_AREA							25L

static char *MESSAGE[] = 
{
	"이상없이 처리가 끝났습니다.",		// status code : 0L 
	"할당된 버퍼가 없습니다.",
	"버퍼 할당이 실패했습니다.",
	"적당한 값이 아닙니다.",					
	"이미 할당된 버퍼가 있습니다.",					
	"할당된 2차원 버퍼가 없었습니다.",
	"2차원 버퍼 할당에 실패했습니다.",
	"이미 할당된 2차원 버퍼가 있습니다.",	
	"제한된 범위를 넘어갔습니다.",			
	"접근하려는 곳이 적당한 범위가 아닙니다.",		
	"영상의 크기가 동일하지 않습니다.",							// status code : 10L 
	"적합한 ROI(Region of Interest)가 아닙니다.", 
	"동일한 ROI(Region of Interest)가 아닙니다.", 
	"접근한 곳은 ROI(Region of Interest) 영역을 벗어났습니다.", 
	"입력 버퍼가 잘못되었습니다.", 
	"파일 열기가 실패했습니다.", 
	"파일 닫기가 실패했습니다.", 
	"버퍼가 유효하지 않습니다.", 
	"플레임의 범위를 넘었습니다.", 
	"계층구조상 이 계층에서는 할당을 정의할 수 없습니다.",
	"히스토그램 클래스를 위한 bucket메모리 할당에 에러가 발생했습니다. ",
	"히스토그램에서 정의된 영역을 넘었습니다.",
	"해당되는 자료 형식이 없습니다.",
	"같은 형식의 클래스 이름이 이미 존재 합니다.",
	"이미 ROI영역이 할당되어 있습니다", 
	"ROI 영역 설정에 오류가 있습니다.",
};

#endif
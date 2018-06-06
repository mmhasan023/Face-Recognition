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
	"�̻���� ó���� �������ϴ�.",		// status code : 0L 
	"�Ҵ�� ���۰� �����ϴ�.",
	"���� �Ҵ��� �����߽��ϴ�.",
	"������ ���� �ƴմϴ�.",					
	"�̹� �Ҵ�� ���۰� �ֽ��ϴ�.",					
	"�Ҵ�� 2���� ���۰� �������ϴ�.",
	"2���� ���� �Ҵ翡 �����߽��ϴ�.",
	"�̹� �Ҵ�� 2���� ���۰� �ֽ��ϴ�.",	
	"���ѵ� ������ �Ѿ���ϴ�.",			
	"�����Ϸ��� ���� ������ ������ �ƴմϴ�.",		
	"������ ũ�Ⱑ �������� �ʽ��ϴ�.",							// status code : 10L 
	"������ ROI(Region of Interest)�� �ƴմϴ�.", 
	"������ ROI(Region of Interest)�� �ƴմϴ�.", 
	"������ ���� ROI(Region of Interest) ������ ������ϴ�.", 
	"�Է� ���۰� �߸��Ǿ����ϴ�.", 
	"���� ���Ⱑ �����߽��ϴ�.", 
	"���� �ݱⰡ �����߽��ϴ�.", 
	"���۰� ��ȿ���� �ʽ��ϴ�.", 
	"�÷����� ������ �Ѿ����ϴ�.", 
	"���������� �� ���������� �Ҵ��� ������ �� �����ϴ�.",
	"������׷� Ŭ������ ���� bucket�޸� �Ҵ翡 ������ �߻��߽��ϴ�. ",
	"������׷����� ���ǵ� ������ �Ѿ����ϴ�.",
	"�ش�Ǵ� �ڷ� ������ �����ϴ�.",
	"���� ������ Ŭ���� �̸��� �̹� ���� �մϴ�.",
	"�̹� ROI������ �Ҵ�Ǿ� �ֽ��ϴ�", 
	"ROI ���� ������ ������ �ֽ��ϴ�.",
};

#endif
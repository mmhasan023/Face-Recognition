#ifndef __KSOBJECTID_H__
#define __KSOBJECTID_H__

#define	KS_OBJECT						0L

#define KS_UINT8						10L
#define KS_INT16						10L+1
#define KS_INT32						10L+2
#define KS_UINT32						10L+3
#define KS_FLOAT						10L+4
#define KS_DOUBLE						10L+5
#define KS_LDOUBLE						10L+6
#define KS_LONG						    10L+7

// Call by value 지원
#define KS_UINT8V						30L
#define KS_INT16V						30L+1
#define KS_INT32V						30L+2
#define KS_UINT32V						30L+3
#define KS_FLOATV						30L+4
#define KS_DOUBLEV						30L+5
#define KS_LDOUBLEV						30L+6
#define KS_LONGV					    30L+7

// 포인터 지원 
#define VOID_POINTER					20L+1	// void*
#define FILE_POINTER					20L+2	// FILE*

// MFC 지원  
#define MFC_COBJECT_POINTER				20L+3	// Class pointer based on CObject
#define MFC_CPOINT_POINTER				20L+4	// Class pointer not based on CObject
#define MFC_CRECT_POINTER				20L+5
#define MFC_CSIZE_POINTER				20L+6
#define MFC_CSTRING_POINTER				20L+7
#define MFC_CTIME_POINTER				20L+8

// 인텔에서 지원해주는 자료형식
#define INTEL_IMAGE_POINTER				40L+1

// CVIP 자료형식 지원
#define CVIP_IMAGE_POINTER				40L+2

// CVIP 자료형식 지원
#define APHELION_IMAGE_POINTER			40L+3

#define KS_STRING						50L
#define KS_CSTRING						50L+1

#define KS_DATA							100L
#define KS_DATA_1D						200L	
#define KS_DATA_1D_UINT8				200L+sizeof(unsigned char) 
#define KS_DATA_1D_INT16				200L+sizeof(short)         
#define KS_DATA_1D_INT32				200L+sizeof(int)           
#define KS_DATA_1D_FLOAT				200L+sizeof(float)         
#define KS_DATA_1D_DOUBLE				200L+sizeof(double)        
#define KS_DATA_2D						300L
#define KS_DATA_2D_UINT8				300L+sizeof(unsigned char)
#define KS_DATA_2D_INT16				300L+sizeof(short)
#define KS_DATA_2D_INT32				300L+sizeof(int)
#define KS_DATA_2D_FLOAT				300L+sizeof(float)
#define KS_DATA_2D_DOUBLE				300L+sizeof(double)
#define KS_DATA_3D						400L
#define KS_DATA_3D_UINT8				400L+sizeof(unsigned char) 
#define KS_DATA_3D_INT16				400L+sizeof(short)         
#define KS_DATA_3D_INT32				400L+sizeof(int)           
#define KS_DATA_3D_FLOAT				400L+sizeof(float)         
#define KS_DATA_3D_DOUBLE				400L+sizeof(double)        

#define KS_USER_DEFINE_ARRAY			500L

#define KS_GENERIC_IMAGE				1000L

#define KS_SIMPLE_IMAGE					2000L

#define KS_CONVOLUTION_KERNEL			2001L
#define KS_CONVOLUTION_KERNEL_2D_INT8	2002L
#define KS_CONVOLUTION_KERNEL_2D_INT32	2003L
#define KS_CONVOLUTION_KERNEL_2D_FLOAT	2004L

#define KS_BITMAP_ROI_2D				2005L
#define KS_BITMAP_ROI_3D				2006L

#define KS_SCALAR_IMAGE					2010L
#define KS_SCALAR_IMAGE_2D				2020L
#define KS_SCALAR_IMAGE_2D_BIT			2020L+1
#define KS_SCALAR_IMAGE_2D_UINT8		2020L+2
#define KS_SCALAR_IMAGE_2D_INT16		2020L+3
#define KS_SCALAR_IMAGE_2D_INT32		2020L+4
#define KS_SCALAR_IMAGE_2D_FLOAT		2020L+5
#define KS_SCALAR_IMAGE_2D_DOUBLE		2020L+6
#define KS_SCALAR_IMAGE_2D_RGB			2020L+7
#define KS_SCALAR_IMAGE_2D_COMPLEX		2020L+8

#define KS_COLOR_IMAGE					2100L

#define KS_COLOR_IMAGE_2D				2110L

#define KS_RGB_IMAGE_2D					2120L
#define KS_RGB_INDEX_IMAGE_2D			2120L+1
#define KS_CMY_IMAGE_2D					2120L+2
#define KS_CMYK_IMAGE_2D				2120L+3
#define KS_HSI_IMAGE_2D					2120L+4
#define KS_HLS_IMAGE_2D					2120L+5
#define KS_YIQ_IMAGE_2D					2120L+6
#define KS_YUV_IMAGE_2D					2120L+7
#define KS_YCbCr_IMAGE_2D				2120L+8

#define KS_COMPLEX_IMAGE				2200L

#define KS_COMPLEX_IMAGE_2D				2210L

#define KS_COMPLEX_IMAGE_2D_FLOAT		2220L
#define KS_COMPLEX_IMAGE_2D_DOUBLE		2220L+1

#define KS_HISTOGRAM					10000L

#define KS_HISTOGRAM_1D					10010L
#define KS_HISTOGRAM_1D_GENERAL			10010L+1
#define KS_HISTOGRAM_1D_STANDARD		10010L+2

#define KS_HISTOGRAM_2D					10020L
#define KS_HISTOGRAM_2D_GENERAL			10020L+1
#define KS_HISTOGRAM_2D_STANDARD		10020L+2

#define KS_SIGNAL						20000L

#define KS_SIGNAL_UINT8					20010L        // not use
#define KS_SIGNAL_INT16					20010L+1      // not use
#define KS_SIGNAL_INT32					20010L+2      // not use
#define KS_SIGNAL_FLOAT					20010L+3
#define KS_SIGNAL_DOUBLE				20010L+4      // not use

#define KS_GRAPHIC						30001L

// Sequence
#define KS_SEQUENCE                     40001L

// Sequence type
#define KS_SEQUENCE_BASE                KS_SEQUENCE           +   1

// Stream type
#define KS_STREAM                       KS_SEQUENCE         +   50
#define KS_STREAM_VIDEO                 KS_STREAM           +   50
#define KS_STREAM_AUDIO                 KS_STREAM_VIDEO     +   50
#define KS_STREAM_MIDI                  KS_STREAM_AUDIO     +   50
#define KS_STREAM_TEXT                  KS_STREAM_MIDI      +   50
#define KS_STREAM_SMELL                 KS_STREAM_TEXT      +   50
#define KS_STREAM_TASTE                 KS_STREAM_SMELL     +   50
#define KS_STREAM_VIBRATION             KS_STREAM_TASTE     +   50
#define KS_STREAM_VECTOR                KS_STREAM_VIBRATION +   50

// Each stream have 50 category
#define KS_SEQUENCE_VIDEO               KS_STREAM_VECTOR      +  50
#define KS_SEQUENCE_AUDIO               KS_SEQUENCE_VIDEO     +  50
#define KS_SEQUENCE_MIDI                KS_SEQUENCE_AUDIO     +  50
#define KS_SEQUENCE_TEXT                KS_SEQUENCE_MIDI      +  50
#define KS_SEQUENCE_SMELL               KS_SEQUENCE_TEXT      +  50
#define KS_SEQUENCE_TASTE               KS_SEQUENCE_SMELL     +  50
#define KS_SEQUENCE_VIBRATION           KS_SEQUENCE_TASTE     +  50
#define KS_SEQUENCE_VECTOR              KS_SEQUENCE_VIBRATION +  50 // vector or graphic

// Partial sequence
#define KS_SEQUENCE_BLOCK               KS_SEQUENCE_VECTOR + 50

// Partial sequence type
#define KS_SEQUENCE_BLOCK_VIDEO         KS_SEQUENCE_BLOCK           + 50
#define KS_SEQUENCE_BLOCK_AUDIO         KS_SEQUENCE_BLOCK_VIDEO     + 50
#define KS_SEQUENCE_BLOCK_MIDI          KS_SEQUENCE_BLOCK_AUDIO     + 50
#define KS_SEQUENCE_BLOCK_TEXT          KS_SEQUENCE_BLOCK_MIDI      + 50
#define KS_SEQUENCE_BLOCK_SMELL         KS_SEQUENCE_BLOCK_TEXT      + 50
#define KS_SEQUENCE_BLOCK_TASTE         KS_SEQUENCE_BLOCK_SMELL     + 50
#define KS_SEQUENCE_BLOCK_VIBRATION     KS_SEQUENCE_BLOCK_TASTE     + 50
#define KS_SEQUENCE_BLOCK_VECTOR        KS_SEQUENCE_BLOCK_VIBRATION + 50

#define KS_VIEW							90000L
#define KS_VIEW_IMAGE					90010L
#define KS_VIEW_PROFILE					90020L
#define KS_VIEW_PROFILE_2D				90020L+1
#define KS_VIEW_PROFILE_3D				90020L+2
#define KS_VIEW_HISTOGRAM				90030L
#define KS_VIEW_HISTOGRAM_2D			90030L+1
#define KS_VIEW_HISTOGRAM_3D			90030L+2
#define KS_VIEW_VALUE					90040L
#define KS_VIEW_SIGNAL					90050L

#define IPL								100000L
#define IPL_IMAGE						100000L+1
#define IPL_ROI							100000L+2
#define IPL_TILE_INFO					100000L+3
#define IPL_NOISE_PARAM					100000L+4
#define IPL_COLOR_TWIST					100000L+5
#define IPL_CONV_KERNEL					100000L+6
#define IPL_CONV_KERNEL_FP				100000L+7
#define IPL_MOMENT_STATE				100000L+8
#define IPL_LIB_VERSION					101000L+9

#define IPL_CONV_KERNEL_DP				100100L+1
#define IPL_CONV_KERNEL_FP_DP			100100L+2
#define IPL_LUT_DP						100100L+3

#define IPL_ERROR_CALLBACK				110000L+1
#define IPL_USER_FUNCTION				110000L+2
#define IPL_USER_FUNCTION_PIXEL			110000L+3

#define IPL_STATUS						KS_INT32V

// Windows API Type
#define API_TYPE						200000L
#define API_BITMAPINFOHEADER			200000L+1
#define PACKED_DIB                      API_BITMAPINFOHEADER

#endif
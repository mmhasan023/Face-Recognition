
////////////////////////////////////////////////////////////////
// Intel image processing library 지원 
//
//                                 20010326 대일
////////////////////////////////////////////////////////////////

#ifndef __IPL_H__
#define __IPL_H__

typedef struct _IplROI {
    int             coi;
    int             xOffset;
    int             yOffset;
    int             width;
    int             height;
} IplROI;


typedef struct _IplTileInfo {
//    IplCallBack     callBack;         /* callback function                  */
	void			*pCallBack;

    void           *id;               /* additional identification field    */
    char           *tileData;         /* pointer on tile data               */
    int             width;            /* width of tile                      */
    int             height;           /* height of tile                     */
} IplTileInfo;

typedef struct _IplImage {
    int             nSize;              /* size of iplImage struct         */
    int             ID;                 /* version                         */
    int             nChannels;
    int             alphaChannel;
    int             depth;              /* pixel depth in bits             */
    char            colorModel[4];
    char            channelSeq[4];
    int             dataOrder;
    int             origin;
    int             align;              /* 4 or 8 byte align               */
    int             width;
    int             height;
    struct _IplROI *roi;
    struct _IplImage
                   *maskROI;            /* poiner to maskROI if any        */
    void           *imageId;            /* use of the application          */
    struct
      _IplTileInfo *tileInfo;           /* contains information on tiling  */
    int             imageSize;          /* useful size in bytes            */
    char           *imageData;          /* pointer to aligned image        */
    int             widthStep;          /* size of aligned line in bytes   */
    int             BorderMode[4];      /*                                 */
    int             BorderConst[4];     /*                                 */
    char           *imageDataOrigin;    /* ptr to full, nonaligned image   */
} IplImage;


#endif




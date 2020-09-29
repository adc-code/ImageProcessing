#ifndef __DIP_IMAGEVIEWERCTRL_H__
#define __DIP_IMAGEVIEWERCTRL_H__


#include "DIP_MappingFunction.h"


class DIP_Image;
class DIP_ImageViewer;


class DIP_ImageViewerCtrl
{
    public:

        static  bool  PerformGreyLevelTransformation  ( DIP_ImageViewer *         pImgViewer,
                                                        DIP_Image *&              oResultImg,
                                                        DIP_MAPPING_FUNCTIONTYPE  iType );

        static  bool  PerformGreyLevelTransformation  ( DIP_ImageViewer *         pImgViewer,
                                                        DIP_Image *&              oResultImg,
                                                        DIP_MAPPING_FUNCTIONTYPE  iType,
                                                        vector<double>            iParameters );

        static  bool  PerformHistogramEqualization   ( DIP_ImageViewer *  pImgViewer,
                                                       DIP_Image *&       oResultImg );

        static  bool  PerformHistogramShift          ( DIP_ImageViewer *  pImgViewer,
                                                       DIP_Image *&       oResultImg,
                                                       int                iAmount );

        static  bool  PerformHistogramStretch        ( DIP_ImageViewer *  pImgViewer,
                                                       DIP_Image *&       oResultImg,
                                                       unsigned int       iNewLowerValue,
                                                       unsigned int       iNewUpperValue );

        static  bool  PerformScaleTransformation     ( DIP_ImageViewer *    pImgViewer,
                                                       DIP_Image *&         oResultImg,
                                                       unsigned int         iNewWidth,
                                                       unsigned int         iNewHeight,
                                                       DIP_IMGSCALING_TYPE  iScalingMethod );

        static  bool  PerformMeanFilter              ( DIP_ImageViewer *        pImgViewer,
                                                       DIP_Image *&             oResultImg,
                                                       DIP_MEANFILTER_TYPE      iMeanType,
                                                       unsigned int             iWindowWidth,
                                                       unsigned int             iWindowHeight,
                                                       DIP_IMAGEBORDER_STRATEGY iBorderStrategy,
                                                       double                   iQValue = 0.0 );

        static  bool  PerformOrderStatFilter         ( DIP_ImageViewer *          pImgViewer,
                                                       DIP_Image *&               oResultImg,
                                                       DIP_ORDEREDSTATFILTER_TYPE iOrderStatType,
                                                       unsigned int               iWindowWidth,
                                                       unsigned int               iWindowHeight,
                                                       DIP_IMAGEBORDER_STRATEGY   iBorderStrategy,
                                                       double                     iDValue );

        static  bool  PerformWeightedSumFilter       ( DIP_ImageViewer *          pImgViewer,
                                                       DIP_Image *&               oResultImg,
                                                       DIP_WEIGHTEDSUMFILTER_TYPE iWeightSumType,
                                                       unsigned int               iWindowWidth,
                                                       unsigned int               iWindowHeight,
                                                       DIP_IMAGEBORDER_STRATEGY   iBorderStrategy );

        static  bool  PerformSharpeningFilter        ( DIP_ImageViewer *          pImgViewer,
                                                       DIP_Image *&               oResultImg,
                                                       unsigned int               iWindowWidth,
                                                       unsigned int               iWindowHeight,
                                                       DIP_IMAGEBORDER_STRATEGY   iBorderStrategy,
                                                       double                     iAValue );

        static  bool  PerformFrequencyFilter         ( DIP_ImageViewer *          pImgViewer,
                                                       DIP_Image *&               oResultImg,
                                                       DIP_FREQFILTER_TYPE        iFilterType,
                                                       double                     iCutOffFreq,
                                                       int                        iNValue );

};


#endif//__DIP_IMAGEVIEWERCTRL_H__



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image_ProcessUtils
//
// Various utilities to process images
// 
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_Image.h"
#include "DIP_MappingFunction.h"
#include "DIP_Neighbourhood.h"


#ifndef __DIP_IMAGE_PROCESSUTILS_H__
#define __DIP_IMAGE_PROCESSUTILS_H__



class DIP_Image_ProcessUtils
{
     public:

         //
         // ApplyGreyLevelTransformation
         //    Used to perform grey level transformations on the input image based on the specified
         //    math function.  Output is in a separate image
         //
         static  bool   ApplyGreyLevelTransformation  ( DIP_Image *          iInputImage,
                                                        DIP_Image *&         oOutputImage,
                                                        DIP_MappingFunction  iMathFunction );

         //
         // ApplyChangeBitsPerPixel
         //
         static  bool   ApplyChangeBitsPerPixel       ( DIP_Image *                iInputImage,
                                                        DIP_Image *&               oOutputImage,
                                                        DIP_IMAGE_BPP              iNewBPP, 
                                                        DIP_GREYLEVELCONVERT_TYPE  iType=BPPCONVERT_SIMPLE );
 
         //
         // ApplyHistogramEqualization
         //
         static  bool   ApplyHistogramEqualization    ( DIP_Image *   iInputImage,
                                                        DIP_Image *&  oOutputImage );

         //
         // ApplyHistogramShift
         //
         static  bool   ApplyHistogramShift           ( DIP_Image *   iInputImage,
                                                        DIP_Image *&  oOutputImage,
                                                        int           iAmount );

         //
         // ApplyHistogramStretch
         //
         static  bool   ApplyHistogramStretch         ( DIP_Image *   iInputImage,
                                                        DIP_Image *&  oOutputImage,
                                                        unsigned int  iNewLowerValue,
                                                        unsigned int  iNewUpperValue );


         //
         // ScaleImage
         //
         static  bool  ApplyScaleTransformation       ( DIP_Image *          iInputImage,
                                                        DIP_Image *&         oOutputImage,
                                                        unsigned int         iNewWidth,
                                                        unsigned int         iNewHeight,
                                                        DIP_IMGSCALING_TYPE  iScalingMethod ); 

         //
         // ApplyMeanFilter
         //
         static  bool   ApplyMeanFilter               ( DIP_Image *              iInputImage,
                                                        DIP_Image *&             oOutputImage,
                                                        DIP_MEANFILTER_TYPE      iMeanType,
                                                        unsigned int             iWindowWidth,
                                                        unsigned int             iWindowHeight,
                                                        DIP_IMAGEBORDER_STRATEGY iBorderStrategy,
                                                        double                   iQ = 0.0 );


         //
         // ApplyOrderedStatFilter
         //
         static  bool   ApplyOrderedStatFilter        ( DIP_Image *                 iInputImage,
                                                        DIP_Image *&                oOutputImage,
                                                        DIP_ORDEREDSTATFILTER_TYPE  iOrderStatType,
                                                        unsigned int                iWindowWidth,
                                                        unsigned int                iWindowHeight,
                                                        DIP_IMAGEBORDER_STRATEGY    iBorderStrategy,
                                                        double                      iD = 0.0 );


         //
         //
         //
         static  bool   ApplyWeightedSumFilter        ( DIP_Image *                 iInputImage,
                                                        DIP_Image *&                oOutputImage,
                                                        DIP_WEIGHTEDSUMFILTER_TYPE  iWeightedSumType,
                                                        unsigned int                iWindowWidth,
                                                        unsigned int                iWindowHeight,
                                                        DIP_IMAGEBORDER_STRATEGY    iBorderStrategy,
                                                        vector<double>              iParameters );


         //
         // ApplySharpenFilter
         //
         static  bool  ApplySharpenFilter             ( DIP_Image *                 iInputImage,
                                                        DIP_Image *&                oOutputImage,
                                                        unsigned int                iWindowWidth,
                                                        unsigned int                iWindowHeight,
                                                        DIP_IMAGEBORDER_STRATEGY    iBorderStrategy,
                                                        double                      iAValue = 1.0 );
     
         //
         // ApplyFreqDomainFilter
         //
         static  bool  ApplyFreqDomainFilter          ( DIP_Image *                 iInputImage,
                                                        DIP_Image *&                oOutputImage,
                                                        DIP_FREQFILTER_TYPE         iType,
                                                        double                      iCutOffPercent,
                                                        int                         iNValue = 1.0 );

    
     private:

         //
         // Since this is a utility class make this private; user is to call functions directly
         //
         DIP_Image_ProcessUtils ();

 
         //
         // For neighbourhood based processing
         //        
         static  bool  PerformNeighbourhoodBasedFiltering  ( DIP_Image *          iInputImage, 
                                                             DIP_Image *&         oOutputImage,
                                                             DIP_Neighbourhood *  iNeighbourhood );

};


#endif//__DIP_IMAGE_PROCESSUTILS_H__



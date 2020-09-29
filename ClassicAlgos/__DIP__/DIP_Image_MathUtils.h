////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image_MathUtils.h
//
// Class that contains various mathematical utilities that operate on images
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_AbstractImage.h"
#include "DIP_Image.h"


#ifndef __DIP_IMAGE_MATHUTILS_H__
#define __DIP_IMAGE_MATHUTILS_H__



enum DIP_SCALEVALUES_METHOD
{
    SCALE_SIMPLE,
    SCALE_ACCURATE
};



class DIP_Image_MathUtils
{
    public:
	
        static  bool  ArePixelsWithinRange ( DIP_Image *  iImage );


        //
        // ScaleImageValues
        //
        static  bool  ScaleImageValues  ( DIP_Image *             iInputImage,
                                          DIP_Image *&            oOutputImage,
                                          DIP_SCALEVALUES_METHOD  iScaleMethod );

        static  bool  ScaleImageValues  ( DIP_Image *             iInputImage,
                                          DIP_SCALEVALUES_METHOD  iScaleMethod );



        // 
        // Subract 
        //   iImage1 : minuend   iImage2 : subtrahend   iImage3 : difference
        static  bool  SubtractImage     ( DIP_Image *   iMinuend_Image,
                                          DIP_Image *   iSubtrahend_Image,
                                          DIP_Image *&  oDifference_Image );



        //
        // Frequency space realted utilities
        //
/*        static  bool  ComputeFreqSpaceFromImg ( DIP_Image *             iInputImage,
                                                DIP_IMAGE_CHANNEL       iChannelNum,
                                                DIP_Math_ComplexSet *&  oComplexSet  );

        static  bool  ComputeImgFromFreqSpace ( DIP_Math_ComplexSet *   iComplexSet, 
                                                DIP_Image *&            oOutputImage );


        static  bool  MakeImgFromFreqSpace    ( DIP_Math_ComplexSet *   iComplexSet,
                                                DIP_FREQSPACE_DISPLAY   iType,
                                                DIP_Image *&            oOutputImage );
*/


    protected:

        DIP_Image_MathUtils ();

};



#endif//__DIP_IMAGE_MATHUTILS_H__




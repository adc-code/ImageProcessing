////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image_Utils.h
//
// Various utilities used to deal with various image types... that is converting between different
// image types.
// 
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image.h"
#include "DIP_ComplexImage.h"
#include "DIP_RealImage.h"


#ifndef __DIP_IMAGE_UTILS_H__
#define __DIP_IMAGE_UTILS_H__


//
// The following constant is purely used to scale the real, imaginary, and magnitude results from
// the frequency space to increase the contrast of the generated image.  There are two things to
// note: first, the generated image of the frequency space is purely for understanding purposes 
// only (it is not used for further calculations).  Secondly, if necessary all the various image
// processing functions can be used on the generated image.  Also, the value is purely arbitary
// and was found by trial and error.
// 
#define  FREQ_LOG_SCALING_FACTOR    10000


enum DIP_COMPLEXCONVERT_TYPE
{
    COMPCONVERT_REAL        =  1,
    COMPCONVERT_IMAGINARY   =  2,
    COMPCONVERT_MAGNITUDE   =  3,
    COMPCONVERT_PHASE       =  4
};



class DIP_Image_Utils
{
    public:

        //
        // BuildComplexFromImage: 
        //    function used to convert a normal image to a complex image; note that the image's
        //    pixel values will be stored in the complex image's real components.  Also note that
        //    this function will allocate memory and thus it is up to the user to free it.
        //
        static  bool  BuildComplexFromImage  ( DIP_Image *         ipImage, 
                                               DIP_ComplexImage *& opComplexImage,
                                               bool                iPadImage=true, 
                                               bool                iPadExtra=true );


        //
        // BuildImageFromComplex: 
        //    function used to convert a complex image to a complex image;  Also note that this
        //    function will allocate memory and thus it is up to the user to free it.  Note that
        //    depending on iConvertType the image can be made from the real, imaginary, magnitude
        //    or the phase of the values of complex image.
        //
        static  bool  BuildImageFromComplex  ( DIP_ComplexImage *      ipComplexImage, 
                                               DIP_Image *&            opImage,
                                               DIP_COMPLEXCONVERT_TYPE iConvertType,
                                               bool                    iTakeLogTransform );


        //
        // BuildRealFromComplex:
        //    function used to convert a complex image to a real image;  Also note that
        //    this function will allocate memory and thus it is up to the user to free it.  Also
        //    depending on iConvertType the image can be made from the real, imaginary, magnitude
        //    or the phase of the values of complex image.
        //
        static  bool  BuildRealFromComplex   ( DIP_ComplexImage *      ipComplexImage, 
                                               DIP_RealImage *&        opRealImage,
                                               DIP_COMPLEXCONVERT_TYPE iConvertType );


};


#endif//__DIP_IMAGE_UTILS_H__




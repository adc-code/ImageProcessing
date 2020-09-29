////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image 
//
// Class used to manage and store a 'normal' image. 
//
// Note that this class is used as a basis for three different image types, as shown in the 
// diagram:
//
//                          +------------+
//                          |  Abstract  |
//                          |   Image    |
//                          +-----+------+
//                                |
//               +----------------+----------------+
//               |                |                |
//          +----+----+     +-----+----+     +-----+-----+
//          |  Real   |     |   Image  |     |  Complex  |
//          |  Image  |     |          |     |   Image   |
//          +---------+     +----------+     +-----------+
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_AbstractImage.h"
#include "DIP_Defs.h"
#include "DIP_Histogram.h"
#include "DIP_Image_Mask.h"


#ifndef __DIP_IMAGE_H__
#define __DIP_IMAGE_H__


class DIP_Image : public virtual DIP_AbstractImage <DIP_PIXEL_TYPE>
{
    public:

        DIP_Image ( unsigned int iWidth, unsigned int iHeight, 
                    DIP_IMAGE_TYPE iType=GREY, DIP_IMAGE_BPP iBPP=BPP_8_BIT );
        DIP_Image ( const DIP_Image & iImage );
       ~DIP_Image ();


        // Gets the number of bits pre pixel (BPP)
        unsigned int    GetBPP           ();

        // Gets the maximum value a pixel can have.  Note that the lowest value is zero.
        unsigned int    GetMaxPixelValue ();

        // Get the number of values that a pixel can have; mathematically this is the max pixel
        // value plus one, however instead of having code is multiple places, this function is
        // to make the code cleaner.
        unsigned int    GetNumValues     ();

       
        //
        // Pixel accessor functions  
        // Note that the get/set functions have been overloaded to be used for accessing pixel data 
        // when different number of channels are present.
        //
        bool  SetPixel  (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE iGreyValue );
        bool  SetPixel  (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE iRedValue, 
                                                           DIP_PIXEL_TYPE iGreenValue, 
                                                           DIP_PIXEL_TYPE iBlueValue );
        bool  SetPixel  (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE iRedValue, 
                                                           DIP_PIXEL_TYPE iGreenValue, 
                                                           DIP_PIXEL_TYPE iBlueValue, 
                                                           DIP_PIXEL_TYPE iAlphaValue );

        bool  GetPixel  (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE & oGreyValue );
        bool  GetPixel  (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE & oRedValue, 
                                                           DIP_PIXEL_TYPE & oGreenValue, 
                                                           DIP_PIXEL_TYPE & oBlueValue );
        bool  GetPixel  (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE & oRedValue, 
                                                           DIP_PIXEL_TYPE & oGreenValue, 
                                                           DIP_PIXEL_TYPE & oBlueValue, 
                                                           DIP_PIXEL_TYPE & oAlphaValue );


        //
        // Basic pixel value information...
        //
        bool  FindMaxValue      ( DIP_IMAGE_CHANNEL iChannelNum, DIP_PIXEL_TYPE & oMaxValue );
        bool  FindMinValue      ( DIP_IMAGE_CHANNEL iChannelNum, DIP_PIXEL_TYPE & oMinValue );
        bool  ComputeHistogram  ( DIP_IMAGE_CHANNEL iChannelNum, DIP_Histogram & oHistogram );

        bool  GetSubImage       ( unsigned int iXpos,  unsigned int iYpos,
                                  unsigned int iWidth, unsigned int idHeight,
                                  DIP_Image *& oNewImage );
 

        //
        // Mask related
        //
        bool  SetMask  (DIP_Image_Mask * pMask);
        void  UseMask  (bool iEnable);


    protected:


    private:

        DIP_Image ();

        DIP_IMAGE_BPP     _BPP;

        bool              _bEnableMask;
        DIP_Image_Mask *  _pMask;


    // Friend classes... 
    //   -> Allow certain classes access to the pixel data for different types of processing.  
    //      Note that the convention used is that all friend classes do not modify the current
    //      image data, but rather create a new image instance for the appropriate output.
    //
    friend class  DIP_Image_MathUtils;
    friend class  DIP_Image_ProcessUtils;
    friend class  DIP_Neighbourhood;


};



#endif//__DIP_IMAGE_H__



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage 
//
// Abstract lass used to manage and store an 'image'.  Note that the DIP refers to Digitial Image 
// Processing, this is also used to  make the name different than what is presented in other 
// programming environments (for example CImage or CImg).  Also, the term image is used to represent
// a 2D set of data, which could be either integer, real, or complex values.
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


#ifndef __DIP_ABSTRACTIMAGE_H__
#define __DIP_ABSTRACTIMAGE_H__


#include "DIP_Defs.h"


#include <vector>
using namespace std;


//
// Used to verify that the buffer offset is valid... make the code neater and easier to follow
//
#define  VALID_OFFSET(X)     ( (X) >= 0 ? true : false )


template <class _TYPE_>
class DIP_AbstractImage
{
    public:

        //
        // DIP_AbstractImage constructor and destructor...
        DIP_AbstractImage (unsigned int iWidth, unsigned int iHeight, DIP_IMAGE_TYPE iType = GREY );
        DIP_AbstractImage (const DIP_AbstractImage & iAbsractImage);
        virtual ~DIP_AbstractImage (); 

        // TODO  = operator

        // Image information dimensional information
        unsigned int    GetWidth      ();
        unsigned int    GetHeight     ();
        DIP_IMAGE_TYPE  GetImageType  ();

        virtual bool    FindMinValue  ( _TYPE_ & oMinValue );
        virtual bool    FindMaxValue  ( _TYPE_ & oMaxValue );


        //
        // Basic data accessibility
        // 
        bool  GetValue  ( unsigned int iX, unsigned int iY, DIP_IMAGE_CHANNEL iChannelNum,
                                                            _TYPE_ &  oPixelValue );
        bool  SetValue  ( unsigned int iX, unsigned int iY, DIP_IMAGE_CHANNEL iChannelNum,
                                                            const _TYPE_ &  iPixelValue );


        bool  ScaleImageValuesToRange ( _TYPE_ iMinValue, _TYPE_ iMaxValue );



    protected:

        // 
        // Note: Default constructor is private so that images are created with a width
        // and height (and values for BPP and number of channels)
        //
        // DIP_AbstractImage ();


        //
        // FindPixelOffset: Important function used to find the pixel position in the buffer
        //     inputs -> x and y position of the pixel (note: valid values are 0 to width-1 or height-1) 
        //     output -> position in the buffer; note returns -1 upon error (values out of range)
        // 
        int   FindPixelOffset  ( unsigned int iX, unsigned int iY );


        //
        // FindPixelCoord: Opposite of FindPixelOffset... from the pixel offset find the 
        // x and y coordinates
        //
        bool  FindPixelCoord   ( int iPixelOffset, unsigned int & oX, unsigned int & oY );


        //
        // IsChannelValid: Utility function to check if it is possible to use a certain channel
        //
        bool  IsChannelValid  ( DIP_IMAGE_CHANNEL iChannelNum );


        //
        // Various data elements
        //        
        unsigned int        _nWidth;
        unsigned int        _nHeight;
        DIP_IMAGE_TYPE      _ImgType;

        _TYPE_ **           _PixelData;
        int                 _nBufferSize;


    // friends:


        friend class DIP_Image;
        friend class DIP_RealImage;
        friend class DIP_ComplexImage;
        friend class DIP_Image_Utils;

};


#endif //__DIP_ABSTRACTIMAGE_H__




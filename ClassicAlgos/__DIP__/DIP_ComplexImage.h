////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_ComplexImage 
//
// Class used to manage and store an 'complex' image, that is an image where each pixel is represented
// by a complex number.  The main purpose of such an image type if for Fourier analysis.
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
#include "DIP_RealImage.h"
#include "DIP_Image.h"
#include "DIP_Defs.h"


#ifndef __DIP_COMPLEXIMAGE_H__
#define __DIP_COMPLEXIMAGE_H__


#define  FFT_FORWARD   true
#define  FFT_INVERSE   false


class DIP_ComplexImage :  public virtual DIP_AbstractImage <DIP_COMPLEXPIXEL_TYPE>
{
    public:

        //
        // Constructors and destructor
        //
        DIP_ComplexImage ( unsigned int iWidth, unsigned int iHeight, DIP_IMAGE_TYPE iType=GREY );
        DIP_ComplexImage ( const DIP_ComplexImage & iImage );
       ~DIP_ComplexImage ();


        //
        // Get the various elements of the complex image as a real image, where the value of each 
        // real pixel directly corresponds to its complex pixel counterpart.  Note that the values
        // of the real and imaginary functions can be any real number, the magnitude components are
        // strictly positive values, while the phase values are bound to the range of -2Pi to +2Pi. 
        //
        bool  GetRealComponents       ( DIP_RealImage *& oRealImage );
        bool  GetImaginaryComponents  ( DIP_RealImage *& oRealImage );
        bool  GetMagnitude            ( DIP_RealImage *& oRealImage );
        bool  GetPhase                ( DIP_RealImage *& oRealImage );


        //
        // Fourier transform related functions to convert to/from the frequency space.  Note that
        // the complex image needs to be built with the correct dimensions (i.e. of size 2^n), and
        // the FFT algorithm does not do any padding on its own.
        //
        bool  ComputeForwardFFT  ( bool iShiftOrigin=true );
        bool  ComputeInverseFFT  ( bool iShiftOrigin=true );
        void  DoOriginShiftMult  ();

        
        //
        // Used to apply a filter function to a complex image.  Note that this function simply
        // multiplies the complex image by a transfer function.  Hence, for this to filter the
        // data correctly, it needs to be in the frequency domain.
        // 
        void ApplyFilterFunction  ( DIP_FREQFILTER_TYPE iType, double iCutoffLimit, int iNValue );


    protected:
  
        //
        // Used to compute the Fourier transform.  The public methods should be used instead of
        // these.
        //
        void  Compute1DFFT    ( vector <DIP_COMPLEXPIXEL_TYPE> & complexData, unsigned int iSize,
                                      int iLog2n, bool iFFTDirection );
        void  Compute2DFFT    ( bool iFFTDirection );
        int   FFT_ReverseBits ( unsigned int index, int size );


    private:

        DIP_ComplexImage ();

};


#endif//__DIP_COMPLEXIMAGE_H__




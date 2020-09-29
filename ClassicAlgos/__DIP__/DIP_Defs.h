////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Defs.h
//
// Various defines used by the various DIP classes... 
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <complex>


#ifndef __DIP_DEFS_H__
#define __DIP_DEFS_H__


//
// Currently define the pixel type as an integer.  This is being done for two reasons: 
// 1. Images that we might use may have more than 8 bits per pixel and the standard int supports this.
// 2. When performing certain operations (such as image subtraction) it is possible to have negative
//    values, so instead of temporily storing them or losing them, the int will allow to keep them.
//
#define  DIP_PIXEL_TYPE         int
#define  DIP_REALPIXEL_TYPE     double
#define  DIP_COMPLEXPIXEL_TYPE  complex<double>



//
// Used to index various channels
//
enum DIP_IMAGE_CHANNEL
{
    GREY_CHANNEL  = 0,
    RED_CHANNEL   = 0,
    GREEN_CHANNEL = 1,
    BLUE_CHANNEL  = 2,
    ALPHA_CHANNEL = 3
};



//
// Used to identify the type of image being used (grey scale, rgb colour, rgb colour + alpha).  The
// value of each entry in the number of channels (or the amount of data elements that are stored). 
//
enum DIP_IMAGE_TYPE
{
    GREY = 1,   
    RGB  = 3,
    RGBA = 4
};



//
// Enumeration used for the number of bits per pixel (BPP) that are possible in the image.  Note
// perhaps using an enum is too much implementation, but shall only allow 16 distinct values.  When
// the image is created (that is in the constructor), we do not want to allow the user to create
// an invalid image since constructors don't (usually) return values.  Also to note that for colour
// images each component has the same number of bits.
//
enum DIP_IMAGE_BPP
{
    BPP_1_BIT  =  1,
    BPP_2_BIT  =  2,
    BPP_3_BIT  =  3,
    BPP_4_BIT  =  4,
    BPP_5_BIT  =  5,
    BPP_6_BIT  =  6,
    BPP_7_BIT  =  7,
    BPP_8_BIT  =  8,
    BPP_9_BIT  =  9,
    BPP_10_BIT = 10,
    BPP_11_BIT = 11,
    BPP_12_BIT = 12,
    BPP_13_BIT = 13,
    BPP_14_BIT = 14,
    BPP_15_BIT = 15,
    BPP_16_BIT = 16
};



//
// DIP_MATH_EPS : epsilon value 
//
#define DIP_MATH_EPS   0.000001



//
// Types of filters
//
enum DIP_FILTER_TYPE
{
    FILTERTYPE_MEAN           = 1,
    FILTERTYPE_ORDEREDSTAT    = 2,
    FILTERTYPE_WEIGHTEDSUM    = 3,
};



//
// Types of mean filters
//
enum DIP_MEANFILTER_TYPE
{
    MEAN_ARITHMETIC      = 1,
    MEAN_GEOMETRIC       = 2,
    MEAN_HARMONIC        = 3,
    MEAN_CONTRAHARMONIC  = 4
};



//
// Types of ordered statistics based filters
//
enum DIP_ORDEREDSTATFILTER_TYPE
{
    OS_MEDIAN            = 1,
    OS_MAX               = 2,
    OS_MIN               = 3,
    OS_MIDPOINT          = 4,
    OS_ALPHATRIMMED      = 5,
    OS_ADAPTIVEMEDIAN    = 6
};



//
// Types of weighted sum filters 
//
enum DIP_WEIGHTEDSUMFILTER_TYPE
{
    WS_AVERAGE           = 1,
    WS_WEIGHTEDAVERAGE   = 2,
    WS_LAPLACIAN         = 3,
    WS_SOBEL_HORIZ       = 4,
    WS_SOBEL_VERT        = 5,
    WS_SOBEL_45_1        = 6,
    WS_SOBEL_45_2        = 7,
    WS_UNSHARP_MASK      = 8,
    WS_OTHER             = 99
};



//
// Supported scaling types
//
enum DIP_IMGSCALING_TYPE
{
    SCALING_NEAREST      = 1,
    SCALING_BILINEAR     = 2 
};



//
// Supported grey level conversion 
//
enum DIP_GREYLEVELCONVERT_TYPE
{
    BPPCONVERT_SIMPLE     = 1,
    BPPCONVERT_ADVANCED   = 2
};



//
// How the neighbourhood deals with the image border
//
enum DIP_IMAGEBORDER_STRATEGY
{
    BORDER_ZERO          = 1,
    BORDER_COPY_CURRENT  = 2,
    BORDER_COPY_NEAREST  = 3,
    BORDER_WRAP_AROUND   = 4
};



//
// Frequency based filters
//
enum DIP_FREQFILTER_TYPE
{
    FREQ_IDEAL_LP       = 1,
    FREQ_IDEAL_HP       = 2,
    FREQ_GAUSSIAN_LP    = 3,
    FREQ_GAUSSIAN_HP    = 4,
    FREQ_BUTTER_LP      = 5,
    FREQ_BUTTER_HP      = 6
};


#define DIP_MAX_HISTOGRAM_SHIFT   255


#endif//__DIP_DEFS_H__




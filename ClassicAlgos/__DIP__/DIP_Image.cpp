////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image 
//
// Class used to manage and store a 'normal' image. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_AbstractImage.h"
#include "DIP_Image.h"

#include <cmath>
#include <iostream>
using namespace std;


template class DIP_AbstractImage <DIP_PIXEL_TYPE>;


DIP_Image::DIP_Image ( unsigned int iWidth, unsigned int iHeight, 
                       DIP_IMAGE_TYPE iType, DIP_IMAGE_BPP iBPP ) 
                : DIP_AbstractImage <DIP_PIXEL_TYPE> ( iWidth, iHeight, iType )
{
    _BPP = iBPP;
    
    _bEnableMask = false;
    _pMask       = NULL;
}
 


DIP_Image::DIP_Image ( const DIP_Image & iImage )
                : DIP_AbstractImage <DIP_PIXEL_TYPE> ( iImage )
{
    _BPP = iImage._BPP;

    _bEnableMask = iImage._bEnableMask;
    _pMask       = iImage._pMask;
}



DIP_Image::~DIP_Image ()
{
}



unsigned int DIP_Image::GetBPP ()
{
    return (unsigned int) _BPP;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetMaxPixelValue
//
////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DIP_Image::GetMaxPixelValue ()
{
    return ( (1 << (unsigned int) _BPP) - 1);
}




////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetNumValues
//
////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DIP_Image::GetNumValues ()
{
    return ( (1 << (unsigned int) _BPP) );
 
}

        

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_SetPixel
//   - grey scale version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::SetPixel (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE iGreyValue)
{
    bool bState = false;

    if (_ImgType == GREY)
    {
        int nOffset = FindPixelOffset (iX, iY);

        if ( VALID_OFFSET (nOffset) )
        {
            _PixelData [GREY_CHANNEL][nOffset] = iGreyValue;

            bState = true;
        }
    }

    return bState;
}
 


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_SetPixel
//   - RGB version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::SetPixel ( unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE iRedValue, 
                                                             DIP_PIXEL_TYPE iGreenValue, 
                                                             DIP_PIXEL_TYPE iBlueValue )
{
    bool bState = false;

    if (_ImgType == RGB)
    {
        int nOffset = FindPixelOffset (iX, iY);

        if ( VALID_OFFSET (nOffset) )
        {
            _PixelData [RED_CHANNEL][nOffset]   = iRedValue;
            _PixelData [GREEN_CHANNEL][nOffset] = iGreenValue;
            _PixelData [BLUE_CHANNEL][nOffset]  = iBlueValue;

            bState = true;
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_SetPixel
//   - RGBA version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::SetPixel ( unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE iRedValue, 
                                                             DIP_PIXEL_TYPE iGreenValue, 
                                                             DIP_PIXEL_TYPE iBlueValue,
                                                             DIP_PIXEL_TYPE iAlphaValue )
{
    bool bState = false;

    if (_ImgType == RGBA)
    {
        int nOffset = FindPixelOffset (iX, iY);

        if ( VALID_OFFSET (nOffset) )
        {
            _PixelData [RED_CHANNEL][nOffset]   = iRedValue;
            _PixelData [GREEN_CHANNEL][nOffset] = iGreenValue;
            _PixelData [BLUE_CHANNEL][nOffset]  = iBlueValue;
            _PixelData [ALPHA_CHANNEL][nOffset] = iAlphaValue;

            bState = true;
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_GetPixel
//   - grey scale version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::GetPixel (unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE & oGreyValue)
{
    bool bState = false;

    if (_ImgType == GREY)
    {
        int nOffset = FindPixelOffset (iX, iY);

        if ( VALID_OFFSET (nOffset) )
        {
            oGreyValue = _PixelData [GREY_CHANNEL][nOffset];

            bState = true;
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_GetPixel
//   - RGB version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::GetPixel ( unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE & oRedValue, 
                                                             DIP_PIXEL_TYPE & oGreenValue, 
                                                             DIP_PIXEL_TYPE & oBlueValue )
{
    bool bState = false;

    if (_ImgType == RGB)
    {
        int nOffset = FindPixelOffset (iX, iY);

        if ( VALID_OFFSET (nOffset) )
        {
            oRedValue   = _PixelData [RED_CHANNEL][nOffset];
            oGreenValue = _PixelData [GREEN_CHANNEL][nOffset];
            oBlueValue  = _PixelData [BLUE_CHANNEL][nOffset];

            bState = true;
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// DIP_SetPixel
//   - RGBA version
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::GetPixel ( unsigned int iX, unsigned int iY, DIP_PIXEL_TYPE & oRedValue, 
                                                             DIP_PIXEL_TYPE & oGreenValue, 
                                                             DIP_PIXEL_TYPE & oBlueValue, 
                                                             DIP_PIXEL_TYPE & oAlphaValue )
{
    bool bState = false;

    if (_ImgType == RGBA)
    {
        int nOffset = FindPixelOffset (iX, iY);

        if ( VALID_OFFSET (nOffset) )
        {
            oRedValue   = _PixelData [RED_CHANNEL][nOffset];
            oGreenValue = _PixelData [GREEN_CHANNEL][nOffset];
            oBlueValue  = _PixelData [BLUE_CHANNEL][nOffset];
            oAlphaValue = _PixelData [ALPHA_CHANNEL][nOffset];

            bState = true;
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetPixel
//
////////////////////////////////////////////////////////////////////////////////////////////////////
// bool DIP_Image::GetPixel ( unsigned int iX, unsigned int iY, DIP_IMAGE_CHANNEL iChannelNum, 
//                                                              DIP_PIXEL_TYPE &  oPixelValue )
// {
//     bool bState = false;
// 
//     if ( IsChannelValid (iChannelNum) )
 //    {
//         int nOffset = FindPixelOffset (iX, iY);
//        
//         if ( VALID_OFFSET (nOffset) )
//         {
//             oPixelValue = _PixelData [ iChannelNum ][ nOffset ];
// 
//             bState = true; 
//         }
//     }
// 
//     return bState;   
// }



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SetPixel
//
////////////////////////////////////////////////////////////////////////////////////////////////////
// bool DIP_Image::SetPixel ( unsigned int iX, unsigned int iY, DIP_IMAGE_CHANNEL iChannelNum, 
//                                                              DIP_PIXEL_TYPE    iPixelValue )
// {
//     bool bState = false;
// 
//     if ( IsChannelValid (iChannelNum) )
//     {
//         int nOffset = FindPixelOffset (iX, iY);
//        
//         if ( VALID_OFFSET (nOffset) )
//         {
//             _PixelData [ iChannelNum ][ nOffset ] = iPixelValue;
// 
//             bState = true; 
//         }
//     }
// 
//     return bState;   
// }



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeHistogram
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::ComputeHistogram ( DIP_IMAGE_CHANNEL iChannelNum, DIP_Histogram & oHistogram )
{
    bool bState = false;

    if ( IsChannelValid (iChannelNum) )
    {
        oHistogram = DIP_Histogram ( GetNumValues() );

        for (int i = 0; i < _nBufferSize; i++)
        {
            oHistogram.IncrementValue ( _PixelData [iChannelNum][i] );
        }

        bState = true;
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// FindMaxValue
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::FindMaxValue ( DIP_IMAGE_CHANNEL iChannelNum, DIP_PIXEL_TYPE & oMaxValue )
{
    bool bRetVal = false;

    if ( IsChannelValid (iChannelNum) )
    {
        // Init with a small value
        DIP_PIXEL_TYPE nMaxValue = -1 * GetMaxPixelValue ();

        for (int j = 0; j < _nBufferSize; j++)
        {   
            if ( _PixelData [ iChannelNum ][ j ] > nMaxValue )
            {
                 nMaxValue = _PixelData [ iChannelNum ][ j ];
                 bRetVal   = true;
            }
        }

        if ( bRetVal ) 
            oMaxValue = nMaxValue;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// FindMinValue
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::FindMinValue ( DIP_IMAGE_CHANNEL iChannelNum, DIP_PIXEL_TYPE & oMinValue )
{
    bool bRetVal = false;

    if ( IsChannelValid (iChannelNum) )
    {
        // Init with a large value
        DIP_PIXEL_TYPE nMinValue = GetMaxPixelValue ();

        for (int j = 0; j < _nBufferSize; j++)
        {  
            if ( _PixelData [ iChannelNum ][ j ] < nMinValue )
            {
                 nMinValue = _PixelData [ iChannelNum ][ j ];
                 bRetVal   = true;
            }
        }

        if ( bRetVal ) 
            oMinValue = nMinValue;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetSubImage
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::GetSubImage ( unsigned int iXpos,  unsigned int iYpos,
                              unsigned int iWidth, unsigned int iHeight,
                              DIP_Image *& oNewImage )
{
    bool bRetVal = false;

    // First check to see if iXpos and iYpos are within the limits 
    if ( iXpos < _nWidth && iYpos < _nHeight ) 
    {
        // also check that the required width and height are within limits as well
        unsigned int nMaxWidth  = _nWidth  - iXpos;
        unsigned int nMaxHeight = _nHeight - iYpos;
       
        if ( iWidth <= nMaxWidth && iHeight <= _nHeight )
        {
            if ( oNewImage )
                delete oNewImage;

            oNewImage = new DIP_Image ( iWidth, iHeight, _ImgType, _BPP );

            if ( oNewImage )
            {
                for ( unsigned int j = 0; j < iHeight; j++ )
                {
                    for ( unsigned int i = 0; i < iWidth; i++ )
                    {
                        if ( _ImgType == GREY )
                        {
                            DIP_PIXEL_TYPE greyPixelValue;
                            GetPixel ( i+iXpos, j+iYpos, greyPixelValue );

                            oNewImage -> SetPixel ( i, j, greyPixelValue );
                        }
                        else if ( _ImgType == RGB )
                        {
                            DIP_PIXEL_TYPE redPixelValue;
                            DIP_PIXEL_TYPE greenPixelValue;
                            DIP_PIXEL_TYPE bluePixelValue;
                            GetPixel ( i+iXpos, j+iYpos, redPixelValue, 
                                                         greenPixelValue, 
                                                         bluePixelValue );

                            oNewImage -> SetPixel ( i, j, redPixelValue, 
                                                          greenPixelValue, 
                                                          bluePixelValue );
                        }
                        else if ( _ImgType == RGBA )
                        {
                            DIP_PIXEL_TYPE redPixelValue;
                            DIP_PIXEL_TYPE greenPixelValue;
                            DIP_PIXEL_TYPE bluePixelValue;
                            DIP_PIXEL_TYPE alphaPixelValue;
                            GetPixel ( i+iXpos, j+iYpos, redPixelValue, 
                                                         greenPixelValue, 
                                                         bluePixelValue, 
                                                         alphaPixelValue );

                            oNewImage -> SetPixel ( i, j, redPixelValue, 
                                                          greenPixelValue, 
                                                          bluePixelValue, 
                                                          alphaPixelValue );
                        }

                    } // for i

                } // for j

                bRetVal = true;                

            } // if oNewImage was created
        }
    } 

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SetMask
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image::SetMask (DIP_Image_Mask * pMask)
{
    bool bOK = false;

    if (pMask)
    {
        _pMask = pMask;
        bOK    = true;
    }

    return bOK;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// UseMask
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DIP_Image::UseMask (bool iEnable)
{
    _bEnableMask = iEnable;
}




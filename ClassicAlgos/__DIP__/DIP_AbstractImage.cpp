////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Implementation of class DIP_AbstractImage
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_AbstractImage.h"

#include <cmath>
#include <cstddef>   


//#ifdef __DEBUGGING_OUTPUT__
#include <iostream>
using namespace std;
//#endif



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage constructor
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
DIP_AbstractImage <_TYPE_>::DIP_AbstractImage ( unsigned int   iWidth, 
                                                unsigned int   iHeight, 
                                                DIP_IMAGE_TYPE iType ) 
{
    _nWidth  = iWidth;
    _nHeight = iHeight;
    _ImgType = iType;

    if (_nWidth == 0 || _nHeight == 0)
    {
        // If either the height and/or width are zero, the object shall be still constructed
        // however nothing should work.
        _PixelData = NULL;
    }
    else
    {
        _PixelData = new _TYPE_ * [ _ImgType ];

        // Compute the buffer size once.
        _nBufferSize = _nWidth * _nHeight;
      
        for (int i = 0; i < _ImgType; i++)
        {
            _PixelData [i] = new _TYPE_ [ _nBufferSize ];
        }
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage copy constructor...
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
DIP_AbstractImage <_TYPE_>::DIP_AbstractImage (const DIP_AbstractImage & iImage)
{
    _nWidth  = iImage._nWidth;
    _nHeight = iImage._nHeight;
    _ImgType = iImage._ImgType;
   
    _nBufferSize = iImage._nBufferSize;

    if (_nBufferSize == 0)
    {
        _PixelData = NULL;
    }
    else
    {
        _PixelData = new _TYPE_ * [ _ImgType ];
       
        for (int i = 0; i < _ImgType; i++)
        {
            _PixelData [i] = new _TYPE_ [ _nBufferSize ];

            for (int j = 0; j < _nBufferSize; j++)
            {
                _PixelData [i][j] = iImage._PixelData [i][j];
            }             
        }
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage destructor...
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
DIP_AbstractImage <_TYPE_>::~DIP_AbstractImage ()
{
    for (int i = 0; i < _ImgType; i++)
    {
        delete [] _PixelData [i];
    }

    delete [] _PixelData;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::FindPixelOffset
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
int DIP_AbstractImage <_TYPE_>::FindPixelOffset (unsigned int iX, unsigned int iY)
{
    int nOffset = -1;

    if (iX < _nWidth && iY < _nHeight)
    {
        nOffset = iX + (iY * _nWidth);
    }

    return nOffset;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::FindPixelCoord
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::FindPixelCoord (int iPixelOffset, unsigned int & oX, unsigned int & oY)
{
    bool bOK = false; 

    unsigned int nY = (unsigned int) (iPixelOffset / _nWidth);

    if (nY < _nHeight)
    {
        oX  = iPixelOffset % _nWidth;
        oY  = nY;

        bOK = true;
    }

    return bOK;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::GetWidth 
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
unsigned int DIP_AbstractImage <_TYPE_>::GetWidth ()
{
    return _nWidth;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::GetHeight
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
unsigned int DIP_AbstractImage <_TYPE_>::GetHeight ()
{
    return _nHeight;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::GetImageType
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
DIP_IMAGE_TYPE DIP_AbstractImage <_TYPE_>::GetImageType ()
{
    return _ImgType;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::GetValue
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::GetValue ( unsigned int iX, unsigned int iY, 
                                            DIP_IMAGE_CHANNEL iChannelNum,
                                            _TYPE_ &  oPixelValue )
{
    bool bState = false;

    if ( IsChannelValid (iChannelNum) )
    {
        int nOffset = FindPixelOffset (iX, iY);
       
        if ( VALID_OFFSET (nOffset) )
        {
            oPixelValue = _PixelData [ iChannelNum ][ nOffset ];

            bState = true; 
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_AbstractImage::SetValue
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::SetValue ( unsigned int iX, unsigned int iY, 
                                            DIP_IMAGE_CHANNEL iChannelNum,
                                            const _TYPE_ &  iPixelValue )
{
    bool bState = false;

    if ( IsChannelValid (iChannelNum) )
    {
        int nOffset = FindPixelOffset (iX, iY);
       
        if ( VALID_OFFSET (nOffset) )
        {
            _PixelData [ iChannelNum ][ nOffset ] = iPixelValue;

            bState = true; 
        }
    }

    return bState;
}




////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetSubImage
//
////////////////////////////////////////////////////////////////////////////////////////////////////
/*template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::GetSubImage ( unsigned int iXpos,  unsigned int iYpos,
                                      unsigned int iWidth, unsigned int iHeight,
                                      DIP_AbstractImage *& oNewImage )
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

            oNewImage = new DIP_AbstractImage ( iWidth, iHeight, _ImgType );

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
*/


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetChannelData
//
////////////////////////////////////////////////////////////////////////////////////////////////////
/*template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::GetChannelData ( DIP_IMAGE_CHANNEL iChannel, DIP_AbstractImage *& oNewImage )
{
    bool bRetVal = false;

    if ( IsChannelValid (iChannel) )
    {
        if ( oNewImage )
            delete oNewImage;

        oNewImage = new DIP_AbstractImage <_TYPE_> ( _nWidth, _nHeight );

        if ( oNewImage )
        {
            for (int j = 0; j < _nBufferSize; j++)
            {
                oNewImage -> _PixelData [ iChannel ][ j ] = _PixelData [ iChannel ][ j ];
            }             

            bRetVal = true;
        }
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SetChannelData
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::SetChannelData ( DIP_IMAGE_CHANNEL iChannelNum, DIP_AbstractImage * iImage )
{
    bool bRetVal = false;

    if ( iImage && IsChannelValid (iChannelNum) )
    {
        if ( (iImage -> GetWidth () == _nWidth) && (iImage -> GetHeight () == _nHeight) )
        {
            for (int j = 0; j < _nBufferSize; j++)
            {
                _PixelData [ iChannelNum ][ j ] = iImage -> _PixelData [ 0 ][ j ];
            }

            bRetVal = true;
        }
    } 

    return bRetVal;
} */



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// IsChannelValid
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::IsChannelValid ( DIP_IMAGE_CHANNEL iChannelNum )
{
    bool bValidChannel = false;

    if ( iChannelNum == GREY_CHANNEL && _ImgType == GREY )
    {
        bValidChannel = true; 
    }
    else if ( iChannelNum == RED_CHANNEL && (_ImgType == RGB || _ImgType == RGBA) )
    {
        bValidChannel = true; 
    }
    else if ( iChannelNum == GREEN_CHANNEL && (_ImgType == RGB || _ImgType == RGBA) )
    {
        bValidChannel = true; 
    }
    else if ( iChannelNum == BLUE_CHANNEL && (_ImgType == RGB || _ImgType == RGBA) )
    {
        bValidChannel = true; 
    }
    else if ( iChannelNum == ALPHA_CHANNEL && (_ImgType == RGBA) )
    {
        bValidChannel = true; 
    }

    return bValidChannel;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SetChannelData
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::FindMinValue ( _TYPE_ & oMinValue )
{   
    return false;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SetChannelData
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::FindMaxValue ( _TYPE_ & oMaxValue )
{
    return false;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ScaleImageValuesToRange
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class _TYPE_>
bool DIP_AbstractImage <_TYPE_>::ScaleImageValuesToRange ( _TYPE_ iMinValue, _TYPE_ iMaxValue )
{
    return false;
}



template class DIP_AbstractImage <DIP_PIXEL_TYPE>;
template class DIP_AbstractImage <DIP_REALPIXEL_TYPE>;
template class DIP_AbstractImage <DIP_COMPLEXPIXEL_TYPE>;




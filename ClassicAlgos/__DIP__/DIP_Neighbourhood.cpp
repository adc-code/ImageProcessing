////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Neighbourhood.cpp
//
// Class used to manage the pixels in a specific neighbourhood around a pixel.  Note that this
// is primarily used during the filtering process.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Filter.h"
#include "DIP_Filter_Mean.h"
#include "DIP_Filter_OrderedStat.h"
#include "DIP_Filter_WeightedSum.h"
#include "DIP_Neighbourhood.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;


// just to make the code a little cleaner and easier to read
#define  X  1
#define  Y  2
#define  LEFT_OF_IMAGE(X)      ( (X) == -1 ? true : false )
#define  WITHIN_IMAGE(X)       ( (X) ==  0 ? true : false )
#define  RIGHT_OF_IMAGE(X)     ( (X) ==  1 ? true : false )
#define  ABOVE_IMAGE(X)        ( (X) == -1 ? true : false )
#define  WITHIN_IMAGE(X)       ( (X) ==  0 ? true : false )
#define  BELOW_IMAGE(X)        ( (X) ==  1 ? true : false )



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_Neighbourhood::DIP_Neighbourhood ( DIP_Image *               iParentImage,
                                       unsigned int              iWidth, 
                                       unsigned int              iHeight, 
                                       DIP_FILTER_TYPE           iType,
                                       int                       iFilterSubType,
                                       vector<double> &          iFilterParameters,
                                       DIP_IMAGEBORDER_STRATEGY  iBorderStrategy )
{
    _pParentImage        = iParentImage;
    _pFilter             = NULL;
    _NeighbourhoodPixels = NULL;

    // Currently only allow neighbourhoods that are symmetric about the pixel.  That requires them
    // to have an odd amount of pixels.
    if ( (_pParentImage != NULL) && 
         (iWidth > 0) && (iWidth % 2 == 1) && (iHeight > 0) && (iHeight % 2 == 1) )
    {
        _nWindowWidth    = iWidth;
        _nWindowHeight   = iHeight;

        _nRegionWidth    = iWidth;
        _nRegionHeight   = iHeight;

        _BorderStrategy  = iBorderStrategy;
        _FilterType      = iType;

        _nCurrentX       = 0;
        _nCurrentY       = 0;
        _nNumberOfPixels = _nRegionWidth * _nRegionHeight;

        // make 1, 3 or 4 vectors based on the number of channels present in image
        _NeighbourhoodPixels = new vector <DIP_PIXEL_TYPE> [ _pParentImage -> _ImgType ];

        InitializePosition ();

        if ( _FilterType == FILTERTYPE_MEAN )
        {
            double dQValue = 0.0;
            if (iFilterParameters.size () > 0)
                dQValue = iFilterParameters [0];

            _pFilter = new DIP_Filter_Mean ( this, (DIP_MEANFILTER_TYPE) iFilterSubType, dQValue );
        }
        else if ( _FilterType == FILTERTYPE_ORDEREDSTAT )
        {
            // Depending on the subtype of the filter, the parameter can be the 'd' value or the 
            // max number of iterations, S_max.

            double dParam = 0.0;
            if (iFilterParameters.size () > 0)
                dParam = iFilterParameters [0];

            _pFilter = new DIP_Filter_OrderedStat ( this, (DIP_ORDEREDSTATFILTER_TYPE) iFilterSubType, dParam );
        }
        else if ( _FilterType == FILTERTYPE_WEIGHTEDSUM )
        {
            _pFilter = new DIP_Filter_WeightedSum ( this, (DIP_WEIGHTEDSUMFILTER_TYPE) iFilterSubType, 
                                                    iFilterParameters );
        }
    }
    else
    {
        // Initialize the various values to -1 so that they can be checked if the neighboourhood
        // is valid.

        _nWindowWidth    = -1;
        _nWindowHeight   = -1;

        _nRegionWidth    = -1;
        _nRegionHeight   = -1;

        _nCurrentX       = -1;
        _nCurrentY       = -1;
        _nNumberOfPixels = -1;
    }  

}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Destructor
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_Neighbourhood::~DIP_Neighbourhood ()
{
    if (_pFilter)
        delete _pFilter;

    if (_NeighbourhoodPixels)
        delete [] _NeighbourhoodPixels;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Neighbourhood::InitializePosition ( unsigned int iX, unsigned int iY )
{
    bool bRetVal = false;

    // Check various values to make sure we don't have problems
    if ( _pParentImage != NULL &&  
         _nRegionWidth > 0 && _nRegionHeight > 0 &&
         iX < _pParentImage -> _nWidth && iY < _pParentImage -> _nHeight )
    {
        int nMaxChannel = _pParentImage -> _ImgType;
        if (_pParentImage -> _ImgType == RGBA)
            nMaxChannel = RGB;

        for (int channel = 0; channel < nMaxChannel; channel++)
            _NeighbourhoodPixels [ channel ].clear ();

        int nXDelta = (_nRegionWidth >> 1);
        int nYDelta = (_nRegionHeight >> 1);

        for (int j = -nYDelta; j <= nYDelta; j++)
        {
            for (int i = -nXDelta; i <= nXDelta; i++)
            {
                DIP_PIXEL_TYPE nPixelValue = 0;

                int nNeighbourhoodX = (int) iX + i;
                int nNeighbourhoodY = (int) iY + j;
              
                int nPixelOffset = _pParentImage -> FindPixelOffset ( nNeighbourhoodX, nNeighbourhoodY );

                for (int channel = 0; channel < nMaxChannel; channel++)
                {
                    if ( VALID_OFFSET (nPixelOffset) )
                    {
                        // pixel is in the image... ok
                        nPixelValue = _pParentImage -> _PixelData [ channel ][ nPixelOffset ];
                    }
                    else
                    {
                       // pixel is not in the image... use border strategy
                       if (_BorderStrategy == BORDER_ZERO)
                       {
                           nPixelValue = 0;
                       }
                       else if (_BorderStrategy == BORDER_COPY_CURRENT)
                       {
                           // Get the current pixel value
                           nPixelOffset = _pParentImage -> FindPixelOffset ( iX, iY );
                           nPixelValue  = _pParentImage -> _PixelData [ channel ][ nPixelOffset ];
                       }
                       else if (_BorderStrategy == BORDER_COPY_NEAREST)
                       {
                           // Get the closest pixel value
                           int nXRange = TestWithinRange ( nNeighbourhoodX, X );
                           int nYRange = TestWithinRange ( nNeighbourhoodY, Y );
   
                           if ( LEFT_OF_IMAGE (nXRange) && ABOVE_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is to the left and above then use the top-left corner
                               nPixelOffset = _pParentImage -> FindPixelOffset ( 0, 0 );
                           }
                           else if ( WITHIN_IMAGE (nXRange) && ABOVE_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is above the image then use the value from the top edge
                               nPixelOffset = _pParentImage -> FindPixelOffset ( nNeighbourhoodX, 0 );
                           }
                           else if ( RIGHT_OF_IMAGE (nXRange) && ABOVE_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is to the right and above then use the top-right corner
                               nPixelOffset = _pParentImage -> FindPixelOffset ( _pParentImage -> _nWidth - 1, 0 );
                           }
                           else if ( LEFT_OF_IMAGE (nXRange) && WITHIN_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is to the left then use the value from the left edge
                               nPixelOffset = _pParentImage -> FindPixelOffset ( 0, nNeighbourhoodY );
                           }
                           else if ( RIGHT_OF_IMAGE (nXRange) && WITHIN_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is to the right then use the value from the right edge
                               nPixelOffset = _pParentImage -> FindPixelOffset ( _pParentImage -> _nWidth - 1, 
                                                                                 nNeighbourhoodY );
                           }
                           else if ( LEFT_OF_IMAGE (nXRange) && BELOW_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is to the left and below then use the bottom-left corner
                               nPixelOffset = _pParentImage -> FindPixelOffset ( 0, _pParentImage -> _nHeight - 1 );
                           }
                           else if ( WITHIN_IMAGE (nXRange) && BELOW_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is below the image then use the value from the bottom edge
                               nPixelOffset = _pParentImage -> FindPixelOffset ( nNeighbourhoodX, 
                                                                                 _pParentImage -> _nHeight - 1 );
                           }
                           else if ( RIGHT_OF_IMAGE (nXRange) && BELOW_IMAGE (nYRange) )
                           {
                               // if neighbourhood pixel is to the right and below then use the bottom-right corner
                               nPixelOffset = _pParentImage -> FindPixelOffset ( _pParentImage -> _nWidth - 1, 
                                                                                 _pParentImage -> _nHeight - 1 );
                           }

                           nPixelValue  = _pParentImage -> _PixelData [ channel ][ nPixelOffset ];
                       }
                       else if (_BorderStrategy == BORDER_WRAP_AROUND)
                       {
                           // Either add or subtract the width/height if the value is less/greater than the range
                           int nXRange = TestWithinRange ( nNeighbourhoodX, X );
                           int nYRange = TestWithinRange ( nNeighbourhoodY, Y );
                           
                           if ( LEFT_OF_IMAGE (nXRange) )
                               nNeighbourhoodX += _pParentImage -> _nWidth;
                           else if ( RIGHT_OF_IMAGE (nXRange) )
                               nNeighbourhoodX -= _pParentImage -> _nWidth;

                           if ( ABOVE_IMAGE (nYRange) )
                               nNeighbourhoodY += _pParentImage -> _nHeight;
                           else if ( BELOW_IMAGE (nYRange) )
                               nNeighbourhoodY -= _pParentImage -> _nHeight;

                           // find the new pixel value
                           nPixelOffset = _pParentImage -> FindPixelOffset ( nNeighbourhoodX, nNeighbourhoodY );
                           nPixelValue  = _pParentImage -> _PixelData [ channel ][ nPixelOffset ];
                       }
                    }

                    _NeighbourhoodPixels[ channel ].push_back ( nPixelValue );

                } // for channel   

            } // for i

        } // for j
    }   

    if (_FilterType == FILTERTYPE_ORDEREDSTAT)
    {   
        for (int channel = 0; channel < _pParentImage -> _ImgType; channel++)
            sort ( _NeighbourhoodPixels [ channel ].begin (),  _NeighbourhoodPixels [ channel ].end () );
    }
    
    /*for (int i = 0; i < _NeighbourhoodPixels[0].size (); i++)
    {
         cout << "   " << _NeighbourhoodPixels[0][i];
         if ((i+1) % _nRegionWidth == 0) cout << endl;
    }*/

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// IncrementPosition
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Neighbourhood::IncrementPosition ()
{
    bool bRetVal = false;

    _nCurrentX ++;
    if (_nCurrentX == _pParentImage -> _nWidth)
    {
        _nCurrentX = 0;
        _nCurrentY ++;
    }

    if ( _nRegionWidth != _nWindowWidth || _nRegionHeight != _nWindowHeight)
    {
        _nRegionWidth  = _nWindowWidth;
        _nRegionHeight = _nWindowHeight;

        _nNumberOfPixels = _nRegionWidth * _nRegionHeight;
    }
    
    InitializePosition ( _nCurrentX, _nCurrentY );

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Neighbourhood::ResetPosition ()
{
    bool bRetVal = false;

    _nCurrentX = 0;
    _nCurrentY = 0;
    
    InitializePosition ( _nCurrentX, _nCurrentY );

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Neighbourhood::IncrementWindowSize ()
{
    bool bRetVal = false;

    _nRegionWidth  += 2;
    _nRegionHeight += 2;

    _nNumberOfPixels = _nRegionWidth * _nRegionHeight;

    // Initialize the neighbourhood again with more pixels
    InitializePosition ( _nCurrentX, _nCurrentY );

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Neighbourhood::ComputeResults ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oPixelValue )
{
    bool bRetVal = false;

    if ( _pFilter )
    {
        bRetVal = _pFilter -> ComputeResults ( iChannel, oPixelValue );
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TestWithinRange
// -> Used to test neighbourhood pixels that are not in the image.  That is neighbourhood is close
//    to the edge.  When computing the nearest value pixel edge strategy we need to do some checks
//    to see which set of pixels values we are going to copy from.
// -> This function returns three values depending on the range:
//      -> -1 if it is less than... that is either above or to the right of the image
//      ->  0 if it is within the range... that is in the image
//      -> +1 if it is greater than... that is either below or to the left of the image
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int DIP_Neighbourhood::TestWithinRange ( int iIndexValue, int XorY )
{
    int nRangeValue = 0;

    if (XorY == 1)
    {
        if ( iIndexValue < 0 )
            nRangeValue = -1; 
        else if ( iIndexValue >= _pParentImage -> _nWidth )
            nRangeValue =  1;
    }
    else
    {
        if ( iIndexValue < 0 )
            nRangeValue = -1; 
        else if ( iIndexValue >= _pParentImage -> _nHeight )
            nRangeValue =  1;
    }

    return nRangeValue;
}





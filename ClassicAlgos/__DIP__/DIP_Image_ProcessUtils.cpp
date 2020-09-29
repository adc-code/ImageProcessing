////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image_ProcessUtils
//
// 
// 
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image_ProcessUtils.h"

#include "DIP_Defs.h"
#include "DIP_ComplexImage.h"
#include "DIP_Image_MathUtils.h"
#include "DIP_Image_Utils.h"
#include "DIP_Neighbourhood.h"

#include <cmath>
#include <iostream>
using namespace std;



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyGreyLevelTransformation
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyGreyLevelTransformation ( DIP_Image *          iInputImage,
                                                            DIP_Image *&         oOutputImage,
                                                            DIP_MappingFunction  iMappingFunction )
{
    cout << "DIP_Image_ProcessUtils::ApplyGreyLevelTransformation" << endl;
    cout << "    iInputImage -> _bEnableMask = " << iInputImage -> _bEnableMask << endl;
    cout << "    iInputImage -> _pMask       = " << iInputImage -> _pMask << endl; 

    bool bRetVal = false;

    if (iInputImage)
    {
        if (oOutputImage)
            delete oOutputImage;
        oOutputImage = new DIP_Image ( *iInputImage );

        unsigned int nNumberValues = iInputImage -> GetNumValues (); 

        if ( iMappingFunction.ComputeLUT ( nNumberValues, nNumberValues ) )
        {
            for (int x = 0; x < nNumberValues; x++)
            {
                int y=-1;
                iMappingFunction.EvaluateUsingLUT ( x, y );
            }

            int nMaxChannel = iInputImage -> _ImgType;
            if (iInputImage -> _ImgType == RGBA)
                nMaxChannel = RGB;

            for (int i = 0; i < nMaxChannel; i++)
            {
                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {
                    if ( iInputImage -> _bEnableMask )
                    {
                        if ( iInputImage -> _pMask )
                        {
                            unsigned int nX = 0;
                            unsigned int nY = 0;
                            iInputImage -> FindPixelCoord ( j, nX, nY );

                            double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY ); 

                            DIP_PIXEL_TYPE  mappedValue;
                            iMappingFunction.EvaluateUsingLUT ( iInputImage -> _PixelData [i][j], 
                                                                mappedValue );

                            oOutputImage -> _PixelData [i][j] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j] 
                                                                      + dMaskValue * mappedValue;
                        }
                    }
                    else
                    {
                        iMappingFunction.EvaluateUsingLUT ( iInputImage  -> _PixelData [i][j], 
                                                            oOutputImage -> _PixelData [i][j] );
                    }
                }
            }
            
            bRetVal = true;
        }
    }

    return bRetVal;         
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyChangeBitsPerPixel
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyChangeBitsPerPixel ( DIP_Image *                iInputImage,
                                                       DIP_Image *&               oOutputImage,
                                                       DIP_IMAGE_BPP              iNewBPP, 
                                                       DIP_GREYLEVELCONVERT_TYPE  iType )
{
    bool bRetVal = false;

    if (iInputImage)
    {
        // Currently can only down sample images
        unsigned int nCurrentBPP = iInputImage -> GetBPP ();

        if (iNewBPP < nCurrentBPP)
        {
            if (oOutputImage)
                delete oOutputImage;

            oOutputImage = new DIP_Image ( *iInputImage );

            if (iType == BPPCONVERT_SIMPLE)
            {
                bool bScaleAtEnd = true;

                unsigned int nBitShift = nCurrentBPP - iNewBPP;

                for (int i = 0; i < iInputImage -> _ImgType; i++)
                {
                    for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                    {
                        DIP_PIXEL_TYPE bitShiftedValue = iInputImage -> _PixelData [i][j] >> nBitShift;

                        if ( iInputImage -> _bEnableMask )
                        {
                            if ( iInputImage -> _pMask )
                            {
                                bScaleAtEnd = false;
                                unsigned int nX = 0;
                                unsigned int nY = 0;
                                iInputImage -> FindPixelCoord ( j, nX, nY );

                                int dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                                if (dMaskValue)
                                    oOutputImage -> _PixelData [i][j] = bitShiftedValue << nBitShift;
                                else
                                    oOutputImage -> _PixelData [i][j] = iInputImage -> _PixelData [i][j];
                            }
                        }
                        else
                        {
                            oOutputImage -> _PixelData [i][j] = bitShiftedValue;
                        }
                    }

                    bRetVal = true;
                }

                if (bScaleAtEnd)
                    DIP_Image_MathUtils::ScaleImageValues ( oOutputImage, SCALE_ACCURATE );    

            }
            else if (iType == BPPCONVERT_ADVANCED)
            {
                int bits = iNewBPP;
                int mult = 256 / ( pow (2, bits) );
                int mask = pow ( 2, (8 - bits) ) - 1;
                int prevSum = 0;
    
                for (int i = 0; i < iInputImage -> _ImgType; i++)
                {
                    for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                    {
                        int value = iInputImage -> _PixelData [ i ][ j ];
                        if (value >> iNewBPP != mask)
                            prevSum = (value + (prevSum & mask));
                        else
                            prevSum = value;
                    
                        DIP_PIXEL_TYPE bitShiftedValue = ((prevSum >> (8 - bits)) * mult) + 1;

                        if ( iInputImage -> _bEnableMask )
                        {
                            if ( iInputImage -> _pMask )
                            {
                                unsigned int nX = 0;
                                unsigned int nY = 0;
                                iInputImage -> FindPixelCoord ( j, nX, nY );

                                double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                                oOutputImage -> _PixelData [ i ][ j ] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j]
                                                                          + dMaskValue * bitShiftedValue;
                            }
                        }
                        else
                        {
                            oOutputImage -> _PixelData [ i ][ j ] = ((prevSum >> (8 - bits)) * mult) + 1;
                        }
                    }
                } 
            }  
        }

        bRetVal = true;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyHistogramEqualization
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyHistogramEqualization ( DIP_Image *   iInputImage,
                                                          DIP_Image *&  oOutputImage )
{
    bool bRetVal = false;

    if (iInputImage)
    {
        if (oOutputImage)
            delete oOutputImage;

        oOutputImage = new DIP_Image ( *iInputImage );

        // Get the max value once
        unsigned int nMaxPixelValue = iInputImage -> GetMaxPixelValue ();

        for (int i = 0; i < iInputImage -> _ImgType; i++)
        {
            DIP_Histogram histogram ( iInputImage -> GetNumValues() );

            if ( iInputImage -> ComputeHistogram ( (DIP_IMAGE_CHANNEL) i, histogram) )
            {
                vector <double> cdfValues; 
                histogram.ComputeCDF (cdfValues);

                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {
                    oOutputImage -> _PixelData [i][j] 
                             = (int) ( cdfValues [ iInputImage -> _PixelData [i][j] ] * nMaxPixelValue );
                }
            }
        } 
 
        bRetVal = true;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyHistogramShift
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyHistogramShift ( DIP_Image *   iInputImage,
                                                   DIP_Image *&  oOutputImage,
                                                   int           iAmount )
{
    bool bRetVal = false;

    if (iInputImage != NULL && abs (iAmount) < DIP_MAX_HISTOGRAM_SHIFT )
    {
        if (oOutputImage)
            delete oOutputImage;

        oOutputImage = new DIP_Image ( *iInputImage );

        DIP_PIXEL_TYPE nMaxPixelValue = iInputImage -> GetMaxPixelValue ();
        for (int i = 0; i < iInputImage -> _ImgType; i++)
        {
            for (int j = 0; j < iInputImage -> _nBufferSize; j++)
            {
                DIP_PIXEL_TYPE nValue = iInputImage -> _PixelData [i][j] + iAmount;

                if ( nValue < 0 )
                    nValue = 0;
                else if (nValue > nMaxPixelValue )
                    nValue = nMaxPixelValue;

                oOutputImage -> _PixelData [i][j] = nValue;
             }
         }

         bRetVal = true;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyHistogramStretch
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyHistogramStretch ( DIP_Image *   iInputImage,
                                                     DIP_Image *&  oOutputImage,
                                                     unsigned int  iNewLowerValue, 
                                                     unsigned int  iNewUpperValue )
{
    bool bRetVal = false;

    if (iInputImage != NULL)
    {
        DIP_PIXEL_TYPE nMaxPixelValue = iInputImage -> GetMaxPixelValue ();
        
        if (iNewLowerValue <= nMaxPixelValue && iNewUpperValue <= nMaxPixelValue)
        {  
            if (oOutputImage)
                delete oOutputImage;

            oOutputImage = new DIP_Image ( *iInputImage );

            for (int i = 0; i < iInputImage -> _ImgType; i++)
            {
                DIP_PIXEL_TYPE  minValue;
                DIP_PIXEL_TYPE  maxValue;

                iInputImage -> FindMinValue ( (DIP_IMAGE_CHANNEL) i, minValue );
                iInputImage -> FindMaxValue ( (DIP_IMAGE_CHANNEL) i, maxValue );

                if ( maxValue != minValue )
                {
                    double dRatio = (double) (iNewUpperValue - iNewLowerValue) /
                                          (double) (maxValue - minValue);

                    for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                    {
                        DIP_PIXEL_TYPE nValue = (iInputImage -> _PixelData [i][j] - minValue)
                                                  * dRatio + iNewLowerValue ;

                        if ( nValue < 0 )
                            nValue = 0;
                        else if (nValue > nMaxPixelValue )
                            nValue = nMaxPixelValue;

                        oOutputImage -> _PixelData [i][j] = nValue;
                    }
                }
             }

             bRetVal = true;
         }
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyMeanFilter
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyMeanFilter ( DIP_Image *              iInputImage, 
                                               DIP_Image *&             oOutputImage,
                                               DIP_MEANFILTER_TYPE      iMeanType,
                                               unsigned int             iWindowWidth,
                                               unsigned int             iWindowHeight,
                                               DIP_IMAGEBORDER_STRATEGY iBorderStrategy,
                                               double                   iQ )
{
    bool bRetVal = false;

    // Make the neighbourhood
    vector<double> dParameters;
    dParameters.push_back ( iQ );

    DIP_Neighbourhood * pPixelNeighbourHood = new DIP_Neighbourhood ( iInputImage, 
                                                                      iWindowWidth, 
                                                                      iWindowHeight,
                                                                      FILTERTYPE_MEAN, 
                                                                      iMeanType,
                                                                      dParameters,
                                                                      iBorderStrategy );

    // Perform the processing
    bRetVal = PerformNeighbourhoodBasedFiltering ( iInputImage, oOutputImage, pPixelNeighbourHood );

    if ( iInputImage -> _bEnableMask )
    {
        if ( iInputImage -> _pMask )
        {
            for (int i = 0; i < iInputImage -> _ImgType; i++)
            {
                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {
                    unsigned int nX = 0;
                    unsigned int nY = 0;
                    iInputImage -> FindPixelCoord ( j, nX, nY );

                    double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                    oOutputImage -> _PixelData [ i ][ j ] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j]
                                                                          + dMaskValue * oOutputImage -> _PixelData [ i ][ j ];
                 }
             }
         }
    }

    if ( pPixelNeighbourHood )
        delete pPixelNeighbourHood;

    //DIP_Image_MathUtils::ScaleImageValues ( oOutputImage, SCALE_ACCURATE );

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyOrderStatisticsFilter
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyOrderedStatFilter ( DIP_Image *                 iInputImage,
                                                      DIP_Image *&                oOutputImage,
                                                      DIP_ORDEREDSTATFILTER_TYPE  iOrderedStatType,
                                                      unsigned int                iWindowWidth,
                                                      unsigned int                iWindowHeight,
                                                      DIP_IMAGEBORDER_STRATEGY    iBorderStrategy,
                                                      double                      iD )
{
    bool bRetVal = false;

    // Make the neighbourhood
    vector<double> dParameters;
    dParameters.push_back ( iD );

    DIP_Neighbourhood * pPixelNeighbourHood = new DIP_Neighbourhood ( iInputImage, 
                                                                      iWindowWidth, 
                                                                      iWindowHeight,
                                                                      FILTERTYPE_ORDEREDSTAT, 
                                                                      iOrderedStatType,
                                                                      dParameters,
                                                                      iBorderStrategy );

    // Perform the processing
    bRetVal = PerformNeighbourhoodBasedFiltering ( iInputImage, oOutputImage, pPixelNeighbourHood );

    if ( iInputImage -> _bEnableMask )
    {
        if ( iInputImage -> _pMask )
        {
            for (int i = 0; i < iInputImage -> _ImgType; i++)
            {
                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {
                    unsigned int nX = 0;
                    unsigned int nY = 0;
                    iInputImage -> FindPixelCoord ( j, nX, nY );

                    double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                    oOutputImage -> _PixelData [ i ][ j ] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j]
                                                                          + dMaskValue * oOutputImage -> _PixelData [ i ][ j ];
                 }
             }
         }
    }

    if ( pPixelNeighbourHood )
        delete pPixelNeighbourHood;

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyWeightSumFilter
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyWeightedSumFilter ( DIP_Image *                 iInputImage,
                                                      DIP_Image *&                oOutputImage,
                                                      DIP_WEIGHTEDSUMFILTER_TYPE  iWeightedSumType,
                                                      unsigned int                iWindowWidth,
                                                      unsigned int                iWindowHeight,
                                                      DIP_IMAGEBORDER_STRATEGY    iBorderStrategy,
                                                      vector<double>              iParameters )
{
    cout << "DIP_Image_ProcessUtils::ApplyWeightedSumFilter" << endl;

    bool bRetVal = false;

    // Make the neighbourhood
    DIP_Neighbourhood * pPixelNeighbourHood = new DIP_Neighbourhood ( iInputImage, 
                                                                      iWindowWidth, 
                                                                      iWindowHeight,
                                                                      FILTERTYPE_WEIGHTEDSUM, 
                                                                      iWeightedSumType,
                                                                      iParameters,
                                                                      iBorderStrategy );

    cout << "   pPixelNeighbourHood = " << pPixelNeighbourHood << endl;

    // Perform the processing
    bRetVal = PerformNeighbourhoodBasedFiltering ( iInputImage, oOutputImage, pPixelNeighbourHood );

    // Rescale if necessary
    if ( iWeightedSumType == WS_LAPLACIAN  || iWeightedSumType == WS_SOBEL_HORIZ || 
         iWeightedSumType == WS_SOBEL_VERT || iWeightedSumType == WS_SOBEL_45_1  ||
         iWeightedSumType == WS_SOBEL_45_2 || iWeightedSumType == WS_UNSHARP_MASK )
    {
        DIP_Image_MathUtils::ScaleImageValues ( oOutputImage, SCALE_ACCURATE );    
    }

    if ( iInputImage -> _bEnableMask )
    {
        if ( iInputImage -> _pMask )
        {
            for (int i = 0; i < iInputImage -> _ImgType; i++)
            {
                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {
                    unsigned int nX = 0;
                    unsigned int nY = 0;
                    iInputImage -> FindPixelCoord ( j, nX, nY );

                    double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                    oOutputImage -> _PixelData [ i ][ j ] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j]
                                                                          + dMaskValue * oOutputImage -> _PixelData [ i ][ j ];
                 }
             }
         }
    }

    if ( pPixelNeighbourHood )
        delete pPixelNeighbourHood;

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplySharpenFilter
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplySharpenFilter ( DIP_Image *               iInputImage,
                                                  DIP_Image *&              oOutputImage,
                                                  unsigned int              iWindowWidth,
                                                  unsigned int              iWindowHeight,
                                                  DIP_IMAGEBORDER_STRATEGY  iBorderStrategy,
                                                  double                    iAValue )
{
    bool bRetVal = false;

    if (iInputImage)
    {
        if (oOutputImage)
            delete oOutputImage;

        oOutputImage = new DIP_Image ( *iInputImage );

        // Make the neighbourhood
        vector<double> dParameters;
        DIP_Neighbourhood * pPixelNeighbourHood = new DIP_Neighbourhood ( iInputImage, 
                                                                          iWindowWidth, 
                                                                          iWindowHeight,
                                                                          FILTERTYPE_WEIGHTEDSUM,
                                                                          WS_AVERAGE,
                                                                          dParameters,
                                                                          iBorderStrategy );

        // Perform the processing
        DIP_Image * pBlurredImg = NULL;
        bRetVal = PerformNeighbourhoodBasedFiltering ( iInputImage, pBlurredImg, pPixelNeighbourHood );

        unsigned int nMaxValue = iInputImage -> GetMaxPixelValue ();
        for (int i = 0; i < iInputImage -> _ImgType; i++)
        {
            for (int j = 0; j < iInputImage -> _nBufferSize; j++)
            {
                DIP_PIXEL_TYPE nTempValue = iInputImage -> _PixelData [i][j] - pBlurredImg -> _PixelData [i][j];
                if (nTempValue < 0 ) nTempValue = 0;
                if (nTempValue > nMaxValue) nTempValue = nMaxValue;

                nTempValue = iAValue * (iInputImage -> _PixelData [i][j]) + nTempValue;
                if (nTempValue < 0 ) nTempValue = 0;
                if (nTempValue > nMaxValue) nTempValue = nMaxValue;

                oOutputImage -> _PixelData [i][j] = nTempValue;
            }
        } 
     
        if ( iInputImage -> _bEnableMask )
        {
            if ( iInputImage -> _pMask )
            {
                for (int i = 0; i < iInputImage -> _ImgType; i++)
                {
                    for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                    {
                        unsigned int nX = 0;
                        unsigned int nY = 0;
                        iInputImage -> FindPixelCoord ( j, nX, nY );

                        double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                        oOutputImage -> _PixelData [ i ][ j ] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j]
                                                                              + dMaskValue * oOutputImage -> _PixelData [ i ][ j ];
                    }
                }
            }
        }

        if ( pBlurredImg )
            delete pBlurredImg;

        if ( pPixelNeighbourHood )
            delete pPixelNeighbourHood;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// PerformNeighbourhoodBasedFiltering
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::PerformNeighbourhoodBasedFiltering ( DIP_Image *        iInputImage, 
                                                                  DIP_Image *&       oOutputImage,
                                                                  DIP_Neighbourhood* iNeighbourhood )
{ 
    bool bRetVal = false;

    if ( iInputImage && iNeighbourhood )
    {
        // Make an output image... note the old one is erased first
        if (oOutputImage)
            delete oOutputImage;
        oOutputImage = new DIP_Image ( *iInputImage );

        int nMaxChannel = iInputImage -> _ImgType;
        if (iInputImage -> _ImgType == RGBA)
            nMaxChannel = RGB;

        DIP_PIXEL_TYPE  pixelValue = 0;
        for (int i = 0; i < nMaxChannel; i++)
        {
            iNeighbourhood -> ResetPosition ();

            for (int j = 0; j < iInputImage -> _nBufferSize; j++)
            {
                if (iNeighbourhood -> ComputeResults ( (DIP_IMAGE_CHANNEL)i, pixelValue))
                {
                    oOutputImage -> _PixelData [i][j] = pixelValue; 
                }

                iNeighbourhood -> IncrementPosition ();
            }
  
            bRetVal = true;
        }
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyScaleTransformation
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyScaleTransformation ( DIP_Image *          iInputImage,
                                                        DIP_Image *&         oOutputImage,
                                                        unsigned int         iNewWidth,
                                                        unsigned int         iNewHeight,
                                                        DIP_IMGSCALING_TYPE  iScalingMethod )
{
    bool bRetVal = false;

    if (iInputImage)
    {
        if ( iScalingMethod == SCALING_NEAREST )
        {
             if (oOutputImage)
                 delete oOutputImage;

             oOutputImage = new DIP_Image ( iNewWidth, iNewHeight, iInputImage -> _ImgType,
                                            iInputImage -> _BPP );

             double dXRatio = iInputImage -> _nWidth / (double) iNewWidth;
             double dYRatio = iInputImage -> _nHeight / (double) iNewHeight;

             for ( unsigned int j = 0; j < iNewHeight; j++ )
             {
                 for ( unsigned int i = 0; i < iNewWidth; i++ )
                 {
                     unsigned int nOldXPixel = floor ( i * dXRatio );
                     unsigned int nOldYPixel = floor ( j * dYRatio );
 
                     int nNewPixelOffset = oOutputImage -> FindPixelOffset ( i, j );
                     int nOldPixelOffset = iInputImage -> FindPixelOffset ( nOldXPixel, nOldYPixel );

                     if ( VALID_OFFSET (nNewPixelOffset) && VALID_OFFSET (nOldPixelOffset) )
                     {
                         for ( int c = 0; c < iInputImage -> _ImgType; c++ ) 
                         {
                             oOutputImage -> _PixelData [ c ][ nNewPixelOffset ] = 
                                             iInputImage -> _PixelData [ c ][ nOldPixelOffset ];
                         }

                         bRetVal = true;
                     }
                 }
             }
        }
        else if ( iScalingMethod == SCALING_BILINEAR )
        {
             if (oOutputImage)
                 delete oOutputImage;

             oOutputImage = new DIP_Image ( iNewWidth, iNewHeight, iInputImage -> _ImgType, 
                                            iInputImage -> _BPP );

             double dXRatio = (iInputImage -> _nWidth - 1) / (double) iNewWidth;
             double dYRatio = (iInputImage -> _nHeight - 1) / (double) iNewHeight;

             for ( unsigned int j = 0; j < iNewHeight; j++ )
             {
                 for ( unsigned int i = 0; i < iNewWidth; i++ )
                 {
                     unsigned int nOldXPixel = (int)( i * dXRatio );
                     unsigned int nOldYPixel = (int)( j * dYRatio );

                     double dDeltaX = ( i * dXRatio ) - nOldXPixel;
                     double dDeltaY = ( j * dYRatio ) - nOldYPixel;

                     int nNewPixelOffset = oOutputImage -> FindPixelOffset ( i, j );
                     int nOldPixelOffset = iInputImage -> FindPixelOffset ( nOldXPixel, nOldYPixel );

                     if ( VALID_OFFSET (nNewPixelOffset) && VALID_OFFSET (nOldPixelOffset) )
                     {
                         for ( int c = 0; c < iInputImage -> _ImgType; c++ ) 
                         {
                             oOutputImage -> _PixelData [ c ][ nNewPixelOffset ] = 
                                    iInputImage -> _PixelData [ c ][ nOldPixelOffset ] * (1 - dDeltaX) * (1 - dDeltaY) +
                                    iInputImage -> _PixelData [ c ][ nOldPixelOffset+1 ] * dDeltaX * (1 - dDeltaY) +
                                    iInputImage -> _PixelData [ c ][ nOldPixelOffset+iInputImage -> _nWidth ] * (1 - dDeltaX) * dDeltaY +
                                    iInputImage -> _PixelData [ c ][ nOldPixelOffset+iInputImage -> _nWidth+1 ] * dDeltaX * dDeltaY;
                         }
                     
                         bRetVal = true;
                     }
                }
            }
        }
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ApplyFreqDomainFilter
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_ProcessUtils::ApplyFreqDomainFilter ( DIP_Image *         iInputImage,
                                                     DIP_Image *&        oOutputImage,
                                                     DIP_FREQFILTER_TYPE iFilterType,
                                                     double              iCutOffPercent,
                                                     int                 iNValue )
{
    bool bRetVal = false;

    if (iInputImage)
    {
        // Make an output image... note the old one (if it exists) is erased first
        if (oOutputImage)
            delete oOutputImage;
        oOutputImage = new DIP_Image ( *iInputImage );

        DIP_ComplexImage * pComplexImage = NULL;
        DIP_Image_Utils::BuildComplexFromImage ( iInputImage, pComplexImage ); 

        if ( pComplexImage )
        {
            pComplexImage -> ComputeForwardFFT ();
            pComplexImage -> ApplyFilterFunction ( iFilterType, iCutOffPercent, iNValue );
            pComplexImage -> ComputeInverseFFT ();
             
            DIP_Image * pFilteredImage = NULL;
            DIP_Image_Utils::BuildImageFromComplex ( pComplexImage, pFilteredImage, COMPCONVERT_REAL, false );
            //DIP_Image_Utils::BuildImageFromComplex ( pComplexImage, pFilteredImage, COMPCONVERT_MAGNITUDE, false );

            pFilteredImage -> ScaleImageValuesToRange ( 0, iInputImage -> GetMaxPixelValue() );

            pFilteredImage -> GetSubImage ( 0, 0, iInputImage -> GetWidth (), iInputImage -> GetHeight (), 
                                            oOutputImage );

            delete pFilteredImage;
            delete pComplexImage;

            bRetVal = true;
        }

        if ( iInputImage -> _bEnableMask )
        {
            if ( iInputImage -> _pMask )
            {
                for (int i = 0; i < iInputImage -> _ImgType; i++)
                {
                    for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                    {
                        unsigned int nX = 0;
                        unsigned int nY = 0;
                        iInputImage -> FindPixelCoord ( j, nX, nY );
 
                        double dMaskValue = iInputImage -> _pMask -> TestPointValue ( nX, nY );

                        oOutputImage -> _PixelData [ i ][ j ] = (1.0 - dMaskValue) * iInputImage -> _PixelData [i][j]
                                                                          + dMaskValue * oOutputImage -> _PixelData [ i ][ j ];
                     }
                 }
             }
         }

//        if (bRetVal)
  //          DIP_Image_MathUtils::ScaleImageValues ( oOutputImage, SCALE_ACCURATE );
    }    

    return bRetVal;
}




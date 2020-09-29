////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image_MathUtils.cpp
//
// Class that contains various mathematical utilities that operate on images
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image.h"
#include "DIP_Image_MathUtils.h"
//#include "DIP_Math_ComplexNum.h"
#include "DIP_Math_Utils.h"

#include <cmath>
#include <iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ScaleImageValues
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_MathUtils::ScaleImageValues ( DIP_Image *             iInputImage,
                                             DIP_Image *&            oOutputImage,
                                             DIP_SCALEVALUES_METHOD  iScaleMethod )
{
    bool bResults = false;

    if (iInputImage)
    {
        if (oOutputImage)
            delete oOutputImage;
        oOutputImage = new DIP_Image ( *iInputImage );

        bResults = ScaleImageValues ( oOutputImage, iScaleMethod );
    }

    return bResults;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ScaleImageValues
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_MathUtils::ScaleImageValues ( DIP_Image *             iInputImage,
                                             DIP_SCALEVALUES_METHOD  iScaleMethod )
{
    bool bResults = false;

    if ( iInputImage )
    {
        if ( iScaleMethod == SCALE_SIMPLE )
        {
            unsigned int nMaxPixelValue = iInputImage -> GetMaxPixelValue ();
            //cout << "@@@  nMaxPixelValue = " << nMaxPixelValue << endl;

            for (int i = 0; i < iInputImage -> _ImgType; i++)
            {
                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {  
                    iInputImage -> _PixelData [ i ][ j ] += nMaxPixelValue;
                    iInputImage -> _PixelData [ i ][ j ] /= 2;
                }
            }

            bResults = true;
        }
        else if ( iScaleMethod == SCALE_ACCURATE )
        {
            for (int i = 0; i < iInputImage -> _ImgType; i++)
            {
                DIP_PIXEL_TYPE minValue;
                iInputImage -> FindMinValue ( (DIP_IMAGE_CHANNEL) i, minValue );
                minValue = abs (minValue);

                for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                {   
                    //cout << " calc = " << iInputImage -> _PixelData [ i ][ j ];
                    iInputImage -> _PixelData [ i ][ j ] += minValue;
                    //cout << " mod = " << iInputImage -> _PixelData [ i ][ j ] << endl;
                }

                DIP_PIXEL_TYPE maxValue;
                iInputImage -> FindMaxValue ( (DIP_IMAGE_CHANNEL) i, maxValue );
                unsigned int nMaxPixelValue = iInputImage -> GetMaxPixelValue ();
                if ( maxValue != 0 )
                {
                    for (int j = 0; j < iInputImage -> _nBufferSize; j++)
                    {   
                        iInputImage -> _PixelData [ i ][ j ] *= ( (double) nMaxPixelValue / 
                                                                  (double) maxValue );
                    }
                }
            }

            bResults = true;
        }
    }

    return bResults;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
//
// ArePixelsWithinRange
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_MathUtils::ArePixelsWithinRange ( DIP_Image * iImage )
{
    cout << "### ArePixelsWithinRange ";
    bool bRetVal = false;

    if ( iImage )
    {
        bool bBelowRange = false;
        for (int i = 0; i < iImage -> _ImgType; i++)
        {
            DIP_PIXEL_TYPE pixelValue;
            if ( iImage -> FindMinValue ((DIP_IMAGE_CHANNEL) i, pixelValue) )
            {
                if (pixelValue < 0)
                {
                    cout << "  below range!!!   ";
                    bBelowRange = true;
                    break;
                }
            }     
        }

        bool bAboveRange = false;
        for (int i = 0; i < iImage -> _ImgType; i++)
        {
            DIP_PIXEL_TYPE pixelValue;
            if (iImage -> FindMaxValue ((DIP_IMAGE_CHANNEL) i, pixelValue) )
            {        
                if (pixelValue > iImage -> GetMaxPixelValue())
                {  
                    cout << "   above range!!!  "; 
                    bAboveRange = true;
                    break;
                } 
            }
        }

        if (!bBelowRange && !bAboveRange)
        {
            cout << "   setting to true";
            bRetVal = true;
        }
    }
    cout << "   " << bRetVal << endl;

    return bRetVal;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
//
// SubtractImage
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_MathUtils::SubtractImage ( DIP_Image *   iMinuend_Image,
                                          DIP_Image *   iSubtrahend_Image,
                                          DIP_Image *&  oDifference_Image )
{
    bool bRetVal = false;

    if ( iMinuend_Image != NULL && iSubtrahend_Image != NULL )
    {
        // Check to see if the images are of the same size and type
        if ( iMinuend_Image -> _nWidth  == iSubtrahend_Image -> _nWidth  &&
             iMinuend_Image -> _nHeight == iSubtrahend_Image -> _nHeight && 
             iMinuend_Image -> _BPP     == iSubtrahend_Image -> _BPP     &&
             iMinuend_Image -> _ImgType == iSubtrahend_Image -> _ImgType )
        {
            if (oDifference_Image)
                delete oDifference_Image;
            oDifference_Image = new DIP_Image ( *iMinuend_Image );

            for (int i = 0; i < iMinuend_Image -> _ImgType; i++)
            {
                for (int j = 0; j < iMinuend_Image -> _nBufferSize; j++)
                {
                    oDifference_Image -> _PixelData [ i ][ j ] = 
                       iMinuend_Image -> _PixelData [ i ][ j ] - iSubtrahend_Image -> _PixelData [ i ][ j ];
                }
            }

            bRetVal = true;
        }
    }

    return bRetVal;
}



/* bool DIP_Image_MathUtils::ComputeFreqSpaceFromImg ( DIP_Image *             iInputImage,
                                                    DIP_IMAGE_CHANNEL       iChannelNum,
                                                    DIP_Math_ComplexSet *&  oComplexSet  )
{
    bool bRetVal = false;

    if ( iInputImage && iInputImage -> IsChannelValid (iChannelNum) )
    {
        if ( oComplexSet )
            delete oComplexSet;

        unsigned int nImgWidth  = iInputImage -> GetWidth ();
        unsigned int nImgHeight = iInputImage -> GetHeight ();

        // find the dimenstions of the padded image
        unsigned int nCompWidth = ceil ( log (nImgWidth) / log (2) ) + 1;
        nCompWidth = pow ( 2, nCompWidth );

        unsigned int nCompHeight = ceil ( log (nImgHeight) / log (2) ) + 1;
        nCompHeight = pow ( 2, nCompHeight );

        unsigned int nMaxDim = nCompWidth;
        if (nCompHeight > nMaxDim)
            nMaxDim = nCompHeight;

        oComplexSet = new DIP_Math_ComplexSet ( nMaxDim, nMaxDim );

        if ( oComplexSet )
        {
            int nImgCol = 0;
            int nImgRow = 0;

            // Note that the following copies the image data and pads the image
            for (int j = 0; j < nMaxDim; j++)
            {
                for (int i = 0; i < nMaxDim; i++)
                {
                    if ( i < nImgWidth && j < nImgHeight )
                    { 
                        DIP_PIXEL_TYPE nPixelValue = 0;
                        iInputImage -> GetPixel (i, j, iChannelNum, nPixelValue );
 
                        double dTemp = (double) nPixelValue;// / 255.0;
 
                        //DIP_Math_ComplexNum complexNum ( nPixelValue, 0 );
                        DIP_Math_ComplexNum complexNum ( dTemp, 0 );
                        oComplexSet -> SetValue ( i, j, complexNum );
                    }
                    else
                    {
                        DIP_Math_ComplexNum complexNum ( 0, 0 );
                        oComplexSet -> SetValue ( i, j, complexNum );
                    }
                }
            }

            // Perform the origin shifting
            oComplexSet -> DoOriginShiftMult ();

            bRetVal = DIP_Math_Utils::ComputeForwardFFT2D ( oComplexSet );
        }
    } 

    return bRetVal;
}



bool DIP_Image_MathUtils::ComputeImgFromFreqSpace ( DIP_Math_ComplexSet * iComplexSet, 
                                                    DIP_Image *&          oOutputImage  )
{
    bool bRetVal = false;

    if ( iComplexSet )
    {
        if ( DIP_Math_Utils::ComputeInverseFFT2D (iComplexSet) )
        {
            iComplexSet -> DoOriginShiftMult ();

            unsigned int nWidth  = iComplexSet -> GetWidth ();
            unsigned int nHeight = iComplexSet -> GetHeight ();

            if (oOutputImage)
                delete oOutputImage;
            oOutputImage = new DIP_Image ( nWidth, nHeight );

            for (int j = 0; j < nHeight; j++)
            {
                for (int i = 0; i < nWidth; i++)
                {
                    DIP_Math_ComplexNum complexNum;
                    iComplexSet -> GetValue ( i, j, complexNum );

                    double dPixelValue = complexNum._Re;// * 255.0;
                    if (dPixelValue < 0) dPixelValue = 0;
                    else if (dPixelValue > 255) dPixelValue = 255;

                    //oOutputImage -> SetPixel ( i, j, complexNum._Re*255 );                    
                    oOutputImage -> SetPixel ( i, j, dPixelValue );
                }
            }
        }
    }

    return bRetVal;
}



bool DIP_Image_MathUtils::MakeImgFromFreqSpace ( DIP_Math_ComplexSet *   iComplexSet,
                                                 DIP_FREQSPACE_DISPLAY   iType,
                                                 DIP_Image *&            oOutputImage )
{
    bool bRetVal = false;

    if ( iComplexSet )
    {
        unsigned int nWidth  = iComplexSet -> GetWidth ();
        unsigned int nHeight = iComplexSet -> GetHeight ();

        if (oOutputImage)
            delete oOutputImage;
        oOutputImage = new DIP_Image ( nWidth, nHeight );

        double dMinValue = 255;
        double dMaxValue = 0;
        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                DIP_Math_ComplexNum complexNum;
                iComplexSet -> GetValue ( i, j, complexNum );

                double dMag = complexNum.ComputeMagnitude();

                double dTempValue = log10 (255 * dMag + 1) / log10 (256);

                //if (j == 0 || j == 63 || j == 127)
                //   cout << " i = " << i << " j = " << j << " Re = " << complexNum._Re 
		//	                                << " Im = " << complexNum._Im 
                //                                        << " mag = " << dMag << "  " << dTempValue << endl;

                //double dTempValue = fabs ( (complexNum.ComputePhase ()));
                //double dTempValue = fabs (complexNum._Re);
                if ( dTempValue < dMinValue )
                     dMinValue = dTempValue;
                if ( dTempValue > dMaxValue )
                     dMaxValue = dTempValue;

                complexNum._Re = dTempValue; //dMag;
                complexNum._Im = 0;

                iComplexSet -> SetValue ( i, j, complexNum );
            }
        }

        cout << " dMinValue = " << dMinValue << endl;
        dMinValue = fabs (dMinValue);
        int maxI, maxJ;
        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                DIP_Math_ComplexNum complexNum;
                iComplexSet -> GetValue ( i, j, complexNum );
 
                complexNum._Re = complexNum._Re + dMinValue;               
                if ( complexNum._Re > dMaxValue )
                {
                     dMaxValue = complexNum._Re;
                     maxI = i; maxJ = j;
                }

                iComplexSet -> SetValue ( i, j, complexNum );
            }
        } 
        cout << " dMaxValue = " << dMaxValue << endl;//"  maxI = " << maxI << "  maxJ = " << maxJ << endl;

        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                DIP_Math_ComplexNum complexNum;
                iComplexSet -> GetValue ( i, j, complexNum );
 
                complexNum._Re = ( complexNum._Re / dMaxValue ) * 255.0;

                oOutputImage -> SetPixel ( i, j, complexNum._Re );
            }
        }


        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                DIP_Math_ComplexNum complexNum;
                iComplexSet -> GetValue ( i, j, complexNum );

                if ( iType == FREQDISPLAY_REAL )
                    oOutputImage -> SetPixel ( i, j, complexNum._Re );
                else if ( iType == FREQDISPLAY_IMAGINARY )
                    oOutputImage -> SetPixel ( i, j, complexNum._Im );
                else if ( iType == FREQDISPLAY_MAGNITUDE )
                {
                    oOutputImage -> SetPixel ( i, j, complexNum.ComputeMagnitude() );
                }
                else if ( iType ==  FREQDISPLAY_PHASE )
                    oOutputImage -> SetPixel ( i, j, complexNum.ComputePhase() );
            }
        } 

        //ScaleImageValues ( oOutputImage, SCALE_ACCURATE );

        bRetVal = true;
    }

    return bRetVal;
} */

    


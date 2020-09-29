////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_Image_Utils.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


bool DIP_Image_Utils::BuildComplexFromImage  ( DIP_Image *         ipImage, 
                                               DIP_ComplexImage *& opComplexImage,
                                               bool                iPadImage, 
                                               bool                iPadExtra )
{
    bool bRetVal = false;

    if (ipImage)
    {
        // Get the original image dimensions
        unsigned int nImgWidth  = ipImage -> GetWidth ();
        unsigned int nImgHeight = ipImage -> GetHeight ();

        // find the dimensions of the complex image
        unsigned int nComplexWidth  = nImgWidth;
        unsigned int nComplexHeight = nImgHeight;

        // pad the image if necessary
        if (iPadImage)
        {
            nComplexWidth  = ceil ( log (nImgWidth)  / M_LN2 );
            nComplexHeight = ceil ( log (nImgHeight) / M_LN2 );

            if (iPadExtra)
            {
                nComplexWidth++;
                nComplexHeight++;
            }

            nComplexWidth  = pow ( 2, nComplexWidth );
            nComplexHeight = pow ( 2, nComplexHeight );
        }

        if (opComplexImage)
            delete opComplexImage;

        opComplexImage = new DIP_ComplexImage ( nComplexWidth, nComplexHeight, ipImage -> _ImgType );

        if (opComplexImage)
        {
            int nImageCol = 0;
            int nImageRow = 0;

            // Note that the following copies the image data and pads the image
            for (int j = 0; j < nComplexHeight; j++)
            {
                for (int i = 0; i < nComplexWidth; i++)
                {
                    for (int c = 0; c < ipImage -> _ImgType; c++)
                    {
                        DIP_PIXEL_TYPE nPixelValue = 0;

                        if ( i < nImgWidth && j < nImgHeight )
                        { 
                            ipImage -> GetValue ( i, j, (DIP_IMAGE_CHANNEL) c, nPixelValue );

                            // double dTemp = (double) nPixelValue;// / 255.0;
                            // DIP_Math_ComplexNum complexNum ( nPixelValue, 0 );
                            // DIP_Math_ComplexNum complexNum ( dTemp, 0 );
                            // oComplexSet -> SetValue ( i, j, complexNum );
                        }

                        DIP_COMPLEXPIXEL_TYPE zComplexNum (nPixelValue, 0); 
                        opComplexImage -> SetValue ( i, j, (DIP_IMAGE_CHANNEL) c, zComplexNum );

                        if (i < 5 && j < 3 )
                        {
                            DIP_COMPLEXPIXEL_TYPE z;
                            opComplexImage -> GetValue ( i, j, (DIP_IMAGE_CHANNEL) c, z );

                           cout << "  " << i << " " << j << "  " << nPixelValue << "  " << zComplexNum.real () << "  " << z.real () << endl;
                        }

                    } // for c

                } // for i

            } // for j

            bRetVal = true;

        } // if opComplexImage exists

    } // if ipImage exsists

    return bRetVal;
}



bool DIP_Image_Utils::BuildImageFromComplex ( DIP_ComplexImage *      ipComplexImage, 
                                              DIP_Image *&            opImage,
                                              DIP_COMPLEXCONVERT_TYPE iConvertType, 
                                              bool                    iTakeLogTransform )
{
    bool bRetVal = false;

    if (ipComplexImage)
    {
        opImage = new DIP_Image ( ipComplexImage -> _nWidth, 
                                  ipComplexImage -> _nHeight,
                                  ipComplexImage -> _ImgType );

        DIP_RealImage * pRealImage = NULL;
        BuildRealFromComplex ( ipComplexImage, pRealImage, iConvertType );
 
        if (pRealImage && opImage)
        {
            if ( iTakeLogTransform )
            {
            // To increase the contrast the log transformation is performed 
            if ( iConvertType == COMPCONVERT_REAL      || 
                 iConvertType == COMPCONVERT_IMAGINARY ||
                 iConvertType == COMPCONVERT_MAGNITUDE  )
            {
                    pRealImage -> LogTransform ( FREQ_LOG_SCALING_FACTOR );
            }

            pRealImage -> ScaleImageValuesToRange ( 0, opImage -> GetMaxPixelValue() );
            }
            else
            {
            pRealImage -> ScaleImageValuesToRange ( 0, opImage -> GetMaxPixelValue() );
               //pRealImage -> AbsoluteValue ();
            }

            for (int j = 0; j < ipComplexImage -> _nHeight; j++)
            {
                for (int i = 0; i < ipComplexImage -> _nWidth; i++)
                {
                    for (int c = 0; c < ipComplexImage -> _ImgType; c++)
                    {
                        DIP_REALPIXEL_TYPE  dRealValue;
                        pRealImage -> GetValue ( i, j, (DIP_IMAGE_CHANNEL) c, dRealValue );

                        opImage -> SetValue ( i, j, (DIP_IMAGE_CHANNEL) c, dRealValue );
                    }
                } 
            }

            delete pRealImage;
        }
    }

    return bRetVal;
}



bool DIP_Image_Utils::BuildRealFromComplex ( DIP_ComplexImage *      ipComplexImage, 
                                             DIP_RealImage *&        opRealImage,
                                             DIP_COMPLEXCONVERT_TYPE iConvertType )
{
    bool bRetVal = false;

    if (ipComplexImage)   
    {
        if ( iConvertType == COMPCONVERT_REAL )
        {
            bRetVal = ipComplexImage -> GetRealComponents ( opRealImage );
        }
        else if ( iConvertType == COMPCONVERT_IMAGINARY )
        {
            bRetVal = ipComplexImage -> GetImaginaryComponents ( opRealImage );
        }
        else if ( iConvertType == COMPCONVERT_MAGNITUDE )
        {
            bRetVal = ipComplexImage -> GetMagnitude ( opRealImage );
        }
        else if ( iConvertType == COMPCONVERT_PHASE )
        {
            bRetVal = ipComplexImage -> GetPhase ( opRealImage );
        }
    }

    return bRetVal;
}


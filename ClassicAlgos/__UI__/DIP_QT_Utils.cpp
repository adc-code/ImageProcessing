
#include "DIP_QT_Utils.h"
#include "DIP_Defs.h"
#include "DIP_Image.h"

#include <QImage>
#include <QMessageBox>


bool DIP_QT_Utils::ConvertQImageToDIPImage ( QImage & iQImage, DIP_Image *& oDIPImage )
{
    bool bRetVal = false;

    if (oDIPImage)
        delete oDIPImage;

    // note: only depths of 8, 24, and 32 are currently supported.  Other formats such
    // as 1 and 16 bit are not supported.

    bool bSupportedImgType = false;
    DIP_IMAGE_TYPE imgType;
    DIP_IMAGE_BPP  imgBPP = BPP_8_BIT;

    int nImgDepth = iQImage.depth ();
    if (nImgDepth == 8)
    {
        imgType           = GREY;
        bSupportedImgType = true;
    }
    else if (nImgDepth == 24 || nImgDepth == 32)
    {
        imgType           = RGB;
        bSupportedImgType = true;
    }

    // currently, for the scope of the project, ignore if an alpha channel exists
    /* if (iQImage.hasAlphaChannel())
    {
        imgType           = RGBA;
        bSupportedImgType = true;
    } */

    if (bSupportedImgType)
    {
        bRetVal = true;

        int nHeight = iQImage.height();
        int nWidth  = iQImage.width();

        oDIPImage = new DIP_Image (nWidth, nHeight, imgType, imgBPP );

        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                QRgb pixelValue = iQImage.pixel (i, j);

                if (imgType == GREY)
                {
                    DIP_PIXEL_TYPE greyPixelValue = qGray (pixelValue);
                    oDIPImage -> SetPixel (i, j, greyPixelValue);
                }
                else if (imgType == RGB)
                {
                    DIP_PIXEL_TYPE rPixelValue = qRed (pixelValue);
                    DIP_PIXEL_TYPE gPixelValue = qGreen (pixelValue);
                    DIP_PIXEL_TYPE bPixelValue = qBlue (pixelValue);

                    oDIPImage -> SetPixel (i, j, rPixelValue,
                                                  gPixelValue,
                                                  bPixelValue);

                    /*else if (imgType == RGBA)
                    {
                        DIP_PIXEL_TYPE aPixelValue = qAlpha (pixelValue);
                        _pImage -> SetPixel (i, j, rPixelValue,
                                                   gPixelValue,
                                                   bPixelValue,
                                                   aPixelValue);
                    }*/
                }
            }
        }
    }
    else
    {
        // Should display error message
        QMessageBox Msgbox;
        Msgbox.setText ("Unsupported file type");
        Msgbox.exec();
    }

    return bRetVal;
}



bool DIP_QT_Utils::ConvertDIPImageToQImage ( DIP_Image * iDIPImage, QImage & oQImage )
{
    bool bRetVal = false;

    if (iDIPImage)
    {
        int nWidth  = iDIPImage -> GetWidth();
        int nHeight = iDIPImage -> GetHeight();

        QImage tmpImage (nWidth, nHeight, QImage::Format_RGB888);

        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                if (iDIPImage -> GetImageType() == GREY)
                {
                    DIP_PIXEL_TYPE pixelValue;
                    iDIPImage -> GetPixel (i, j, pixelValue);

                    tmpImage.setPixel (i, j, qRgb (pixelValue,
                                                   pixelValue,
                                                   pixelValue));
                }
                else if (iDIPImage -> GetImageType() == RGB)
                {
                    DIP_PIXEL_TYPE rPixelValue;
                    DIP_PIXEL_TYPE gPixelValue;
                    DIP_PIXEL_TYPE bPixelValue;

                    iDIPImage -> GetPixel (i, j, rPixelValue,
                                                 gPixelValue,
                                                 bPixelValue );

                    tmpImage.setPixel (i, j, qRgb (rPixelValue,
                                                   gPixelValue,
                                                   bPixelValue) );
                }
                /* Again... alpha channels currently not supported
                 *     else if (pImage -> GetImageType() == RGBA)
                    {
                        DIP_PIXEL_TYPE rPixelValue;
                        DIP_PIXEL_TYPE gPixelValue;
                        DIP_PIXEL_TYPE bPixelValue;
                        DIP_PIXEL_TYPE aPixelValue;

                        pImage -> GetPixel (i, j, rPixelValue,
                                                  gPixelValue,
                                                  bPixelValue,
                                                  aPixelValue);

                        tmpImage.setPixel (i, j, qRgba (rPixelValue,
                                                        gPixelValue,
                                                        bPixelValue,
                                                        aPixelValue) );
                    } */
            }
        }

        oQImage = tmpImage;
        bRetVal = true;
    }

    return bRetVal;
}





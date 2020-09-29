#include <QtWidgets>

#include "DIP_ImageViewerCtrl.h"

#include "DIP_Image.h"
#include "DIP_ImageViewer.h"
#include "DIP_Image_ProcessUtils.h"
#include "DIP_MappingFunction.h"

#include <iostream>
using namespace std;


bool DIP_ImageViewerCtrl::PerformGreyLevelTransformation  ( DIP_ImageViewer *         pImgViewer,
                                                            DIP_Image *&              oResultImg,
                                                            DIP_MAPPING_FUNCTIONTYPE  iType )
{
    vector<double>  dParams;
    
    return PerformGreyLevelTransformation ( pImgViewer, oResultImg, iType, dParams );
}



bool DIP_ImageViewerCtrl::PerformGreyLevelTransformation  ( DIP_ImageViewer *         pImgViewer,
                                                            DIP_Image *&              oResultImg,
                                                            DIP_MAPPING_FUNCTIONTYPE  iType,
                                                            vector<double>            iParameters )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        if ( iType == MAPFUNC_LOG_E || iType == MAPFUNC_LOG_10 ||
             iType == MAPFUNC_EXP_E || iType == MAPFUNC_EXP_10 )
        {
            if (pImage)
                iParameters.push_back (pImage -> GetMaxPixelValue ());
            else
                iParameters.push_back (pImage -> GetMaxPixelValue ());
        }

        // Make the mapping function
        DIP_MappingFunction mappingFunction (iType, iParameters);

        // Process the image
        bRetVal = DIP_Image_ProcessUtils::ApplyGreyLevelTransformation ( pImage,
                                                                         oResultImg,
                                                                         mappingFunction );

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformHistogramEqualization  ( DIP_ImageViewer *  pImgViewer,
                                                          DIP_Image *&       oResultImg )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        bRetVal = DIP_Image_ProcessUtils::ApplyHistogramEqualization (pImage, oResultImg);

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}


bool DIP_ImageViewerCtrl::PerformHistogramStretch  ( DIP_ImageViewer *  pImgViewer,
                                                     DIP_Image *&       oResultImg,
                                                     unsigned int       iNewLowerValue,
                                                     unsigned int       iNewUpperValue )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        bRetVal = DIP_Image_ProcessUtils::ApplyHistogramStretch (pImage,
                                                                 oResultImg,
                                                                 iNewLowerValue,
                                                                 iNewUpperValue );

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformHistogramShift  ( DIP_ImageViewer *  pImgViewer,
                                                   DIP_Image *&       oResultImg,
                                                   int                iAmount )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        bRetVal = DIP_Image_ProcessUtils::ApplyHistogramShift (pImage, oResultImg, iAmount);

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformScaleTransformation  ( DIP_ImageViewer *    pImgViewer,
                                                        DIP_Image *&         oResultImg,
                                                        unsigned int         iNewWidth,
                                                        unsigned int         iNewHeight,
                                                        DIP_IMGSCALING_TYPE  iScalingMethod )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        bRetVal = DIP_Image_ProcessUtils::ApplyScaleTransformation (pImage,
                                                                    oResultImg,
                                                                    iNewWidth,
                                                                    iNewHeight,
                                                                    iScalingMethod);

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformMeanFilter  ( DIP_ImageViewer *        pImgViewer,
                                               DIP_Image *&             oResultImg,
                                               DIP_MEANFILTER_TYPE      iMeanType,
                                               unsigned int             iWindowWidth,
                                               unsigned int             iWindowHeight,
                                               DIP_IMAGEBORDER_STRATEGY iBorderStrategy,
                                               double                   iQValue )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        QApplication::setOverrideCursor (Qt::WaitCursor);
        bRetVal = DIP_Image_ProcessUtils::ApplyMeanFilter ( pImage,
                                                            oResultImg,
                                                            iMeanType,
                                                            iWindowWidth,
                                                            iWindowHeight,
                                                            iBorderStrategy,
                                                            iQValue );

        QApplication::restoreOverrideCursor();

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformOrderStatFilter  ( DIP_ImageViewer *          pImgViewer,
                                                    DIP_Image *&               oResultImg,
                                                    DIP_ORDEREDSTATFILTER_TYPE iOrderStatType,
                                                    unsigned int               iWindowWidth,
                                                    unsigned int               iWindowHeight,
                                                    DIP_IMAGEBORDER_STRATEGY   iBorderStrategy,
                                                    double                     iDValue )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        QApplication::setOverrideCursor (Qt::WaitCursor);
        bRetVal = DIP_Image_ProcessUtils::ApplyOrderedStatFilter ( pImage,
                                                                   oResultImg,
                                                                   iOrderStatType,
                                                                   iWindowWidth,
                                                                   iWindowHeight,
                                                                   iBorderStrategy,
                                                                   iDValue );

        QApplication::restoreOverrideCursor();

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformWeightedSumFilter ( DIP_ImageViewer *          pImgViewer,
                                                     DIP_Image *&               oResultImg,
                                                     DIP_WEIGHTEDSUMFILTER_TYPE iWeightSumType,
                                                     unsigned int               iWindowWidth,
                                                     unsigned int               iWindowHeight,
                                                     DIP_IMAGEBORDER_STRATEGY   iBorderStrategy )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        vector <double> dParameters;

        // Process the image
        QApplication::setOverrideCursor (Qt::WaitCursor);

        bRetVal = DIP_Image_ProcessUtils::ApplyWeightedSumFilter ( pImage,
                                                                   oResultImg,
                                                                   iWeightSumType,
                                                                   iWindowWidth,
                                                                   iWindowHeight,
                                                                   iBorderStrategy,
                                                                   dParameters );

        QApplication::restoreOverrideCursor();

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformSharpeningFilter  ( DIP_ImageViewer *          pImgViewer,
                                                     DIP_Image *&               oResultImg,
                                                     unsigned int               iWindowWidth,
                                                     unsigned int               iWindowHeight,
                                                     DIP_IMAGEBORDER_STRATEGY   iBorderStrategy,
                                                     double                     iAValue )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        QApplication::setOverrideCursor (Qt::WaitCursor);
        bool bOK = DIP_Image_ProcessUtils::ApplySharpenFilter ( pImage,
                                                                oResultImg,
                                                                iWindowWidth,
                                                                iWindowHeight,
                                                                iBorderStrategy,
                                                                iAValue );
        QApplication::restoreOverrideCursor();

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}



bool DIP_ImageViewerCtrl::PerformFrequencyFilter ( DIP_ImageViewer *    pImgViewer,
                                                   DIP_Image *&         oResultImg,
                                                   DIP_FREQFILTER_TYPE  iFilterType,
                                                   double               iCutOffFreq,
                                                   int                  iNValue )
{
    bool bRetVal = false;

    if ( pImgViewer )
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        // Process the image
        QApplication::setOverrideCursor (Qt::WaitCursor);
        bool bOK = DIP_Image_ProcessUtils::ApplyFreqDomainFilter ( pImage,
                                                                   oResultImg,
                                                                   iFilterType,
                                                                   iCutOffFreq,
                                                                   iNValue );
        QApplication::restoreOverrideCursor();

        // Display the results
        pImgViewer -> UpdateImage ( oResultImg );
    }

    return bRetVal;
}




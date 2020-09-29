#include <QTGui>
#include <QtWidgets>

#include "DIP_AdaptiveFilterDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"


DIP_AdaptiveFilterDlg::DIP_AdaptiveFilterDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _bDoPreview    = false;
    _nBorderType   = (DIP_IMAGEBORDER_STRATEGY) 3;
    _nSizeIncrease = 2;

    _nWidth       = 3;
    _nHeight      = 3;

    comboBorder -> clear ();
    comboBorder -> addItem ("Use zero");           // 0
    comboBorder -> addItem ("Copy central value"); // 1
    comboBorder -> addItem ("Copy nearest value"); // 2
    comboBorder -> addItem ("Wrap around");        // 3
    comboBorder -> setCurrentIndex (_nBorderType - 1);

    comboSMax -> clear ();
    comboSMax -> addItem ("1 pixel");  // 0
    comboSMax -> addItem ("2 pixel");  // 1
    comboSMax -> addItem ("3 pixel");  // 2
    comboSMax -> addItem ("4 pixel");  // 3
    comboSMax -> setCurrentIndex (_nSizeIncrease - 1);

    connect (spWidth,     SIGNAL(valueChanged(int)), this, SLOT(OnUpdateWidth(int)));
    connect (spHeight,    SIGNAL(valueChanged(int)), this, SLOT(OnUpdateHeight(int)));
    connect (comboBorder, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateBorderCB(int)));
    connect (comboSMax,   SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateSMaxCB(int)));
    connect (cbPreview,   SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}



void DIP_AdaptiveFilterDlg::OnUpdateWidth (int iValue)
{
    _nWidth = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_AdaptiveFilterDlg::OnUpdateHeight (int iValue)
{
    _nHeight = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_AdaptiveFilterDlg::OnUpdateBorderCB (int iValue)
{
    _nBorderType = (DIP_IMAGEBORDER_STRATEGY) (iValue + 1);

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_AdaptiveFilterDlg::OnUpdateSMaxCB (int iValue)
{
    _nSizeIncrease = iValue + 1;
}


/*
DIP_ORDEREDSTATFILTER_TYPE DIP_OrderStatisticsFilterDlg::GetSelectedType ()
{
    return (DIP_ORDEREDSTATFILTER_TYPE) _nCurrentType;
}
DIP_IMAGEBORDER_STRATEGY DIP_OrderStatisticsFilterDlg::GetBorderStrategy ()
{
    return (DIP_IMAGEBORDER_STRATEGY) (_nBorderType + 1);
}
unsigned int DIP_OrderStatisticsFilterDlg::GetWidth ()
{
    return _nWidth;
}
unsigned int DIP_OrderStatisticsFilterDlg::GetHeight ()
{
    return _nHeight;
}*/



void DIP_AdaptiveFilterDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_AdaptiveFilterDlg::PerformTransformation (bool iUpdateViewerState)
{
     DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;

        DIP_ImageViewerCtrl::PerformOrderStatFilter ( pImgViewer,
                                                      pTempImage,
                                                      OS_ADAPTIVEMEDIAN,
                                                      _nWidth,
                                                      _nHeight,
                                                      _nBorderType,
                                                      _nSizeIncrease );

        if (!iUpdateViewerState)
        {
            if (pTempImage)
                delete pTempImage;
        }
        else
        {
            pImgViewer -> SetCurrentImage (pTempImage);
        }
    }
}


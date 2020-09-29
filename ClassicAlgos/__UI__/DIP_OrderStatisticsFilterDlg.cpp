#include <QTGui>
#include <QtWidgets>

#include "DIP_OrderStatisticsFilterDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"


DIP_OrderStatisticsFilterDlg::DIP_OrderStatisticsFilterDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _bDoPreview   = false;
    _nCurrentType = MEDIAN;
    _nDValue      = 3;
    _nBorderType  = 2;

    _nWidth       = 3;
    _nHeight      = 3;

    rbMedian   -> setChecked (true);
    rbMin      -> setChecked (false);
    rbMax      -> setChecked (false);
    rbMidpoint -> setChecked (false);
    rbAlpha    -> setChecked (false);
    labelD     -> setEnabled (false);
    spDValue   -> setEnabled (false);

    comboBorder -> clear ();
    comboBorder -> addItem ("Use zero");
    comboBorder -> addItem ("Copy central value");
    comboBorder -> addItem ("Copy nearest value");
    comboBorder -> addItem ("Wrap around");
    comboBorder -> setCurrentIndex (2);

    connect (rbMedian, SIGNAL(toggled(bool)), this, SLOT(OnUpdateMedianRB(bool)));
    connect (rbMin, SIGNAL(toggled(bool)), this, SLOT(OnUpdateMinRB(bool)));
    connect (rbMax, SIGNAL(toggled(bool)), this, SLOT(OnUpdateMaxRB(bool)));
    connect (rbMidpoint, SIGNAL(toggled(bool)), this, SLOT(OnUpdateMidpointRB(bool)));
    connect (rbAlpha, SIGNAL(toggled(bool)), this, SLOT(OnUpdateAlphaRB(bool)));
    connect (spDValue, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateDValue(int)));
    connect (spWidth, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateWidth(int)));
    connect (spHeight, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateHeight(int)));
    connect (comboBorder, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateBorderCB(int)));
    connect (cbPreview, SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}


void DIP_OrderStatisticsFilterDlg::OnUpdateMedianRB (bool bState)
{
    _nCurrentType = MEDIAN;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateMinRB (bool bState)
{
    _nCurrentType = MIN;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateMaxRB (bool bState)
{
    _nCurrentType = MAX;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateMidpointRB (bool bState)
{
    _nCurrentType = MIDPOINT;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateAlphaRB (bool bState)
{
    _nCurrentType = ALPHA;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateWidth (int iValue)
{
    _nWidth = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateHeight (int iValue)
{
    _nHeight = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnUpdateBorderCB (int iValue)
{
    _nBorderType = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::EnableUIElements ()
{
    labelD      -> setEnabled (false);
    spDValue    -> setEnabled (false);

    if (_nCurrentType == ALPHA)
    {
        labelD   -> setEnabled (true);
        spDValue -> setEnabled (true);
    }
}


DIP_ORDEREDSTATFILTER_TYPE DIP_OrderStatisticsFilterDlg::GetSelectedType ()
{
    return (DIP_ORDEREDSTATFILTER_TYPE) _nCurrentType;
}


DIP_IMAGEBORDER_STRATEGY DIP_OrderStatisticsFilterDlg::GetBorderStrategy ()
{
    return (DIP_IMAGEBORDER_STRATEGY) (_nBorderType + 1);
}


int DIP_OrderStatisticsFilterDlg::GetDValue ()
{
    return spDValue -> value();
}


unsigned int DIP_OrderStatisticsFilterDlg::GetWidth ()
{
    return _nWidth;
}


unsigned int DIP_OrderStatisticsFilterDlg::GetHeight ()
{
    return _nHeight;
}


void DIP_OrderStatisticsFilterDlg::OnUpdateDValue (int iValue)
{
    _nDValue = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_OrderStatisticsFilterDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_OrderStatisticsFilterDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformOrderStatFilter ( pImgViewer,
                                                      pTempImage,
                                                      GetSelectedType(),
                                                      _nWidth,
                                                      _nHeight,
                                                      GetBorderStrategy(),
                                                      _nDValue );

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


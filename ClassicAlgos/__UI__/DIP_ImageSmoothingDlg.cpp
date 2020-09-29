
#include <QTGui>
#include <QtWidgets>

#include "DIP_ImageSmoothingDlg.h"
#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"
#include "DIP_Image_ProcessUtils.h"


DIP_ImageSmoothingDlg::DIP_ImageSmoothingDlg (QWidget * pParent)
                      : QDialog (pParent)
{
    setupUi (this);

    _nSpatFilterType = 0;
    _nFreqFilterType = FILTER_IDEAL;
    _nBorderType     = 2;
    _nWidth          = 3;
    _nHeight         = 3;
    _bDoPreview      = false;
    _dCutOffFreq     = 0.15;
    _nNValue         = 1;

    //sbGamma -> setValue (_dGammaValue);
    EnableUIElements (true);

    rbSpatial   -> setChecked (true);
    rbFrequency -> setChecked (false);

    rbIdeal     -> setChecked (true);
    rbGauss     -> setChecked (false);
    rbButter    -> setChecked (false);

    comboSpType -> clear ();
    comboSpType -> addItem (QString("Average"));
    comboSpType -> addItem (QString("Weighted Average"));
    comboSpType -> setCurrentIndex (_nSpatFilterType);

    comboBorder -> clear ();
    comboBorder -> addItem ("Use zero");
    comboBorder -> addItem ("Copy central value");
    comboBorder -> addItem ("Copy nearest value");
    comboBorder -> addItem ("Wrap around");
    comboBorder -> setCurrentIndex (_nBorderType);

    spFc -> setValue (15);

    connect (rbSpatial,   SIGNAL(toggled(bool)), this, SLOT(OnUpdateSpatDomainRB(bool)));
    connect (rbFrequency, SIGNAL(toggled(bool)), this, SLOT(OnUpdateFreqDomainRB(bool)));
    connect (comboSpType, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateSpatType(int)));
    connect (spWidth,     SIGNAL(valueChanged(int)), this, SLOT(OnUpdateWidth(int)));
    connect (spHeight,    SIGNAL(valueChanged(int)), this, SLOT(OnUpdateHeight(int)));
    connect (comboBorder, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateBorderCB(int)));

    connect (rbIdeal,     SIGNAL(toggled(bool)), this, SLOT(OnUpdateIdealFilterRB(bool)));
    connect (rbGauss,     SIGNAL(toggled(bool)), this, SLOT(OnUpdateGaussFilterRB(bool)));
    connect (rbButter,    SIGNAL(toggled(bool)), this, SLOT(OnUpdateButterFilterRB(bool)));
    connect (spFc,        SIGNAL(valueChanged(int)), this, SLOT(OnUpdateCutOffFreq(int)));
    connect (spN,         SIGNAL(valueChanged(int)), this, SLOT(OnUpdateNValue(int)));

    connect (cbPreview,   SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}


void DIP_ImageSmoothingDlg::OnUpdateSpatDomainRB (bool bState)
{
    if (rbSpatial -> isChecked())
    {
        _nDomain = DOMAIN_SPAT;

        EnableUIElements (true);

        if (_bDoPreview)
            PerformTransformation ();
    }
}


void DIP_ImageSmoothingDlg::OnUpdateFreqDomainRB (bool bState)
{
    if (rbFrequency -> isChecked())
    {
        _nDomain = DOMAIN_FREQ;

        EnableUIElements (false);

        if (_bDoPreview)
            PerformTransformation ();
    }
}


void DIP_ImageSmoothingDlg::OnUpdateSpatType (int iValue)
{
    _nSpatFilterType = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateWidth (int iValue)
{
    _nWidth = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateHeight (int iValue)
{
    _nHeight = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateBorderCB (int iValue)
{
    _nBorderType = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateCutOffFreq (int iValue)
{
    _dCutOffFreq = (double) iValue * 0.01;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateNValue (int iValue)
{
    _nNValue = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateIdealFilterRB (bool bState)
{
    _nFreqFilterType = FILTER_IDEAL;

/*    rbIdeal  -> setChecked (bState);
    rbGauss  -> setChecked (!bState);
    rbButter -> setChecked (!bState);
    spN      -> setEnabled (!bState);*/

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateGaussFilterRB (bool bState)
{
    _nFreqFilterType = FILTER_GAUSS;

    /*rbIdeal  -> setChecked (!bState);
    rbGauss  -> setChecked (bState);
    rbButter -> setChecked (!bState);
    spN      -> setEnabled (!bState);*/

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::OnUpdateButterFilterRB (bool bState)
{
    _nFreqFilterType = FILTER_BUTTER;

    /*rbIdeal  -> setChecked (!bState);
    rbGauss  -> setChecked (bState);
    rbButter -> setChecked (bState);
    spN      -> setEnabled (bState);*/

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSmoothingDlg::EnableUIElements (bool bState)
{
    // Spatial domain elements
    labelSpType -> setEnabled (bState);
    comboSpType -> setEnabled (bState);
    labelNeigh  -> setEnabled (bState);
    labelWidth  -> setEnabled (bState);
    labelHeight -> setEnabled (bState);
    spWidth     -> setEnabled (bState);
    spHeight    -> setEnabled (bState);
    labelBorder -> setEnabled (bState);
    comboBorder -> setEnabled (bState);

    // Frequency domain elements
    rbIdeal     -> setEnabled (!bState);
    rbGauss     -> setEnabled (!bState);
    rbButter    -> setEnabled (!bState);
    labelFc     -> setEnabled (!bState);
    spFc        -> setEnabled (!bState);
    labelN      -> setEnabled (!bState);
    spN         -> setEnabled (!bState);
}


DIP_WEIGHTEDSUMFILTER_TYPE DIP_ImageSmoothingDlg::GetSpatialFilterType ()
{
    return (DIP_WEIGHTEDSUMFILTER_TYPE) (_nSpatFilterType + 1);
}


DIP_IMAGEBORDER_STRATEGY DIP_ImageSmoothingDlg::GetBorderStrategy ()
{
    return (DIP_IMAGEBORDER_STRATEGY) (_nBorderType + 1);
}


DIP_FREQFILTER_TYPE DIP_ImageSmoothingDlg::GetFrequencyFilterType ()
{
    return (DIP_FREQFILTER_TYPE) _nFreqFilterType;
}


void DIP_ImageSmoothingDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}



void DIP_ImageSmoothingDlg::PerformTransformation (bool iUpdateViewerState)
{
    if (_nDomain == DOMAIN_SPAT)
    {
        PerformSpatTransformation (iUpdateViewerState);
    }
    else if (_nDomain == DOMAIN_FREQ)
    {
        PerformFreqTransformation (iUpdateViewerState);
    }
}



void DIP_ImageSmoothingDlg::PerformSpatTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformWeightedSumFilter ( pImgViewer,
                                                        pTempImage,
                                                        GetSpatialFilterType(),
                                                        _nWidth,
                                                        _nHeight,
                                                        GetBorderStrategy() );

        if (iUpdateViewerState == false)
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


void DIP_ImageSmoothingDlg::PerformFreqTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformFrequencyFilter ( pImgViewer,
                                                      pTempImage,
                                                      GetFrequencyFilterType(),
                                                      _dCutOffFreq,
                                                      _nNValue );

        if (iUpdateViewerState == false)
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


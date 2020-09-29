
#include <QTGui>
#include <QtWidgets>

#include "DIP_ResizeDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"



DIP_ResizeDlg::DIP_ResizeDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _nInputMode  = MODE_PREDEFINED;
    _nPreDefMode = SCALE_ZOOM;

    _bDoPreview  = false;
    _dPercentage = 0.5;
    _ScalingType = SCALING_NEAREST;

    rbNearest    -> setChecked (true);
    rbBilinear   -> setChecked (false);

    rbZoom       -> setChecked (true);
    rbShrink     -> setChecked (false);

    rbPredefined -> setChecked (true);
    rbUser       -> setChecked (false);

    EnableUIElements (true);

    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) pParent;
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();
        if (pImage)
        {
            _nOriginalWidth = pImage -> GetWidth ();
            _nOriginalHeight = pImage -> GetHeight ();
        }
    }

    _nCurrentWidth = _nOriginalWidth;
    _nCurrentHeight = _nOriginalHeight;

    sbWidth  -> setValue (_nOriginalWidth);
    sbHeight -> setValue (_nOriginalHeight);

    cbPercentage -> clear ();
    cbPercentage -> addItem (QString (" 10%")); // 0
    cbPercentage -> addItem (QString (" 25%")); // 1
    cbPercentage -> addItem (QString (" 50%")); // 2
    cbPercentage -> setCurrentIndex (2);

    connect (rbNearest, SIGNAL(toggled(bool)), this, SLOT(OnUpdateNearestRB(bool)));
    connect (rbBilinear, SIGNAL(toggled(bool)), this, SLOT(OnUpdateBilinearRB(bool)));

    connect (rbPredefined, SIGNAL(toggled(bool)), this, SLOT(OnUpdatePredefinedRB(bool)));
    connect (rbUser, SIGNAL(toggled(bool)), this, SLOT(OnUpdateUserDefinedRB(bool)));

    connect (rbZoom, SIGNAL(toggled(bool)), this, SLOT(OnUpdateZoomRB(bool)));
    connect (rbShrink, SIGNAL(toggled(bool)), this, SLOT(OnUpdateShrinkRB(bool)));

    connect (sbWidth, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateWidthSpinner(int)));
    connect (sbHeight, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateHeightSpinner(int)));
    connect (cbPercentage, SIGNAL(currentIndexChanged(int)), SLOT(OnUpdatePercentageCB(int)));

    connect (cbPreview, SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}


void DIP_ResizeDlg::EnableUIElements (bool bState)
{
    rbZoom       -> setEnabled (bState);
    rbShrink     -> setEnabled (bState);
    cbPercentage -> setEnabled (bState);
    labelPercent -> setEnabled (bState);

    sbWidth      -> setEnabled (!bState);
    sbHeight     -> setEnabled (!bState);
    labelWidth   -> setEnabled (!bState);
    labelHeight  -> setEnabled (!bState);
}


void DIP_ResizeDlg::OnUpdateWidthSpinner (int iValue)
{
    _nCurrentWidth = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdateHeightSpinner (int iValue)
{
    _nCurrentHeight = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdatePredefinedRB (bool bState)
{
    rbPredefined -> setChecked (bState);
    rbUser       -> setChecked (!bState);

    _nInputMode = MODE_PREDEFINED;

    EnableUIElements (true);

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdateUserDefinedRB (bool bState)
{
    rbPredefined -> setChecked (!bState);
    rbUser       -> setChecked (bState);

    _nInputMode = MODE_USER;

    EnableUIElements (false);

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdateZoomRB (bool bState)
{
    rbZoom   -> setChecked (bState);
    rbShrink -> setChecked (!bState);

    _nPreDefMode = SCALE_ZOOM;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdateShrinkRB (bool bState)
{
    rbZoom   -> setChecked (!bState);
    rbShrink -> setChecked (bState);

    _nPreDefMode = SCALE_SHRINK;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdatePercentageCB (int nValue)
{
    if (nValue == 0)
        _dPercentage = 0.1;
    else if (nValue == 1)
        _dPercentage = 0.25;
    else if (nValue == 2)
        _dPercentage = 0.50;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdateNearestRB (bool bState)
{
    rbNearest  -> setChecked (bState);
    rbBilinear -> setChecked (!bState);

    _ScalingType = SCALING_NEAREST;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ResizeDlg::OnUpdateBilinearRB (bool bState)
{
    rbNearest  -> setChecked (!bState);
    rbBilinear -> setChecked (bState);

    _ScalingType = SCALING_BILINEAR;

    if (_bDoPreview)
        PerformTransformation ();
}



void DIP_ResizeDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_ResizeDlg::GetCurrentResizeValues ( unsigned int &         oWidth,
                                             unsigned int &         oHeight,
                                             DIP_IMGSCALING_TYPE &  oScalingType )
{
    if (_nInputMode == MODE_PREDEFINED)
    {
        if (_nPreDefMode == SCALE_ZOOM)
        {
            oWidth  = _nOriginalWidth  * (1.0 + _dPercentage);
            oHeight = _nOriginalHeight * (1.0 + _dPercentage);
        }
        else
        {
            oWidth  = _nOriginalWidth  * (1.0 - _dPercentage);
            oHeight = _nOriginalHeight * (1.0 - _dPercentage);
        }
    }
    else if (_nInputMode == MODE_USER)
    {
        oWidth  = _nCurrentWidth;
        oHeight = _nCurrentHeight;
    }

    oScalingType = _ScalingType;
}



void DIP_ResizeDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        unsigned int nWidth = _nCurrentWidth;
        unsigned int nHeight = _nCurrentHeight;
        DIP_IMGSCALING_TYPE tmpScalingType;

        GetCurrentResizeValues (nWidth, nHeight, tmpScalingType);

        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformScaleTransformation ( pImgViewer,
                                                          pTempImage,
                                                          nWidth,
                                                          nHeight,
                                                          _ScalingType );

        _nCurrentWidth = nWidth;
        _nCurrentHeight = nHeight;
        sbWidth  -> setValue (nWidth);
        sbHeight -> setValue (nHeight);

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




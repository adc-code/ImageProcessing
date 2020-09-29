
#include <QTGui>
#include <QtWidgets>

#include "DIP_ImageSharpeningDlg.h"
#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"

#include <iostream>
using namespace std;

DIP_ImageSharpeningDlg::DIP_ImageSharpeningDlg (QWidget * pParent)
                      : QDialog (pParent)
{
    setupUi (this);

    _nSpatFilterType = LAPLACIAN;
    _SobelDir        = SOBEL_HORIZ;
    _nFreqFilterType = FILTER_IDEAL_HP;
    _nDomain         = DOMAIN_SPAT;
    _nBorderType     = 2;
    _nWidth          = 3;
    _nHeight         = 3;
    _bDoPreview      = false;
    _dAValue         = 1.0;

    _dCutOffFreq     = 0.25;
    _nNValue         = 1;

    EnableUIElements (true);
    EnableSpatUIElements ();

    _ButtonGroup = new QButtonGroup (this);
    //rbSpatial   -> setParent (_ButtonGroup)
    //rbFrequency -> setParent (_ButtonGroup);
    rbSpatial   -> setChecked (true);
    //rbFrequency -> setChecked (false);

    rbLaplacian -> setChecked (true);
    rbIdeal     -> setChecked (true);

    comboBorder -> clear ();
    comboBorder -> addItem ("Use zero");
    comboBorder -> addItem ("Copy central value");
    comboBorder -> addItem ("Copy nearest value");
    comboBorder -> addItem ("Wrap around");
    comboBorder -> setCurrentIndex (_nBorderType);

    comboDirection -> clear ();
    comboDirection -> addItem ("X axis");
    comboDirection -> addItem ("Y axis");
    // add a degree symbol
    QChar   cDeg (0x00B0);
    QString str = "+45";  str.append (cDeg);
    comboDirection -> addItem (str);
    str = "-45";  str.append (cDeg);
    comboDirection -> addItem (str);
    comboDirection -> setCurrentIndex (0);

    spFc -> setValue (_dCutOffFreq);
    spN  -> setValue (_nNValue);

    connect (rbSpatial,   SIGNAL(toggled(bool)), this, SLOT(OnUpdateSpatDomainRB(bool)));
    connect (rbFrequency, SIGNAL(toggled(bool)), this, SLOT(OnUpdateFreqDomainRB(bool)));
    connect (rbLaplacian, SIGNAL(toggled(bool)), this, SLOT(OnUpdateLaplacianRB(bool)));
    connect (rbSobel,     SIGNAL(toggled(bool)), this, SLOT(OnUpdateSobelRB(bool)));
    connect (rbUnsharp,   SIGNAL(toggled(bool)), this, SLOT(OnUpdateUnsharpenRB(bool)));
    connect (rbHB,        SIGNAL(toggled(bool)), this, SLOT(OnUpdateHighboostRB(bool)));
    connect (comboDirection, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateSobelDirCB(int)));
    connect (spAValue,    SIGNAL(valueChanged(double)), this, SLOT(OnUpdateAValue(double)));

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


void DIP_ImageSharpeningDlg::OnUpdateSpatDomainRB (bool bState)
{
    cout << "DIP_ImageSharpeningDlg::OnUpdateSpatDomainRB   " << bState << endl;
    cout << "   rbSpatial -> isChecked() = " << rbSpatial -> isChecked() << endl;

//    if (rbSpatial -> isChecked() == true && bState == true)
  //  {
  //  }
//    if (rbSpatial -> isChecked())
    {
        cout << "  checking!!!" << endl;
        _nDomain = DOMAIN_SPAT;

  //      rbSpatial   -> setChecked (bState);
    //    rbFrequency -> setChecked (!bState);

        EnableUIElements (true);

        if (_bDoPreview)
            PerformTransformation ();
    }
}


void DIP_ImageSharpeningDlg::OnUpdateFreqDomainRB (bool bState)
{
    cout << "DIP_ImageSharpeningDlg::OnUpdateFreqDomainRB   " << bState << endl;

//    if (rbFrequency -> isChecked())
    {
        _nDomain = DOMAIN_FREQ;

  //      rbSpatial   -> setChecked (!bState);
    //     rbFrequency -> setChecked (bState);

        EnableUIElements (false);

        if (_bDoPreview)
            PerformTransformation ();
    }
}

void DIP_ImageSharpeningDlg::OnUpdateSobelDirCB (int iValue)
{
    _SobelDir = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateLaplacianRB (bool bState)
{
    _nSpatFilterType = LAPLACIAN;

    EnableSpatUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateSobelRB (bool bState)
{
    _nSpatFilterType = SOBEL;

    EnableSpatUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateUnsharpenRB (bool bState)
{
    _nSpatFilterType = UNSHARPMASK;

    EnableSpatUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateHighboostRB (bool bState)
{
    _nSpatFilterType = HIGHBOOST;

    EnableSpatUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateWidth (int iValue)
{
    _nWidth = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateHeight (int iValue)
{
    _nHeight = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateBorderCB (int iValue)
{
    _nBorderType = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateAValue (double iValue)
{
    _dAValue = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateCutOffFreq (int iValue)
{
    _dCutOffFreq = (double) iValue * 0.01;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateNValue (int iValue)
{
    _nNValue = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateIdealFilterRB (bool bState)
{
    _nFreqFilterType = FILTER_IDEAL_HP;

/*    rbIdeal  -> setChecked (bState);
    rbGauss  -> setChecked (!bState);
    rbButter -> setChecked (!bState);
    spN      -> setEnabled (!bState);*/

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateGaussFilterRB (bool bState)
{
    _nFreqFilterType = FILTER_GAUSS_HP;

    /*rbIdeal  -> setChecked (!bState);
    rbGauss  -> setChecked (bState);
    rbButter -> setChecked (!bState);
    spN      -> setEnabled (!bState);*/

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_ImageSharpeningDlg::OnUpdateButterFilterRB (bool bState)
{
    _nFreqFilterType = FILTER_BUTTER_HP;

    /*rbIdeal  -> setChecked (!bState);
    rbGauss  -> setChecked (bState);
    rbButter -> setChecked (bState);
    spN      -> setEnabled (bState);*/

    if (_bDoPreview)
        PerformTransformation ();
}



void DIP_ImageSharpeningDlg::EnableUIElements (bool bState)
{
    // Spatial domain elements
    rbLaplacian    -> setEnabled (bState);
    rbSobel        -> setEnabled (bState);
    rbUnsharp      -> setEnabled (bState);
    rbHB           -> setEnabled (bState);
    labelNeigh     -> setEnabled (bState);
    labelWidth     -> setEnabled (bState);
    labelHeight    -> setEnabled (bState);
    spWidth        -> setEnabled (bState);
    spHeight       -> setEnabled (bState);
    labelBorder    -> setEnabled (bState);
    comboBorder    -> setEnabled (bState);
    labelSobelDir  -> setEnabled (bState);
    comboDirection -> setEnabled (bState);
    labelA         -> setEnabled (bState);
    spAValue       -> setEnabled (bState);

    // Frequency domain elements
    rbIdeal     -> setEnabled (!bState);
    rbGauss     -> setEnabled (!bState);
    rbButter    -> setEnabled (!bState);
    labelFc     -> setEnabled (!bState);
    spFc        -> setEnabled (!bState);
    labelN      -> setEnabled (!bState);
    spN         -> setEnabled (!bState);
}


void DIP_ImageSharpeningDlg::EnableSpatUIElements ()
{
    labelSobelDir  -> setEnabled (false);
    comboDirection -> setEnabled (false);
    labelA         -> setEnabled (false);
    spAValue       -> setEnabled (false);

    if (_nSpatFilterType == LAPLACIAN)
    {
        ; //rbLaplacian    -> setEnabled (true);
    }
    else if (_nSpatFilterType == SOBEL)
    {
        //rbSobel        -> setEnabled (true);
        labelSobelDir  -> setEnabled (true);
        comboDirection -> setEnabled (true);
    }
    else if (_nSpatFilterType == UNSHARPMASK)
    {
        ;
    }
    else if (_nSpatFilterType == HIGHBOOST)
    {
        labelA   -> setEnabled (true);
        spAValue -> setEnabled (true);
    }
}


DIP_WEIGHTEDSUMFILTER_TYPE DIP_ImageSharpeningDlg::GetSpatialFilterType ()
{
    DIP_WEIGHTEDSUMFILTER_TYPE nType = WS_LAPLACIAN;

    if (_nSpatFilterType == LAPLACIAN)
        nType = WS_LAPLACIAN;
    else if (_nSpatFilterType == SOBEL)
    {
        if (_SobelDir == SOBEL_HORIZ)
            nType = WS_SOBEL_HORIZ;
        else if (_SobelDir == SOBEL_VERT)
            nType = WS_SOBEL_VERT;
        else if (_SobelDir == SOBEL_DIAG1)
            nType = WS_SOBEL_45_1;
        else if (_SobelDir == SOBEL_DIAG2)
            nType = WS_SOBEL_45_2;
    }

    return nType;
}


DIP_IMAGEBORDER_STRATEGY DIP_ImageSharpeningDlg::GetBorderStrategy ()
{
    return (DIP_IMAGEBORDER_STRATEGY) (_nBorderType + 1);
}


DIP_FREQFILTER_TYPE DIP_ImageSharpeningDlg::GetFrequencyFilterType ()
{
    return (DIP_FREQFILTER_TYPE) _nFreqFilterType;
}


void DIP_ImageSharpeningDlg::OnPreviewCB (int iState)
{
    cout << "DIP_ImageSharpeningDlg::OnPreviewCB" << endl;
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_ImageSharpeningDlg::PerformTransformation (bool iUpdateViewerState)
{
    cout << "DIP_ImageSharpeningDlg::PerformTransformation   " << _nDomain << endl;
    if (_nDomain == DOMAIN_SPAT)
    {
        PerformSpatTransformation (iUpdateViewerState);
    }
    else if (_nDomain == DOMAIN_FREQ)
    {
        PerformFreqTransformation (iUpdateViewerState);
    }
}


void DIP_ImageSharpeningDlg::PerformSpatTransformation (bool iUpdateViewerState)
{
    cout << "DIP_ImageSharpeningDlg::PerformSpatTransformation   " << _nSpatFilterType << endl;

    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;

        if (_nSpatFilterType == LAPLACIAN || _nSpatFilterType == SOBEL)
        {
            DIP_ImageViewerCtrl::PerformWeightedSumFilter ( pImgViewer,
                                                            pTempImage,
                                                            GetSpatialFilterType(),
                                                            _nWidth,
                                                            _nHeight,
                                                            GetBorderStrategy() );
        }
        else if (_nSpatFilterType == UNSHARPMASK || _nSpatFilterType == HIGHBOOST)
        {
            DIP_ImageViewerCtrl::PerformSharpeningFilter  ( pImgViewer,
                                                            pTempImage,
                                                            _nWidth,
                                                            _nHeight,
                                                            GetBorderStrategy(),
                                                            _dAValue );
        }

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



void DIP_ImageSharpeningDlg::PerformFreqTransformation (bool iUpdateViewerState)
{
    cout << "DIP_ImageSharpeningDlg::PerformFreqTransformation" << endl;

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


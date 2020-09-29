
#include <QTGui>
#include <QtWidgets>

#include "DIP_HistoTransDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"
#include "DIP_Image_ProcessUtils.h"

#include <iostream>
using namespace std;



DIP_HistoTransDlg::DIP_HistoTransDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _nTransform   = HISTO_SHIFT;
    _nShiftAmount = 0;
    _nStretchType = LOWERFREE_UPPERFIXED;
    _nCurrChannel = (DIP_IMAGE_CHANNEL) 0;

    plotArea -> xAxis -> setRange (0, 255);
    plotArea -> yAxis -> setRange (0, 1);
    plotArea -> xAxis -> setTicks (false);
    plotArea -> yAxis -> setTicks (false);
    plotArea -> axisRect() -> setAutoMargins (QCP::msNone);
    plotArea -> axisRect() -> setMargins (QMargins(0,0,0,0));

    rbHistoEq      -> setChecked (false);
    rbHistoShift   -> setChecked (true);
    rbHistoStretch -> setChecked (false);

    DIP_ImageViewer* pViewer = (DIP_ImageViewer*) pParent;
    if ( pViewer )
    {
        DIP_Image * pImage = pViewer -> GetCurrentImage ();
        if (pImage)
        {
            int nLimit = pImage -> GetMaxPixelValue() / 2;
            sliderShift -> setMinimum ( -1 * nLimit );
            sliderShift -> setMaximum ( nLimit );
            sliderShift -> setValue ( _nShiftAmount );
            sliderShift -> setSingleStep ( 1 );
            sliderShift -> setPageStep ( pImage -> GetMaxPixelValue() / 10 );

            pImage -> FindMinValue (_nCurrChannel, _nLowerLimit);
            pImage -> FindMaxValue (_nCurrChannel, _nUpperLimit);

            sliderLimit -> setSingleStep ( 1 );
            sliderLimit -> setPageStep ( pImage -> GetMaxPixelValue() / 10 );
            sliderLimit -> setMinimum (0);
            sliderLimit -> setMaximum (_nUpperLimit);
            sliderLimit -> setValue   (_nLowerLimit);

            UpdateGraph (pImage);
        }
    }

    comboLimits -> addItem ("Lower Limit");
    comboLimits -> addItem ("Upper Limit");
    comboLimits -> setCurrentIndex (0);

    EnableUIElements (HISTO_SHIFT);

    connect (rbHistoEq,      SIGNAL(toggled(bool)), this, SLOT(OnSelectHistoEq(bool)));
    connect (rbHistoShift,   SIGNAL(toggled(bool)), this, SLOT(OnSelectHistoShift(bool)));
    connect (rbHistoStretch, SIGNAL(toggled(bool)), this, SLOT(OnSelectHistoStretch(bool)));

    connect (sliderShift,    SIGNAL(valueChanged(int)), this, SLOT(OnChangeShiftSlider(int)));

    connect (comboLimits,    SIGNAL(currentIndexChanged(int)), this, SLOT(OnChangeLimitsCombo(int)));
    connect (sliderLimit,    SIGNAL(valueChanged(int)), this, SLOT(OnChangeLimitsSlider(int)));

    connect (cbPreview,      SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}



void DIP_HistoTransDlg::EnableUIElements (int iMode)
{
    // Three different modes...
    // 1) histogram equalization
    //     -> disable shift
    //     -> disable stretch
    // 2) histogram shift
    //     -> enable shift
    //     -> disable stretch
    // 3) histogram stretch
    //     -> disable shift
    //     -> enable stretch

    bool bEnableStretch = false;
    bool bEnableShift   = false;
    if (iMode == 2)
        bEnableShift = true;
    else if (iMode == 3)
        bEnableStretch = true;

    sliderShift -> setEnabled (bEnableShift);

    txtModLimit -> setEnabled (bEnableStretch);
    comboLimits -> setEnabled (bEnableStretch);
    sliderLimit -> setEnabled (bEnableStretch);
}



void DIP_HistoTransDlg::OnSelectHistoEq (bool iState)
{
    _nTransform = HISTO_EQ;
    EnableUIElements (HISTO_EQ);

    if (_bDoPreview)
        PerformTransformation ();
    else
        UpdateGraphNoPreview ();
}



void DIP_HistoTransDlg::OnSelectHistoShift (bool iState)
{
    _nTransform = HISTO_SHIFT;
    EnableUIElements (HISTO_SHIFT);

    //UpdateGraph (pTempImage);

    if (_bDoPreview)
        PerformTransformation ();
    else
        UpdateGraphNoPreview ();
}


void DIP_HistoTransDlg::OnSelectHistoStretch (bool iState)
{
    _nTransform = HISTO_STRETCH;
    EnableUIElements (HISTO_STRETCH);

    //UpdateGraph (pTempImage);

    if (_bDoPreview)
        PerformTransformation ();
    else
        UpdateGraphNoPreview ();
}



void DIP_HistoTransDlg::OnChangeShiftSlider (int iValue)
{
    _nShiftAmount = iValue;

    //UpdateGraph (pTempImage);

    if (_bDoPreview)
        PerformTransformation ();
    else
        UpdateGraphNoPreview ();
}



void DIP_HistoTransDlg::OnChangeLimitsSlider (int iValue)
{
    if (_nStretchType == LOWERFREE_UPPERFIXED)
        _nLowerLimit = iValue;
    else if (_nStretchType == LOWERFIXED_UPPERFREE)
        _nUpperLimit = iValue;

    //UpdateGraph (pTempImage);

    if (_bDoPreview)
        PerformTransformation ();
    else
        UpdateGraphNoPreview ();
}



void DIP_HistoTransDlg::OnChangeLimitsCombo (int iValue)
{
    if (iValue == 0)
    {
        _nStretchType = LOWERFREE_UPPERFIXED;

        sliderLimit -> setMinimum (0);
        sliderLimit -> setMaximum (_nUpperLimit);
        sliderLimit -> setValue   (_nLowerLimit);

        if (_bDoPreview)
            PerformTransformation ();
        else
            UpdateGraphNoPreview ();
    }
    else if (iValue == 1)
    {
        _nStretchType = LOWERFIXED_UPPERFREE;

        sliderLimit -> setMinimum (_nLowerLimit);
        DIP_ImageViewer* pViewer = (DIP_ImageViewer*) parentWidget();
        if (pViewer)
        {
            DIP_Image * pImage = pViewer -> GetCurrentImage ();
            if (pImage)
                   sliderLimit -> setMaximum (pImage -> GetMaxPixelValue());
        }
        sliderLimit -> setValue (_nUpperLimit);

        if (_bDoPreview)
            PerformTransformation ();
        else
            UpdateGraphNoPreview ();
    }
}


void DIP_HistoTransDlg::UpdateGraphNoPreview ()
{
    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parentWidget ();
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        DIP_Image * pResults = NULL;
        if (_nTransform == HISTO_SHIFT)
        {
            DIP_Image_ProcessUtils::ApplyHistogramShift (pImage, pResults, _nShiftAmount);
        }
        else if (_nTransform == HISTO_STRETCH)
        {
            DIP_Image_ProcessUtils::ApplyHistogramStretch (pImage,
                                                           pResults,
                                                           _nLowerLimit,
                                                           _nUpperLimit );
        }
        else if (_nTransform == HISTO_EQ)
        {
            DIP_Image_ProcessUtils::ApplyHistogramEqualization (pImage, pResults);
        }

        UpdateGraph (pResults);

        if (pResults)
            delete pResults;
    }
}



void DIP_HistoTransDlg::UpdateGraph (DIP_Image * pImage)
{
    if (pImage)
    {
        unsigned int nNumBins = pImage -> GetNumValues ();
        DIP_Histogram histogram ( nNumBins );

        pImage -> ComputeHistogram ( _nCurrChannel, histogram );

        QString strMean   = QString::number (histogram.ComputeMean(), 'f', 2);
        QString strStdDev = QString::number (histogram.ComputeStdDev(), 'f', 2);

        txtMean   -> setText (strMean);
        txtStdDev -> setText (strStdDev);

        histogram.Normalize ();

        QVector<double> xValues;
        QVector<double> yValues;

        for (unsigned int i = 0; i < nNumBins; i++)
        {
            double dValue;
            if ( histogram.GetValue ( i, dValue ) )
            {
                xValues.push_back (i);
                yValues.push_back (dValue);
            }
        }

        plotArea -> clearPlottables ();

        QCPBars * pBars = new QCPBars (plotArea -> xAxis, plotArea -> yAxis);
        if (pBars)
        {
            pBars -> setWidth (1);
            pBars -> setData (xValues, yValues);
            pBars -> setPen (Qt::NoPen);
            pBars -> setBrush (QColor (0, 0, 0, 255));
        }

        plotArea -> replot();

    } // if pImage
}



void DIP_HistoTransDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;

        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_HistoTransDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parentWidget ();
    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;

        if (_nTransform == HISTO_SHIFT)
        {
            DIP_ImageViewerCtrl::PerformHistogramShift  ( (DIP_ImageViewer*)parentWidget(),
                                                          pTempImage,
                                                          _nShiftAmount );
        }
        else if (_nTransform == HISTO_STRETCH)
        {
            DIP_ImageViewerCtrl::PerformHistogramStretch ( (DIP_ImageViewer*)parentWidget(),
                                                           pTempImage,
                                                           _nLowerLimit,
                                                           _nUpperLimit );
        }
        else if (_nTransform == HISTO_EQ)
        {
             DIP_ImageViewerCtrl::PerformHistogramEqualization ( (DIP_ImageViewer*)parentWidget(),
                                                                pTempImage);
        }

        UpdateGraph (pTempImage);

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







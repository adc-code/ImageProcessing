
#include <QTGui>
#include <QtWidgets>

#include "DIP_SigmoidalDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"

#include "DIP_MappingFunction.h"

#include <iostream>
using namespace std;



DIP_SigmoidalDlg::DIP_SigmoidalDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _dSlope            = INITIAL_SLOPE;
    _dMeanValuePercent = PERCENT_FIFTY;
    _dBottomPercent    = PERCENT_ZERO;
    _dTopPercent       = PERCENT_HUNDRED;
    _bDoPreview        = false;

    _MaxValue          = EIGHTBIT_MAX;
    DIP_ImageViewer* pImgViewer = (DIP_ImageViewer*) pParent;
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage();
        if (pImage)
            _MaxValue = pImage -> GetMaxPixelValue ();
    }

    spMeanValue -> setMinimum ( 0 );
    spMeanValue -> setMaximum ( _MaxValue );
    spMeanValue -> setValue   ( _dMeanValuePercent * _MaxValue );

    spBottom    -> setMinimum ( 0 );
    spBottom    -> setMaximum ( _MaxValue * PERCENT_FIFTY );
    spBottom    -> setValue   ( _dBottomPercent * _MaxValue );

    spTop       -> setMinimum ( _MaxValue * PERCENT_FIFTY );
    spTop       -> setMaximum ( _MaxValue );
    spTop       -> setValue   ( _dTopPercent * _MaxValue );

    spSlope     -> setValue ( _dSlope );

    UpdateGraph ();

    connect (spMeanValue, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateMeanSpinner(int)));
    connect (spSlope,     SIGNAL(valueChanged(int)), this, SLOT(OnUpdateSlopeSpinner(int)));
    connect (spBottom,    SIGNAL(valueChanged(int)), this, SLOT(OnUpdateBottomSpinner(int)));
    connect (spTop,       SIGNAL(valueChanged(int)), this, SLOT(OnUpdateTopSpinner(int)));

    connect (cbPreview,   SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}



void DIP_SigmoidalDlg::OnUpdateMeanSpinner (int iValue)
{
    _dMeanValuePercent = (double) iValue / (double) _MaxValue;

    if (_bDoPreview)
        PerformTransformation ();

    UpdateGraph ();
}


void DIP_SigmoidalDlg::OnUpdateSlopeSpinner (int iValue)
{
    _dSlope = iValue;

    if (_bDoPreview)
        PerformTransformation ();

    UpdateGraph ();
}

void DIP_SigmoidalDlg::OnUpdateTopSpinner (int iValue)
{
    _dTopPercent = (double) iValue / (double) _MaxValue;

    if (_bDoPreview)
        PerformTransformation ();

    UpdateGraph ();
}


void DIP_SigmoidalDlg::OnUpdateBottomSpinner (int iValue)
{
    _dBottomPercent = (double) iValue / (double) _MaxValue;

    if (_bDoPreview)
        PerformTransformation ();

    UpdateGraph ();
}



void DIP_SigmoidalDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_SigmoidalDlg::UpdateGraph ()
{
    // Note: when passing the parameters to the mapping function the order
    // is important.
    vector<double>  dParameters;
    dParameters.push_back ( _dSlope );
    dParameters.push_back ( _dMeanValuePercent );
    dParameters.push_back ( _dBottomPercent );
    dParameters.push_back ( _dTopPercent );

    DIP_MappingFunction  mappingFunction ( MAPFUNC_SIGMOIDAL, dParameters );

    QVector<double> xValues, yValues;
    for (double X = 0.0; X <= 1.01; X += 0.02)
    {
        double Y = 0;
        mappingFunction.Evaluate ( X, Y );

        xValues.push_back (X);
        yValues.push_back (Y);
    }

    plotArea -> addGraph ();
    plotArea -> graph (0) -> setData (xValues, yValues);
    plotArea -> xAxis -> setRange (-0.025, 1.025);
    plotArea -> yAxis -> setRange (-0.025, 1.025);
    plotArea -> xAxis -> setTicks (false);
    plotArea -> yAxis -> setTicks (false);
    plotArea -> axisRect() -> setAutoMargins (QCP::msNone);
    plotArea -> axisRect() -> setMargins (QMargins(0,0,0,0));
    QPen currentPen = plotArea -> graph(0) -> pen ();
    currentPen.setWidth (2);
    plotArea -> graph(0) -> setPen (currentPen);

    plotArea -> replot();
}


void DIP_SigmoidalDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_MAPPING_FUNCTIONTYPE mapFuncType = MAPFUNC_SIGMOIDAL;
        vector<double>  dParameters;
        dParameters.push_back ( _dSlope );
        dParameters.push_back ( _dMeanValuePercent );
        dParameters.push_back ( _dBottomPercent );
        dParameters.push_back ( _dTopPercent );

        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformGreyLevelTransformation  ( pImgViewer,
                                                               pTempImage,
                                                               mapFuncType,
                                                               dParameters );

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



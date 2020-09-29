
#include <QTGui>
#include <QtWidgets>

#include "DIP_PowerLawDlg.h"
#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"



DIP_PowerLawDlg::DIP_PowerLawDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _dGammaValue = 1.0;
    _bDoPreview  = false;

    plotArea -> xAxis -> setRange (-0.025, 1.025);
    plotArea -> yAxis -> setRange (-0.025, 1.025);
    plotArea -> xAxis -> setTicks (false);
    plotArea -> yAxis -> setTicks (false);
    plotArea -> axisRect () -> setAutoMargins (QCP::msNone);
    plotArea -> axisRect () -> setMargins (QMargins(0,0,0,0));
    plotArea -> addGraph ();

    QPen currentPen = plotArea -> graph(0) -> pen ();
    currentPen.setWidth (2);
    plotArea -> graph(0) -> setPen (currentPen);

    sbGamma -> setValue (_dGammaValue);

    UpdateGraph ();

    connect (sbGamma,   SIGNAL(valueChanged(double)), this, SLOT(OnUpdateSpinner(double)));
    connect (cbPreview, SIGNAL(stateChanged(int)),    this, SLOT(OnPreviewCB(int)));
}



void DIP_PowerLawDlg::OnUpdateSpinner (double iValue)
{
    _dGammaValue = iValue;

    UpdateGraph ();

    if (_bDoPreview)
        PerformTransformation ();
}



void DIP_PowerLawDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;

        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}



void DIP_PowerLawDlg::UpdateGraph ()
{
    DIP_MAPPING_FUNCTIONTYPE mapFuncType = MAPFUNC_POWER;

    vector <double> dParameters;
    dParameters.push_back (_dGammaValue);
    DIP_MappingFunction  mappingFunction ( mapFuncType, dParameters );

    QVector<double> xValues, yValues;
    for (double X = 0.0; X <= 1.01; X += 0.01)
    {
        double Y = 0;
        mappingFunction.Evaluate ( X, Y );

        xValues.push_back (X);
        yValues.push_back (Y);
    }

    plotArea -> graph (0) -> setData (xValues, yValues);
    plotArea -> replot ();
}



void DIP_PowerLawDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_MAPPING_FUNCTIONTYPE mapFuncType = MAPFUNC_POWER;

        vector <double> dParameters;
        dParameters.push_back (_dGammaValue);
        DIP_MappingFunction  mappingFunction ( mapFuncType, dParameters );

        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformGreyLevelTransformation ( pImgViewer,
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


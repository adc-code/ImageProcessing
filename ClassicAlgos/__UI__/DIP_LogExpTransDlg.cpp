#include <QTGui>
#include <QtWidgets>

#include "DIP_LogExpTransDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"


DIP_LogExpTransDlg::DIP_LogExpTransDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _bDoPreview = false;
    _nType      = LOGARITHMIC;

    rbLog -> setChecked (true);
    rbExp -> setChecked (false);

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

    UpdateGraph ();

    connect (rbLog, SIGNAL(toggled(bool)), this, SLOT(OnUpdateLogRB(bool)));
    connect (rbExp, SIGNAL(toggled(bool)), this, SLOT(OnUpdateExpRB(bool)));
    connect (cbPreview, SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}


void DIP_LogExpTransDlg::OnUpdateLogRB (bool bState)
{
    rbLog -> setChecked (bState);
    rbExp -> setChecked (!bState);

    _nType = LOGARITHMIC;

    UpdateGraph ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_LogExpTransDlg::OnUpdateExpRB (bool bState)
{
    rbLog -> setChecked (!bState);
    rbExp -> setChecked (bState);

    _nType = EXPONENTIAL;

    UpdateGraph ();

    if (_bDoPreview)
        PerformTransformation ();
}



void DIP_LogExpTransDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;

        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_LogExpTransDlg::UpdateGraph ()
{
    DIP_MAPPING_FUNCTIONTYPE mapFuncType = MAPFUNC_IDENTITY;

    if (_nType == LOGARITHMIC)
        mapFuncType = MAPFUNC_LOG_E;
    else
        mapFuncType = MAPFUNC_EXP_E;

    vector <double> dParameters;
    if ( ((DIP_ImageViewer*)parentWidget()) -> GetCurrentImage() )
    {
        dParameters.push_back (((DIP_ImageViewer*)parentWidget())
                                   -> GetCurrentImage() -> GetMaxPixelValue ());
    }
    else
    {
        dParameters.push_back (255);
    }

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



void DIP_LogExpTransDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer* pImgViewer = (DIP_ImageViewer*) parentWidget ();

    if (pImgViewer)
    {
        DIP_MAPPING_FUNCTIONTYPE mapFuncType = MAPFUNC_IDENTITY;

        if (_nType == LOGARITHMIC)
            mapFuncType = MAPFUNC_LOG_E;
        else
            mapFuncType = MAPFUNC_EXP_E;

        vector <double> dParameters;
        if ( pImgViewer -> GetCurrentImage() )
        {
            dParameters.push_back ( pImgViewer -> GetCurrentImage() -> GetMaxPixelValue ());
        }
        else
        {
            dParameters.push_back (255);
        }

        DIP_MappingFunction  mappingFunction ( mapFuncType, dParameters );

        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformGreyLevelTransformation ( pImgViewer,
                                                              pTempImage,
                                                              mapFuncType );

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



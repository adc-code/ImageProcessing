#include <QTGui>
#include <QtWidgets>

#include "DIP_MeanFilterDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"


DIP_MeanFilterDlg::DIP_MeanFilterDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _bDoPreview   = false;
    _nCurrentType = MEAN_ARTH;
    _dQValue      = 0.0;
    _nBorderType  = 2;

    _nWidth       = 3;
    _nHeight      = 3;

    rbArtimetic -> setChecked (true);
    rbGeometic  -> setChecked (false);
    rbHarmonic  -> setChecked (false);
    rbContra    -> setChecked (false);
    labelQ      -> setEnabled (false);
    spQValue    -> setEnabled (false);

    comboBorder -> clear ();
    comboBorder -> addItem ("Use zero");
    comboBorder -> addItem ("Copy central value");
    comboBorder -> addItem ("Copy nearest value");
    comboBorder -> addItem ("Wrap around");
    comboBorder -> setCurrentIndex (2);

    connect (rbArtimetic, SIGNAL(toggled(bool)), this, SLOT(OnUpdateArthRB(bool)));
    connect (rbGeometic,  SIGNAL(toggled(bool)), this, SLOT(OnUpdateGeoRB(bool)));
    connect (rbHarmonic,  SIGNAL(toggled(bool)), this, SLOT(OnUpdateHarmRB(bool)));
    connect (rbContra,    SIGNAL(toggled(bool)), this, SLOT(OnUpdateContraRB(bool)));
    connect (spQValue,    SIGNAL(valueChanged(double)), this, SLOT(OnUpdateQValue(double)));
    connect (spWidth,     SIGNAL(valueChanged(int)), this, SLOT(OnUpdateWidth(int)));
    connect (spHeight,    SIGNAL(valueChanged(int)), this, SLOT(OnUpdateHeight(int)));
    connect (comboBorder, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdateBorderCB(int)));
    connect (cbPreview,   SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}


void DIP_MeanFilterDlg::OnUpdateArthRB (bool bState)
{
    _nCurrentType = MEAN_ARTH;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnUpdateGeoRB (bool bState)
{
    _nCurrentType = MEAN_GEO;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnUpdateHarmRB (bool bState)
{
    _nCurrentType = MEAN_HARM;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnUpdateContraRB (bool bState)
{
    _nCurrentType = MEAN_CONTRA;

    EnableUIElements ();

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnUpdateWidth (int iValue)
{
    _nWidth = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnUpdateHeight (int iValue)
{
    _nHeight = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnUpdateBorderCB (int iValue)
{
    _nBorderType = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::EnableUIElements ()
{
    labelQ      -> setEnabled (false);
    spQValue    -> setEnabled (false);

    if (_nCurrentType == MEAN_CONTRA)
    {
        labelQ   -> setEnabled (true);
        spQValue -> setEnabled (true);
    }
}


DIP_MEANFILTER_TYPE DIP_MeanFilterDlg::GetSelectedType ()
{
    return (DIP_MEANFILTER_TYPE) _nCurrentType;
}


DIP_IMAGEBORDER_STRATEGY DIP_MeanFilterDlg::GetBorderStrategy ()
{
    return (DIP_IMAGEBORDER_STRATEGY) (_nBorderType + 1);
}


double DIP_MeanFilterDlg::GetQValue ()
{
    return spQValue -> value();
}


/*unsigned int DIP_MeanFilterDlg::GetWidth ()
{
    return _nWidth;
}


unsigned int DIP_MeanFilterDlg::GetHeight ()
{
    return _nHeight;
}*/


void DIP_MeanFilterDlg::OnUpdateQValue (double iValue)
{
    _dQValue = iValue;

    if (_bDoPreview)
        PerformTransformation ();
}


void DIP_MeanFilterDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}


void DIP_MeanFilterDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformMeanFilter ( pImgViewer,
                                                 pTempImage,
                                                 GetSelectedType(),
                                                 _nWidth,
                                                 _nHeight,
                                                 GetBorderStrategy(),
                                                 _dQValue );

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


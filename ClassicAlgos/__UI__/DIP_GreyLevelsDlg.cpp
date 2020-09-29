#include <QTGui>
#include <QtWidgets>

#include "DIP_GreyLevelsDlg.h"
#include "DIP_ImageViewer.h"

#include "DIP_Image_ProcessUtils.h"


DIP_GreyLevelsDlg::DIP_GreyLevelsDlg (QWidget * pParent)
			: QDialog (pParent)
{
    setupUi (this);

    _bDoPreview = false;
    _nAlgoType  = ALGO_SIMPLE;
    _nBPP       = 8;

    rbSimple   -> setChecked (true);
    rbImgQuant -> setChecked (false);

    sliderBPP  -> setValue (8);
    txtBPP     -> setText ("256");

    connect (sliderBPP,  SIGNAL(valueChanged(int)), this, SLOT(OnUpdateSlider(int)));

    connect (rbSimple,   SIGNAL(toggled(bool)), this, SLOT(OnSimpleAlgoRB(bool)));
    connect (rbImgQuant, SIGNAL(toggled(bool)), this, SLOT(OnAdvancedAlgoRB(bool)));

    connect (cbPreview,  SIGNAL(stateChanged(int)), this, SLOT(OnPreviewCB(int)));
}



void DIP_GreyLevelsDlg::OnUpdateSlider (int nValue)
{
    _nBPP = nValue;

    txtBPP -> setText (QString("%1").arg(2 << (nValue-1)));

    if (_bDoPreview)
        PerformUpdate ();
}



void DIP_GreyLevelsDlg::OnSimpleAlgoRB (bool bValue)
{
    rbSimple   -> setChecked (bValue);
    rbImgQuant -> setChecked (!bValue);

    _nAlgoType  = ALGO_SIMPLE;

    if (_bDoPreview)
        PerformUpdate ();
}



void DIP_GreyLevelsDlg::OnAdvancedAlgoRB (bool bValue)
{
    rbSimple   -> setChecked (!bValue);
    rbImgQuant -> setChecked (bValue);

    _nAlgoType  = ALGO_ADVANCED;

    if (_bDoPreview)
        PerformUpdate ();
}


int DIP_GreyLevelsDlg::GetSliderValue ()
{
     ; //    return sliderBPP -> value();
}



void DIP_GreyLevelsDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformUpdate ();
    }
    else
        _bDoPreview = false;
}


void DIP_GreyLevelsDlg::PerformUpdate (bool iUpdateViewerState)
{
    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parentWidget ();
    if (pImgViewer)
    {
        DIP_GREYLEVELCONVERT_TYPE type = BPPCONVERT_SIMPLE;
        if (_nAlgoType == ALGO_ADVANCED)
            type = BPPCONVERT_ADVANCED;

        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();
        DIP_IMAGE_BPP newBPP = (DIP_IMAGE_BPP) sliderBPP -> value();

        DIP_Image * pTempImage = NULL;
        DIP_Image_ProcessUtils::ApplyChangeBitsPerPixel ( pImage,
                                                          pTempImage,
                                                          newBPP,
                                                          type );

        pImgViewer -> UpdateImage (pTempImage);

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




#include <QtGui>

#include "DIP_DisplayImgDlg.h"

#include "DIP_Image.h"
#include "DIP_ImageViewer.h"
#include "DIP_QT_Utils.h"


DIP_DisplayImgDlg::DIP_DisplayImgDlg (QWidget *parent)
                 : QDialog(parent),
                   _pImageCanvas(new QLabel)
{
    setupUi (this);

    _pImageCanvas -> setBackgroundRole (QPalette::Base);
    _pImageCanvas -> setScaledContents (true);
    _pImageCanvas -> setSizePolicy (QSizePolicy::Ignored, QSizePolicy::Ignored);

    //_pImageCanvas->

//Ignored


/*    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parent;
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetImage ();

        if (pImage)
        {
            DIP_IMAGE_TYPE imgType = pImage -> GetImageType ();

            QString strType ("Unknown");
            QString strBPP ("Unknown");
            if (imgType == GREY)
            {
                strType = "Greyscale";
                strBPP = QString("%1").arg (pImage->GetBPP());
            }
            else if (imgType == RGB)
            {
                strType = "Colour RGB";
                strBPP = QString("%1").arg (pImage->GetBPP() * 3);
            }
            else if (pImage -> GetImageType() == RGBA)
            {
                strType = "Colour RGBA";
                strBPP = QString("%1").arg (pImage->GetBPP() * 4);
            }

            txtFileName -> setText (pImgViewer -> GetFilename());
            txtWidth    -> setText (QString ("%1").arg (pImage -> GetWidth()));
            txtHeight   -> setText (QString ("%1").arg (pImage -> GetHeight()));
            txtImgType  -> setText (strType);
            txtBPP      -> setText (strBPP);
        }
    }

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept())); */
}



void DIP_DisplayImgDlg::SetImage (DIP_Image * pImage)
{
    QImage tmpImage;
    DIP_QT_Utils::ConvertDIPImageToQImage (pImage, tmpImage);
    ImageCanvas -> setPixmap (QPixmap::fromImage (tmpImage));
    ImageCanvas -> setScaledContents (true);
    ImageCanvas -> setSizePolicy (QSizePolicy::Ignored, QSizePolicy::Ignored);

}



void DIP_DisplayImgDlg::resizeEvent(QResizeEvent * event)
{
    _pImageCanvas -> resize ( event->size() );
}


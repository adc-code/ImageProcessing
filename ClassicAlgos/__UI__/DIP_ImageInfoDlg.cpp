
#include <QtGui>

#include "DIP_ImageInfoDlg.h"

#include "DIP_Image.h"
#include "DIP_ImageViewer.h"


DIP_ImageInfoDlg::DIP_ImageInfoDlg (QWidget *parent)
                 : QDialog(parent)
{
    setupUi (this);

    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parent;
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

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

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
}



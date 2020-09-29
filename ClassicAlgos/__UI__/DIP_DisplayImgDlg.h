#ifndef __DIP_DISPLAYIMGDLG_H__
#define __DIP_DISPLAYIMGDLG_H__


#include <QDialog>
#include <QLabel>

#include "ui_DIP_DisplayImgDlg.h"

#include "DIP_Image.h"


class DIP_DisplayImgDlg : public QDialog, public Ui::DisplayImgDlg
{
    Q_OBJECT

    public:

        DIP_DisplayImgDlg (QWidget * parent = 0);

        void  SetImage  (DIP_Image * pImage);


    private:

        void resizeEvent (QResizeEvent * event);

        QLabel *       _pImageCanvas;
        //QScrollArea *  _pScrollArea;

};


#endif//__DIP_DISPLAYIMGDLG_H__



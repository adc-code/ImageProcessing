#ifndef __DIP_IMAGEINFODLG_H__
#define __DIP_IMAGEINFODLG_H__


#include <QDialog>
#include "ui_DIP_ImageInfoDlg.h"


class DIP_ImageInfoDlg : public QDialog, public Ui::ImageInfoDlg
{
    Q_OBJECT

    public:

        DIP_ImageInfoDlg (QWidget * parent = 0);

};


#endif//__DIP_IMAGEINFODLG_H__



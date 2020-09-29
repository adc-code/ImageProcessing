#ifndef __DIP_IMAGEHISTOGRAMDLG_H__
#define __DIP_IMAGEHISTOGRAMDLG_H__


#include <QDialog>
#include "ui_DIP_ImageHistogramDlg.h"



class DIP_ImageHistogramDlg : public QDialog, public Ui::HistogramDlg
{
    Q_OBJECT

    public:

        DIP_ImageHistogramDlg (QWidget * parent = 0);


    private slots:

        void  OnUpdateChannelCB  (int nChannel);


    private:

        void  UpdateDialogContents ();


        int  _nCurrentChannel;

};


#endif//__DIP_IMAGEHISTOGRAMDLG_H__



#ifndef __DIP_POWERLAWDLG_H__
#define __DIP_POWERLAWDLG_H__


#include <QDialog>

#include "ui_DIP_PowerLawDlg.h"



class DIP_PowerLawDlg : public QDialog, public Ui::PowerLawDialog
{
    Q_OBJECT

    public:
        
        DIP_PowerLawDlg (QWidget * pParent = 0);


        void    PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating the spinner for the Gamma value
        //
        void  OnUpdateSpinner (double iValue);

        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void    UpdateGraph ();

        double  _dGammaValue;
        bool    _bDoPreview;

};


#endif//__DIP_POWERLAWDLG_H__



#ifndef __DIP_LOGEXPTRANSDLG_H__
#define __DIP_LOGEXPTRANSDLG_H__


#include <QDialog>

#include "ui_DIP_LogExpTransDlg.h"


#define  LOGARITHMIC  1
#define  EXPONENTIAL  2



class DIP_LogExpTransDlg : public QDialog, public Ui::LogExpTransDialog
{
    Q_OBJECT

    public:
        
        DIP_LogExpTransDlg (QWidget * pParent = 0);

        void  PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating the state of the radio buttons (RB)
        //
        void  OnUpdateLogRB (bool bState);
        void  OnUpdateExpRB (bool bState);

        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void  UpdateGraph ();

        int   _nType;
        bool  _bDoPreview;

};


#endif//__DIP_LOGEXPTRANSDLG_H__



#ifndef __DIP_GREYLEVELSDLG_H__
#define __DIP_GREYLEVELSDLG_H__


#include <QDialog>

#include "ui_DIP_GreyLevelsDlg.h"


#define  ALGO_SIMPLE    1
#define  ALGO_ADVANCED  2


class DIP_GreyLevelsDlg : public QDialog, public Ui::GreyLevelsDialog
{
    Q_OBJECT

    public:
        
        DIP_GreyLevelsDlg (QWidget * pParent = 0);

        int GetSliderValue ();

        void  PerformUpdate (bool iUpdateViewerState = false);


    private slots:

        void  OnUpdateSlider (int nValue);

        void  OnSimpleAlgoRB   (bool bValue);
        void  OnAdvancedAlgoRB (bool bValue);

        void  OnPreviewCB  (int iValue);


    private:

        bool  _bDoPreview;
        int   _nAlgoType;
        int   _nBPP;

};


#endif//__DIP_GREYLEVELSDLG_H__



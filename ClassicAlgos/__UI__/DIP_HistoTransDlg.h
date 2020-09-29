#ifndef __DIP_HISTOTRANSDLG_H__
#define __DIP_HISTOTRANSDLG_H__


#include <QDialog>

#include "ui_DIP_HistoTransDlg.h"

#include "DIP_Defs.h"
#include "DIP_Image.h"


#define  HISTO_EQ       1
#define  HISTO_SHIFT    2
#define  HISTO_STRETCH  3

#define  LOWERFREE_UPPERFIXED  1
#define  LOWERFIXED_UPPERFREE  2


class DIP_HistoTransDlg : public QDialog, public Ui::HistoTransDlg
{
    Q_OBJECT

    public:
        
        DIP_HistoTransDlg (QWidget * pParent = 0);

        void  PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating different controls
        //
        void  OnSelectHistoEq      (bool iState);
        void  OnSelectHistoShift   (bool iState);
        void  OnSelectHistoStretch (bool iState);

        void  OnChangeShiftSlider  (int iValue);

        void  OnChangeLimitsCombo  (int iValue);
        void  OnChangeLimitsSlider (int iValue);

        void  OnPreviewCB          (int iState);


    private:

        void  EnableUIElements     (int iMode);
        void  UpdateGraph          (DIP_Image * pImage);
        void  UpdateGraphNoPreview ();

        int                _nShiftAmount;
        int                _nLowerLimit;
        int                _nUpperLimit;
        int                _nStretchType;
        int                _nTransform;
        bool               _bDoPreview;
        DIP_IMAGE_CHANNEL  _nCurrChannel;

};


#endif//__DIP_HISTOTRANSDLG_H__




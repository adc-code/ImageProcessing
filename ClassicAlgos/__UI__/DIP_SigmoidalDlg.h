#ifndef __DIP_SIGMOIDALDLG_H__
#define __DIP_SIGMOIDALDLG_H__


#include <QDialog>

#include "ui_DIP_SigmoidalDlg.h"

#include "DIP_Defs.h"


#define  PERCENT_ZERO     0.0
#define  PERCENT_FIFTY    0.5
#define  PERCENT_HUNDRED  1.0

#define  INITIAL_SLOPE    10

#define  EIGHTBIT_MAX     255


class DIP_SigmoidalDlg : public QDialog, public Ui::SigmoidalDialog
{
    Q_OBJECT

    public:
        
        DIP_SigmoidalDlg (QWidget * pParent = 0);

        void    PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating the spinner for different
        // dimensions/parameters
        //
        void  OnUpdateMeanSpinner (int iValue);
        void  OnUpdateSlopeSpinner (int iValue);
        void  OnUpdateBottomSpinner (int iValue);
        void  OnUpdateTopSpinner (int iValue);

        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void    UpdateGraph ();


        double          _dMeanValuePercent;
        double          _dSlope;
        double          _dBottomPercent;
        double          _dTopPercent;

        DIP_PIXEL_TYPE  _MaxValue;

        bool            _bDoPreview;

};


#endif//__DIP_SIGMOIDALDLG_H__




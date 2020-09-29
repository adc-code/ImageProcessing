#ifndef __DIP_RESIZEDLG_H__
#define __DIP_RESIZEDLG_H__


#include <QDialog>

#include "ui_DIP_ResizeDlg.h"

#include "DIP_Defs.h"


#define  MODE_PREDEFINED   1
#define  MODE_USER         2

#define  SCALE_ZOOM        1
#define  SCALE_SHRINK      2


class DIP_ResizeDlg : public QDialog, public Ui::ResizeDialog
{
    Q_OBJECT

    public:
        
        DIP_ResizeDlg (QWidget * pParent = 0);

        void    PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating the spinner for dimensions
        //
        void  OnUpdateWidthSpinner  (int iValue);
        void  OnUpdateHeightSpinner (int iValue);

        //
        // Usage mode radio buttons
        //
        void  OnUpdatePredefinedRB  (bool bState);
        void  OnUpdateUserDefinedRB (bool bState);

        void  OnUpdateZoomRB       (bool bState);
        void  OnUpdateShrinkRB     (bool bState);
        void  OnUpdatePercentageCB (int nValue);

        void  OnUpdateNearestRB  (bool bState);
        void  OnUpdateBilinearRB (bool bState);


        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void  EnableUIElements (bool bState);

        void  GetCurrentResizeValues ( unsigned int &         oWidth,
                                       unsigned int &         oHeight,
                                       DIP_IMGSCALING_TYPE &  oScalingType );


        int                  _nInputMode;
        int                  _nPreDefMode;

        int                  _nOriginalWidth;
        int                  _nOriginalHeight;
        int                  _nCurrentWidth;
        int                  _nCurrentHeight;

        double               _dPercentage;
        DIP_IMGSCALING_TYPE  _ScalingType;

        bool                 _bDoPreview;

};


#endif//__DIP_POWERLAWDLG_H__



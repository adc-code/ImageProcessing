#ifndef __DIP_MEANFILTERDLG_H__
#define __DIP_MEANFILTERDLG_H__


#include <QDialog>

#include "DIP_Defs.h"
#include "ui_DIP_MeanFilterDlg.h"


#define  MEAN_ARTH    1
#define  MEAN_GEO     2
#define  MEAN_HARM    3
#define  MEAN_CONTRA  4


class DIP_MeanFilterDlg : public QDialog, public Ui::MeanFilterDialog
{
    Q_OBJECT

    public:
        
        DIP_MeanFilterDlg (QWidget * pParent = 0);

        void  PerformTransformation (bool iUpdateViewerState = false);



    private slots:

        //
        // Used to deal with updating the state of the radio buttons (RB)
        //
        void  OnUpdateArthRB   (bool bState);
        void  OnUpdateGeoRB    (bool bState);
        void  OnUpdateHarmRB   (bool bState);
        void  OnUpdateContraRB (bool bState);

        void  OnUpdateQValue   (double iValue);

        void  OnUpdateWidth    (int iValue);
        void  OnUpdateHeight   (int iValue);

        void  OnUpdateBorderCB (int iValue);


        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void  EnableUIElements ();

        DIP_MEANFILTER_TYPE       GetSelectedType   ();
        DIP_IMAGEBORDER_STRATEGY  GetBorderStrategy ();
        double                    GetQValue         ();
        //unsigned int              GetWidth          ();
        //unsigned int              GetHeight         ();


        bool          _bDoPreview;
        int           _nCurrentType;
        double        _dQValue;
        unsigned int  _nWidth;
        unsigned int  _nHeight;
        int           _nBorderType;
};


#endif//__DIP_MEANFILTERDLG_H__



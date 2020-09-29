#ifndef __DIP_ADAPTIVEFILTERDLG_H__
#define __DIP_ADAPTIVEFILTERDLG_H__


#include <QDialog>

#include "DIP_Defs.h"
#include "ui_DIP_AdaptiveFilterDlg.h"


class DIP_AdaptiveFilterDlg : public QDialog, public Ui::AdaptiveDialog
{
    Q_OBJECT

    public:
        
        DIP_AdaptiveFilterDlg (QWidget * pParent = 0);

        void  PerformTransformation (bool iUpdateViewerState = false);
//        DIP_ORDEREDSTATFILTER_TYPE  GetSelectedType   ();
//        DIP_IMAGEBORDER_STRATEGY    GetBorderStrategy ();
//        int                         GetDValue         ();
//        unsigned int                GetWidth          ();
//        unsigned int                GetHeight         ();


    private slots:

        //
        // Used to deal with updating the state of the radio buttons (RB)
        //
//        void  OnUpdateMedianRB   (bool bState);
//        void  OnUpdateMinRB      (bool bState);
//        void  OnUpdateMaxRB      (bool bState);
//        void  OnUpdateMidpointRB (bool bState);
//        void  OnUpdateAlphaRB    (bool bState);

//        void  OnUpdateDValue     (int iValue);

        void  OnUpdateWidth     (int iValue);
        void  OnUpdateHeight    (int iValue);
        void  OnUpdateBorderCB  (int iValue);
        void  OnUpdateSMaxCB    (int iValue);

        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:



        bool                     _bDoPreview;
        int                      _nSizeIncrease;
        unsigned int             _nWidth;
        unsigned int             _nHeight;
        DIP_IMAGEBORDER_STRATEGY _nBorderType;
};


#endif//__DIP_ADAPTIVEFILTERDLG_H__



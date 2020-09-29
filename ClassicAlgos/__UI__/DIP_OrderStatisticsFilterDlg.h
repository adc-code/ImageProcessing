#ifndef __DIP_ORDERSTATISTICSFILTERDLG_H__
#define __DIP_ORDERSTATISTICSFILTERDLG_H__


#include <QDialog>

#include "DIP_Defs.h"
#include "ui_DIP_OrderStatisticsFilterDlg.h"


#define  MEDIAN    1
#define  MIN       2
#define  MAX       3
#define  MIDPOINT  4
#define  ALPHA     5


class DIP_OrderStatisticsFilterDlg : public QDialog, public Ui::OrderStatDialog
{
    Q_OBJECT

    public:
        
        DIP_OrderStatisticsFilterDlg (QWidget * pParent = 0);

        DIP_ORDEREDSTATFILTER_TYPE  GetSelectedType   ();
        DIP_IMAGEBORDER_STRATEGY    GetBorderStrategy ();
        int                         GetDValue         ();
        unsigned int                GetWidth          ();
        unsigned int                GetHeight         ();

        void  PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating the state of the radio buttons (RB)
        //
        void  OnUpdateMedianRB   (bool bState);
        void  OnUpdateMinRB      (bool bState);
        void  OnUpdateMaxRB      (bool bState);
        void  OnUpdateMidpointRB (bool bState);
        void  OnUpdateAlphaRB    (bool bState);

        void  OnUpdateDValue     (int iValue);

        void  OnUpdateWidth      (int iValue);
        void  OnUpdateHeight     (int iValue);

        void  OnUpdateBorderCB   (int iValue);


        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void  EnableUIElements ();

        bool          _bDoPreview;
        int           _nCurrentType;
        int           _nDValue;
        unsigned int  _nWidth;
        unsigned int  _nHeight;
        int           _nBorderType;
};


#endif//__DIP_ORDERSTATISTICSFILTERDLG_H__



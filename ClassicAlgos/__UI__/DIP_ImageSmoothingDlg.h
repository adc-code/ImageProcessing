#ifndef __DIP_IMAGESMOOTHINGDLG_H__
#define __DIP_IMAGESMOOTHINGDLG_H__


#include <QDialog>

#include "ui_DIP_ImageSmoothingDlg.h"
#include "DIP_Defs.h"


#define  DOMAIN_SPAT  1
#define  DOMAIN_FREQ  2

#define  FILTER_IDEAL   1
#define  FILTER_GAUSS   3
#define  FILTER_BUTTER  5


class DIP_ImageSmoothingDlg : public QDialog, public Ui::SmoothDialog
{
    Q_OBJECT

    public:
        
        DIP_ImageSmoothingDlg (QWidget * pParent = 0);

        void    PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        void    OnUpdateSpatDomainRB  (bool bState);
        void    OnUpdateFreqDomainRB  (bool bState);

        void    OnUpdateSpatType      (int iValue);
        void    OnUpdateWidth         (int iValue);
        void    OnUpdateHeight        (int iValue);
        void    OnUpdateBorderCB      (int iValue);

        void    OnUpdateIdealFilterRB (bool bState);
        void    OnUpdateGaussFilterRB (bool bState);
        void    OnUpdateButterFilterRB(bool bState);

        void    OnUpdateCutOffFreq    (int iValue);
        void    OnUpdateNValue        (int iValue);

        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void    EnableUIElements     (bool bState);

        void    PerformSpatTransformation (bool iUpdateViewerState);
        void    PerformFreqTransformation (bool iUpdateViewerState);

        DIP_WEIGHTEDSUMFILTER_TYPE  GetSpatialFilterType   ();
        DIP_IMAGEBORDER_STRATEGY    GetBorderStrategy      ();
        DIP_FREQFILTER_TYPE         GetFrequencyFilterType ();


        bool          _bDoPreview;
        int           _nDomain;
        int           _nSpatFilterType;
        int           _nFreqFilterType;
        unsigned int  _nWidth;
        unsigned int  _nHeight;
        int           _nBorderType;

        double        _dCutOffFreq;
        int           _nNValue;
};


#endif//__DIP_IMAGESMOOTHINGDLG_H__



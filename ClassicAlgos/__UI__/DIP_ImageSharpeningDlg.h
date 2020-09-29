#ifndef __DIP_IMAGESHARPENINGDLG_H__
#define __DIP_IMAGESHARPENINGDLG_H__


#include <QDialog>

#include "ui_DIP_ImageSharpeningDlg.h"
#include "DIP_Defs.h"


#define  DOMAIN_SPAT  1
#define  DOMAIN_FREQ  2

#define  LAPLACIAN    1
#define  SOBEL        2
#define  UNSHARPMASK  3
#define  HIGHBOOST    4

#define  SOBEL_HORIZ  0
#define  SOBEL_VERT   1
#define  SOBEL_DIAG1  2
#define  SOBEL_DIAG2  3

#define  FILTER_IDEAL_HP   2
#define  FILTER_GAUSS_HP   4
#define  FILTER_BUTTER_HP  6


class DIP_ImageSharpeningDlg : public QDialog, public Ui::SharpenDialog
{
    Q_OBJECT

    public:
        
        DIP_ImageSharpeningDlg (QWidget * pParent = 0);


        void    PerformTransformation (bool iUpdateViewerState=false);


    private slots:

        void    OnUpdateSpatDomainRB (bool bState);
        void    OnUpdateFreqDomainRB (bool bState);

        void    OnUpdateLaplacianRB  (bool bState);
        void    OnUpdateSobelRB      (bool bState);
        void    OnUpdateUnsharpenRB  (bool bState);
        void    OnUpdateHighboostRB  (bool bState);


        void    OnUpdateWidth        (int iValue);
        void    OnUpdateHeight       (int iValue);
        void    OnUpdateBorderCB     (int iValue);

        void    OnUpdateSobelDirCB   (int iValue);
        void    OnUpdateAValue       (double iValue);


        void    OnUpdateIdealFilterRB  (bool bState);
        void    OnUpdateGaussFilterRB  (bool bState);
        void    OnUpdateButterFilterRB (bool bState);

        void    OnUpdateCutOffFreq (int iValue);
        void    OnUpdateNValue     (int iValue);


        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void    EnableUIElements     (bool bState);
        void    EnableSpatUIElements ();

        void    PerformSpatTransformation (bool iUpdateViewerState);
        void    PerformFreqTransformation (bool iUpdateViewerState);

        DIP_WEIGHTEDSUMFILTER_TYPE  GetSpatialFilterType   ();
        DIP_IMAGEBORDER_STRATEGY    GetBorderStrategy      ();
        DIP_FREQFILTER_TYPE         GetFrequencyFilterType ();


        bool           _bDoPreview;
        int            _nDomain;
        int            _nSpatFilterType;
        int            _nFreqFilterType;
        int            _SobelDir;
        double         _dAValue;
        unsigned int   _nWidth;
        unsigned int   _nHeight;
        int            _nBorderType;

        double         _dCutOffFreq;
        int            _nNValue;

        QButtonGroup * _ButtonGroup;
};


#endif//__DIP_IMAGESHARPENINGDLG_H__



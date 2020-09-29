#ifndef __DIP_IMAGEVIEWER_H__
#define __DIP_IMAGEVIEWER_H__

#include <QMainWindow>
#include <QImage>
#include <QPrinter>

#include "DIP_Image.h"
#include "DIP_DisplayImgDlg.h"


class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;



class DIP_ImageViewer : public QMainWindow
{
    Q_OBJECT

    public:
         DIP_ImageViewer ();
        ~DIP_ImageViewer ();

        bool loadFile (const QString &);

        DIP_Image *  GetCurrentImage ();
        void         SetCurrentImage (DIP_Image * pImage);

        QString &    GetFilename ();

        void UpdateImage (DIP_Image * pNewImage);

    //
    // Callbacks...
    //
    private slots:

        void  open();
        void  saveAs();
        void  print();
        void  zoomIn();
        void  zoomOut();
        void  normalSize();
        void  about();

        void  OnImageInfo ();
        void  OnDisplayHistogram ();
        void  OnResizeImage ();
        void  OnRestoreImage ();
        void  OnDisplayImage ();

        void  OnChangeGreyLevels ();
        void  OnNegative ();
        void  OnLogExpTrans ();
        void  OnPowerLaw ();
        void  OnHistoEq ();
        void  OnSigmoidalFunc ();
        void  OnPiecewise ();

        void  OnImageSharpening ();
        void  OnImageSmoothing ();

        void  OnMeanFilter ();
        void  OnOrderStat ();
        void  OnAdaptiveFilter ();


    //protected:
    //    void  closeEvent (QCloseEvent * event);

    private:
        void createActions ();
        void createMenus   ();
        void updateActions ();
        bool saveFile (const QString &fileName);

        void setImage (DIP_Image * pImage);

        void scaleImage(double factor);
        void adjustScrollBar(QScrollBar *scrollBar, double factor);


        QString        _strFilename;
        DIP_Image *    _pOriginalImage;
        DIP_Image *    _pCurrentImage;
 
        QLabel *       _pImageCanvas;
        QScrollArea *  _pScrollArea;

        double         _dScaleFactor;
        DIP_DisplayImgDlg * _pDisplayImgDlg;

        QPrinter printer;

        QAction * saveAsAct;
        QAction * printAct;
        QAction * zoomInAct;
        QAction * zoomOutAct;
        QAction * normalSizeAct;

        QAction * _pImageInfoAction;
        QAction * _pHistogramAction;
        QAction * _pViewOrgImgAction;
        QAction * _pRestoreOrgImgAction;
        QAction * _pResizeImgAction;

        QAction * _pIntensityTransAction;
        QAction * _pChangeGreyLevelsAction;
        QAction * _pNegativeAction;
        QAction * _pLogExpAction;

        QAction * _pPowerAction;
        QAction * _pPieceWiseAction;
        QAction * _pHistogramEqAction;
        QAction * _pSigmoidalAction;

        QAction * _pSmoothingAction;
        QAction * _pSharpeningAction;
        QAction * _pMeanFilter;

        QAction * _pOrderStatistics;
        QAction * _pAdaptiveFilter;

};


#endif//__DIP_IMAGEVIEWER_H__



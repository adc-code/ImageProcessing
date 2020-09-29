
#include <QtGui>
#include <QtWidgets>

#include "DIP_ImageHistogramDlg.h"

#include "DIP_Image.h"
#include "DIP_Histogram.h"
#include "DIP_ImageViewer.h"





DIP_ImageHistogramDlg::DIP_ImageHistogramDlg (QWidget *parent)
                      : QDialog (parent)
{
    setupUi (this);

    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parent;
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();

        if (pImage)
        {
            _nCurrentChannel = 0;
            if (pImage -> GetImageType() == GREY)
            {
                comboChannel -> clear ();
                comboChannel -> addItem (QString ("Grey"));  // 0
                comboChannel -> setCurrentIndex (0);
            }
            else if ( pImage -> GetImageType() == RGB ||
                      pImage -> GetImageType() == RGBA )
            {
                comboChannel -> clear ();
                comboChannel -> addItem (QString ("Red"));    // 0
                comboChannel -> addItem (QString ("Green"));  // 1
                comboChannel -> addItem (QString ("Blue"));   // 2
                comboChannel -> setCurrentIndex (0);
            }

            UpdateDialogContents ();
        }
    } 

    connect (comboChannel, SIGNAL(currentIndexChanged(int)), SLOT(OnUpdateChannelCB(int)));
    connect (okButton, SIGNAL(clicked()), this, SLOT(accept())); 
}



void DIP_ImageHistogramDlg::OnUpdateChannelCB (int nChannel)
{
    if (nChannel != _nCurrentChannel)
    {
        _nCurrentChannel = nChannel;

        UpdateDialogContents ();
    }
}


void DIP_ImageHistogramDlg::UpdateDialogContents ()
{
    DIP_ImageViewer * pImgViewer = (DIP_ImageViewer*) parentWidget ();
    if (pImgViewer)
    {
        DIP_Image * pImage = pImgViewer -> GetCurrentImage ();
        if (pImage)
        {
            unsigned int nNumBins = pImage -> GetNumValues ();
            DIP_Histogram histogram ( nNumBins );

            pImage -> ComputeHistogram ( (DIP_IMAGE_CHANNEL) _nCurrentChannel,
                                         histogram );

            txtMean   -> setText (QString("%1").arg(histogram.ComputeMean()));
            txtStdDev -> setText (QString("%1").arg(histogram.ComputeStdDev()));
            txtCount  -> setText (QString("%1").arg(histogram.FindTotalCount()));

            DIP_PIXEL_TYPE minValue;
            pImage    -> FindMinValue ((DIP_IMAGE_CHANNEL)_nCurrentChannel, minValue);
            txtMin    -> setText (QString("%1").arg(minValue));

            DIP_PIXEL_TYPE maxValue;
            pImage    -> FindMaxValue ((DIP_IMAGE_CHANNEL)_nCurrentChannel, maxValue);
            txtMax    -> setText (QString("%1").arg(maxValue));

            histogram.Normalize ();

            QVector<double> xValues;
            QVector<double> yValues;

            for (unsigned int i = 0; i < nNumBins; i++)
            {
                double dValue;
                if ( histogram.GetValue ( i, dValue ) )
                {
                    xValues.push_back (i);
                    yValues.push_back (dValue);
                }
            }

            QCPBars * pBars = new QCPBars (plotArea -> xAxis, plotArea -> yAxis);
            if (pBars)
            {
                pBars -> setWidth (1);
                pBars -> setData (xValues, yValues);
                pBars -> setPen (Qt::NoPen);
                pBars -> setBrush (QColor (0, 0, 0, 255));
            }

            //plotArea -> addGraph();
            //plotArea -> graph(0) -> setData(xValues, yValues);

            plotArea -> xAxis -> setRange (0, 255);
            plotArea -> yAxis -> setRange (0, 1);
            plotArea -> xAxis -> setTicks (false);
            plotArea -> yAxis -> setTicks (false);
            plotArea -> axisRect() -> setAutoMargins (QCP::msNone);
            plotArea -> axisRect() -> setMargins (QMargins(0,0,0,0));
            plotArea -> replot();

        } // if pImage

    } // if pImageViewer

}

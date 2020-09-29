
#include <QTGui>
#include <QtWidgets>
#include <QMessageBox>

#include "DIP_PiecewiseDlg.h"

#include "DIP_ImageViewer.h"
#include "DIP_ImageViewerCtrl.h"

#include "DIP_MappingFunction.h"

#include <vector>

#include <iostream>


DIP_PiecewiseDlg::DIP_PiecewiseDlg (QWidget * pParent)
              : QDialog (pParent)
{
    setupUi (this);

    _nMaxValue    = 255;
    _nPresetNum   = 0;
    _nSelectedRow = ROW_NOT_SELECTED;
    _bDoPreview   = false;

    _nParams.push_back (0);
    _nParams.push_back (0);
    _nParams.push_back (_nMaxValue);
    _nParams.push_back (_nMaxValue);

    comboPreset -> clear ();
    comboPreset -> addItem ("Preset 1");
    comboPreset -> addItem ("Preset 2");
    comboPreset -> addItem ("Preset 3");
    comboPreset -> addItem ("Preset 4");
    comboPreset -> addItem ("Preset 5");
    comboPreset -> setCurrentIndex (_nPresetNum);

    pbRemovePnt -> setEnabled (false);
    pbAddPnt    -> setEnabled (false);
    spinXValue  -> setEnabled (false);
    spinYValue  -> setEnabled (false);

    plotArea -> xAxis -> setRange (-0.025, 1.025);
    plotArea -> yAxis -> setRange (-0.025, 1.025);
    plotArea -> xAxis -> setTicks (false);
    plotArea -> yAxis -> setTicks (false);
    plotArea -> axisRect () -> setAutoMargins (QCP::msNone);
    plotArea -> axisRect () -> setMargins (QMargins(0,0,0,0));
    plotArea -> addGraph ();  // line graph
    plotArea -> addGraph ();  // point graph
    plotArea -> addGraph ();  // selected graph

    QPen currentPen = plotArea -> graph(0) -> pen ();
    currentPen.setWidth (2);
    plotArea -> graph(0) -> setPen (currentPen);
    plotArea -> graph(1) -> setScatterStyle (QCPScatterStyle(QCPScatterStyle::ssCircle,
                                             Qt::blue, Qt::blue, 4));
    plotArea -> graph(2) -> setScatterStyle (QCPScatterStyle(QCPScatterStyle::ssCircle,
                                             Qt::blue, Qt::white, 8));


    tablePoints -> setColumnCount (2);
    QStringList strTableHeader;
    strTableHeader << "X" << "Y";
    tablePoints -> setHorizontalHeaderLabels (strTableHeader);
    tablePoints -> horizontalHeader() -> setSectionResizeMode (QHeaderView::Stretch);
    tablePoints -> setSelectionBehavior (QAbstractItemView::SelectRows);
    tablePoints -> verticalHeader() -> setVisible (false);
    tablePoints -> setEditTriggers (QAbstractItemView::NoEditTriggers);


    UpdateGraph    ();
    UpdatePointSet ();

    connect (pbAddPnt,    SIGNAL(released()),               this, SLOT(OnAddButton()));
    connect (pbRemovePnt, SIGNAL(released()),               this, SLOT(OnRemoveButton()));
    connect (tablePoints, SIGNAL(cellClicked(int, int)),    this, SLOT(OnCellClicked(int, int)));
    connect (comboPreset, SIGNAL(currentIndexChanged(int)), this, SLOT(OnUpdatePresetCombo(int)));
    connect (spinXValue,  SIGNAL(valueChanged(int)),        this, SLOT(OnUpdateXValue(int)));
    connect (spinYValue,  SIGNAL(valueChanged(int)),        this, SLOT(OnUpdateYValue(int)));
    connect (cbPreview,   SIGNAL(stateChanged(int)),        this, SLOT(OnPreviewCB(int)));
}



void DIP_PiecewiseDlg::OnUpdatePresetCombo (int iSelected)
{
    _nPresetNum   = iSelected;
    _nSelectedRow = ROW_NOT_SELECTED;

     vector <double>  dXWeights;
     vector <double>  dYWeights;

     if (iSelected == 0)
     {
         dXWeights.push_back (0.0);  dYWeights.push_back (0.0);
         dXWeights.push_back (1.0);  dYWeights.push_back (1.0);
     }
     else if (iSelected == 1)
     {
         dXWeights.push_back (0.0);  dYWeights.push_back (0.0);
         dXWeights.push_back (0.4);  dYWeights.push_back (0.2);
         dXWeights.push_back (0.6);  dYWeights.push_back (0.8);
         dXWeights.push_back (1.0);  dYWeights.push_back (1.0);
     }
     else if (iSelected == 2)
     {
         dXWeights.push_back (0.0);  dYWeights.push_back (0.0);
         dXWeights.push_back (0.3);  dYWeights.push_back (0.3);
         dXWeights.push_back (0.3);  dYWeights.push_back (0.8);
         dXWeights.push_back (0.7);  dYWeights.push_back (0.8);
         dXWeights.push_back (0.7);  dYWeights.push_back (0.7);
         dXWeights.push_back (1.0);  dYWeights.push_back (1.0);
     }
     else if (iSelected == 3)
     {
         dXWeights.push_back (0.0);  dYWeights.push_back (0.0);
         dXWeights.push_back (0.4);  dYWeights.push_back (0.6);
         dXWeights.push_back (1.0);  dYWeights.push_back (1.0);
     }
     else if (iSelected == 4)
     {
         dXWeights.push_back (0.0);  dYWeights.push_back (0.2);
         dXWeights.push_back (0.4);  dYWeights.push_back (0.2);
         dXWeights.push_back (0.4);  dYWeights.push_back (0.5);
         dXWeights.push_back (0.6);  dYWeights.push_back (0.5);
         dXWeights.push_back (0.6);  dYWeights.push_back (0.2);
         dXWeights.push_back (1.0);  dYWeights.push_back (0.2);
     }

     _nParams.clear ();
     for (int i = 0; i < dXWeights.size(); i++)
     {
         _nParams.push_back (_nMaxValue * dXWeights[i]);
         _nParams.push_back (_nMaxValue * dYWeights[i]);
     }

     UpdateGraph    ();
     UpdatePointSet ();

     if (_bDoPreview)
         PerformTransformation ();
}


void DIP_PiecewiseDlg::OnPreviewCB (int iState)
{
    if (iState)
    {
        _bDoPreview = true;
        PerformTransformation ();
    }
    else
        _bDoPreview = false;
}



void DIP_PiecewiseDlg::OnAddButton ()
{
    if (_nSelectedRow != ROW_NOT_SELECTED)
    {
        bool bInsertAfter = true;
        if (_nSelectedRow == tablePoints -> rowCount () - 1)
            bInsertAfter = false;

        int nInsertPosition = _nSelectedRow+1;
        int nNewX = (_nParams [ 2*(_nSelectedRow+1) ]   + _nParams [ 2*_nSelectedRow ]) / 2;
        int nNewY = (_nParams [ 2*(_nSelectedRow+1)+1 ] + _nParams [ 2*_nSelectedRow+1 ]) / 2;

        if (!bInsertAfter)
        {
            nInsertPosition = _nSelectedRow;
            nNewX = (_nParams [ 2*(_nSelectedRow) ]   + _nParams [ 2*(_nSelectedRow-1) ]) / 2;
            nNewY = (_nParams [ 2*(_nSelectedRow)+1 ] + _nParams [ 2*(_nSelectedRow-1)+1 ]) / 2;

        }

        _nParams.insert ( _nParams.begin() + 2*nInsertPosition, nNewY );
        _nParams.insert ( _nParams.begin() + 2*nInsertPosition, nNewX );

        _nSelectedRow = ROW_NOT_SELECTED;
        tablePoints -> clearSelection ();
        pbAddPnt    -> setEnabled (false);
        pbRemovePnt -> setEnabled (false);

        UpdateGraph    ();
        UpdatePointSet ();

        if (_bDoPreview)
            PerformTransformation ();
    }
}



void DIP_PiecewiseDlg::OnRemoveButton ()
{
    if (_nSelectedRow != ROW_NOT_SELECTED)
    {
        bool bFirstOrLast = false;
        if (_nSelectedRow == 0 ||
            _nSelectedRow == tablePoints -> rowCount () - 1)
        {
            bFirstOrLast = true;
        }

        if (bFirstOrLast)
        {
            _nSelectedRow = ROW_NOT_SELECTED;
            tablePoints -> clearSelection ();
            pbAddPnt    -> setEnabled (false);
            pbRemovePnt -> setEnabled (false);
            UpdateGraph ();

            QMessageBox::information (this,
                                      "Error",
                                      "Cannot remove the first or last points");
        }
        else
        {
            _nParams.erase ( _nParams.begin() + 2*_nSelectedRow );
            _nParams.erase ( _nParams.begin() + 2*_nSelectedRow );

            _nSelectedRow = ROW_NOT_SELECTED;
            tablePoints -> clearSelection ();
            pbAddPnt    -> setEnabled (false);
            pbRemovePnt -> setEnabled (false);

            UpdateGraph    ();
            UpdatePointSet ();

            if (_bDoPreview)
                PerformTransformation ();
        }
    }
}



void DIP_PiecewiseDlg::OnUpdateXValue (int iValue)
{
    if (_nSelectedRow != ROW_NOT_SELECTED)
    {
        _nParams [ 2*_nSelectedRow ] = iValue;

        UpdateGraph    ();
        UpdatePointSet ();

        tablePoints -> selectRow (_nSelectedRow);

        if (_bDoPreview)
            PerformTransformation ();
    }
}



void DIP_PiecewiseDlg::OnUpdateYValue (int iValue)
{
    if (_nSelectedRow != ROW_NOT_SELECTED)
    {
        _nParams [ 2*_nSelectedRow+1 ] = iValue;

        UpdateGraph    ();
        UpdatePointSet ();

        tablePoints -> selectRow (_nSelectedRow);

        if (_bDoPreview)
            PerformTransformation ();
    }
}



void DIP_PiecewiseDlg::UpdateGraph ()
{
    //
    // Draw the first graph
    //
    vector<double>  dParameters;
    for (int i = 0; i < _nParams.size(); i++)
    {
        dParameters.push_back ( (double) _nParams[i] / (double) _nMaxValue );
    }

    DIP_MappingFunction  mappingFunction ( MAPFUNC_PIECEWISE, dParameters );

    QVector<double> xValues, yValues;
    for (double X = 0.0; X <= 1.01; X += 0.01)
    {
        double Y = 0;
        mappingFunction.Evaluate ( X, Y );

        xValues.push_back (X);
        yValues.push_back (Y);
    }
    plotArea -> graph (0) -> setData (xValues, yValues);

    //
    // Draw the points
    //
    xValues.clear ();
    yValues.clear ();
    for (int i = 0; i < _nParams.size()-1; i+=2)
    {
        xValues.push_back ( (double) _nParams [i]   / (double) _nMaxValue);
        yValues.push_back ( (double) _nParams [i+1] / (double) _nMaxValue);
    }
    plotArea -> graph (1) -> setData (xValues, yValues);

    //
    // Draw the selected point if necessary
    //
    xValues.clear ();
    yValues.clear ();

    if (_nSelectedRow != ROW_NOT_SELECTED)
    {
        xValues.push_back ( (double) _nParams [2 * _nSelectedRow] / (double) _nMaxValue);
        yValues.push_back ( (double) _nParams [2 * _nSelectedRow+1] / (double) _nMaxValue);
    }
    plotArea -> graph (2) -> setData (xValues, yValues);

    plotArea -> replot ();
}



void DIP_PiecewiseDlg::UpdatePointSet ()
{
    cout << endl << "%%% UpdatePointSet %%%" << endl;
    tablePoints -> setRowCount (0);

    for (int i = 0; i < _nParams.size()-1; i+=2)
    {
        int row = tablePoints -> rowCount ();
        tablePoints -> insertRow (row);

        QTableWidgetItem * pXCoord = new QTableWidgetItem;
        pXCoord -> setText (QString("%1").arg(_nParams[i]));
        pXCoord -> setTextAlignment (Qt::AlignRight | Qt::AlignVCenter);
        tablePoints -> setItem (row, 0, pXCoord);

        QTableWidgetItem * pYCoord = new QTableWidgetItem;
        pYCoord -> setText (QString("%1").arg(_nParams[i+1]));
        pYCoord -> setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        tablePoints -> setItem (row, 1, pYCoord);

        cout << "   i " << _nParams[i] << "  "  << _nParams[i+1] << endl;
    }
}



void DIP_PiecewiseDlg::OnCellClicked (int iRow, int iColumn)
{
    cout << "### DIP_PiecewiseDlg::OnCellClicked ### " << endl;
    cout << "   _nSelectedRow  = " << _nSelectedRow << "  iRow = " << iRow << endl;

    if (_nSelectedRow == ROW_NOT_SELECTED || iRow != _nSelectedRow)
    {
        // If no row is currently selected -OR- a different row
        // is selected from the currently selected one...
        _nSelectedRow = iRow;
        _nSelectedCol = iColumn;

        // Note... QT will trigger callbacks (or signals) when a UI element
        // is programatically set, which is nice and can be ignored for most
        // cases.  However in this case some undesired problems can happen.
        bool bBlockState = false;
        cout << "   _nSelectedRow is now... " << _nSelectedRow << endl;
        cout << "   setting X spinner ->  " << _nParams [2*_nSelectedRow];

        {
            bBlockState = spinXValue -> blockSignals (true);
            spinXValue -> setValue (_nParams [2*_nSelectedRow]);
            if (_nSelectedRow != 0 && _nSelectedRow != (tablePoints -> rowCount () - 1) )
            {
                spinXValue -> setEnabled (true);
                spinXValue -> setMinimum (_nParams [2*(_nSelectedRow-1)]);
                spinXValue -> setMaximum (_nParams [2*(_nSelectedRow+1)]);
            }
            else
            {
                spinXValue -> setEnabled (false);
            }
            spinXValue -> blockSignals (bBlockState);
        }

        {
            bBlockState = spinYValue -> blockSignals (true);
            spinYValue -> setEnabled (true);
            spinYValue -> setValue   (_nParams [2*_nSelectedRow+1]);
            spinYValue -> setMinimum (0);
            spinYValue -> setMaximum (_nMaxValue);
            spinYValue -> blockSignals (bBlockState);
        }
        cout << "   setting Y spinner ->  " << _nParams [2*_nSelectedRow + 1];

        if (_nSelectedRow != 0 &&
            _nSelectedRow != tablePoints -> rowCount () - 1)
        {
            pbRemovePnt -> setEnabled (true);
        }
        else
        {
            pbRemovePnt -> setEnabled (false);
        }

        QString strAddButtonText = "Add Point (after)";
        if (_nSelectedRow == tablePoints -> rowCount () - 1)
        {
            strAddButtonText = "Add Point (before)";
        }

        pbAddPnt -> setEnabled (true);
        pbAddPnt -> setText (strAddButtonText);

        tablePoints -> selectRow (_nSelectedRow);

        cout << endl;
    }
    else if (iRow == _nSelectedRow)
    {
        // if the currently selected row is reselected...
        _nSelectedRow = ROW_NOT_SELECTED;
        //_nSelectedCol = ROW_NOT_SELECTED;

        tablePoints -> clearSelection ();

        spinXValue  -> setEnabled (false);
        spinYValue  -> setEnabled (false);

        pbRemovePnt -> setEnabled (false);
        pbAddPnt    -> setEnabled (false);
        spinXValue  -> setEnabled (false);
        spinYValue  -> setEnabled (false);
    }

    UpdateGraph ();
}



void DIP_PiecewiseDlg::PerformTransformation (bool iUpdateViewerState)
{
    DIP_ImageViewer *  pImgViewer = (DIP_ImageViewer*) parentWidget();

    if (pImgViewer)
    {
        DIP_MAPPING_FUNCTIONTYPE mapFuncType = MAPFUNC_PIECEWISE;
        vector<double>  dParameters;

        for (int i = 0; i < _nParams.size(); i++)
        {
            dParameters.push_back ( (double) _nParams[i] / (double) _nMaxValue );
        }

        DIP_Image * pTempImage = NULL;
        DIP_ImageViewerCtrl::PerformGreyLevelTransformation  ( pImgViewer,
                                                               pTempImage,
                                                               mapFuncType,
                                                               dParameters );

        if (!iUpdateViewerState)
        {
            if (pTempImage)
                delete pTempImage;
        }
        else
        {
            pImgViewer -> SetCurrentImage (pTempImage);
        }
    }
}

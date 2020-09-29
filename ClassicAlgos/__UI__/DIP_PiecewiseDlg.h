#ifndef __DIP_PIECEWISEDLG_H__
#define __DIP_PIECEWISEDLG_H__


#include <QDialog>
#include <vector>

#include "ui_DIP_PiecewiseDlg.h"

#include "DIP_Defs.h"


#define  ROW_NOT_SELECTED   -1


class DIP_PiecewiseDlg : public QDialog, public Ui::PiecewiseDialog
{
    Q_OBJECT

    public:

        DIP_PiecewiseDlg (QWidget * pParent = 0);

        void    PerformTransformation (bool iUpdateViewerState = false);


    private slots:

        //
        // Used to deal with updating the spinner for dimensions
        //
        void  OnUpdatePresetCombo (int iSelected);
        void  OnCellClicked       (int iRow, int iColumn);
        void  OnAddButton         ();
        void  OnRemoveButton      ();
        void  OnUpdateXValue      (int iValue);
        void  OnUpdateYValue      (int iValue);


        //
        // Used to handle if the preview checkbox was clicked
        //
        void  OnPreviewCB (int iState);


    private:

        void    UpdateGraph           ();
        void    UpdatePointSet        ();

        int               _nPresetNum;
        bool              _bDoPreview;
        int               _nSelectedRow;
        int               _nSelectedCol;
        int               _nMaxValue;
        std::vector<int>  _nParams;

};


#endif//__DIP_PIECEWISEDLG_H__

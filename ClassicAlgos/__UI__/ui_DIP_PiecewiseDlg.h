/********************************************************************************
** Form generated from reading UI file 'DIP_PiecewiseDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_PIECEWISEDLG_H
#define UI_DIP_PIECEWISEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PiecewiseDialog
{
public:
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *plotArea;
    QTableWidget *tablePoints;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboPreset;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinXValue;
    QLabel *label_4;
    QSpinBox *spinYValue;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbAddPnt;
    QPushButton *pbRemovePnt;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PiecewiseDialog)
    {
        if (PiecewiseDialog->objectName().isEmpty())
            PiecewiseDialog->setObjectName(QStringLiteral("PiecewiseDialog"));
        PiecewiseDialog->resize(501, 258);
        horizontalLayout_9 = new QHBoxLayout(PiecewiseDialog);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 5, 5, 5);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame = new QFrame(PiecewiseDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        plotArea = new QCustomPlot(frame);
        plotArea->setObjectName(QStringLiteral("plotArea"));
        plotArea->setMinimumSize(QSize(200, 200));

        horizontalLayout->addWidget(plotArea);


        horizontalLayout_8->addWidget(frame);

        tablePoints = new QTableWidget(PiecewiseDialog);
        tablePoints->setObjectName(QStringLiteral("tablePoints"));

        horizontalLayout_8->addWidget(tablePoints);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_3 = new QGroupBox(PiecewiseDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboPreset = new QComboBox(groupBox_3);
        comboPreset->setObjectName(QStringLiteral("comboPreset"));

        verticalLayout->addWidget(comboPreset);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(PiecewiseDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinXValue = new QSpinBox(groupBox_2);
        spinXValue->setObjectName(QStringLiteral("spinXValue"));
        spinXValue->setMaximum(255);
        spinXValue->setSingleStep(5);

        horizontalLayout_2->addWidget(spinXValue);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinYValue = new QSpinBox(groupBox_2);
        spinYValue->setObjectName(QStringLiteral("spinYValue"));
        spinYValue->setMaximum(255);
        spinYValue->setSingleStep(5);

        horizontalLayout_2->addWidget(spinYValue);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox = new QGroupBox(PiecewiseDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        pbAddPnt = new QPushButton(groupBox);
        pbAddPnt->setObjectName(QStringLiteral("pbAddPnt"));

        verticalLayout_2->addWidget(pbAddPnt);

        pbRemovePnt = new QPushButton(groupBox);
        pbRemovePnt->setObjectName(QStringLiteral("pbRemovePnt"));

        verticalLayout_2->addWidget(pbRemovePnt);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(groupBox);


        horizontalLayout_8->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        cbPreview = new QCheckBox(PiecewiseDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_6->addWidget(cbPreview);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        buttonBox = new QDialogButtonBox(PiecewiseDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_6->addWidget(buttonBox);


        verticalLayout_5->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_5);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(spinXValue);
        label_4->setBuddy(spinYValue);
#endif // QT_NO_SHORTCUT

        retranslateUi(PiecewiseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PiecewiseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PiecewiseDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PiecewiseDialog);
    } // setupUi

    void retranslateUi(QDialog *PiecewiseDialog)
    {
        PiecewiseDialog->setWindowTitle(QApplication::translate("PiecewiseDialog", "Piecewise-linear", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("PiecewiseDialog", "Prefill using: ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("PiecewiseDialog", "Current Point:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PiecewiseDialog", "X:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PiecewiseDialog", "Y:", Q_NULLPTR));
        groupBox->setTitle(QString());
        pbAddPnt->setText(QApplication::translate("PiecewiseDialog", "Add Point (after)", Q_NULLPTR));
        pbRemovePnt->setText(QApplication::translate("PiecewiseDialog", "      Remove Point      ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("PiecewiseDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PiecewiseDialog: public Ui_PiecewiseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_PIECEWISEDLG_H

/********************************************************************************
** Form generated from reading UI file 'DIP_SigmoidalDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_SIGMOIDALDLG_H
#define UI_DIP_SIGMOIDALDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_SigmoidalDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *plotArea;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spMeanValue;
    QLabel *label_2;
    QSpinBox *spSlope;
    QLabel *label_3;
    QSpinBox *spBottom;
    QLabel *label_4;
    QSpinBox *spTop;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SigmoidalDialog)
    {
        if (SigmoidalDialog->objectName().isEmpty())
            SigmoidalDialog->setObjectName(QStringLiteral("SigmoidalDialog"));
        SigmoidalDialog->resize(396, 255);
        horizontalLayout_4 = new QHBoxLayout(SigmoidalDialog);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame = new QFrame(SigmoidalDialog);
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


        horizontalLayout_2->addWidget(frame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(1);
        label = new QLabel(SigmoidalDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spMeanValue = new QSpinBox(SigmoidalDialog);
        spMeanValue->setObjectName(QStringLiteral("spMeanValue"));
        spMeanValue->setMaximum(255);
        spMeanValue->setSingleStep(5);

        formLayout->setWidget(0, QFormLayout::FieldRole, spMeanValue);

        label_2 = new QLabel(SigmoidalDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spSlope = new QSpinBox(SigmoidalDialog);
        spSlope->setObjectName(QStringLiteral("spSlope"));
        spSlope->setMaximum(100);
        spSlope->setSingleStep(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spSlope);

        label_3 = new QLabel(SigmoidalDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spBottom = new QSpinBox(SigmoidalDialog);
        spBottom->setObjectName(QStringLiteral("spBottom"));
        spBottom->setMaximum(127);
        spBottom->setSingleStep(5);

        formLayout->setWidget(2, QFormLayout::FieldRole, spBottom);

        label_4 = new QLabel(SigmoidalDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spTop = new QSpinBox(SigmoidalDialog);
        spTop->setObjectName(QStringLiteral("spTop"));
        spTop->setMinimum(128);
        spTop->setMaximum(255);
        spTop->setSingleStep(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, spTop);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cbPreview = new QCheckBox(SigmoidalDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_3->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(SigmoidalDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(SigmoidalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SigmoidalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SigmoidalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SigmoidalDialog);
    } // setupUi

    void retranslateUi(QDialog *SigmoidalDialog)
    {
        SigmoidalDialog->setWindowTitle(QApplication::translate("SigmoidalDialog", "Sigmoidal", Q_NULLPTR));
        label->setText(QApplication::translate("SigmoidalDialog", "Mean Value: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("SigmoidalDialog", "Slope: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("SigmoidalDialog", "Bottom Offset: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("SigmoidalDialog", "Top Offset: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("SigmoidalDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SigmoidalDialog: public Ui_SigmoidalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_SIGMOIDALDLG_H

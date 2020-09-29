/********************************************************************************
** Form generated from reading UI file 'DIP_ImageHistogramDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_IMAGEHISTOGRAMDLG_H
#define UI_DIP_IMAGEHISTOGRAMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_HistogramDlg
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *plotArea;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_6;
    QComboBox *comboChannel;
    QLabel *label;
    QLineEdit *txtMean;
    QLabel *label_4;
    QLineEdit *txtStdDev;
    QLabel *label_5;
    QLineEdit *txtCount;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txtMin;
    QLineEdit *txtMax;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *HistogramDlg)
    {
        if (HistogramDlg->objectName().isEmpty())
            HistogramDlg->setObjectName(QStringLiteral("HistogramDlg"));
        HistogramDlg->resize(549, 226);
        horizontalLayout_4 = new QHBoxLayout(HistogramDlg);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame = new QFrame(HistogramDlg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, -1);
        plotArea = new QCustomPlot(frame);
        plotArea->setObjectName(QStringLiteral("plotArea"));
        plotArea->setMinimumSize(QSize(200, 200));

        horizontalLayout_2->addWidget(plotArea);


        horizontalLayout_3->addWidget(frame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_6 = new QLabel(HistogramDlg);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        comboChannel = new QComboBox(HistogramDlg);
        comboChannel->setObjectName(QStringLiteral("comboChannel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboChannel);

        label = new QLabel(HistogramDlg);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        txtMean = new QLineEdit(HistogramDlg);
        txtMean->setObjectName(QStringLiteral("txtMean"));
        txtMean->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtMean);

        label_4 = new QLabel(HistogramDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        txtStdDev = new QLineEdit(HistogramDlg);
        txtStdDev->setObjectName(QStringLiteral("txtStdDev"));
        txtStdDev->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtStdDev);

        label_5 = new QLabel(HistogramDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        txtCount = new QLineEdit(HistogramDlg);
        txtCount->setObjectName(QStringLiteral("txtCount"));
        txtCount->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, txtCount);

        label_2 = new QLabel(HistogramDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(HistogramDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        txtMin = new QLineEdit(HistogramDlg);
        txtMin->setObjectName(QStringLiteral("txtMin"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtMin);

        txtMax = new QLineEdit(HistogramDlg);
        txtMax->setObjectName(QStringLiteral("txtMax"));

        formLayout->setWidget(5, QFormLayout::FieldRole, txtMax);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new QPushButton(HistogramDlg);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(HistogramDlg);

        QMetaObject::connectSlotsByName(HistogramDlg);
    } // setupUi

    void retranslateUi(QDialog *HistogramDlg)
    {
        HistogramDlg->setWindowTitle(QApplication::translate("HistogramDlg", "Histogram", Q_NULLPTR));
        label_6->setText(QApplication::translate("HistogramDlg", "Channel: ", Q_NULLPTR));
        label->setText(QApplication::translate("HistogramDlg", "Mean: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("HistogramDlg", "Standard Deviation: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("HistogramDlg", "Number of Samples: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("HistogramDlg", "Minimum: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("HistogramDlg", "Maximum: ", Q_NULLPTR));
        okButton->setText(QApplication::translate("HistogramDlg", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HistogramDlg: public Ui_HistogramDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_IMAGEHISTOGRAMDLG_H

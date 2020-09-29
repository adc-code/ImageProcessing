/********************************************************************************
** Form generated from reading UI file 'DIP_HistoTransDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_HISTOTRANSDLG_H
#define UI_DIP_HISTOTRANSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_HistoTransDlg
{
public:
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame;
    QCustomPlot *plotArea;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout;
    QRadioButton *rbHistoEq;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *rbHistoStretch;
    QSpacerItem *verticalSpacer;
    QRadioButton *rbHistoShift;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSlider *sliderShift;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *txtModLimit;
    QComboBox *comboLimits;
    QSlider *sliderLimit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *txtMean;
    QLabel *label_2;
    QLineEdit *txtStdDev;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HistoTransDlg)
    {
        if (HistoTransDlg->objectName().isEmpty())
            HistoTransDlg->setObjectName(QStringLiteral("HistoTransDlg"));
        HistoTransDlg->resize(550, 249);
        horizontalLayout_8 = new QHBoxLayout(HistoTransDlg);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, 5, 5, 5);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        frame = new QFrame(HistoTransDlg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(200, 200));
        frame->setMaximumSize(QSize(200, 200));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        plotArea = new QCustomPlot(frame);
        plotArea->setObjectName(QStringLiteral("plotArea"));
        plotArea->setGeometry(QRect(0, 0, 200, 200));
        plotArea->setMinimumSize(QSize(200, 200));

        horizontalLayout_7->addWidget(frame);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame_2 = new QFrame(HistoTransDlg);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, 1, 1, 1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(5);
        rbHistoEq = new QRadioButton(frame_2);
        rbHistoEq->setObjectName(QStringLiteral("rbHistoEq"));

        gridLayout->addWidget(rbHistoEq, 2, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        rbHistoStretch = new QRadioButton(frame_2);
        rbHistoStretch->setObjectName(QStringLiteral("rbHistoStretch"));

        verticalLayout_2->addWidget(rbHistoStretch);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        rbHistoShift = new QRadioButton(frame_2);
        rbHistoShift->setObjectName(QStringLiteral("rbHistoShift"));

        gridLayout->addWidget(rbHistoShift, 0, 0, 1, 1);

        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sliderShift = new QSlider(groupBox);
        sliderShift->setObjectName(QStringLiteral("sliderShift"));
        sliderShift->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderShift);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(frame_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        txtModLimit = new QLabel(groupBox_2);
        txtModLimit->setObjectName(QStringLiteral("txtModLimit"));

        horizontalLayout_2->addWidget(txtModLimit);

        comboLimits = new QComboBox(groupBox_2);
        comboLimits->setObjectName(QStringLiteral("comboLimits"));

        horizontalLayout_2->addWidget(comboLimits);


        verticalLayout->addLayout(horizontalLayout_2);

        sliderLimit = new QSlider(groupBox_2);
        sliderLimit->setObjectName(QStringLiteral("sliderLimit"));
        sliderLimit->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliderLimit);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox_2, 1, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout);

        plotArea->raise();

        verticalLayout_3->addWidget(frame_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(HistoTransDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        txtMean = new QLineEdit(HistoTransDlg);
        txtMean->setObjectName(QStringLiteral("txtMean"));
        txtMean->setFrame(true);
        txtMean->setAlignment(Qt::AlignCenter);
        txtMean->setReadOnly(true);

        horizontalLayout_5->addWidget(txtMean);

        label_2 = new QLabel(HistoTransDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        txtStdDev = new QLineEdit(HistoTransDlg);
        txtStdDev->setObjectName(QStringLiteral("txtStdDev"));
        txtStdDev->setAlignment(Qt::AlignCenter);
        txtStdDev->setReadOnly(true);

        horizontalLayout_5->addWidget(txtStdDev);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cbPreview = new QCheckBox(HistoTransDlg);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_4->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(HistoTransDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout_4);


        retranslateUi(HistoTransDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), HistoTransDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HistoTransDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(HistoTransDlg);
    } // setupUi

    void retranslateUi(QDialog *HistoTransDlg)
    {
        HistoTransDlg->setWindowTitle(QApplication::translate("HistoTransDlg", "Histogram Transformations", Q_NULLPTR));
        rbHistoEq->setText(QApplication::translate("HistoTransDlg", "Histogram Equalization", Q_NULLPTR));
        rbHistoStretch->setText(QApplication::translate("HistoTransDlg", "Histogram stretch", Q_NULLPTR));
        rbHistoShift->setText(QApplication::translate("HistoTransDlg", "Histogram shift", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        txtModLimit->setText(QApplication::translate("HistoTransDlg", "Modify: ", Q_NULLPTR));
        label->setText(QApplication::translate("HistoTransDlg", "Mean: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("HistoTransDlg", "Std Dev: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("HistoTransDlg", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HistoTransDlg: public Ui_HistoTransDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_HISTOTRANSDLG_H

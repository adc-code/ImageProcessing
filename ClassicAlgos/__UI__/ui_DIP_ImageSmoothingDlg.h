/********************************************************************************
** Form generated from reading UI file 'DIP_ImageSmoothingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_IMAGESMOOTHINGDLG_H
#define UI_DIP_IMAGESMOOTHINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SmoothDialog
{
public:
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelSpType;
    QComboBox *comboSpType;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelNeigh;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelWidth;
    QSpinBox *spWidth;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelHeight;
    QSpinBox *spHeight;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelBorder;
    QComboBox *comboBorder;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *rbSpatial;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *rbFrequency;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupFreqType;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbIdeal;
    QRadioButton *rbGauss;
    QRadioButton *rbButter;
    QFormLayout *formLayout;
    QLabel *labelFc;
    QSpinBox *spFc;
    QSpinBox *spN;
    QLabel *labelN;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SmoothDialog)
    {
        if (SmoothDialog->objectName().isEmpty())
            SmoothDialog->setObjectName(QStringLiteral("SmoothDialog"));
        SmoothDialog->resize(399, 269);
        verticalLayout_10 = new QVBoxLayout(SmoothDialog);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(5, 5, 5, 5);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(3);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_3 = new QGroupBox(SmoothDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelSpType = new QLabel(groupBox_3);
        labelSpType->setObjectName(QStringLiteral("labelSpType"));

        horizontalLayout_2->addWidget(labelSpType);

        comboSpType = new QComboBox(groupBox_3);
        comboSpType->setObjectName(QStringLiteral("comboSpType"));

        horizontalLayout_2->addWidget(comboSpType);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_6->addWidget(groupBox_3);

        groupBox = new QGroupBox(SmoothDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelNeigh = new QLabel(groupBox);
        labelNeigh->setObjectName(QStringLiteral("labelNeigh"));

        verticalLayout_4->addWidget(labelNeigh);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelWidth = new QLabel(groupBox);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        horizontalLayout_4->addWidget(labelWidth);

        spWidth = new QSpinBox(groupBox);
        spWidth->setObjectName(QStringLiteral("spWidth"));
        spWidth->setMinimum(1);
        spWidth->setMaximum(13);
        spWidth->setSingleStep(2);
        spWidth->setValue(3);

        horizontalLayout_4->addWidget(spWidth);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelHeight = new QLabel(groupBox);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        horizontalLayout_5->addWidget(labelHeight);

        spHeight = new QSpinBox(groupBox);
        spHeight->setObjectName(QStringLiteral("spHeight"));
        spHeight->setMinimum(1);
        spHeight->setMaximum(13);
        spHeight->setSingleStep(2);
        spHeight->setValue(3);

        horizontalLayout_5->addWidget(spHeight);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SmoothDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelBorder = new QLabel(groupBox_2);
        labelBorder->setObjectName(QStringLiteral("labelBorder"));

        horizontalLayout_7->addWidget(labelBorder);

        comboBorder = new QComboBox(groupBox_2);
        comboBorder->setObjectName(QStringLiteral("comboBorder"));

        horizontalLayout_7->addWidget(comboBorder);


        gridLayout_3->addLayout(horizontalLayout_7, 0, 0, 1, 1);


        verticalLayout_6->addWidget(groupBox_2);


        gridLayout->addLayout(verticalLayout_6, 0, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        rbSpatial = new QRadioButton(SmoothDialog);
        rbSpatial->setObjectName(QStringLiteral("rbSpatial"));

        verticalLayout_7->addWidget(rbSpatial);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        rbFrequency = new QRadioButton(SmoothDialog);
        rbFrequency->setObjectName(QStringLiteral("rbFrequency"));

        verticalLayout_8->addWidget(rbFrequency);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);


        gridLayout->addLayout(verticalLayout_8, 1, 0, 1, 1);

        groupFreqType = new QGroupBox(SmoothDialog);
        groupFreqType->setObjectName(QStringLiteral("groupFreqType"));
        horizontalLayout_9 = new QHBoxLayout(groupFreqType);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rbIdeal = new QRadioButton(groupFreqType);
        rbIdeal->setObjectName(QStringLiteral("rbIdeal"));

        verticalLayout->addWidget(rbIdeal);

        rbGauss = new QRadioButton(groupFreqType);
        rbGauss->setObjectName(QStringLiteral("rbGauss"));

        verticalLayout->addWidget(rbGauss);

        rbButter = new QRadioButton(groupFreqType);
        rbButter->setObjectName(QStringLiteral("rbButter"));

        verticalLayout->addWidget(rbButter);


        horizontalLayout_8->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelFc = new QLabel(groupFreqType);
        labelFc->setObjectName(QStringLiteral("labelFc"));
        labelFc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelFc);

        spFc = new QSpinBox(groupFreqType);
        spFc->setObjectName(QStringLiteral("spFc"));
        spFc->setMinimum(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, spFc);

        spN = new QSpinBox(groupFreqType);
        spN->setObjectName(QStringLiteral("spN"));
        spN->setMinimum(1);
        spN->setMaximum(4);

        formLayout->setWidget(1, QFormLayout::FieldRole, spN);

        labelN = new QLabel(groupFreqType);
        labelN->setObjectName(QStringLiteral("labelN"));
        labelN->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelN);


        horizontalLayout_8->addLayout(formLayout);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        gridLayout->addWidget(groupFreqType, 1, 1, 1, 1);


        verticalLayout_9->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbPreview = new QCheckBox(SmoothDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(SmoothDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_9->addLayout(horizontalLayout);


        verticalLayout_10->addLayout(verticalLayout_9);


        retranslateUi(SmoothDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SmoothDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SmoothDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SmoothDialog);
    } // setupUi

    void retranslateUi(QDialog *SmoothDialog)
    {
        SmoothDialog->setWindowTitle(QApplication::translate("SmoothDialog", "Image Smoothing", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        labelSpType->setText(QApplication::translate("SmoothDialog", "Filter Type: ", Q_NULLPTR));
        groupBox->setTitle(QString());
        labelNeigh->setText(QApplication::translate("SmoothDialog", "Neighbourhood Size:", Q_NULLPTR));
        labelWidth->setText(QApplication::translate("SmoothDialog", "Width: ", Q_NULLPTR));
        labelHeight->setText(QApplication::translate("SmoothDialog", "Height: ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        labelBorder->setText(QApplication::translate("SmoothDialog", "Border Strategy: ", Q_NULLPTR));
        rbSpatial->setText(QApplication::translate("SmoothDialog", "Spatial\n"
"Domain", Q_NULLPTR));
        rbFrequency->setText(QApplication::translate("SmoothDialog", "Frequency\n"
"Domain", Q_NULLPTR));
        groupFreqType->setTitle(QString());
        rbIdeal->setText(QApplication::translate("SmoothDialog", "Ideal", Q_NULLPTR));
        rbGauss->setText(QApplication::translate("SmoothDialog", "Gaussian", Q_NULLPTR));
        rbButter->setText(QApplication::translate("SmoothDialog", "Butterworth", Q_NULLPTR));
        labelFc->setText(QApplication::translate("SmoothDialog", "Cut off Frequency: ", Q_NULLPTR));
        labelN->setText(QApplication::translate("SmoothDialog", "n: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("SmoothDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SmoothDialog: public Ui_SmoothDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_IMAGESMOOTHINGDLG_H

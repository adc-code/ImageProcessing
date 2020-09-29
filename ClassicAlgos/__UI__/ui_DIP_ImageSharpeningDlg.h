/********************************************************************************
** Form generated from reading UI file 'DIP_ImageSharpeningDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_IMAGESHARPENINGDLG_H
#define UI_DIP_IMAGESHARPENINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
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

class Ui_SharpenDialog
{
public:
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_10;
    QRadioButton *rbSpatial;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QRadioButton *rbFrequency;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *rbLaplacian;
    QRadioButton *rbSobel;
    QRadioButton *rbUnsharp;
    QRadioButton *rbHB;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelSobelDir;
    QComboBox *comboDirection;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelA;
    QDoubleSpinBox *spAValue;
    QSpacerItem *verticalSpacer_6;
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
    QLabel *labelN;
    QSpinBox *spN;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SharpenDialog)
    {
        if (SharpenDialog->objectName().isEmpty())
            SharpenDialog->setObjectName(QStringLiteral("SharpenDialog"));
        SharpenDialog->resize(445, 329);
        horizontalLayout_11 = new QHBoxLayout(SharpenDialog);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 5, 5, 5);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        frame = new QFrame(SharpenDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_10 = new QHBoxLayout(frame);
        horizontalLayout_10->setSpacing(4);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_10 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_10);

        rbSpatial = new QRadioButton(frame);
        rbSpatial->setObjectName(QStringLiteral("rbSpatial"));

        verticalLayout_2->addWidget(rbSpatial);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        rbFrequency = new QRadioButton(frame);
        rbFrequency->setObjectName(QStringLiteral("rbFrequency"));

        verticalLayout_2->addWidget(rbFrequency);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_10->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(3);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_3);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_13 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_13->setSpacing(-1);
#endif
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        rbLaplacian = new QRadioButton(groupBox_3);
        rbLaplacian->setObjectName(QStringLiteral("rbLaplacian"));

        verticalLayout_6->addWidget(rbLaplacian);

        rbSobel = new QRadioButton(groupBox_3);
        rbSobel->setObjectName(QStringLiteral("rbSobel"));

        verticalLayout_6->addWidget(rbSobel);

        rbUnsharp = new QRadioButton(groupBox_3);
        rbUnsharp->setObjectName(QStringLiteral("rbUnsharp"));

        verticalLayout_6->addWidget(rbUnsharp);

        rbHB = new QRadioButton(groupBox_3);
        rbHB->setObjectName(QStringLiteral("rbHB"));

        verticalLayout_6->addWidget(rbHB);


        horizontalLayout_13->addLayout(verticalLayout_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(1);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelSobelDir = new QLabel(groupBox_3);
        labelSobelDir->setObjectName(QStringLiteral("labelSobelDir"));

        horizontalLayout_2->addWidget(labelSobelDir);

        comboDirection = new QComboBox(groupBox_3);
        comboDirection->setObjectName(QStringLiteral("comboDirection"));

        horizontalLayout_2->addWidget(comboDirection);


        verticalLayout_9->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelA = new QLabel(groupBox_3);
        labelA->setObjectName(QStringLiteral("labelA"));
        labelA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelA);

        spAValue = new QDoubleSpinBox(groupBox_3);
        spAValue->setObjectName(QStringLiteral("spAValue"));
        spAValue->setMinimum(1);
        spAValue->setMaximum(2);
        spAValue->setSingleStep(0.1);

        horizontalLayout_3->addWidget(spAValue);


        verticalLayout_9->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_6);


        horizontalLayout_13->addLayout(verticalLayout_9);


        horizontalLayout_14->addLayout(horizontalLayout_13);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(false);
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


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame);
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


        verticalLayout_10->addWidget(groupBox_2);


        verticalLayout_5->addLayout(verticalLayout_10);

        groupFreqType = new QGroupBox(frame);
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

        formLayout->setWidget(0, QFormLayout::FieldRole, spFc);

        labelN = new QLabel(groupFreqType);
        labelN->setObjectName(QStringLiteral("labelN"));
        labelN->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelN);

        spN = new QSpinBox(groupFreqType);
        spN->setObjectName(QStringLiteral("spN"));
        spN->setMinimum(0);
        spN->setMaximum(10);
        spN->setSingleStep(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spN);


        horizontalLayout_8->addLayout(formLayout);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(groupFreqType);


        horizontalLayout_10->addLayout(verticalLayout_5);


        verticalLayout_7->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(3, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cbPreview = new QCheckBox(SharpenDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(SharpenDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_7->addLayout(horizontalLayout);


        horizontalLayout_11->addLayout(verticalLayout_7);


        retranslateUi(SharpenDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SharpenDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SharpenDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SharpenDialog);
    } // setupUi

    void retranslateUi(QDialog *SharpenDialog)
    {
        SharpenDialog->setWindowTitle(QApplication::translate("SharpenDialog", "Image Sharpening", Q_NULLPTR));
        rbSpatial->setText(QApplication::translate("SharpenDialog", "Spatial\n"
"Domain", Q_NULLPTR));
        rbFrequency->setText(QApplication::translate("SharpenDialog", "Frequency\n"
"Domain", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        rbLaplacian->setText(QApplication::translate("SharpenDialog", "Laplacian", Q_NULLPTR));
        rbSobel->setText(QApplication::translate("SharpenDialog", "Sobel", Q_NULLPTR));
        rbUnsharp->setText(QApplication::translate("SharpenDialog", "Unsharp Masking", Q_NULLPTR));
        rbHB->setText(QApplication::translate("SharpenDialog", "High boost", Q_NULLPTR));
        labelSobelDir->setText(QApplication::translate("SharpenDialog", "Direction: ", Q_NULLPTR));
        labelA->setText(QApplication::translate("SharpenDialog", "A: ", Q_NULLPTR));
        groupBox->setTitle(QString());
        labelNeigh->setText(QApplication::translate("SharpenDialog", "Neighbourhood Size:", Q_NULLPTR));
        labelWidth->setText(QApplication::translate("SharpenDialog", "Width: ", Q_NULLPTR));
        labelHeight->setText(QApplication::translate("SharpenDialog", "Height: ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        labelBorder->setText(QApplication::translate("SharpenDialog", "Border Strategy: ", Q_NULLPTR));
        groupFreqType->setTitle(QString());
        rbIdeal->setText(QApplication::translate("SharpenDialog", "Ideal", Q_NULLPTR));
        rbGauss->setText(QApplication::translate("SharpenDialog", "Gaussian", Q_NULLPTR));
        rbButter->setText(QApplication::translate("SharpenDialog", "Butterworth", Q_NULLPTR));
        labelFc->setText(QApplication::translate("SharpenDialog", "Cut off Frequency: ", Q_NULLPTR));
        labelN->setText(QApplication::translate("SharpenDialog", "n: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("SharpenDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SharpenDialog: public Ui_SharpenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_IMAGESHARPENINGDLG_H

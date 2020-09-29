/********************************************************************************
** Form generated from reading UI file 'DIP_GreyLevelsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_GREYLEVELSDLG_H
#define UI_DIP_GREYLEVELSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GreyLevelsDialog
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbSimple;
    QRadioButton *rbImgQuant;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *sliderBPP;
    QLineEdit *txtBPP;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GreyLevelsDialog)
    {
        if (GreyLevelsDialog->objectName().isEmpty())
            GreyLevelsDialog->setObjectName(QStringLiteral("GreyLevelsDialog"));
        GreyLevelsDialog->resize(344, 147);
        horizontalLayout_6 = new QHBoxLayout(GreyLevelsDialog);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(GreyLevelsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        rbSimple = new QRadioButton(groupBox);
        rbSimple->setObjectName(QStringLiteral("rbSimple"));

        horizontalLayout_4->addWidget(rbSimple);

        rbImgQuant = new QRadioButton(groupBox);
        rbImgQuant->setObjectName(QStringLiteral("rbImgQuant"));

        horizontalLayout_4->addWidget(rbImgQuant);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(GreyLevelsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        sliderBPP = new QSlider(groupBox_2);
        sliderBPP->setObjectName(QStringLiteral("sliderBPP"));
        sliderBPP->setMinimum(1);
        sliderBPP->setMaximum(8);
        sliderBPP->setOrientation(Qt::Horizontal);
        sliderBPP->setInvertedControls(false);
        sliderBPP->setTickPosition(QSlider::TicksBelow);
        sliderBPP->setTickInterval(1);

        horizontalLayout->addWidget(sliderBPP);

        txtBPP = new QLineEdit(groupBox_2);
        txtBPP->setObjectName(QStringLiteral("txtBPP"));
        txtBPP->setMaximumSize(QSize(40, 16777215));
        txtBPP->setMaxLength(4);
        txtBPP->setAlignment(Qt::AlignCenter);
        txtBPP->setReadOnly(true);

        horizontalLayout->addWidget(txtBPP);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cbPreview = new QCheckBox(GreyLevelsDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_2->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(GreyLevelsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout);


        retranslateUi(GreyLevelsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GreyLevelsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GreyLevelsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GreyLevelsDialog);
    } // setupUi

    void retranslateUi(QDialog *GreyLevelsDialog)
    {
        GreyLevelsDialog->setWindowTitle(QApplication::translate("GreyLevelsDialog", "Modify Grey Levels", Q_NULLPTR));
        groupBox->setTitle(QString());
        rbSimple->setText(QApplication::translate("GreyLevelsDialog", "Simple\n"
"(Division based)", Q_NULLPTR));
        rbImgQuant->setText(QApplication::translate("GreyLevelsDialog", "Grey Level\n"
"Quantization", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("GreyLevelsDialog", "Number of Grey Levels", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("GreyLevelsDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GreyLevelsDialog: public Ui_GreyLevelsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_GREYLEVELSDLG_H

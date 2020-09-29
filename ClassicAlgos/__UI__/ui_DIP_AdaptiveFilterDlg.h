/********************************************************************************
** Form generated from reading UI file 'DIP_AdaptiveFilterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_ADAPTIVEFILTERDLG_H
#define UI_DIP_ADAPTIVEFILTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdaptiveDialog
{
public:
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelNeigh;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelWidth;
    QSpinBox *spWidth;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelHeight;
    QSpinBox *spHeight;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelNeigh_2;
    QComboBox *comboSMax;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelBorder;
    QComboBox *comboBorder;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AdaptiveDialog)
    {
        if (AdaptiveDialog->objectName().isEmpty())
            AdaptiveDialog->setObjectName(QStringLiteral("AdaptiveDialog"));
        AdaptiveDialog->resize(303, 198);
        horizontalLayout_10 = new QHBoxLayout(AdaptiveDialog);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, 5, 5, 5);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_3 = new QGroupBox(AdaptiveDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        labelNeigh = new QLabel(groupBox_3);
        labelNeigh->setObjectName(QStringLiteral("labelNeigh"));

        verticalLayout_2->addWidget(labelNeigh);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelWidth = new QLabel(groupBox_3);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));
        labelWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelWidth);

        spWidth = new QSpinBox(groupBox_3);
        spWidth->setObjectName(QStringLiteral("spWidth"));
        spWidth->setMinimum(1);
        spWidth->setMaximum(13);
        spWidth->setSingleStep(2);
        spWidth->setValue(3);

        horizontalLayout->addWidget(spWidth);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelHeight = new QLabel(groupBox_3);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));
        labelHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelHeight);

        spHeight = new QSpinBox(groupBox_3);
        spHeight->setObjectName(QStringLiteral("spHeight"));
        spHeight->setMinimum(1);
        spHeight->setMaximum(13);
        spHeight->setSingleStep(2);
        spHeight->setValue(3);

        horizontalLayout_2->addWidget(spHeight);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(AdaptiveDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelNeigh_2 = new QLabel(groupBox_2);
        labelNeigh_2->setObjectName(QStringLiteral("labelNeigh_2"));
        labelNeigh_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelNeigh_2);

        comboSMax = new QComboBox(groupBox_2);
        comboSMax->setObjectName(QStringLiteral("comboSMax"));

        horizontalLayout_3->addWidget(comboSMax);


        horizontalLayout_8->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(AdaptiveDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_7 = new QHBoxLayout(groupBox);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelBorder = new QLabel(groupBox);
        labelBorder->setObjectName(QStringLiteral("labelBorder"));
        labelBorder->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(labelBorder);

        comboBorder = new QComboBox(groupBox);
        comboBorder->setObjectName(QStringLiteral("comboBorder"));

        horizontalLayout_6->addWidget(comboBorder);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cbPreview = new QCheckBox(AdaptiveDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_5->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(AdaptiveDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_5->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_3);


        retranslateUi(AdaptiveDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdaptiveDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdaptiveDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdaptiveDialog);
    } // setupUi

    void retranslateUi(QDialog *AdaptiveDialog)
    {
        AdaptiveDialog->setWindowTitle(QApplication::translate("AdaptiveDialog", "Adaptive Median Filter", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        labelNeigh->setText(QApplication::translate("AdaptiveDialog", "Neighbourhood Size:", Q_NULLPTR));
        labelWidth->setText(QApplication::translate("AdaptiveDialog", "Width: ", Q_NULLPTR));
        labelHeight->setText(QApplication::translate("AdaptiveDialog", "Height: ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        labelNeigh_2->setText(QApplication::translate("AdaptiveDialog", "Max isotropic size increase:", Q_NULLPTR));
        groupBox->setTitle(QString());
        labelBorder->setText(QApplication::translate("AdaptiveDialog", "Border Strategy: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("AdaptiveDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdaptiveDialog: public Ui_AdaptiveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_ADAPTIVEFILTERDLG_H

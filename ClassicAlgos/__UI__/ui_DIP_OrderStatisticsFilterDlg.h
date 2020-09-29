/********************************************************************************
** Form generated from reading UI file 'DIP_OrderStatisticsFilterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_ORDERSTATISTICSFILTERDLG_H
#define UI_DIP_ORDERSTATISTICSFILTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
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

class Ui_OrderStatDialog
{
public:
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *MeanFilterGroup;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbMedian;
    QRadioButton *rbMin;
    QRadioButton *rbMax;
    QRadioButton *rbMidpoint;
    QRadioButton *rbAlpha;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *labelD;
    QSpinBox *spDValue;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *spWidth;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spHeight;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QComboBox *comboBorder;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cbPreview;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OrderStatDialog)
    {
        if (OrderStatDialog->objectName().isEmpty())
            OrderStatDialog->setObjectName(QStringLiteral("OrderStatDialog"));
        OrderStatDialog->resize(284, 284);
        horizontalLayout_8 = new QHBoxLayout(OrderStatDialog);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(6, 6, 6, 6);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, -1, -1, -1);
        MeanFilterGroup = new QGroupBox(OrderStatDialog);
        MeanFilterGroup->setObjectName(QStringLiteral("MeanFilterGroup"));
        gridLayout = new QGridLayout(MeanFilterGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rbMedian = new QRadioButton(MeanFilterGroup);
        rbMedian->setObjectName(QStringLiteral("rbMedian"));

        verticalLayout->addWidget(rbMedian);

        rbMin = new QRadioButton(MeanFilterGroup);
        rbMin->setObjectName(QStringLiteral("rbMin"));

        verticalLayout->addWidget(rbMin);

        rbMax = new QRadioButton(MeanFilterGroup);
        rbMax->setObjectName(QStringLiteral("rbMax"));

        verticalLayout->addWidget(rbMax);

        rbMidpoint = new QRadioButton(MeanFilterGroup);
        rbMidpoint->setObjectName(QStringLiteral("rbMidpoint"));

        verticalLayout->addWidget(rbMidpoint);

        rbAlpha = new QRadioButton(MeanFilterGroup);
        rbAlpha->setObjectName(QStringLiteral("rbAlpha"));

        verticalLayout->addWidget(rbAlpha);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelD = new QLabel(MeanFilterGroup);
        labelD->setObjectName(QStringLiteral("labelD"));
        labelD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelD);

        spDValue = new QSpinBox(MeanFilterGroup);
        spDValue->setObjectName(QStringLiteral("spDValue"));
        spDValue->setMaximum(3);

        horizontalLayout->addWidget(spDValue);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addWidget(MeanFilterGroup);

        groupBox = new QGroupBox(OrderStatDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

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
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

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


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(OrderStatDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        comboBorder = new QComboBox(groupBox_2);
        comboBorder->setObjectName(QStringLiteral("comboBorder"));

        horizontalLayout_7->addWidget(comboBorder);


        gridLayout_3->addLayout(horizontalLayout_7, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cbPreview = new QCheckBox(OrderStatDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_3->addWidget(cbPreview);

        buttonBox = new QDialogButtonBox(OrderStatDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_5);


        retranslateUi(OrderStatDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OrderStatDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OrderStatDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OrderStatDialog);
    } // setupUi

    void retranslateUi(QDialog *OrderStatDialog)
    {
        OrderStatDialog->setWindowTitle(QApplication::translate("OrderStatDialog", "Ordered Statistics Filter", Q_NULLPTR));
        MeanFilterGroup->setTitle(QString());
        rbMedian->setText(QApplication::translate("OrderStatDialog", "Median", Q_NULLPTR));
        rbMin->setText(QApplication::translate("OrderStatDialog", "Min", Q_NULLPTR));
        rbMax->setText(QApplication::translate("OrderStatDialog", "Max", Q_NULLPTR));
        rbMidpoint->setText(QApplication::translate("OrderStatDialog", "Midpoint", Q_NULLPTR));
        rbAlpha->setText(QApplication::translate("OrderStatDialog", "Alpha trimmed mean", Q_NULLPTR));
        labelD->setText(QApplication::translate("OrderStatDialog", "d:", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("OrderStatDialog", "Neighbourhood Size:", Q_NULLPTR));
        label_3->setText(QApplication::translate("OrderStatDialog", "Width: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("OrderStatDialog", "Height: ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("OrderStatDialog", "Border Strategy: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("OrderStatDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OrderStatDialog: public Ui_OrderStatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_ORDERSTATISTICSFILTERDLG_H

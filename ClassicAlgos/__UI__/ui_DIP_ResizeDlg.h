/********************************************************************************
** Form generated from reading UI file 'DIP_ResizeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_RESIZEDLG_H
#define UI_DIP_RESIZEDLG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResizeDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QRadioButton *rbNearest;
    QRadioButton *rbBilinear;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbZoom;
    QRadioButton *rbShrink;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelPercent;
    QComboBox *cbPercentage;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rbPredefined;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rbUser;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelWidth;
    QSpinBox *sbWidth;
    QLabel *labelHeight;
    QSpinBox *sbHeight;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeDialog)
    {
        if (ResizeDialog->objectName().isEmpty())
            ResizeDialog->setObjectName(QStringLiteral("ResizeDialog"));
        ResizeDialog->resize(428, 214);
        verticalLayout_6 = new QVBoxLayout(ResizeDialog);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 5, 5, 5);
        groupBox = new QGroupBox(ResizeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        rbNearest = new QRadioButton(groupBox);
        rbNearest->setObjectName(QStringLiteral("rbNearest"));

        horizontalLayout_2->addWidget(rbNearest);

        rbBilinear = new QRadioButton(groupBox);
        rbBilinear->setObjectName(QStringLiteral("rbBilinear"));

        horizontalLayout_2->addWidget(rbBilinear);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_6->addWidget(groupBox);

        widget_2 = new QWidget(ResizeDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_4 = new QGridLayout(widget_2);
#ifndef Q_OS_MAC
        gridLayout_4->setSpacing(-1);
#endif
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(1, 1, 1, 1);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 11, 0, 12);
        groupBox1 = new QGroupBox(widget_2);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        gridLayout = new QGridLayout(groupBox1);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rbZoom = new QRadioButton(groupBox1);
        rbZoom->setObjectName(QStringLiteral("rbZoom"));

        verticalLayout_2->addWidget(rbZoom);

        rbShrink = new QRadioButton(groupBox1);
        rbShrink->setObjectName(QStringLiteral("rbShrink"));

        verticalLayout_2->addWidget(rbShrink);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 12, -1);
        labelPercent = new QLabel(groupBox1);
        labelPercent->setObjectName(QStringLiteral("labelPercent"));

        verticalLayout_3->addWidget(labelPercent);

        cbPercentage = new QComboBox(groupBox1);
        cbPercentage->setObjectName(QStringLiteral("cbPercentage"));

        verticalLayout_3->addWidget(cbPercentage);


        horizontalLayout_5->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox1, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(12, -1, 0, -1);
        rbPredefined = new QRadioButton(widget_2);
        rbPredefined->setObjectName(QStringLiteral("rbPredefined"));

        verticalLayout_4->addWidget(rbPredefined);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(12, -1, -1, -1);
        rbUser = new QRadioButton(widget_2);
        rbUser->setObjectName(QStringLiteral("rbUser"));

        verticalLayout_5->addWidget(rbUser);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        gridLayout_3->addLayout(verticalLayout_5, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 12, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelWidth = new QLabel(groupBox_2);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        horizontalLayout_3->addWidget(labelWidth);

        sbWidth = new QSpinBox(groupBox_2);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        sbWidth->setMinimum(1);
        sbWidth->setMaximum(3000);

        horizontalLayout_3->addWidget(sbWidth);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        labelHeight = new QLabel(groupBox_2);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        horizontalLayout_4->addWidget(labelHeight);

        sbHeight = new QSpinBox(groupBox_2);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sbHeight->setMinimum(1);
        sbHeight->setMaximum(3000);

        horizontalLayout_4->addWidget(sbHeight);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        verticalLayout_6->addWidget(widget_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, -1, 12, -1);
        cbPreview = new QCheckBox(ResizeDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(ResizeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_6->addLayout(horizontalLayout);


        retranslateUi(ResizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeDialog)
    {
        ResizeDialog->setWindowTitle(QApplication::translate("ResizeDialog", "Resize Image", Q_NULLPTR));
        label->setText(QApplication::translate("ResizeDialog", "   Interpolation Type:  ", Q_NULLPTR));
        rbNearest->setText(QApplication::translate("ResizeDialog", "Nearest Neighbour", Q_NULLPTR));
        rbBilinear->setText(QApplication::translate("ResizeDialog", "Bilinear", Q_NULLPTR));
        groupBox1->setTitle(QString());
        rbZoom->setText(QApplication::translate("ResizeDialog", "Zoom", Q_NULLPTR));
        rbShrink->setText(QApplication::translate("ResizeDialog", "Shrink", Q_NULLPTR));
        labelPercent->setText(QApplication::translate("ResizeDialog", "Percentage: ", Q_NULLPTR));
        cbPercentage->clear();
        cbPercentage->insertItems(0, QStringList()
         << QApplication::translate("ResizeDialog", "10%", Q_NULLPTR)
         << QApplication::translate("ResizeDialog", "25%", Q_NULLPTR)
         << QApplication::translate("ResizeDialog", "50%", Q_NULLPTR)
         << QApplication::translate("ResizeDialog", "100%", Q_NULLPTR)
        );
        rbPredefined->setText(QApplication::translate("ResizeDialog", "Predefined", Q_NULLPTR));
        rbUser->setText(QApplication::translate("ResizeDialog", "User Defined", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        labelWidth->setText(QApplication::translate("ResizeDialog", "Width: ", Q_NULLPTR));
        labelHeight->setText(QApplication::translate("ResizeDialog", "Height: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("ResizeDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResizeDialog: public Ui_ResizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_RESIZEDLG_H

/********************************************************************************
** Form generated from reading UI file 'DIP_PowerLawDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_POWERLAWDLG_H
#define UI_DIP_POWERLAWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PowerLawDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *plotArea;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QDoubleSpinBox *sbGamma;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PowerLawDialog)
    {
        if (PowerLawDialog->objectName().isEmpty())
            PowerLawDialog->setObjectName(QStringLiteral("PowerLawDialog"));
        PowerLawDialog->resize(264, 298);
        horizontalLayout_4 = new QHBoxLayout(PowerLawDialog);
#ifndef Q_OS_MAC
        horizontalLayout_4->setSpacing(-1);
#endif
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(PowerLawDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        plotArea = new QCustomPlot(frame);
        plotArea->setObjectName(QStringLiteral("plotArea"));
        plotArea->setMinimumSize(QSize(200, 200));

        horizontalLayout_3->addWidget(plotArea);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label = new QLabel(PowerLawDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        sbGamma = new QDoubleSpinBox(PowerLawDialog);
        sbGamma->setObjectName(QStringLiteral("sbGamma"));
        sbGamma->setMinimum(0.01);
        sbGamma->setMaximum(20);
        sbGamma->setSingleStep(0.1);

        horizontalLayout->addWidget(sbGamma);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cbPreview = new QCheckBox(PowerLawDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_2->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(PowerLawDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(PowerLawDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PowerLawDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PowerLawDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PowerLawDialog);
    } // setupUi

    void retranslateUi(QDialog *PowerLawDialog)
    {
        PowerLawDialog->setWindowTitle(QApplication::translate("PowerLawDialog", "Power Law", Q_NULLPTR));
        label->setText(QApplication::translate("PowerLawDialog", "Gamma : ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("PowerLawDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PowerLawDialog: public Ui_PowerLawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_POWERLAWDLG_H

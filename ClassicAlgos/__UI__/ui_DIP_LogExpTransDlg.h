/********************************************************************************
** Form generated from reading UI file 'DIP_LogExpTransDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_LOGEXPTRANSDLG_H
#define UI_DIP_LOGEXPTRANSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_LogExpTransDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *plotArea;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *rbLog;
    QRadioButton *rbExp;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbPreview;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LogExpTransDialog)
    {
        if (LogExpTransDialog->objectName().isEmpty())
            LogExpTransDialog->setObjectName(QStringLiteral("LogExpTransDialog"));
        LogExpTransDialog->resize(264, 284);
        horizontalLayout_4 = new QHBoxLayout(LogExpTransDialog);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(LogExpTransDialog);
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        rbLog = new QRadioButton(LogExpTransDialog);
        rbLog->setObjectName(QStringLiteral("rbLog"));

        horizontalLayout_2->addWidget(rbLog);

        rbExp = new QRadioButton(LogExpTransDialog);
        rbExp->setObjectName(QStringLiteral("rbExp"));

        horizontalLayout_2->addWidget(rbExp);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbPreview = new QCheckBox(LogExpTransDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout->addWidget(cbPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(LogExpTransDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(LogExpTransDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogExpTransDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogExpTransDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogExpTransDialog);
    } // setupUi

    void retranslateUi(QDialog *LogExpTransDialog)
    {
        LogExpTransDialog->setWindowTitle(QApplication::translate("LogExpTransDialog", "Log/Exp Transformation", Q_NULLPTR));
        rbLog->setText(QApplication::translate("LogExpTransDialog", "Logarithmic      ", Q_NULLPTR));
        rbExp->setText(QApplication::translate("LogExpTransDialog", "Exponential", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("LogExpTransDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogExpTransDialog: public Ui_LogExpTransDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_LOGEXPTRANSDLG_H

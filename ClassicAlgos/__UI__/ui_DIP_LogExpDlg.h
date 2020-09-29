/********************************************************************************
** Form generated from reading UI file 'DIP_LogExpDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_LOGEXPDLG_H
#define UI_DIP_LOGEXPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogExpDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rbLog;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *rbExp;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LogExpDialog)
    {
        if (LogExpDialog->objectName().isEmpty())
            LogExpDialog->setObjectName(QStringLiteral("LogExpDialog"));
        LogExpDialog->resize(300, 102);
        verticalLayout = new QVBoxLayout(LogExpDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_2->setSpacing(-1);
#endif
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, -1, 0, 1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        rbLog = new QRadioButton(LogExpDialog);
        rbLog->setObjectName(QStringLiteral("rbLog"));

        horizontalLayout_2->addWidget(rbLog);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        rbExp = new QRadioButton(LogExpDialog);
        rbExp->setObjectName(QStringLiteral("rbExp"));

        horizontalLayout_2->addWidget(rbExp);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 1, -1, 1);
        prevButton = new QPushButton(LogExpDialog);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        buttonBox = new QDialogButtonBox(LogExpDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LogExpDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogExpDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogExpDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogExpDialog);
    } // setupUi

    void retranslateUi(QDialog *LogExpDialog)
    {
        LogExpDialog->setWindowTitle(QApplication::translate("LogExpDialog", "Logarithmic/Exponential", Q_NULLPTR));
        rbLog->setText(QApplication::translate("LogExpDialog", "Logarithmic", Q_NULLPTR));
        rbExp->setText(QApplication::translate("LogExpDialog", "Exponential", Q_NULLPTR));
        prevButton->setText(QApplication::translate("LogExpDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogExpDialog: public Ui_LogExpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_LOGEXPDLG_H

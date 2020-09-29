/********************************************************************************
** Form generated from reading UI file 'DIP_DisplayImgDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_DISPLAYIMGDLG_H
#define UI_DIP_DISPLAYIMGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DisplayImgDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *ImageCanvas;

    void setupUi(QDialog *DisplayImgDlg)
    {
        if (DisplayImgDlg->objectName().isEmpty())
            DisplayImgDlg->setObjectName(QStringLiteral("DisplayImgDlg"));
        DisplayImgDlg->resize(448, 371);
        horizontalLayout = new QHBoxLayout(DisplayImgDlg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ImageCanvas = new QLabel(DisplayImgDlg);
        ImageCanvas->setObjectName(QStringLiteral("ImageCanvas"));

        horizontalLayout->addWidget(ImageCanvas);


        retranslateUi(DisplayImgDlg);

        QMetaObject::connectSlotsByName(DisplayImgDlg);
    } // setupUi

    void retranslateUi(QDialog *DisplayImgDlg)
    {
        DisplayImgDlg->setWindowTitle(QApplication::translate("DisplayImgDlg", "Dialog", Q_NULLPTR));
        ImageCanvas->setText(QApplication::translate("DisplayImgDlg", "Image", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DisplayImgDlg: public Ui_DisplayImgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_DISPLAYIMGDLG_H

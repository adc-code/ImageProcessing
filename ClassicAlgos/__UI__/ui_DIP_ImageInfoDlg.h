/********************************************************************************
** Form generated from reading UI file 'DIP_ImageInfoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_IMAGEINFODLG_H
#define UI_DIP_IMAGEINFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImageInfoDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtFileName;
    QLabel *labelWidth;
    QLineEdit *txtWidth;
    QLabel *labelHeight;
    QLineEdit *txtHeight;
    QLabel *label_2;
    QLineEdit *txtBPP;
    QLabel *label_3;
    QLineEdit *txtImgType;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ImageInfoDlg)
    {
        if (ImageInfoDlg->objectName().isEmpty())
            ImageInfoDlg->setObjectName(QStringLiteral("ImageInfoDlg"));
        ImageInfoDlg->resize(247, 149);
        verticalLayout = new QVBoxLayout(ImageInfoDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        label = new QLabel(ImageInfoDlg);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtFileName = new QLineEdit(ImageInfoDlg);
        txtFileName->setObjectName(QStringLiteral("txtFileName"));
        txtFileName->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, txtFileName);

        labelWidth = new QLabel(ImageInfoDlg);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));
        labelWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelWidth);

        txtWidth = new QLineEdit(ImageInfoDlg);
        txtWidth->setObjectName(QStringLiteral("txtWidth"));
        txtWidth->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtWidth);

        labelHeight = new QLabel(ImageInfoDlg);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelHeight);

        txtHeight = new QLineEdit(ImageInfoDlg);
        txtHeight->setObjectName(QStringLiteral("txtHeight"));
        txtHeight->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtHeight);

        label_2 = new QLabel(ImageInfoDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        txtBPP = new QLineEdit(ImageInfoDlg);
        txtBPP->setObjectName(QStringLiteral("txtBPP"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txtBPP);

        label_3 = new QLabel(ImageInfoDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        txtImgType = new QLineEdit(ImageInfoDlg);
        txtImgType->setObjectName(QStringLiteral("txtImgType"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtImgType);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okButton = new QPushButton(ImageInfoDlg);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_3->addWidget(okButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

#ifndef QT_NO_SHORTCUT
        labelWidth->setBuddy(txtWidth);
        labelHeight->setBuddy(txtHeight);
#endif // QT_NO_SHORTCUT

        retranslateUi(ImageInfoDlg);

        QMetaObject::connectSlotsByName(ImageInfoDlg);
    } // setupUi

    void retranslateUi(QDialog *ImageInfoDlg)
    {
        ImageInfoDlg->setWindowTitle(QApplication::translate("ImageInfoDlg", "Image Information", Q_NULLPTR));
        label->setText(QApplication::translate("ImageInfoDlg", "File Name : ", Q_NULLPTR));
        labelWidth->setText(QApplication::translate("ImageInfoDlg", "Width : ", Q_NULLPTR));
        labelHeight->setText(QApplication::translate("ImageInfoDlg", "Height : ", Q_NULLPTR));
        label_2->setText(QApplication::translate("ImageInfoDlg", "Bits per Pixel : ", Q_NULLPTR));
        label_3->setText(QApplication::translate("ImageInfoDlg", "Image Type : ", Q_NULLPTR));
        okButton->setText(QApplication::translate("ImageInfoDlg", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageInfoDlg: public Ui_ImageInfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_IMAGEINFODLG_H

/********************************************************************************
** Form generated from reading UI file 'DIP_MeanFilterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIP_MEANFILTERDLG_H
#define UI_DIP_MEANFILTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_MeanFilterDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *MeanFilterGroup;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbArtimetic;
    QRadioButton *rbGeometic;
    QRadioButton *rbHarmonic;
    QRadioButton *rbContra;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *labelQ;
    QDoubleSpinBox *spQValue;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *spWidth;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *spHeight;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QComboBox *comboBorder;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cbPreview;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MeanFilterDialog)
    {
        if (MeanFilterDialog->objectName().isEmpty())
            MeanFilterDialog->setObjectName(QStringLiteral("MeanFilterDialog"));
        MeanFilterDialog->resize(283, 284);
        verticalLayout_5 = new QVBoxLayout(MeanFilterDialog);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 6, 6, 6);
        MeanFilterGroup = new QGroupBox(MeanFilterDialog);
        MeanFilterGroup->setObjectName(QStringLiteral("MeanFilterGroup"));
        gridLayout = new QGridLayout(MeanFilterGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_2->setSpacing(-1);
#endif
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rbArtimetic = new QRadioButton(MeanFilterGroup);
        rbArtimetic->setObjectName(QStringLiteral("rbArtimetic"));

        verticalLayout->addWidget(rbArtimetic);

        rbGeometic = new QRadioButton(MeanFilterGroup);
        rbGeometic->setObjectName(QStringLiteral("rbGeometic"));

        verticalLayout->addWidget(rbGeometic);

        rbHarmonic = new QRadioButton(MeanFilterGroup);
        rbHarmonic->setObjectName(QStringLiteral("rbHarmonic"));

        verticalLayout->addWidget(rbHarmonic);

        rbContra = new QRadioButton(MeanFilterGroup);
        rbContra->setObjectName(QStringLiteral("rbContra"));

        verticalLayout->addWidget(rbContra);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelQ = new QLabel(MeanFilterGroup);
        labelQ->setObjectName(QStringLiteral("labelQ"));
        labelQ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelQ);

        spQValue = new QDoubleSpinBox(MeanFilterGroup);
        spQValue->setObjectName(QStringLiteral("spQValue"));
        spQValue->setMinimum(-3);
        spQValue->setMaximum(3);

        horizontalLayout->addWidget(spQValue);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addWidget(MeanFilterGroup);

        groupBox = new QGroupBox(MeanFilterDialog);
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
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

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
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

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

        groupBox_2 = new QGroupBox(MeanFilterDialog);
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
        horizontalLayout_3->setContentsMargins(6, -1, 6, -1);
        cbPreview = new QCheckBox(MeanFilterDialog);
        cbPreview->setObjectName(QStringLiteral("cbPreview"));

        horizontalLayout_3->addWidget(cbPreview);

        buttonBox = new QDialogButtonBox(MeanFilterDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_5->addLayout(horizontalLayout_3);

#ifndef QT_NO_SHORTCUT
        labelQ->setBuddy(spQValue);
#endif // QT_NO_SHORTCUT

        retranslateUi(MeanFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MeanFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MeanFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MeanFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *MeanFilterDialog)
    {
        MeanFilterDialog->setWindowTitle(QApplication::translate("MeanFilterDialog", "Mean Filter", Q_NULLPTR));
        MeanFilterGroup->setTitle(QString());
        rbArtimetic->setText(QApplication::translate("MeanFilterDialog", "Arithmetic", Q_NULLPTR));
        rbGeometic->setText(QApplication::translate("MeanFilterDialog", "Geometric", Q_NULLPTR));
        rbHarmonic->setText(QApplication::translate("MeanFilterDialog", "Harmonic", Q_NULLPTR));
        rbContra->setText(QApplication::translate("MeanFilterDialog", "Contra-harmonic", Q_NULLPTR));
        labelQ->setText(QApplication::translate("MeanFilterDialog", "    Q:", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("MeanFilterDialog", "Neighbourhood Size:", Q_NULLPTR));
        label->setText(QApplication::translate("MeanFilterDialog", "Width: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MeanFilterDialog", "Height: ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("MeanFilterDialog", "Border Strategy: ", Q_NULLPTR));
        cbPreview->setText(QApplication::translate("MeanFilterDialog", "Preview", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MeanFilterDialog: public Ui_MeanFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIP_MEANFILTERDLG_H

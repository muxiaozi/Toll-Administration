/********************************************************************************
** Form generated from reading UI file 'paydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYDIALOG_H
#define UI_PAYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_PayDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *tabPay;
    QDialogButtonBox *btnboxPay;

    void setupUi(QDialog *PayDialog)
    {
        if (PayDialog->objectName().isEmpty())
            PayDialog->setObjectName(QStringLiteral("PayDialog"));
        PayDialog->setWindowModality(Qt::NonModal);
        PayDialog->resize(736, 305);
        PayDialog->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/image/money.png"), QSize(), QIcon::Normal, QIcon::Off);
        PayDialog->setWindowIcon(icon);
        PayDialog->setModal(false);
        gridLayout = new QGridLayout(PayDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabPay = new QTableView(PayDialog);
        tabPay->setObjectName(QStringLiteral("tabPay"));

        gridLayout->addWidget(tabPay, 0, 0, 1, 1);

        btnboxPay = new QDialogButtonBox(PayDialog);
        btnboxPay->setObjectName(QStringLiteral("btnboxPay"));
        btnboxPay->setOrientation(Qt::Horizontal);
        btnboxPay->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnboxPay, 1, 0, 1, 1);


        retranslateUi(PayDialog);
        QObject::connect(btnboxPay, SIGNAL(accepted()), PayDialog, SLOT(accept()));
        QObject::connect(btnboxPay, SIGNAL(rejected()), PayDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PayDialog);
    } // setupUi

    void retranslateUi(QDialog *PayDialog)
    {
        PayDialog->setWindowTitle(QApplication::translate("PayDialog", "\347\274\264\350\264\271\350\257\246\347\273\206", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        PayDialog->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class PayDialog: public Ui_PayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'QtTcpServer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTCPSERVER_H
#define UI_QTTCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_QtTcpServerClass
{
public:

    void setupUi(QDialog *QtTcpServerClass)
    {
        if (QtTcpServerClass->objectName().isEmpty())
            QtTcpServerClass->setObjectName(QString::fromUtf8("QtTcpServerClass"));
        QtTcpServerClass->resize(600, 400);

        retranslateUi(QtTcpServerClass);

        QMetaObject::connectSlotsByName(QtTcpServerClass);
    } // setupUi

    void retranslateUi(QDialog *QtTcpServerClass)
    {
        QtTcpServerClass->setWindowTitle(QCoreApplication::translate("QtTcpServerClass", "QtTcpServer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtTcpServerClass: public Ui_QtTcpServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTCPSERVER_H

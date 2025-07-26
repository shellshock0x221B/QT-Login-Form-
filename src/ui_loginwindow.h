/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *loginbutton;
    QLineEdit *name_entre;
    QLineEdit *pass_entre;
    QPushButton *loginbutton_2;
    QPushButton *cancel;
    QLabel *status;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(459, 342);
        LoginWindow->setStyleSheet(QString::fromUtf8("font: 10pt \"Noto Sans\";"));
        loginbutton = new QPushButton(LoginWindow);
        loginbutton->setObjectName(QString::fromUtf8("loginbutton"));
        loginbutton->setGeometry(QRect(40, 270, 171, 41));
        loginbutton->setStyleSheet(QString::fromUtf8("font: 14pt \"Noto Sans\";"));
        name_entre = new QLineEdit(LoginWindow);
        name_entre->setObjectName(QString::fromUtf8("name_entre"));
        name_entre->setGeometry(QRect(80, 120, 291, 51));
        name_entre->setStyleSheet(QString::fromUtf8("font: 16pt \"Noto Sans\";"));
        pass_entre = new QLineEdit(LoginWindow);
        pass_entre->setObjectName(QString::fromUtf8("pass_entre"));
        pass_entre->setGeometry(QRect(80, 190, 291, 51));
        pass_entre->setStyleSheet(QString::fromUtf8("font: 16pt \"Noto Sans\";"));
        loginbutton_2 = new QPushButton(LoginWindow);
        loginbutton_2->setObjectName(QString::fromUtf8("loginbutton_2"));
        loginbutton_2->setGeometry(QRect(110, 10, 231, 61));
        loginbutton_2->setStyleSheet(QString::fromUtf8("font: 26pt \"Noto Sans\";"));
        cancel = new QPushButton(LoginWindow);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(230, 270, 181, 41));
        cancel->setStyleSheet(QString::fromUtf8("font: 14pt \"Noto Sans\";"));
        status = new QLabel(LoginWindow);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(150, 80, 141, 21));
        status->setStyleSheet(QString::fromUtf8("font: 57 16pt \"Adwaita Sans\";"));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        loginbutton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        name_entre->setText(QString());
        pass_entre->setText(QString());
        loginbutton_2->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        cancel->setText(QCoreApplication::translate("LoginWindow", "cancel", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

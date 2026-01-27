/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(353, 372);
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 10, 221, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(15);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 80, 49, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 140, 61, 16));
        label_3->setFont(font1);
        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 260, 131, 41));
        QFont font2;
        font2.setPointSize(11);
        pushButton->setFont(font2);
        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 210, 121, 16));
        label_5 = new QLabel(LoginWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 210, 61, 16));
        label_5->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_5->setTextFormat(Qt::TextFormat::RichText);
        lineEdit = new QLineEdit(LoginWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 100, 291, 31));
        lineEdit_2 = new QLineEdit(LoginWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 160, 291, 31));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\320\243\320\262\321\226\320\271\320\264\321\226\321\202\321\214 \320\264\320\276\n"
"\320\262\320\260\321\210\320\276\320\263\320\276 \320\260\320\272\320\260\321\203\320\275\321\202\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\320\233\320\276\320\263\321\226\320\275:", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "\320\243\320\262\321\226\320\271\321\202\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "\320\251\320\265 \320\275\320\265 \320\274\320\260\321\224\321\202\320\265 \320\260\320\272\320\260\321\203\320\275\321\202\321\203?", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><a href=\"register\"><span style=\" text-decoration: underline; color:#27bf73;\">\320\240\320\265\321\224\321\201\321\202\321\200\320\260\321\206\321\226\321\217</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

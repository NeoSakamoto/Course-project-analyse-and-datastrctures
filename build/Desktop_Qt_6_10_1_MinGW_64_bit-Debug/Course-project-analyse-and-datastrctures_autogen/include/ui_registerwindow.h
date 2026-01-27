/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(353, 372);
        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 130, 61, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        label_3->setFont(font);
        label_2 = new QLabel(RegisterWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 49, 16));
        label_2->setFont(font);
        pushButton = new QPushButton(RegisterWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 260, 131, 41));
        QFont font1;
        font1.setPointSize(11);
        pushButton->setFont(font1);
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 10, 221, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(15);
        label->setFont(font2);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(RegisterWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 190, 101, 16));
        label_4->setFont(font);
        lineEdit = new QLineEdit(RegisterWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 90, 291, 31));
        lineEdit_2 = new QLineEdit(RegisterWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(30, 150, 291, 31));
        lineEdit_3 = new QLineEdit(RegisterWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(30, 210, 291, 31));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "\320\233\320\276\320\263\321\226\320\275:", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterWindow", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "\320\240\320\265\321\224\321\201\321\202\321\200\320\260\321\206\321\226\321\217\n"
"\320\275\320\276\320\262\320\276\320\263\320\276 \320\260\320\272\320\260\321\203\320\275\321\202\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "\320\237\320\260\321\200\320\276\320\273\321\214 \321\211\320\265 \321\200\320\260\320\267:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H

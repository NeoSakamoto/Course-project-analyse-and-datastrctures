/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QFrame *frame;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label_3;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *label_4;
    QTextEdit *textEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *textEdit_5;
    QLabel *label_7;
    QTextEdit *textEdit_6;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(941, 573);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName("centralwidget");
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(20, 10, 731, 361));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(770, 10, 151, 321));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 131, 16));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 30, 131, 21));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 131, 16));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(10, 80, 131, 21));
        textEdit_3 = new QTextEdit(frame);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(10, 130, 131, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 131, 16));
        textEdit_4 = new QTextEdit(frame);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(10, 180, 131, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 160, 131, 16));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 210, 131, 16));
        textEdit_5 = new QTextEdit(frame);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(10, 230, 131, 21));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 260, 131, 16));
        textEdit_6 = new QTextEdit(frame);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(10, 280, 131, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(770, 340, 151, 31));
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 941, 21));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName("statusbar");
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("Menu", "\320\220\321\200\320\265\320\275\320\264\320\276\320\262\320\260\320\275\320\260", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("Menu", "\320\246\321\226\320\275\320\260 / \320\263\320\276\320\264", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("Menu", "\320\240\321\226\320\272 \320\262\320\270\320\277\321\203\321\201\320\272\321\203", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("Menu", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Menu", "\320\221\321\200\320\265\320\275\320\264", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Menu", "ID", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Menu", "\342\204\226", nullptr));
        label_2->setText(QCoreApplication::translate("Menu", "ID:", nullptr));
        label_3->setText(QCoreApplication::translate("Menu", "\320\221\321\200\320\265\320\275\320\264:", nullptr));
        label_4->setText(QCoreApplication::translate("Menu", "\320\221\321\200\320\265\320\275\320\264:", nullptr));
        label_5->setText(QCoreApplication::translate("Menu", "\320\240\321\226\320\272 \320\262\320\270\320\277\321\203\321\201\320\272\321\203:", nullptr));
        label_6->setText(QCoreApplication::translate("Menu", "\320\246\321\226\320\275\320\260 / \320\263\320\276\320\264 ($):", nullptr));
        label_7->setText(QCoreApplication::translate("Menu", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        pushButton->setText(QCoreApplication::translate("Menu", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H

#include "registerwindow.h"
#include <QFile>
#include <QMessageBox>
#include "ui_registerwindow.h"
using namespace std;

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

bool RegisterWindow::loginExists(const QString &login)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(";");

        if (parts.size() >= 1) {
            QString savedLogin = parts[0];
            if (savedLogin == login)
                return true;
        }
    }

    return false;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString password_confirm = ui->lineEdit_3->text();

    if (password != password_confirm) {
        QMessageBox::critical(this, "Помилка", "Паролі не співпадають");
        return;
    }

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::critical(this, "Помилка", "Заповніть усі поля");
        return;
    }

    if (loginExists(login)) {
        QMessageBox::critical(this, "Помилка", "Цей логін вже існує. Виберіть інший");
        return;
    }

    QFile file("users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Помилка", "Не вдалося відкрити файл для запису!");
        return;
    }

    QTextStream out(&file);
    out << login << ";" << password << ";" << "user" << "\n";
    file.close();

    emit registrationSucceeded(login, password);
    accept();
}


#include <QMessageBox>
#include <QFile>
#include "loginwindow.h"
#include "registerwindow.h"
#include "menu.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->label_5->setText("<a href='register'>Реєстрація</a>");
    ui->label_5->setTextFormat(Qt::RichText);
    ui->label_5->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_5->setOpenExternalLinks(false);

    connect(ui->label_5, &QLabel::linkActivated,
            this, &LoginWindow::onLinkClicked);
}

bool LoginWindow::checkLogin(const QString &login, const QString &password, UserData &user) {
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(";");

        if (parts.size() >= 3) {
            QString savedLogin = parts[0];
            QString savedPassword = parts[1];
            QString savedRole = parts[2];

            if (savedLogin == login && savedPassword == password) {
                user.login = savedLogin;
                user.password = savedPassword;
                user.role = savedRole;
                return true;
            }
        }
    }

    return false;
}

void LoginWindow::onLinkClicked(const QString& link)
{
    if (link == "register") {
        RegisterWindow reg(this);
        reg.setWindowTitle("Реєстрація");

        connect(&reg, &RegisterWindow::registrationSucceeded, this, &LoginWindow::AutoLogin);

        if (reg.exec() == QDialog::Accepted) {
            QMessageBox::information(this, "OK", "Реєстрація завершена");
        }
    }
}

void LoginWindow::AutoLogin(const QString &login, const QString &password)
{
    Menu* menu = new Menu("user", login);
    menu->show();
    this->close();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Заповніть усі поля");
        return;
    }

    UserData user;

    if (checkLogin(login, password, user)) {
        QMessageBox::information(this, "Вхід", "Вхід успішний");

        Menu* menu = new Menu(user.role, user.login);
        menu->show();

        this->close();
    } else {
        QMessageBox::critical(this, "Помилка", "Невірний логін або пароль");
    }
}


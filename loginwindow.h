#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

struct UserData {
    QString login;
    QString password;
    QString role;
};

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

    void AutoLogin(const QString &login, const QString &password);
    bool checkLogin(const QString &login, const QString &password, UserData &user);

    ~LoginWindow();

private slots:
    void onLinkClicked(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H

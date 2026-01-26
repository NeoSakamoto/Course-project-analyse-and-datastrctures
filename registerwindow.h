#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterWindow *ui;
    bool loginExists(const QString &login);

signals:
    void registrationSucceeded(const QString &login, const QString &password);
};

#endif // REGISTERWINDOW_H

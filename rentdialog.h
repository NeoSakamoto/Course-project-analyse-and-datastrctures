#pragma once

#include <QDialog>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

class RentDialog : public QDialog {
    Q_OBJECT
public:
    explicit RentDialog(QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Взяти в оренду");

        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        QHBoxLayout* fromLayout = new QHBoxLayout();
        fromLayout->addWidget(new QLabel("Дата початку:"));
        fromDate = new QDateEdit(QDate::currentDate(), this);
        fromDate->setCalendarPopup(true);
        fromDate->setMinimumDate(QDate::currentDate());
        fromLayout->addWidget(fromDate);
        mainLayout->addLayout(fromLayout);

        QHBoxLayout* toLayout = new QHBoxLayout();
        toLayout->addWidget(new QLabel("Дата кінця:"));
        toDate = new QDateEdit(QDate::currentDate(), this);
        toDate->setCalendarPopup(true);
        toDate->setMinimumDate(QDate::currentDate());
        toLayout->addWidget(toDate);
        mainLayout->addLayout(toLayout);

        QHBoxLayout* buttonsLayout = new QHBoxLayout();
        QPushButton* okButton = new QPushButton("OK", this);
        QPushButton* cancelButton = new QPushButton("Cancel", this);
        buttonsLayout->addWidget(okButton);
        buttonsLayout->addWidget(cancelButton);
        mainLayout->addLayout(buttonsLayout);

        connect(okButton, &QPushButton::clicked, this, &RentDialog::onOkClicked);
        connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    }

    QDate getFromDate() const { return fromDate->date(); }
    QDate getToDate() const { return toDate->date(); }

private slots:
    void onOkClicked() {
        if (toDate->date() < fromDate->date()) {
            QMessageBox::critical(this, "Помилка", "Дата кінця не може бути раньше дати початку оренди!");
            return;
        }
        accept();
    }

private:
    QDateEdit* fromDate;
    QDateEdit* toDate;
};

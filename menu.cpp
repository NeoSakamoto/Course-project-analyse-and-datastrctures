#include "menu.h"
#include <QMessageBox>
#include "./ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui->treeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    Menu_Load("cars.txt", ui->treeWidget, cars);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::AddToWidget(Car car) {
    int rownum = ui->treeWidget->topLevelItemCount();
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, QString::number(rownum));
    item->setText(1, QString::number(car.id));
    item->setText(2, QString::fromStdString(car.brand));
    item->setText(3, QString::fromStdString(car.model));
    item->setText(4, QString::number(car.year));
    item->setText(5, QString::number(car.price, 'f', 1));
    item->setText(6, car.isRented == true ? "RENT" : "NOT RENT");
}

bool Menu::CheckFields(Car& car) {
    vector<string> infos;
    bool isRent;

    infos.push_back(ui->textEdit->toPlainText().toStdString());
    infos.push_back(ui->textEdit_2->toPlainText().toStdString());
    infos.push_back(ui->textEdit_3->toPlainText().toStdString());
    infos.push_back(ui->textEdit_4->toPlainText().toStdString());
    infos.push_back(ui->textEdit_5->toPlainText().toStdString());
    isRent = ui->checkBox->isChecked();

    for (const string& info : infos) {
        if (info.empty()) {
            QMessageBox::critical(this, "Помилка", "Для того щоб додати елемент, заповніть усі поля");
            return false;
        }
    }

    car.brand = infos[1];
    car.model = infos[2];
    try {
        car.id = stoi(infos[0]);
        car.year = stoi(infos[3]);
        car.price = stod(infos[4]);
    } catch (exception&) {
        QMessageBox::critical(this, "Помилка", "Некоректне одне з числових значень");
        return false;
    }

    car.isRented = isRent;
    return true;
}

void Menu::InsertEl(int structure, int count) {
    if (structure == 1) {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < count; i++) {
            searchtree.Insert(cars[i]);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<chrono::microseconds>(end - start);

        QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " мікросекунд");
    }
    if (structure == 2) {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < count; i++) {
            btree.Insert(cars[i]);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<chrono::microseconds>(end - start);

        QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " мікросекунд");
    }
    if (structure == 3) {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < count; i++) {
            hash.add(cars[i]);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<chrono::microseconds>(end - start);

        QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " мікросекунд");
    }
    if (structure == 4) {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < count; i++) {
            list.push_back(cars[i]);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<chrono::microseconds>(end - start);

        QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " мікросекунд");
    }
    if (structure == 5) {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < count; i++) {
            heap.insert(cars[i]);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<chrono::microseconds>(end - start);

        QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " мікросекунд");
    }
}

void Menu::StructureAddEl(int structureind, int addcount) {
    if (structureind == 1) {
        if (addcount == 0) {
            Car car;
            if (!CheckFields(car)) return;
            cars.push_back(car);
            AddToWidget(car);

            auto start = chrono::high_resolution_clock::now();
            searchtree.Insert(car);
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

            QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " наносекунд");
        }
        else if (addcount == 1) {
            InsertEl(1, 100);
        }
        else if (addcount == 2) {
            InsertEl(1, 1000);
        }
        else if (addcount == 3) {
            InsertEl(1, 5000);
        }
    }
    if (structureind == 2) {
        if (addcount == 0) {
            Car car;
            if (!CheckFields(car)) return;
            cars.push_back(car);
            AddToWidget(car);

            auto start = chrono::high_resolution_clock::now();
            btree.Insert(car);
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

            QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " наносекунд");
        }
        else if (addcount == 1) {
            InsertEl(2, 100);
        }
        else if (addcount == 2) {
            InsertEl(2, 1000);
        }
        else if (addcount == 3) {
            InsertEl(2, 5000);
        }
    }
    if (structureind == 3) {
        if (addcount == 0) {
            Car car;
            if (!CheckFields(car)) return;
            cars.push_back(car);
            AddToWidget(car);

            auto start = chrono::high_resolution_clock::now();
            hash.add(car);
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

            QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " наносекунд");
        }
        else if (addcount == 1) {
            InsertEl(3, 100);
        }
        else if (addcount == 2) {
            InsertEl(3, 1000);
        }
        else if (addcount == 3) {
            InsertEl(3, 5000);
        }
    }
    if (structureind == 4) {
        if (addcount == 0) {
            Car car;
            if (!CheckFields(car)) return;
            cars.push_back(car);
            AddToWidget(car);

            auto start = chrono::high_resolution_clock::now();
            list.push_back(car);
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

            QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " наносекунд");
        }
        else if (addcount == 1) {
            InsertEl(4, 100);
        }
        else if (addcount == 2) {
            InsertEl(4, 1000);
        }
        else if (addcount == 3) {
            InsertEl(4, 5000);
        }
    }
    if (structureind == 5) {
        if (addcount == 0) {
            Car car;
            if (!CheckFields(car)) return;
            cars.push_back(car);

            auto start = chrono::high_resolution_clock::now();
            heap.insert(car);
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

            QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " наносекунд");
        }
        else if (addcount == 1) {
            InsertEl(5, 100);
        }
        else if (addcount == 2) {
            InsertEl(5, 1000);
        }
        else if (addcount == 3) {
            InsertEl(5, 5000);
        }
    }
}

void Menu::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked()) StructureAddEl(1, ui->comboBox->currentIndex());
    else if (ui->radioButton_2->isChecked()) StructureAddEl(2, ui->comboBox->currentIndex());
    else if (ui->radioButton_3->isChecked()) StructureAddEl(3, ui->comboBox->currentIndex());
    else if (ui->radioButton_4->isChecked()) StructureAddEl(4, ui->comboBox->currentIndex());
    else if (ui->radioButton_5->isChecked()) StructureAddEl(5, ui->comboBox->currentIndex());
    else QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для операції");
}


void Menu::on_comboBox_activated(int index)
{
    if (index != 0) {
        ui->frame->setEnabled(false);
    }
    else {
        ui->frame->setEnabled(true);
    }
}


void Menu::on_comboBox_2_activated(int index)
{
    if (index == 0 || index == 1) ui->frame->setEnabled(false);
}


void Menu::on_pushButton_4_clicked()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();

    if (!item) {
        QMessageBox::critical(this, "Помилка", "Для використовування цього інструмента, виберіть спочатку елемент для редагування");
    }

    editeditem = item;

    ui->frame_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->textEdit_8->setEnabled(false);
    ui->textEdit_7->setEnabled(false);

    ui->textEdit->setText(item->text(1));
    ui->textEdit_2->setText(item->text(2));
    ui->textEdit_3->setText(item->text(3));
    ui->textEdit_4->setText(item->text(4));
    ui->textEdit_5->setText(item->text(5));
    ui->checkBox->setChecked(item->text(6) == "NOT RENT" ? false : true);

    ui->pushButton_5->show();
    ui->pushButton_6->show();

}


void Menu::on_pushButton_6_clicked()
{
    ui->frame_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->textEdit_8->setEnabled(true);
    ui->textEdit_7->setEnabled(true);

    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
    ui->checkBox->setChecked(false);

    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
}


void Menu::on_pushButton_5_clicked()
{
    ui->frame_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->textEdit_8->setEnabled(true);
    ui->textEdit_7->setEnabled(true);

    ui->pushButton_5->hide();
    ui->pushButton_6->hide();

    editeditem->setText(1, ui->textEdit->toPlainText());
    editeditem->setText(2, ui->textEdit_2->toPlainText());
    editeditem->setText(3, ui->textEdit_3->toPlainText());
    editeditem->setText(4, ui->textEdit_4->toPlainText());
    editeditem->setText(5, ui->textEdit_5->toPlainText());
    editeditem->setText(6, ui->checkBox->isChecked() == true ? "RENT" : "NOT RENT");

    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
    ui->checkBox->setChecked(false);
}


void Menu::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->checkBox->setText("Не орендована");
    else ui->checkBox->setText("Орендована");
}

void Menu::RemoveFromStruct(int struc) {
    if (ui->textEdit_8->toPlainText().isEmpty()) {
        QMessageBox::critical(this, "Помилка", "Введіть ID");
        return;
    }

    bool ok;
    int id = ui->textEdit_8->toPlainText().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Помилка", "Некоректний ID");
        return;
    }

    bool success = false;
    std::chrono::microseconds duration{0};

    auto start = chrono::high_resolution_clock::now();

    switch (struc) {
    case 1:
        success = searchtree.Remove(id);
        break;
    case 2:
        success = btree.Remove(id);
        break;
    case 3:
        success = hash.remove(id);
        break;
    case 4:
        success = list.remove(id);
        break;
    case 5:
        success = heap.removeMin();
        break;
    }

    auto end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);

    QMessageBox::information(
        this,
        success ? "Успіх" : "Помилка",
        QString("%1\nЗатрачений час: %2 мікросекунд")
            .arg(success ? "Елемент видалено" : "ID не знайдено")
            .arg(duration.count())
        );
}


void Menu::on_pushButton_2_clicked()
{
    if (ui->radioButton->isChecked()) RemoveFromStruct(1);
    else if (ui->radioButton_2->isChecked()) RemoveFromStruct(2);
    else if (ui->radioButton_3->isChecked()) RemoveFromStruct(3);
    else if (ui->radioButton_4->isChecked()) RemoveFromStruct(4);
    else if (ui->radioButton_5->isChecked()) RemoveFromStruct(5);
    else QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для операції");
}

void Menu::SearchInStruct(int struc) {
    if (ui->textEdit_7->toPlainText().isEmpty()) {
        QMessageBox::critical(this, "Помилка", "Введіть ID для пошуку");
        return;
    }

    bool ok;
    int id = ui->textEdit_7->toPlainText().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Помилка", "Некоректний ID");
        return;
    }

    Car* result = nullptr;
    std::chrono::microseconds duration{0};

    auto start = chrono::high_resolution_clock::now();

    switch (struc) {
    case 1:
        result = searchtree.Find(id);
        break;

    case 2:
        result = btree.Find(id);
        break;

    case 3:
        result = hash.findById(id);
        break;

    case 4:
        result = list.findById(id);
        break;

    case 5:
        result = /*heap.findById(id);*/ nullptr;
        break;
    }

    auto end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);

    if (result) {
        QMessageBox::information(
            this,
            "Успіх",
            QString(
                "Елемент знайдено\n"
                "ID: %1\n"
                "Марка: %2\n"
                "Модель: %3\n"
                "Рік: %4\n"
                "Ціна: %5\n"
                "Час пошуку: %6 мікросекунд"
                )
                .arg(result->id)
                .arg(QString::fromStdString(result->brand))
                .arg(QString::fromStdString(result->model))
                .arg(result->year)
                .arg(result->price)
                .arg(duration.count())
            );
    } else {
        QMessageBox::critical(
            this,
            "Не знайдено",
            QString(
                "Елемент з ID %1 не знайдено\n"
                "Час пошуку: %2 мікросекунд"
                )
                .arg(id)
                .arg(duration.count())
            );
    }
}

void Menu::on_pushButton_3_clicked()
{
    if (ui->radioButton->isChecked()) SearchInStruct(1);
    else if (ui->radioButton_2->isChecked()) SearchInStruct(2);
    else if (ui->radioButton_3->isChecked()) SearchInStruct(3);
    else if (ui->radioButton_4->isChecked()) SearchInStruct(4);
    else if (ui->radioButton_5->isChecked()) SearchInStruct(5);
    else QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для операції");
}


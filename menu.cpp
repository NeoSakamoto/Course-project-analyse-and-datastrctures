#include "menu.h"
#include "rentdialog.h"
#include <QMessageBox>
#include <QDate>
#include "./ui_menu.h"

Menu::Menu(const QString& role, const QString& login, QWidget *parent)
    : QMainWindow(parent)
    , userRole(role)
    , userLogin(login)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    if (userRole == "admin") {
        ui->frame_5->show();
    } else {
        ui->frame_5->hide();
    }

    Menu_Load("cars.txt", ui->treeWidget, cars);
    Structures_Load(cars);

    ui->label->setText("Ласкаво просимо, " + userLogin + "!");

    auto header = ui->treeWidget->header();
    header->setDefaultAlignment(Qt::AlignCenter);
    header->setSectionResizeMode(QHeaderView::ResizeToContents);
    header->setSectionResizeMode(0, QHeaderView::Stretch);
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    header->setSectionResizeMode(8, QHeaderView::Stretch);

    auto header2 = ui->treeWidget_2->header();
    header2->setDefaultAlignment(Qt::AlignCenter);
    header2->setSectionResizeMode(QHeaderView::ResizeToContents);
    header2->setSectionResizeMode(0, QHeaderView::Stretch);
    header2->setSectionResizeMode(1, QHeaderView::Stretch);
    header2->setSectionResizeMode(8, QHeaderView::Stretch);

    ui->treeWidget_2->clear();
    for (const Car& car : cars) {
        if (car.owner == userLogin.toStdString())
            AddToWidget(car);
    }

    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::Structures_Load(vector<Car>& cars) {
    for (const Car& car : cars) {
        searchtree.Insert(car);
        btree.Insert(car);
        hash.add(car);
        list.push_back(car);
        heap.insert(car);
    }
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
    item->setText(7, QString::fromStdString("-"));
    item->setText(8, userLogin);

    if (car.owner == userLogin.toStdString()) {
        int rownum2 = ui->treeWidget_2->topLevelItemCount();
        QTreeWidgetItem *item2 = new QTreeWidgetItem(ui->treeWidget_2);
        item2->setText(0, QString::number(rownum2));
        item2->setText(1, QString::number(car.id));
        item2->setText(2, QString::fromStdString(car.brand));
        item2->setText(3, QString::fromStdString(car.model));
        item2->setText(4, QString::number(car.year));
        item2->setText(5, QString::number(car.price, 'f', 1));
        item2->setText(6, car.isRented ? "RENT" : "NOT RENT");
        item2->setText(7, QString::fromStdString(car.rentedUntil));
        item2->setText(8, QString::fromStdString(car.owner));
    }
}

bool Menu::CheckFields(Car& car) {
    vector<string> infos;
    bool isRent;

    infos.push_back(ui->textEdit_6->toPlainText().toStdString());
    infos.push_back(ui->textEdit_9->toPlainText().toStdString());
    infos.push_back(ui->textEdit_10->toPlainText().toStdString());
    infos.push_back(ui->textEdit_11->toPlainText().toStdString());
    infos.push_back(ui->textEdit_12->toPlainText().toStdString());
    isRent = ui->checkBox->isChecked();

    for (const string& info : infos) {
        if (info.empty()) {
            QMessageBox::critical(this, "Помилка", "Для того щоб додати елемент, заповніть усі поля");
            return false;
        }
    }

    car.brand = infos[1];
    car.model = infos[2];
    car.owner = userLogin.toStdString();
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

void Menu::StructureAddEl(int structureind) {
    Car car;
    if (!CheckFields(car)) return;
    cars.push_back(car);
    AddToWidget(car);
    chrono::nanoseconds duration;

    if (structureind == 1) {
        auto start = chrono::high_resolution_clock::now();
        searchtree.Insert(car);
        auto end = chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

        btree.Insert(car);
        hash.add(car);
        list.push_back(car);
        heap.insert(car);
    }
    if (structureind == 2) {
        auto start = chrono::high_resolution_clock::now();
        btree.Insert(car);
        auto end = chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

        searchtree.Insert(car);
        hash.add(car);
        list.push_back(car);
        heap.insert(car);
    }
    if (structureind == 3) {
        auto start = chrono::high_resolution_clock::now();
        hash.add(car);
        auto end = chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

        searchtree.Insert(car);
        btree.Insert(car);
        list.push_back(car);
        heap.insert(car);
    }
    if (structureind == 4) {
        auto start = chrono::high_resolution_clock::now();
        list.push_back(car);
        auto end = chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

        searchtree.Insert(car);
        btree.Insert(car);
        hash.add(car);
        heap.insert(car);
    }
    if (structureind == 5) {
        auto start = chrono::high_resolution_clock::now();
        heap.insert(car);
        auto end = chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

        searchtree.Insert(car);
        btree.Insert(car);
        hash.add(car);
        list.push_back(car);
    }
    QMessageBox::information(this, "Успіх", "Елемент було додано за " + QString::number(duration.count()) + " наносекунд");
    AppendCarToFile(car);
}

void Menu::AppendCarToFile(const Car& car) {
    std::ofstream file("cars.txt", ios::app);
    if (!file.is_open()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося відкрити файл для запису");
        return;
    }

    file << car.id << ";"
         << car.brand << ";"
         << car.model << ";"
         << car.year << ";"
         << car.price << ";"
         << (car.isRented ? "1" : "0") << ";"
         << car.rentedUntil << ";"
         << car.owner
         << "\n";
    file.close();
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
        return;
    }

    editeditem = item;

    ui->frame->setEnabled(true);
    ui->frame_2->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
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
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
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
    if (!editeditem) {
        QMessageBox::critical(this, "Помилка", "Спочатку оберіть елемент для редагування");
        return;
    }

    int id = editeditem->text(1).toInt();

    Car updatedCar;
    updatedCar.id = id;
    updatedCar.brand = ui->textEdit_2->toPlainText().toStdString();
    updatedCar.model = ui->textEdit_3->toPlainText().toStdString();
    updatedCar.year = ui->textEdit_4->toPlainText().toInt();
    updatedCar.price = ui->textEdit_5->toPlainText().toDouble();
    updatedCar.isRented = ui->checkBox->isChecked();
    if (updatedCar.isRented == true) {
        updatedCar.rentedUntil = editeditem->text(7).toStdString();
    } else updatedCar.rentedUntil = "-";
    updatedCar.owner = editeditem->text(8).toStdString();

    int structureIndex = 0;
    if (ui->radioButton->isChecked()) structureIndex = 1;
    else if (ui->radioButton_2->isChecked()) structureIndex = 2;
    else if (ui->radioButton_3->isChecked()) structureIndex = 3;
    else if (ui->radioButton_4->isChecked()) structureIndex = 4;
    else if (ui->radioButton_5->isChecked()) structureIndex = 5;

    if (structureIndex == 0) {
        QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для редагування");
        return;
    }

    Car* mainCar = nullptr;

    auto start = chrono::high_resolution_clock::now();
    switch (structureIndex) {
    case 1: mainCar = searchtree.Find(id); break;
    case 2: mainCar = btree.Find(id); break;
    case 3: mainCar = hash.findById(id); break;
    case 4: mainCar = list.findById(id); break;
    case 5: mainCar = heap.findById(id); break;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    if (!mainCar) {
        QMessageBox::critical(this, "Помилка", "ID не знайдено в обраній структурі");
        return;
    }

    *mainCar = updatedCar;

    if (structureIndex != 1 && searchtree.Find(id)) *searchtree.Find(id) = updatedCar;
    if (structureIndex != 2 && btree.Find(id)) *btree.Find(id) = updatedCar;
    if (structureIndex != 3 && hash.findById(id)) *hash.findById(id) = updatedCar;
    if (structureIndex != 4 && list.findById(id)) *list.findById(id) = updatedCar;
    if (structureIndex != 5 && heap.findById(id)) *heap.findById(id) = updatedCar;

    UpdateCarInFile(updatedCar);

    auto updateTree = [&](QTreeWidget* tree){
        for (int i = 0; i < tree->topLevelItemCount(); ++i) {
            QTreeWidgetItem* it = tree->topLevelItem(i);
            if (it->text(1).toInt() == id) {
                it->setText(2, QString::fromStdString(updatedCar.brand));
                it->setText(3, QString::fromStdString(updatedCar.model));
                it->setText(4, QString::number(updatedCar.year));
                it->setText(5, QString::number(updatedCar.price, 'f', 1));
                it->setText(6, updatedCar.isRented ? "RENT" : "NOT RENT");
                it->setText(7, QString::fromStdString(updatedCar.rentedUntil));
                it->setText(8, QString::fromStdString(updatedCar.owner));
            }
        }
    };

    updateTree(ui->treeWidget);
    updateTree(ui->treeWidget_2);

    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
    ui->checkBox->setChecked(false);

    ui->frame->setEnabled(true);
    ui->frame_2->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_9->setEnabled(true);

    ui->textEdit_7->setEnabled(true);
    ui->textEdit_8->setEnabled(true);

    ui->pushButton_5->hide();
    ui->pushButton_6->hide();

    QMessageBox::information(this, "Успіх",
                             "Дані автомобіля оновлено\n"
                             "Час оновлення у вибраній структурі: " + QString::number(duration.count()) + " мікросекунд");
}

void Menu::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0) ui->checkBox->setText("Не орендована");
    else ui->checkBox->setText("Орендована");
}

void Menu::RemoveFromStruct(int structureIndex) {
    QTreeWidgetItem* item = ui->treeWidget_2->currentItem();
    bool fromUserTree = true;

    if (!item) {
        item = ui->treeWidget->currentItem();
        fromUserTree = false;
    }

    int id = -1;
    if (item) {
        id = item->text(1).toInt();
    } else if (!ui->textEdit_8->toPlainText().isEmpty()) {
        bool ok;
        id = ui->textEdit_8->toPlainText().toInt(&ok);
        if (!ok) {
            QMessageBox::critical(this, "Помилка", "Некоректний ID");
            return;
        }
    } else {
        QMessageBox::critical(this, "Помилка", "Спочатку виділіть елемент для видалення або введіть ID");
        return;
    }

    bool idExists = false;
    ifstream infile("cars.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string token;
            if (getline(ss, token, ';')) {
                if (stoi(token) == id) {
                    idExists = true;
                    break;
                }
            }
        }
        infile.close();
    }

    if (!idExists) {
        QMessageBox::critical(this, "Помилка", "Машина з таким ID не існує");
        return;
    }

    bool success = false;
    std::chrono::microseconds duration{0};

    auto start = chrono::high_resolution_clock::now();

    switch (structureIndex) {
    case 1: success = searchtree.Remove(id); break;
    case 2: success = btree.Remove(id); break;
    case 3: success = hash.remove(id); break;
    case 4: success = list.remove(id); break;
    case 5: success = heap.removeMin(); break;
    default: break;
    }

    auto end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);

    if (structureIndex != 1) searchtree.Remove(id);
    if (structureIndex != 2) btree.Remove(id);
    if (structureIndex != 3) hash.remove(id);
    if (structureIndex != 4) list.remove(id);
    if (structureIndex != 5) heap.removeMin();

    {
        ifstream infile("cars.txt");
        if (infile.is_open()) {
            ofstream temp("cars_temp.txt");
            string line;
            while (getline(infile, line)) {
                stringstream ss(line);
                string token;
                vector<string> parts;
                while (getline(ss, token, ';'))
                    parts.push_back(token);

                if (!parts.empty() && stoi(parts[0]) != id)
                    temp << line << "\n";
            }
            infile.close();
            temp.close();
            remove("cars.txt");
            rename("cars_temp.txt", "cars.txt");
        }
    }

    auto removeFromWidget = [&](QTreeWidget* tree) {
        for (int i = tree->topLevelItemCount() - 1; i >= 0; --i) {
            QTreeWidgetItem* it = tree->topLevelItem(i);
            if (it->text(1).toInt() == id)
                delete tree->takeTopLevelItem(i);
        }
    };

    removeFromWidget(ui->treeWidget);
    removeFromWidget(ui->treeWidget_2);

    QMessageBox::information(
        this,
        success ? "Успіх" : "Помилка",
        QString("%1\nЗатрачений час на обрану структуру: %2 мікросекунд")
            .arg(success ? "Елемент видалено" : "ID не знайдено в структурі")
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
        result = heap.findById(id);
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

void Menu::RentInStruct(int struc) {
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    if (!item) {
        QMessageBox::critical(this, "Помилка", "Виберіть спочатку елемент для оренди");
        return;
    }
    if (item->text(6) == "RENT") {
        QMessageBox::critical(this, "Помилка", "Не можна взяти в оренду вже орендовану машину. Оберіть іншу");
        return;
    }

    RentDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) return;

    QDate from = dialog.getFromDate();
    QDate to = dialog.getToDate();
    string FromToString = from.toString("dd.MM.yyyy").toStdString() + "-" + to.toString("dd.MM.yyyy").toStdString();

    item->setText(7, QString::fromStdString(FromToString));
    item->setText(6, "RENT");

    int carId = item->text(1).toInt();

    auto start = chrono::high_resolution_clock::now();
    auto findCar = [&](int structure) -> Car* {
        switch (structure) {
        case 1: return searchtree.Find(carId);
        case 2: return btree.Find(carId);
        case 3: return hash.findById(carId);
        case 4: return list.findById(carId);
        case 5: return heap.findById(carId);
        }
        return nullptr;
    };

    Car* mainCar = findCar(struc);

    if (!mainCar) {
        QMessageBox::critical(this, "Помилка", "Машина з таким ID не знайдена в цій структурі!");
        return;
    }

    mainCar->isRented = true;
    mainCar->rentedUntil = FromToString;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    QMessageBox::information(this, "Успіх", "Елемент було взято в оренду за " + QString::number(duration.count()) + " мікросекунд");

    for (int i = 1; i <= 5; ++i) {
        if (i == struc) continue;
        Car* c = findCar(i);
        if (c) {
            c->isRented = true;
            c->rentedUntil = FromToString;
        }
    }

    for (Car& car : cars) {
        if (carId == car.id) {
            car.isRented = true;
            car.rentedUntil = FromToString;
            UpdateCarInFile(car);
            break;
        }
    }
}

void Menu::UpdateCarInFile(const Car& carToUpdate) {
    ifstream infile("cars.txt");
    if (!infile.is_open()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося відкрити файл для оновлення");
        return;
    }

    ofstream tempFile("cars_temp.txt");
    if (!tempFile.is_open()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося створити тимчасовий файл");
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<string> parts;

        while (getline(ss, token, ';'))
            parts.push_back(token);

        if (!parts.empty() && stoi(parts[0]) == carToUpdate.id) {
            tempFile << carToUpdate.id << ";"
                     << carToUpdate.brand << ";"
                     << carToUpdate.model << ";"
                     << carToUpdate.year << ";"
                     << carToUpdate.price << ";"
                     << (carToUpdate.isRented ? "1" : "0") << ";"
                     << carToUpdate.rentedUntil << ";"
                     << carToUpdate.owner
                     << "\n";
        } else {
            tempFile << line << "\n";
        }
    }

    infile.close();
    tempFile.close();

    remove("cars.txt");
    rename("cars_temp.txt", "cars.txt");
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

void Menu::on_pushButton_7_clicked()
{
    if (ui->radioButton_6->isChecked()) StructureAddEl(1);
    else if (ui->radioButton_7->isChecked()) StructureAddEl(2);
    else if (ui->radioButton_8->isChecked()) StructureAddEl(3);
    else if (ui->radioButton_9->isChecked()) StructureAddEl(4);
    else if (ui->radioButton_10->isChecked()) StructureAddEl(5);
    else QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для операції");
}

void Menu::on_pushButton_9_clicked()
{
    if (ui->radioButton->isChecked()) RentInStruct(1);
    else if (ui->radioButton_2->isChecked()) RentInStruct(2);
    else if (ui->radioButton_3->isChecked()) RentInStruct(3);
    else if (ui->radioButton_4->isChecked()) RentInStruct(4);
    else if (ui->radioButton_5->isChecked()) RentInStruct(5);
    else QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для операції");
}


void Menu::on_pushButton_8_clicked()
{
    if (ui->radioButton_6->isChecked()) RemoveFromStruct(1);
    else if (ui->radioButton_7->isChecked()) RemoveFromStruct(2);
    else if (ui->radioButton_8->isChecked()) RemoveFromStruct(3);
    else if (ui->radioButton_9->isChecked()) RemoveFromStruct(4);
    else if (ui->radioButton_10->isChecked()) RemoveFromStruct(5);
    else QMessageBox::critical(this, "Помилка", "Оберіть структуру даних для операції");
}


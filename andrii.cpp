#include "funcs.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <QTreeWidget>

void InfofromFile(string& filename, vector<Car>& cars) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Car car;

        getline(ss, token, ';');
        car.id = stoi(token);

        getline(ss, token, ';');
        car.brand = token;

        getline(ss, token, ';');
        car.model = token;

        getline(ss, token, ';');
        car.year = stoi(token);

        getline(ss, token, ';');
        car.price = stod(token);

        getline(ss, token, ';');
        car.isRented = (token == "1");

        cars.push_back(car);
    }
}

void Menu_Load(const string& filename, QTreeWidget* tree, vector<Car>& cars) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> parts;

        while (getline(ss, token, ';'))
            parts.push_back(token);

        if (parts.size() < 6) continue;

        Car car;

        car.id = stoi(parts[0]);
        car.brand = parts[1];
        car.model = parts[2];
        car.year = stoi(parts[3]);
        car.price = stod(parts[4]);
        car.isRented = (parts[5] == "1");
        cars.push_back(car);

        static int rownum = 1;
        QTreeWidgetItem *item = new QTreeWidgetItem(tree);
        item->setText(0, QString::number(rownum++));
        item->setText(1, QString::fromStdString(parts[0]));
        item->setText(2, QString::fromStdString(parts[1]));
        item->setText(3, QString::fromStdString(parts[2]));
        item->setText(4, QString::fromStdString(parts[3]));
        item->setText(5, QString::fromStdString(parts[4]));
        item->setText(6, parts[5] == "1" ? "RENT" : "NOT RENT");
    }
}

HashTable::HashTable() {
    buffer_size = default_size;
    size = 0;
    sizewdeleted = 0;

    arr = new Node * [buffer_size];
    for (int i = 0; i < buffer_size; i++) {
        arr[i] = nullptr;
    }
}
HashTable::~HashTable() {
    for (int i = 0; i < buffer_size; i++) {
        Node* current = arr[i];
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] arr;
}

void HashTable::resize() {
    int past_bsz = buffer_size;
    buffer_size *= 2;

    Node** arr2 = new Node * [buffer_size] {};

    size = 0;
    sizewdeleted = 0;

    for (int i = 0; i < past_bsz; i++) {
        Node* current = arr[i];

        while (current) {
            if (current->state) {
                Car car_copy = current->car;

                int ind = hash_function(car_copy, buffer_size);
                Node* tmp = new Node{ car_copy };
                tmp->next = arr2[ind];
                arr2[ind] = tmp;

                size++;
                sizewdeleted++;
            }
            current = current->next;
        }
    }

    for (int i = 0; i < past_bsz; i++) {
        Node* current = arr[i];
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] arr;

    arr = arr2;
}

void HashTable::add(const Car& car_) {
    if (int(resize_cof * buffer_size) < size + 1)
        resize();

    int ind = hash_function(car_, buffer_size);
    Node* current = arr[ind];

    if (!current) {
        arr[ind] = new Node{ car_ };

        size++;
        sizewdeleted++;
        return;
    }

    Node* prev = nullptr;
    while (current) {
        if (current->car == car_ && current->state) {
            return;
        }

        if (!current->state) {
            current->car = car_;
            current->state = true;

            return;
        }

        prev = current;
        current = current->next;
    }

    if (!prev) {
        arr[ind]->next = new Node{ car_ };
    }
    else {
        prev->next = new Node{ car_ };
    }

    size++;
    sizewdeleted++;
}

Car* HashTable::findById(int id) {
    int ind = hash_function(id, buffer_size);
    Node* current = arr[ind];

    while (current) {
        if (current->state && current->car.id == id) {
            return &current->car;
        }
        current = current->next;
    }
    return nullptr;
}


bool HashTable::remove(const Car& car_) {
    int ind = hash_function(car_, buffer_size);
    Node* current = arr[ind];

    while (current) {
        if (current->car.id == car_.id && current->state != false) {
            current->state = false;
            break;
        }
        else current = current->next;
    }
    if (!current) return false;

    size--;
    sizewdeleted++;
    return true;
}

void HashTable::tableout() {
    for (int i = 0; i < buffer_size; i++) {
        Node* current = arr[i];
        while (current) {
            if (current->state == true) {
                cout << current->car.GetInfo() << endl;
            }

            current = current->next;
        }
    }
}

int HashTable::hash_function(const Car& car_, const int& n) {
    return car_.id % n;
}

List::List() : head(nullptr), tail(nullptr), size(0) {};
List::~List() { clear(); };

void List::push_back(const Car& car) {
    if (size == 0) {
        tail = head = new Node{ car, nullptr, nullptr };
    }
    else {
        tail = tail->next = new Node{ car, tail, nullptr };
    }
    size++;
}

void List::push_front(const Car& car) {
    if (size == 0) {
        head = tail = new Node{ car, nullptr, nullptr };
    }
    else {
        head = head->prev = new Node{ car, nullptr, head };
    }
    size++;
}

bool List::remove(const int& id) {
    if (size == 0) {
        cout << "Додайте спочатку хоча-б один елемент, щоб видаляти" << endl;
        return false;
    }

    Node* current = head;

    while (current != nullptr && !(current->car.id == id)) {
        current = current->next;
    }

    if (!current) return false;

    if (current == head) head = current->next;
    if (current == tail) tail = current->prev;

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;

    delete current;
    size--;
    return true;
}

void List::search(const Car& car) {
    if (size == 0) {
        cout << "Нема серед чого шукати" << endl;
        return;
    }

    Node* current = head;
    int i = 0;

    while (current != nullptr && !(current->car.id == car.id)) {
        i++;
        current = current->next;
    }

    if (current) cout << "Об'єкт знаходиться у списку під індексом #" << i << "." << endl;
    else cout << "Об'єкт не було знайдено";
}

Car* List::findById(int id) {
    if (size == 0)
        return nullptr;

    Node* current = head;
    while (current) {
        if (current->car.id == id)
            return &current->car;
        current = current->next;
    }
    return nullptr;
}

void List::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void List::nodeout() {
    if (size == 0) {
        cout << "Список пустий, виводити нічого" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->car.GetInfo() << endl;
        current = current->next;
    }
    delete current;
}

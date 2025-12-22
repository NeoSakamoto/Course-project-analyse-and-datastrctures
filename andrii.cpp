#include "funcs.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

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

void HashTable::remove(const Car& car_) {
    int ind = hash_function(car_, buffer_size);
    Node* current = arr[ind];

    while (current) {
        if (current->car == car_) {
            current->state = false;
            return;
        }
        else current = current->next;
    }
    size--;
    sizewdeleted++;
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

void List::remove(const Car& car) {
    if (size == 0) {
        cout << "Додайте спочатку хоча-б один елемент, щоб видаляти" << endl;
        return;
    }

    Node* current = head;

    while (current != nullptr && !(current->car == car)) {
        current = current->next;
    }

    if (!current) cout << "Дані за вашим запитом не було знайдено у списку" << endl;

    if (current == head) head = current->next;
    if (current == tail) tail = current->prev;

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;

    delete current;
    size--;
}

void List::search(const Car& car) {
    if (size == 0) {
        cout << "Нема серед чого шукати" << endl;
        return;
    }

    Node* current = head;
    int i = 0;

    while (current != nullptr && !(current->car == car)) {
        i++;
        current = current->next;
    }

    if (current) cout << "Об'єкт знаходиться у списку під індексом #" << i << "." << endl;
    else cout << "Об'єкт не було знайдено";
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
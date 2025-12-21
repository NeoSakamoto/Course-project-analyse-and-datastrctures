#include "funcs.h"
#include <iostream>
#include <vector>
#include <algorithm>

class HashTable {
private:
    struct Node {
        Car car;

        bool state;
        Node* next;

        Node(const Car& car_) : car(car_), state(true), next(nullptr) {};
    };
    Node** arr;

    const int default_size = 10;
    const double resize_cof = 0.75;

    int size; // усі елементи !ОКРІМ! Node -> state == false
    int buffer_size; // розмір масиву Node
    int sizewdeleted; // усі елементи !З! Node -> state == false

public:
    HashTable();
    ~HashTable();

    void resize();
    void add(const Car& car_);
    void remove(const Car& car_);
    vector<Car> tableout();

    int hash_function(const Car& car, const int& n);
};

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

vector<Car> HashTable::tableout() {
    vector<Car> all;

    for (int i = 0; i < buffer_size; i++) {
        Node* current = arr[i];
        while (current) {
            if (current->state == true) {
                all.push_back(current->car);
            }

            current = current->next;
        }
    }
    return all;
}

int HashTable::hash_function(const Car& car_, const int& n) {
    int i = 0;

    /*for (int j = 0; somestr[j]; j++) {
        i += somestr[j];
    }*/

    return i % n;
}
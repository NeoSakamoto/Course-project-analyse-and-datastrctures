#include "funcs.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

BinaryHeap::BinaryHeap() {
}

int BinaryHeap::parent(int i) {
    return (i - 1) / 2;
}

int BinaryHeap::left(int i) {
    return 2 * i + 1;
}

int BinaryHeap::right(int i) {
    return 2 * i + 2;
}

bool BinaryHeap::Edit(int id, string newBrand, string newModel, int newYear, double newPrice) {
    Car* car = findById(id);
    if (car == nullptr) {
        return false;
    }

    car->brand = newBrand;
    car->model = newModel;
    car->year = newYear;
    car->price = newPrice;

    return true;
}

void BinaryHeap::heapifyUp(int i) {
    while (i > 0 && heap[parent(i)].price > heap[i].price) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void BinaryHeap::heapifyDown(int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < heap.size() && heap[l].price < heap[smallest].price)
        smallest = l;

    if (r < heap.size() && heap[r].price < heap[smallest].price)
        smallest = r;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void BinaryHeap::insert(const Car& c) {
    heap.push_back(c);
    heapifyUp(heap.size() - 1);
}

Car BinaryHeap::getMin() {
    return heap[0];
}

bool BinaryHeap::removeMin() {
    if (heap.empty())
        return false;

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
        heapifyDown(0);

    return true;
}

bool BinaryHeap::empty() {
    return heap.empty();
}

Car* BinaryHeap::findById(int id) {
    for (auto& car : heap) {
        if (car.id == id) {
            return &car;
        }
    }
    return nullptr;
}

void egorTask() {
    BinaryHeap heap;

    for (int i = 0; i < 10; i++) {
        Car c;
        c.id = i;
        c.price = 500 + rand() % 500;
        heap.insert(c);
    }

    Car* found = heap.findById(5);
    if (found != nullptr) {
        cout << "Found car price: " << found->price << endl;
    }
}

void BinaryHeap::LoadFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        vector<string> parts;
        while (getline(ss, token, ';')) parts.push_back(token);

        if (parts.size() >= 6) {
            Car c;
            c.id = stoi(parts[0]);
            c.brand = parts[1];
            c.model = parts[2];
            c.year = stoi(parts[3]);
            c.price = stod(parts[4]);
            c.isRented = (parts[5] == "1");

            if (parts.size() >= 8) {
                c.rentedUntil = parts[6];
                c.owner = parts[7];
            } else {
                c.rentedUntil = "-";
                c.owner = "Admin";
            }
            insert(c);
        }
    }
    file.close();
}

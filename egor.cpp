#include "funcs.h"
#include <queue>
#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

struct CarPriceComparator {
    bool operator()(const Car& a, const Car& b) const {
        return a.price > b.price;
    }
};

priority_queue<Car, vector<Car>, CarPriceComparator> carQueue;

void egorTask() {
    auto startInsert = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; i++) {
        Car c;
        c.id = i;
        c.price = 500 + rand() % 500;
        carQueue.push(c);
    }

    auto endInsert = chrono::high_resolution_clock::now();

    auto startTop = chrono::high_resolution_clock::now();
    Car cheapest = carQueue.top();
    auto endTop = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> insertTime = endInsert - startInsert;
    chrono::duration<double, nano> topTime = endTop - startTop;

    cout << "Priority Queue (Heap):\n";
    cout << "Insert time (1000 elements): " << insertTime.count() << " ms\n";
    cout << "Get min price time: " << topTime.count() << " ns\n";
}

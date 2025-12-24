#include "funcs.h"
#include <iostream>

using namespace std;

int BinaryHeap::parent(int i) { return (i - 1) / 2; }
int BinaryHeap::left(int i) { return 2 * i + 1; }
int BinaryHeap::right(int i) { return 2 * i + 2; }

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

void BinaryHeap::removeMin() {
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

bool BinaryHeap::empty() {
    return heap.empty();
}

void egorTask() {
    BinaryHeap heap;

    for (int i = 0; i < 10; i++) {
        Car c;
        c.id = i;
        c.price = 500 + rand() % 500;
        heap.insert(c);
    }

    if (!heap.empty()) {
        Car cheapest = heap.getMin();
        cout << "Cheapest car price: " << cheapest.price << endl;
    }
}

#include "funcs.h"
#include <queue>
#include <vector>

struct CarPriceComparator {
    bool operator()(const Car& a, const Car& b) const {
        return a.price > b.price;
    }
};

priority_queue<Car, vector<Car>, CarPriceComparator> carQueue;

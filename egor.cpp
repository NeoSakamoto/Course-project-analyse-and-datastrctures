#include "funcs.h"
#include <queue>
#include <vector>

struct CarPriceComparator {
    bool operator()(const Car& a, const Car& b) const {
        return a.pricePerDay > b.pricePerDay;
    }
};

priority_queue<Car, vector<Car>, CarPriceComparator> carQueue;

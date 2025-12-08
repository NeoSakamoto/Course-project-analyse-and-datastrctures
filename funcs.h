#pragma once
#include <iostream>
using namespace std;

struct date {
    int d;
    int m;
    int y;
};

struct car {
    string RentnerName;
    string RentnerSecName;
    string Brand;
    string Model;
    date Rentstart;
    date Rentfinish;
};

void carinfo(car obj);
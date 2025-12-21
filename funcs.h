#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

struct date {
    int d;
    int m;
    int y;
};

struct Car {
    int id;
    string brand;
    string model;
    int year;
    double price;
    bool isRented;

    bool operator==(const Car& other) const {
        return price == other.price;
    }

    Car(int _id = 0, string _b = "", string _m = "", int _y = 0, double _p = 0.0) {
        id = _id; brand = _b; model = _m; year = _y; price = _p; isRented = false;
    }

    string GetInfo() const {
        string status = isRented ? "АРЕНДОВАНА" : "НЕ АРЕНДОВАНА";

        ostringstream oss;
        oss << id << " | " << brand << " " << model << " (" << year << ") - " << fixed << setprecision(1) << price << "$ " << status;
        return oss.str();
    }
};
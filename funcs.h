#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Car {
public:
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

    string ToString() const {
        return to_string(id) + ";" + brand + ";" + model + ";" +
            to_string(year) + ";" + to_string(price) + ";" + (isRented ? "1" : "0");
    }
};

void InfofromFile(string& filename, vector<Car>& cars);

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
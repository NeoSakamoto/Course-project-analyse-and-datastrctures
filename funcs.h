#pragma once
#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <QTreeWidget>
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
        return id == other.id && brand == other.brand && model == other.model &&
            year == other.year && price == other.price && isRented == other.isRented;
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

void Menu_Load(const string& filename, QTreeWidget* tree);

// Andriy
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
    void tableout();

    int hash_function(const Car& car, const int& n);
};

class List {
    struct Node {
        Car car;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;

public:
    List();
    ~List();

    size_t size;

    void push_back(const Car& car);
    void push_front(const Car& car);

    void search(const Car& car);
    void remove(const Car& car);

    void nodeout();
    void clear();
};

// Ihor
struct Node {
    Car data;
    Node* left;
    Node* right;
    Node(Car c);
};

class CarSearchTree {
private:
    Node* root;

    Node* AddNodeRecursive(Node* node, Car c);
    void CollectData(Node* node, vector<Car>& list);
    void ClearMemory(Node* node);

public:
    CarSearchTree();
    ~CarSearchTree();

    void Insert(Car c);
    vector<Car> GetList();
    Car* Find(int id);

    void SaveToFile(string filename);
    void LoadFromFile(string filename);

    bool RentCar(int id);
    bool ReturnCar(int id);
};

const int T = 3;

struct BTreeNode {
    vector<Car> keys;
    vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool _leaf);
};

class CarBTree {
private:
    BTreeNode* root;

    void ClearMemory(BTreeNode* node);
    void CollectDataRecursive(BTreeNode* node, vector<Car>& list);
    void SplitChild(BTreeNode* x, int i, BTreeNode* y);
    void InsertNonFull(BTreeNode* node, Car k);
    Car* SearchRecursive(BTreeNode* node, int id);

public:
    CarBTree();
    ~CarBTree();

    void Insert(Car k);
    Car* Find(int id, double& timeTakenIds);
    Car* Find(int id);

    vector<Car> GetSortedList();

    bool RentCar(int id);
    bool ReturnCar(int id);

    void SaveToFile(string filename);
    void LoadFromFile(string filename);
};

#endif
struct Car {
    int id;
    double price;
};

class BinaryHeap {
private:
    vector<Car> heap;

    int parent(int i);
    int left(int i);
    int right(int i);

    void heapifyUp(int i);
    void heapifyDown(int i);

public:
    void insert(const Car& c);
    Car getMin();
    void removeMin();
    bool empty();
};

void egorTask();

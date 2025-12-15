#pragma once
#include "funcs.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

struct Car {
    int id;
    string brand;
    string model;
    int year;
    double price;
    bool isRented;

    Car(int _id = 0, string _b = "", string _m = "", int _y = 0, double _p = 0.0) {
        id = _id; brand = _b; model = _m; year = _y; price = _p; isRented = false;
    }

    string GetInfo() const {
        string status = isRented ? "ÇÀÉÍßÒÎ" : "Â²ËÜÍÎ";
        return to_string(id) + " | " + brand + " " + model + " (" + to_string(year) + ") - " + to_string(price) + "$ " + status;
    }
};

struct Node {
    Car data;
    Node* left;
    Node* right;
    Node(Car c) : data(c), left(nullptr), right(nullptr) {}
};

class CarTree {
private:
    Node* root;

    Node* AddNodeRecursive(Node* node, Car c) {
        if (node == nullptr) return new Node(c);
        if (c.id < node->data.id)
            node->left = AddNodeRecursive(node->left, c);
        else if (c.id > node->data.id)
            node->right = AddNodeRecursive(node->right, c);
        return node;
    }

    void CollectData(Node* node, vector<Car>& list) {
        if (node != nullptr) {
            CollectData(node->left, list);
            list.push_back(node->data);
            CollectData(node->right, list);
        }
    }

    void ClearMemory(Node* node) {
        if (node) {
            ClearMemory(node->left);
            ClearMemory(node->right);
            delete node;
        }
    }

public:
    CarTree() : root(nullptr) {}
    ~CarTree() { ClearMemory(root); }

    void Insert(Car c) { root = AddNodeRecursive(root, c); }

    vector<Car> GetList() {
        vector<Car> list;
        CollectData(root, list);
        return list;
    }

   Car* Find(int id) {
        auto start = chrono::high_resolution_clock::now();

        Node* current = root;
        Car* result = nullptr; 

        while (current != nullptr) {
            if (id == current->data.id) {
                result = &(current->data); 
                break; 
            }
            else if (id < current->data.id) current = current->left;
            else current = current->right;
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::nano> duration = end - start;

        cout << "ID: " << id << ". Час пошуку: " << duration.count() << " наносекунд." << endl;

        return result;
    }
};

#pragma once
#include "funcs.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

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

    void SaveToFile(string filename) {
        ofstream file(filename);
        if (!file.is_open()) return;

        vector<Car> list = GetList();
        for (const auto& car : list) {
            file << car.ToString() << endl;
        }
        file.close();
    }

    void LoadFromFile(string filename) {
        ifstream file(filename);
        if (!file.is_open()) return;

        ClearMemory(root);
        root = nullptr;

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string segment;
            vector<string> data;

            while (getline(ss, segment, ';')) {
                data.push_back(segment);
            }

            if (data.size() >= 6) {
                try {
                    Car c;
                    c.id = stoi(data[0]);
                    c.brand = data[1];
                    c.model = data[2];
                    c.year = stoi(data[3]);
                    c.price = stod(data[4]);
                    c.isRented = (data[5] == "1");

                    Insert(c);
                }
                catch (...) {
                    continue;
                }
            }
        }
        file.close();
    }

    bool RentCar(int id) {
        Car* car = Find(id);
        if (car && !car->isRented) {
            car->isRented = true;
            return true;
        }
        return false;
    }

    bool ReturnCar(int id) {
        Car* car = Find(id);
        if (car && car->isRented) {
            car->isRented = false;
            return true;
        }
        return false;
    }
};

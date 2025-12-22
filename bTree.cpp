#pragma once
#include <funcs.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

    Car() : id(0), year(0), price(0.0), isRented(false) {}

    Car(int _id, string _brand, string _model, int _year, double _price, bool _rented = false)
        : id(_id), brand(_brand), model(_model), year(_year), price(_price), isRented(_rented) {}

    string ToString() const {
        return to_string(id) + ";" + brand + ";" + model + ";" +
               to_string(year) + ";" + to_string(price) + ";" + (isRented ? "1" : "0");
    }
};

const int T = 3;

struct BTreeNode {
    vector<Car> keys;
    vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool _leaf) : isLeaf(_leaf) {}
};

class CarTree {
private:
    BTreeNode* root;

    void ClearMemory(BTreeNode* node) {
        if (node) {
            if (!node->isLeaf) {
                for (auto child : node->children) ClearMemory(child);
            }
            delete node;
        }
    }

    void CollectDataRecursive(BTreeNode* node, vector<Car>& list) {
        if (node != nullptr) {
            int i;
            for (i = 0; i < node->keys.size(); i++) {
                if (!node->isLeaf) CollectDataRecursive(node->children[i], list);
                list.push_back(node->keys[i]);
            }
            if (!node->isLeaf) CollectDataRecursive(node->children[i], list);
        }
    }

    void SplitChild(BTreeNode* x, int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->isLeaf);

        for (int j = 0; j < T - 1; j++) z->keys.push_back(y->keys[j + T]);

        if (!y->isLeaf) {
            for (int j = 0; j < T; j++) z->children.push_back(y->children[j + T]);
        }

        y->keys.resize(T - 1);
        if (!y->isLeaf) y->children.resize(T);

        x->children.insert(x->children.begin() + i + 1, z);
        x->keys.insert(x->keys.begin() + i, y->keys[T - 1]);
    }

    void InsertNonFull(BTreeNode* node, Car k) {
        int i = node->keys.size() - 1;

        if (node->isLeaf) {
            node->keys.push_back(k);
            while (i >= 0 && k.id < node->keys[i].id) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = k;
        } else {
            while (i >= 0 && k.id < node->keys[i].id) i--;
            i++;
            if (node->children[i]->keys.size() == 2 * T - 1) {
                SplitChild(node, i, node->children[i]);
                if (k.id > node->keys[i].id) i++;
            }
            InsertNonFull(node->children[i], k);
        }
    }

    Car* SearchRecursive(BTreeNode* node, int id) {
        int i = 0;
        while (i < node->keys.size() && id > node->keys[i].id) i++;

        if (i < node->keys.size() && id == node->keys[i].id) return &(node->keys[i]);
        if (node->isLeaf) return nullptr;

        return SearchRecursive(node->children[i], id);
    }

public:
    CarTree() : root(nullptr) {}
    ~CarTree() { ClearMemory(root); }

    void Insert(Car k) {
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == 2 * T - 1) {
                BTreeNode* s = new BTreeNode(false);
                s->children.push_back(root);
                SplitChild(s, 0, root);
                root = s;
                InsertNonFull(s, k);
            } else {
                InsertNonFull(root, k);
            }
        }
    }

    Car* Find(int id, double& timeTakenIds) {
        auto start = chrono::high_resolution_clock::now();

        Car* result = nullptr;
        if (root) result = SearchRecursive(root, id);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::nano> duration = end - start;
        timeTakenIds = duration.count();

        return result;
    }

    Car* Find(int id) {
        if (root) return SearchRecursive(root, id);
        return nullptr;
    }

    vector<Car> GetSortedList() {
        vector<Car> list;
        CollectDataRecursive(root, list);
        return list;
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

    void SaveToFile(string filename) {
        ofstream file(filename);
        if (!file.is_open()) return;

        vector<Car> allCars = GetSortedList();
        for (const auto& car : allCars) {
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
};

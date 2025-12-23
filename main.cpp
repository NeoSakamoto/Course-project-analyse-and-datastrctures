#include <iostream>
#include <windows.h>
#include "funcs.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Car> cars;
	HashTable hash;
	List list;
	string filename = "cars.txt";
	InfofromFile(filename, cars);

	/*for (const Car& car : cars) {
		hash.add(car);
	}
	hash.tableout();*/

	/*for (const Car& car : cars) {
		list.push_back(car);
	}
	list.nodeout();*/

	/*CarSearchTree *searchtree = new CarSearchTree();
	for (const Car& car : cars) {
		searchtree->Insert(car);
	}
	
	for (const Car& car : searchtree->GetList()) {
		cout << car.GetInfo() << endl;
	}*/

	/*CarBTree btree;
	for (const Car& car : cars) {
		btree.Insert(car);
	}
	for (const Car& car : btree.GetSortedList()) {
		cout << car.GetInfo() << endl;
	}*/
}
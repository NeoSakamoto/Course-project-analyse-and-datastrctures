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

	/*for (Car car : cars) {
		hash.add(car);
	}
	hash.tableout();*/

	/*for (Car car : cars) {
		list.push_back(car);
	}
	list.nodeout();*/
}
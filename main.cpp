#include <iostream>
#include <windows.h>
#include "funcs.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Car> cars;
	string filename = "cars.txt";
	InfofromFile(filename, cars);

	for (Car car : cars) {
		cout << car.GetInfo() << endl;
	}
}
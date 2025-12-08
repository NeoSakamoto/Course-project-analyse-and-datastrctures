#include "funcs.h"

void carinfo(car obj) {
	cout << "Ім'я та Фамілія арендатора: " << obj.RentnerName << " " << obj.RentnerSecName << endl;
	cout << "Марка та модель автомобіля: " << obj.Brand << " " << obj.Model << endl;
	cout << "Початок та кінець аренди: " << obj.Rentstart.d << "." << obj.Rentstart.m << "." << obj.Rentstart.y
		<< " — " << obj.Rentfinish.d << "." << obj.Rentfinish.m << "." << obj.Rentfinish.y;
}
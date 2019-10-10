#include "Keeper.h"
#include "Carrier.h"
#include "Aircraft.h"
#include "Train.h"
#include "Func.h"
#include "Car.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	Keeper<Aircraft> aircraft;
	Keeper<Train> train;
	Keeper<Car> car;

	int button;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Выберите транспорт: " << endl << endl;
		cout << "1 - Самолет" << endl;
		cout << "2 - Поезд" << endl;
		cout << "3 - Автомобиль" << endl;
		cout << "0 - Выход из программы" << endl << endl;
		cout << "Выберите команду: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (button) {
		case 1: transportmenu(aircraft, "C://Users//Nikita//Desktop//Files for Lab1//Aircraft.txt"); break;
		case 2: transportmenu(train, "C://Users//Nikita//Desktop//Files for Lab1//Train.txt"); break;
		case 3: transportmenu(car, "C://Users//Nikita//Desktop//Files for Lab1//Car.txt"); break;
		case 0: flag = false; break;
		default: cout << endl << "Введена некорректная команда!" << endl << endl; system("pause"); break;
		}
	}
	return 0;
}
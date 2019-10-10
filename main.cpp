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
		cout << "�������� ���������: " << endl << endl;
		cout << "1 - �������" << endl;
		cout << "2 - �����" << endl;
		cout << "3 - ����������" << endl;
		cout << "0 - ����� �� ���������" << endl << endl;
		cout << "�������� �������: ";
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
		default: cout << endl << "������� ������������ �������!" << endl << endl; system("pause"); break;
		}
	}
	return 0;
}
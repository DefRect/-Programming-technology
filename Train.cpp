#include "Train.h"
#include <iostream>
#include <string>

using namespace std;

Train::Train() {
	cout << "Вызван конструктор по умолчанию класса Train" << endl << endl;
	name = "NaN";
	city = nullptr;
	number_city = 0;
	number_carriage = 0;
	year = 0;
	cargo_volume = 0;
}

Train::Train(const Train & other) {
	*this = other;
}

Train::~Train() {
	cout << "Вызван деструктор класса Train" << endl << endl;
	delete[] city;
}

void Train::set(){
	cin >> *this;
}

Train & Train::operator=(const Train & other) {
	this->name = other.name;
	this->cargo_volume = other.cargo_volume;
	this->number_carriage = other.number_carriage;
	this->year = other.year;
	this->number_city = other.number_city;
	this->city = new string[this->number_city];
	if (this->city != nullptr)
		delete[] this->city;
	for (int i = 0; i < this->number_city; ++i) {
		this->city[i] = other.city[i];
	}
	return *this;
}

ofstream & operator<<(ofstream & fout, Train & obj) {
	fout << obj.name << " " << obj.number_carriage << " " << obj.year << " " << obj.cargo_volume << " ";
	fout << obj.number_city << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		fout << obj.city[i] << " ";
	}
	fout << endl;
	return fout;
}

ifstream & operator>>(ifstream & fin, Train & obj) {
	fin >> obj.name >> obj.number_carriage >> obj.year >> obj.cargo_volume >> obj.number_city;
	obj.city = new string[obj.number_city];

	for (int i = 0; i < obj.number_city; ++i) {
		fin >> obj.city[i];
	}
	return fin;
}

ostream & operator<<(ostream & out, Train & obj) {
	out << "Название: " << obj.name << endl;
	out << "Колиество вагонов: " << obj.number_carriage << endl;
	out << "Год выпуска: " << obj.year << endl;
	out << "Объем перевозимого груза: " << obj.cargo_volume << endl;
	out << "Количество посещаемых городов: " << obj.number_city << endl;
	out << "Путь: ";
	for (int i = 0; i < obj.number_city; ++i) {
		out << obj.city[i];
		if (obj.number_city - 1 != i)
			out << " -> ";
	}
	out << endl << "--------------------------------------------------------------------------------";
	return out;
}

istream & operator>>(istream & in, Train & obj) {
	cout << "Введите данные" << endl << endl;
	cout << "Название: ";
	cin >> obj.name;

	while (1) {
		cout << "Количество вагонов: ";
		cin >> obj.number_carriage;
		if (cin.fail() || obj.number_carriage < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	while (1) {
		cout << "Год выпуска: ";
		cin >> obj.year;
		if (cin.fail() || obj.year < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	while (1) {
		cout << "Объем перевозимого груза(кг^3): ";
		cin >> obj.cargo_volume;
		if (cin.fail() || obj.cargo_volume < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	while (1) {
		cout << "Количество посещаемых городов: ";
		cin >> obj.number_city;
		if (cin.fail() || obj.number_city < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	if (obj.city != nullptr)
		delete[] obj.city;

	obj.city = new string[obj.number_city];
	cout << endl << "Введите названия городов" << endl << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		cout << i + 1 << " город: ";
		cin >> obj.city[i];
	}

	return in;
}

#include "Aircraft.h"
#include <iostream>
#include <string>

using namespace std;

Aircraft::Aircraft(){
	cout << "Вызван конструктор по умолчанию класса Aircraft" << endl << endl;

	type = "NaN";
	name = "NaN";
	city = nullptr;
	number_city = 0;
	cargo_volume = 0;
	length = 0;
	width = 0;
	height = 0;
}

Aircraft::Aircraft(const Aircraft & other){
	*this = other;
}

Aircraft::~Aircraft(){
	cout << "Вызван деструктор класса Aircraft" << endl << endl;
	delete[] city;
}

void Aircraft::set(){
	cin >> *this;
}

Aircraft & Aircraft::operator=(const Aircraft & other){
	this->type = other.type;
	this->name = other.name;
	this->cargo_volume = other.cargo_volume;
	this->length = other.length;
	this->width = other.width;
	this->height = other.height;
	this->number_city = other.number_city;
	if (this->city != nullptr)
		delete[] this->city;
	this->city = new string[this->number_city];
	for (int i = 0; i < this->number_city; ++i) {
		this->city[i] = other.city[i];
	}
	return *this;
}

ofstream & operator<<(ofstream & fout, Aircraft & obj){
	fout << obj.type << " " << obj.name << " " << obj.cargo_volume << " " << obj.length << " " << obj.width << " " << obj.height << " ";
	fout << obj.number_city << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		fout << obj.city[i] << " ";
	}
	fout << endl;
	return fout;
}

ifstream & operator>>(ifstream & fin, Aircraft & obj){
	fin >> obj.type >> obj.name >> obj.cargo_volume >> obj.length >> obj.width >> obj.height >> obj.number_city;
	obj.city = new string[obj.number_city];

	for (int i = 0; i < obj.number_city; ++i) {
		fin >> obj.city[i];
	}
	return fin;
}

ostream & operator<<(ostream & out, Aircraft & obj){
	out << "Тип: " << obj.type << endl;
	out << "Название: " << obj.name << endl;
	out << "Объем перевозимого груза: " << obj.cargo_volume << endl;
	out << "Длина: " << obj.length << endl;
	out << "Ширина: " << obj.width << endl;
	out << "Высота: " << obj.height << endl;
	out << "Количество посещаемых городов: " << obj.number_city << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		out << "  " << i + 1 << " город: " << obj.city[i] << endl;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}

istream & operator>>(istream & in, Aircraft & obj){
	cout << "Введите данные" << endl << endl;
	cout << "Тип: ";
	cin >> obj.type;
	cout << "Название: ";
	cin >> obj.name;

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
		cout << "Длниа: ";
		cin >> obj.length;
		if (cin.fail() || obj.length < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "Ширина: ";
		cin >> obj.width;
		if (cin.fail() || obj.width < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "Высота: ";
		cin >> obj.height;
		if (cin.fail() || obj.height < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "Сколько городов посещает: ";
		cin >> obj.number_city;
		if (cin.fail() || obj.number_city < 0) {
			cout << "Некорректные данные, попробуте снова!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	if(obj.city != nullptr)
		delete[] obj.city;

	obj.city = new string[obj.number_city];
	cout << endl << "Введите названия городов" << endl << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		cout << i + 1 << " город: ";
		cin >> obj.city[i];
	}

	return in;
}

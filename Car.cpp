#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car(){
	cout << "������ ����������� �� ��������� ������ Car" << endl << endl;
	mark = "NaN";
	model = "NaN";
	year = 0;
	cargo_volume = 0;
	number_city = 0;
	city = nullptr;
}

Car::Car(const Car &other){
	*this = other;
}

Car::~Car(){
	cout << "������ ���������� ������ Car" << endl << endl;
	delete[] city;
}

void Car::set(){
	cin >> *this;
}

Car & Car::operator=(const Car & other){
	this->mark = other.mark;
	this->model = other.model;
	this->year = other.year;
	this->number_city = other.number_city;
	if (this->city != nullptr)
		delete[] this->city;
	this->city = new Town[this->number_city];
	for (int i = 0; i < this->number_city; ++i) {
		this->city[i].name = other.city[i].name;
		this->city[i].hours = other.city[i].hours;
	}
	return *this;
}

ofstream & operator<<(ofstream & fout, Car & obj){
	fout << obj.mark << " " << obj.model << " " << obj.year << " " << obj.cargo_volume << " " << obj.number_city;
	for (int i = 0; i < obj.number_city; ++i) {
		fout << obj.city[i].name << " " << obj.city[i].hours << " ";
	}
	fout << endl;
	return fout;
}

ifstream & operator>>(ifstream & fin, Car & obj){
	fin >> obj.mark >> obj.model >> obj.year >> obj.cargo_volume >> obj.number_city;
	obj.city = new Town[obj.number_city];
	for (int i = 0; i < obj.number_city; ++i) {
		fin >> obj.city[i].name >> obj.city[i].hours;
	}
	return fin;
}

ostream & operator<<(ostream & out, Car & obj){
	out << "�����: " << obj.mark << endl;
	out << "������: " << obj.model << endl;
	out << "��� �������: " << obj.year << endl;
	out << "����� ������������ �����: " << obj.cargo_volume << endl;
	out << "���������� �������: " << obj.number_city << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		out << "�����: " << obj.city[i].name << " (" << obj.city[i].hours << " ����� ��������)" << endl;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}

istream & operator>>(istream & in, Car & obj){
	cout << "������� ������" << endl << endl;
	cout << "�����: ";
	cin >> obj.mark;
	cout << "������: ";
	cin >> obj.model;

	while (1) {
		cout << "��� �������: ";
		cin >> obj.year;
		if (cin.fail() || obj.year < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	while (1) {
		cout << "����� ������������ �����(��^3): ";
		cin >> obj.cargo_volume;
		if (cin.fail() || obj.cargo_volume < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	while (1) {
		cout << "���������� �������: ";
		cin >> obj.number_city;
		if (cin.fail() || obj.number_city < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	if (obj.city != nullptr)
		delete[] obj.city;

	obj.city = new Town[obj.number_city];
	cout << endl << "������� ������� � ����� �������� (� �����)" << endl << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		cout << "�����: ";
		cin >> obj.city[i].name;
		cout << "����� �������� (� �����): ";
		cin >> obj.city[i].hours;
	}

	return in;
}
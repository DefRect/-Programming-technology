#include "Aircraft.h"
#include <iostream>
#include <string>

using namespace std;

Aircraft::Aircraft(){
	cout << "������ ����������� �� ��������� ������ Aircraft" << endl << endl;

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
	cout << "������ ���������� ������ Aircraft" << endl << endl;
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
	out << "���: " << obj.type << endl;
	out << "��������: " << obj.name << endl;
	out << "����� ������������ �����: " << obj.cargo_volume << endl;
	out << "�����: " << obj.length << endl;
	out << "������: " << obj.width << endl;
	out << "������: " << obj.height << endl;
	out << "���������� ���������� �������: " << obj.number_city << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		out << "  " << i + 1 << " �����: " << obj.city[i] << endl;
	}
	out << "--------------------------------------------------------------------------------";
	return out;
}

istream & operator>>(istream & in, Aircraft & obj){
	cout << "������� ������" << endl << endl;
	cout << "���: ";
	cin >> obj.type;
	cout << "��������: ";
	cin >> obj.name;

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
		cout << "�����: ";
		cin >> obj.length;
		if (cin.fail() || obj.length < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "������: ";
		cin >> obj.width;
		if (cin.fail() || obj.width < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "������: ";
		cin >> obj.height;
		if (cin.fail() || obj.height < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}
	while (1) {
		cout << "������� ������� ��������: ";
		cin >> obj.number_city;
		if (cin.fail() || obj.number_city < 0) {
			cout << "������������ ������, ��������� �����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;
	}

	if(obj.city != nullptr)
		delete[] obj.city;

	obj.city = new string[obj.number_city];
	cout << endl << "������� �������� �������" << endl << endl;
	for (int i = 0; i < obj.number_city; ++i) {
		cout << i + 1 << " �����: ";
		cin >> obj.city[i];
	}

	return in;
}

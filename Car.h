#pragma once
#include "Carrier.h"
#include "Keeper.h"
#include <fstream>

struct Town {
	string name;
	int hours;
};

class Car : public Carrier {
	string mark;
	string model;
	int year;
	int cargo_volume;
	int number_city;
	Town *city;
public:
	Car();
	Car(const Car&);
	~Car();

	void set();

	friend ofstream& operator << (ofstream &fout, Car& obj);
	friend ifstream& operator >> (ifstream &fin, Car& obj);

	friend ostream& operator << (ostream &out, Car& obj);
	friend istream& operator >> (istream &in, Car& obj);

	Car& operator =(const Car &other);
};
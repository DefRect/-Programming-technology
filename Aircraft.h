#pragma once
#include <fstream>
#include "Carrier.h"
#include "Keeper.h"

using namespace std;

class Aircraft : public Carrier {
	string type;
	string name;
	string *city;
	int number_city;
	int cargo_volume;
	int length;
	int width;
	int height;

public:
	Aircraft();
	Aircraft(const Aircraft &other);
	~Aircraft();

	void set();

	friend ofstream& operator << (ofstream &fout, Aircraft& obj);
	friend ifstream& operator >> (ifstream &fin, Aircraft& obj);

	friend ostream& operator << (ostream &out, Aircraft& obj);
	friend istream& operator >> (istream &in, Aircraft& obj);

	Aircraft& operator =(const Aircraft &other);
};
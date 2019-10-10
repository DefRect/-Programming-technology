#pragma once
#include <fstream>
#include "Carrier.h"
#include "Keeper.h"

using namespace std;

class Train : public Carrier {
	string name;
	string *city;
	int number_city;
	int number_carriage;
	int year;
	int cargo_volume;
public:
	Train();
	Train(const Train&);
	~Train();

	void set();

	friend ofstream& operator << (ofstream &fout, Train& obj);
	friend ifstream& operator >> (ifstream &fin, Train& obj);

	friend ostream& operator << (ostream &out, Train& obj);
	friend istream& operator >> (istream &in, Train& obj);

	Train& operator =(const Train &other);
};
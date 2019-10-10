#pragma once
#include "Keeper.h"

class Carrier{
public:
	Carrier();
	virtual ~Carrier();
	virtual void set() = 0;
};
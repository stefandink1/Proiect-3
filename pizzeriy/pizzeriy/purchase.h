#pragma once
#include <iostream>

using namespace std;

class purchase
{
protected:
	float pizzaValue;
	virtual void calcPrice() = 0;
public:
	purchase(float);
	~purchase();
};


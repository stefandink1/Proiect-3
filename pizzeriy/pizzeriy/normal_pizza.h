#pragma once
#include "pizza.h"

class normal_pizza :public pizza
{
public:
	normal_pizza() : pizza() { this->veggie = false; };
	normal_pizza(string name, vector<ingredient> arr) : pizza(name, arr) { this->veggie = false; };

	void printPizza();
};


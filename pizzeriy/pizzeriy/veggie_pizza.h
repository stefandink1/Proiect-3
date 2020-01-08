#pragma once
#include "pizza.h"

class veggie_pizza :public pizza
{
public:
	veggie_pizza() : pizza() { this->veggie = true; };
	veggie_pizza(const veggie_pizza &obj) : pizza(obj) {};
	veggie_pizza(string name, vector<ingredient> arr) : pizza(name, arr) { this->veggie = true; };

	void printPizza();
};
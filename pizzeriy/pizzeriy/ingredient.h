#pragma once
#include <string>
#include <iostream>

using namespace std;

class ingredient
{
	string name;
	float amount;
	float pricePerUnit;
	float totalPrice;

public:
	ingredient();
	ingredient(string, float, float);

	float get_price();
	void menu_print();

	friend istream& operator>>(istream&, ingredient&);
	friend ostream& operator<<(ostream&, ingredient);
};

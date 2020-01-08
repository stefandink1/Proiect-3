#pragma once
#include "product.h"
#include <vector>

class pizza : protected product
{
	float price;
	static float manshipwork;

	void calcPrice();
protected:
	string name;
	vector<ingredient> ingArr;
	bool veggie;
public:
	pizza();
	pizza(float);
	pizza(const pizza &obj);
	pizza(string, vector<ingredient>);
	virtual ~pizza();

	float get_m();

	string get_name();
	float get_price();
	bool isVeggie() { return veggie; };
	virtual void printPizza();

	friend istream& operator>>(istream&, pizza&);
	friend ostream& operator<<(ostream&, pizza);
};


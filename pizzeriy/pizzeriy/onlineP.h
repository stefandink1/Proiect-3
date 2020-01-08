#pragma once
#include "purchase.h"
class onlineP :public purchase
{
	float distance;
	float totalPrice;
	void askDistance();
	void calcPrice();
public:
	onlineP(float val) :purchase(val) { askDistance(); calcPrice(); };
	float getPrice();
};


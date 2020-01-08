#pragma once
#include "purchase.h"
class offlineP :protected purchase
{
	float totalPrice;
	void calcPrice();
public:
	offlineP(float val) :purchase(val) { calcPrice(); };
	float getPrice();
};


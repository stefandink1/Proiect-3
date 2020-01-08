#include "pch.h"
#include "offline.h"

void offlineP::calcPrice() {
	this->totalPrice = this->pizzaValue;
}

float offlineP::getPrice() {
	return totalPrice;
}
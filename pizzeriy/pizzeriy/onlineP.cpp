#include "pch.h"
#include "onlineP.h"

void onlineP::askDistance() {
	cout << "Care este distanta pana la resedinta d-voastra? (km)" << endl;
	cin >> distance;
}

void onlineP::calcPrice() {
	float delivery = (0.05*this->pizzaValue)*(distance / 10);
	totalPrice = this->pizzaValue + delivery;
}

float onlineP::getPrice() {
	return totalPrice;
}
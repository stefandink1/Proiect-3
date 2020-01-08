#include "pch.h"
#include "ingredient.h"


ingredient::ingredient() {

}

ingredient::ingredient(string name, float amount, float ppu) {
	this->name = name;
	this->amount = amount;
	this->pricePerUnit = ppu;
	this->totalPrice = amount * ppu;
}

float ingredient::get_price() {
	return this->totalPrice;
}

void ingredient::menu_print() {
	cout << "-" << this->name << " " << this->amount << "g" << endl;
}

istream& operator>>(istream& in, ingredient& obj) {
	cout << "Denumire Ingredient: ";
	getline(in, obj.name);
	cout << "Cantitate (g): ";
	in >> obj.amount;
	cout << "Pret pe Unitate (lei): ";
	in >> obj.pricePerUnit;
	obj.totalPrice = obj.amount*obj.pricePerUnit;
	return in;
}
ostream& operator<<(ostream& out, ingredient obj) {
	out << "-Denumire: " << obj.name << " |Cantitate: " << obj.amount << " |Pret pe unitate: " << obj.pricePerUnit << " |Pret total: " << obj.totalPrice << endl;
	return out;
}
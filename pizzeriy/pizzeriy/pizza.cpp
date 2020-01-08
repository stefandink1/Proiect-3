#include "pch.h"
#include "pizza.h"

float pizza::manshipwork;

pizza::pizza() {
}
pizza::pizza(float x) {
	manshipwork = x;
}
pizza::pizza(const pizza &obj) {
	this->name = obj.name;
	this->ingArr = obj.ingArr;
	this->calcPrice();
	manshipwork = 0;
}

pizza::pizza(string name, vector<ingredient> arr) {
	this->name = name;
	this->ingArr = arr;
	this->calcPrice();
	manshipwork = 0;
}

pizza::~pizza()
{
}

void pizza::calcPrice() {
	this->price = manshipwork;
	for (int i = 0; i < ingArr.size(); i++)
		this->price += ingArr[i].get_price();
}
float pizza::get_m() {
	return manshipwork;
}

string pizza::get_name() {
	return this->name;
}
float pizza::get_price() {
	return this->price;
}

istream& operator>>(istream& in, pizza& obj) {
	cout << "Denumire pizza: ";
	getline(in, obj.name);
	cout << "Numarul de ingrediente: ";
	int n;
	in >> n;
	for (int i = 1; i <= n; i++)
	{
		in.ignore();
		cout << "Ingredientul " << i << ": " << endl;
		string iName;
		float iAmount, iPPU;
		cout << "-Denumire: ";
		getline(in, iName);
		cout << "-Cantitate(g): ";
		in >> iAmount;
		cout << "-Pret pe Unitate: ";
		in >> iPPU;
		ingredient aux(iName, iAmount, iPPU);
		obj.ingArr.push_back(aux);
	}
	obj.calcPrice();
	return in;
}
ostream& operator<<(ostream& out, pizza obj) {
	out << obj.name << endl;
	out << "|Ingrediente: " << endl;
	for (int i = 0; i < obj.ingArr.size(); i++)
	{
		out << "|";
		obj.ingArr[i].menu_print();
	}
	cout << "|-Pret: " << obj.get_price() << "lei" << endl;
	return out;
}
void pizza::printPizza() {
	cout << this->name << endl;
	cout << "|Ingrediente: " << endl;
	for (int i = 0; i < this->ingArr.size(); i++)
	{
		cout << "|";
		this->ingArr[i].menu_print();
	}
	cout << "|-Pret: " << this->get_price() << "lei" << endl;
}

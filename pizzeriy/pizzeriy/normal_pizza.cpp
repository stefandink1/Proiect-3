#include "pch.h"
#include "normal_pizza.h"

void normal_pizza::printPizza() {
	cout << "Pizza: " << this->name << endl;
	cout << "|Ingrediente: " << endl;
	for (int i = 0; i < this->ingArr.size(); i++)
	{
		cout << "|";
		this->ingArr[i].menu_print();
	}
	cout << "|-Pret: " << this->get_price() << "lei" << endl;
}
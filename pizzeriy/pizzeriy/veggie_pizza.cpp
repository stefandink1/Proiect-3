#include "pch.h"
#include "veggie_pizza.h"

void veggie_pizza::printPizza() {
	cout << "Veggie: " << this->name << endl;
	cout << "|Ingrediente: " << endl;
	for (int i = 0; i < this->ingArr.size(); i++)
	{
		cout << "|";
		this->ingArr[i].menu_print();
	}
	cout << "|-Pret: " << this->get_price() << "lei" << endl;
}
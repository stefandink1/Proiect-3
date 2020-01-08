#pragma once
#include "veggie_pizza.h"
#include "normal_pizza.h"
#include "onlineP.h"
#include "offline.h"

template <class T>
class menu
{
	vector<T*> pizzaArr;
	int NoProd;
	vector<T*> soldArr;
	float pizzaSold = 0;
	float veggieTotal = 0;

	void addPizza(T*);
	void printMenu();
	void order();
public:
	void operator+=(T*);
	void producerSide();
	void clientSide();
	void dayEnd();
	menu();
	menu(vector<T*>);
	~menu();
};

template <class T>
menu<T>::menu() {
}
template <class T>
menu<T>::menu(vector<T*>)
{

}

template <class T>
menu<T>::~menu()
{
}

template <class T>
void menu<T>::addPizza(T* obj) {
	pizzaArr.push_back(obj);
}

template <class T>
void menu<T>::printMenu() {
	for (int i = 0; i < pizzaArr.size(); i++)
	{
		cout << i + 1 << "." << endl;
		cout << *pizzaArr[i];
	}
}

template <class T>
void menu<T>::producerSide() {
	cout << " -PRODUCATOR- " << endl;
	cout << "Inserati pretul manoperei: ";
	float manop;
	cin >> manop;
	T a(manop);
	cout << "Cate produse doriti sa adaugati in meniu?" << endl;
	cin >> NoProd;
	for (int i = 0; i < NoProd; i++)
	{
		int choice;
	askType:
		cout << "Veggie (1) sau Normala (2)?" << endl;
		cin >> choice;
		cin.ignore();
		if (choice == 1 || choice == 2)
		{
			veggie_pizza *obj = new veggie_pizza();
			cin >> *obj;
			addPizza(dynamic_cast<pizza*>(obj));
		}
		else if (choice == 1 || choice == 2)
		{
			normal_pizza *obj = new normal_pizza();
			cin >> *obj;
			addPizza(dynamic_cast<pizza*>(obj));
		}
		else
		{
			cout << "Nu exista acest tip de pizza." << endl;
			goto askType;
		}
	}
	printMenu();
}

template <class T>
void menu<T>::operator+=(T* obj) {
	soldArr.push_back(obj);
	if (obj->isVeggie())
		veggieTotal += obj->get_price();
	pizzaSold++;
}

template <class T>
void menu<T>::order() {
	int choice, away;
	cout << "Ce doriti sa comandati din meniu? (inserati numarul produsului)" << endl;
	cin >> choice;
	choice--;
	cout << "Doriti: " << pizzaArr[choice]->get_name() << endl;
takeaway:
	cout << "Aici sau la domiciliu? (aici = 1, domiciliu=2)" << endl;
	cin >> away;
	if (away == 1)
	{
		this->operator+=(pizzaArr[choice]);
		cout << "Comanda d-voastra este: " << endl;
		cout << *pizzaArr[choice];
	}
	else if (away == 2)
	{
		this->operator+=(pizzaArr[choice]);
		cout << "Comanda d-voastra este: " << endl;
		cout << *pizzaArr[choice];
		onlineP ord(pizzaArr[choice]->get_price());
		cout << "Pretul cu transport: " << ord.getPrice();
	}
	else
	{
		cout << "Aceasta nu este o varianta. :)" << endl;
		goto takeaway;
	}
}

template <class T>
void menu<T>::clientSide() {
	cout << "-CLIENT-" << endl;
getorder:
	order();
nextClient:
	cout << endl << "Clientul urmator? (da=1, nu=2)" << endl;
	int choice;
	try {
		cin >> choice;
		if (choice != 1 && choice != 2) {
			throw 0;
		}
		if (choice == 1)
			goto getorder;
	}
	catch (int) {
		cout << "Trebuie sa alegeti 1 sau 2";
		goto nextClient;
	}
}

template <class T>
void menu<T>::dayEnd() {
	cout << "-INVENTAR-" << endl;
	cout << "Numarul de pizza vandute: " << this->pizzaSold << endl;
	cout << "Venit din veggie: " << this->veggieTotal << endl;
	cout << "Produsele vandute: " << endl;
	for (int i = 0; i < soldArr.size(); i++)
		cout << i + 1 << "." << endl << *soldArr[i];
}

#include "pch.h"
#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
	menu<pizza> meniu;
	meniu.producerSide();
	meniu.clientSide();
	meniu.dayEnd();
}
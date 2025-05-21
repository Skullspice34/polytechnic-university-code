/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 20, 2023
* Topic: Composition and Dynamic Memory
* File name: dynamic.cpp
* This file declares a class named Sodas
* Name: Prof. de la Cruz
*/
#include "SodaMachine.h"
#include <string>
int main() {
	SodaMachine sodas;
	string name = "";
	double price = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Enter the name for soda #" << i + 1 << ": ";
		getline(cin, name);
		cout << "Enter the price for " << name << ": ";
		cin >> price;
		sodas.addSoda(name, price);
		cout << endl;
		cin.ignore(256, '\n');
	}
	sodas.printMachine();
	cout << "Enter the name of the soda to be removed: ";
	getline(cin, name);
	sodas.sellSoda(sodas.findSoda(name));
	sodas.printMachine();
	system("pause");
	return 0;
}
/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 20, 2023
* Topic: Composition and Dynamic Memory
* File name: SodaMachine.cpp
* This file declares a class named Sodas
* Name: Prof. de la Cruz
*/
#include "SodaMachine.h"
SodaMachine::SodaMachine() {
	sodas = 0;
	machine = nullptr;
}
SodaMachine::SodaMachine(const SodaMachine& aMachine) {
	sodas = aMachine.getSize();
	machine = new Sodas * [getSize()];
	copyArray(aMachine.getArray(), aMachine.getSize());
}
SodaMachine::~SodaMachine() {
	// first relase memeory allocated to Sodas objects
	for (int i = 0; i < getSize(); i++)
		machine[i]->~Sodas();
	delete[] machine;
}
void SodaMachine::addSoda(string aName, double aPrice) {
	if (getSize() > 0) { // the array exists
		Sodas** temp = machine;
		machine = new Sodas * [++sodas];
		copyArray(temp, getSize() - 1);
		delete[] temp;
	}
	else{ // must create the array
		machine = new Sodas * [++sodas];
	}
	machine[getSize() - 1] = new Sodas(aName, aPrice);
}
void SodaMachine::sellSoda(const int index) {
	if (getSize() > 0 && index < getSize() && index > -1) {
		if (getSize() > 1) {
			machine[index]->~Sodas();
			Sodas** temp = machine;
			machine = new Sodas * [--sodas];
			copyArray(temp, getSize() + 1);
			delete[] temp;
		}
		else {
			machine[0]->~Sodas();
			delete[] machine;
		}
	}
}
int SodaMachine::getSize() const {
	return sodas;
}
Sodas** SodaMachine::getArray() const {
	return machine;
}
void SodaMachine::copyArray(Sodas** aMachine, const int size) {
	int limit = size < getSize() ? size : getSize();
	for (int i = 0; i < limit; i++)
		machine[i] = aMachine[i];
}
int SodaMachine::findSoda(string aName) const {
	if (getSize() > 0) {
		for (int i = 0; i < getSize(); i++) {
			if (machine[i]->getName().compare(aName) == 0)
				return i;
		}
	}
	return -1;
}
void SodaMachine::printMachine() const {
	if (getSize() > 0) {
		printf("%-*s$%s\n", machine[0]->getNameSize(), "NAME", "PRICE");
		for (int i = 0; i < getSize(); i++)
			machine[i]->printSoda();
		cout << endl;
	}
}
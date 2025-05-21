/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 20, 2023
* Topic: Composition and Dynamic Memory
* File name: SodaMachine.h
* This file declares a class named Sodas
* Name: Prof. de la Cruz
*/
#pragma once
#include "Sodas.h"
class SodaMachine {
private: 
	int sodas; // the size of the array
	Sodas** machine; // the Sodas array
public:
	SodaMachine();
	SodaMachine(const SodaMachine&);
	~SodaMachine();
	void addSoda(string, double);
	void sellSoda(const int);
	int getSize() const;
	Sodas** getArray() const;
	void copyArray(Sodas**, const int);
	int findSoda(string) const;
	void printMachine() const;
};


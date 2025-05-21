/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 20, 2023
* Topic: Composition and Dynamic Memory
* File name: Sodas.h
* This file declares a class named Sodas
* Name: Prof. de la Cruz
*/
#pragma once
// preprocessor directives
#include <iostream>
using namespace std;
class Sodas {
private:
	// declare an integer class variable named sodasCount
	static int sodasCount;
	static size_t nameSize; // to store the size of the name field
	string name;
	double price;
public:
	// declare the default and copy constructors, and the destructor
	Sodas();
	Sodas(string, double);
	Sodas(const Sodas&);
	~Sodas();
	void setName(string);
	void setPrice(double);
	void setNameSize(const string); // to set the size of the name field
	string getName() const;
	double getPrice() const;
	int getSodasCount() const;
	size_t getNameSize() const; // to get the size of the name field
	void printSoda() const;
	// declare the overload for the greater than, >, operator
	bool operator >(const Sodas&) const;
	void operator =(const Sodas&); // to be used in the arrange method in main
};
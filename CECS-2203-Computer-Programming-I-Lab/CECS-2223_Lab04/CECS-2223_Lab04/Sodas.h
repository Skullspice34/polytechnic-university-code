/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 13, 2023
* Topic: Lab 4 - Arrays of objects and operator overload
* File name: Sodas.h
* This file declares a class named Sodas
* Complete the declaration as required.
* Name: Coral S. Schmidt, ID#148830
*/
#pragma once

// preprocessor directives
#include <string>
#include <iostream>
using namespace std;

class Sodas {
private:
	// declare an integer class variable named sodasCount
	static int sodasCount;

	string name;
	double price;
public:
	// declare the default and copy constructors, and the destructor
	Sodas();
	Sodas(const Sodas& other);
	~Sodas();

	void setName(string);
	void setPrice(double);
	string getName() const;
	double getPrice() const;
	int getSodasCount() const;
	void printSoda() const;

	// declare the overload for the greater than, >, operator
	friend bool operator>(const Sodas& soda1, const Sodas& soda2);
};


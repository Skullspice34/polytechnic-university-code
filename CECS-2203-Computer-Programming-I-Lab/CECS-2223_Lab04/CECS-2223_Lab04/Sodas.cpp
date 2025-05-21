/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 13, 2023
* Topic: Lab 4 - Arrays of objects and operator overload
* File name: Sodas.cpp
* Name: Coral S. Schmidt, ID#148830
* This file defines the Sodas class
*/
// do we need any preprocessor directives?
#include "Sodas.h"

// initialize the class variable to 0
int Sodas::sodasCount = 0;

// The default constructor assigns the empty string to the name, 
// 0 to the price, and increments the value of sodasCount
Sodas::Sodas()
{
	name = "";
	price = 0.0;
	sodasCount++;
}

// The copy constructor calls the accessor methods from the parameter 
// to assign field values to the new object
Sodas::Sodas(const Sodas& other)
{
	name = other.name;
	price = other.price;
}

// The destructor is defined with an empty block of code
Sodas::~Sodas()
{
}

// The set methods DO NOT prompt the user for values or include any 
// cout or printf statements. You must validate the parameter's value
// for the price using the ternary operator, assign 0 if invalid.
void Sodas::setName(string sodaName)
{
	name = sodaName;
}

void Sodas::setPrice(double sodaPrice)
{
	price = (sodaPrice >= 0.0) ? sodaPrice : 0.0;
}

// define the get methods, they should all be constant
string Sodas::getName() const
{
	return name;
}

double Sodas::getPrice() const
{
	return price;
}

int Sodas::getSodasCount() const
{
	return sodasCount;
}



// The printSoda method uses printf to output values formatted
// to be displayed in a table at 12 spaces per column aligned to
// the left of the column. The values to be displayed are: name 
// and price. All values must be printed in the same line. 
// For example, a Sodas object named Coca-Cola would display:
// Coca-Cola   $1.25
// Make sure to include the dollar sign in the output.
void Sodas::printSoda() const
{
	printf("%-12s $%.2f\n", name.c_str(), price);
}

// The overload to the > operator receives a constant reference to a
// Sodas object as parameter and returns a boolean value. It compares
// the values of the price fields and returns true if the price of the 
// object is greater than the price of the parameter, false otherwise.
// This method cannot change the values of the object.

bool operator>(const Sodas& soda1, const Sodas& soda2)
{
	return soda1.price > soda2.price;
}

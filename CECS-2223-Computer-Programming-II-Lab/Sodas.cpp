/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: September 20, 2023
* Topic: Composition and Dynamic Memory
* File name: Sodas.cpp
* Name: Prof. de la Cruz
* This file defines the Sodas class
*/
// do we need any preprocessor directives?
#include "Sodas.h"
// initialize the class variable to 0
int Sodas::sodasCount = 0;
// initialize the nameSize class variable
size_t Sodas::nameSize = 0;
// The default constructor assigns the empty string to the name, 
// 0 to the price, and increments the value of sodasCount
Sodas::Sodas() {
	name = "";
	price = 0;
	sodasCount++;
}
Sodas::Sodas(string aName, double aPrice) {
	name = aName;
	setNameSize(name);
	price = aPrice;
	sodasCount++;
}
// The copy constructor calls the accessor methods from the parameter 
// to assign field values to the new object
Sodas::Sodas(const Sodas& aSoda) {
	name = aSoda.getName();
	setNameSize(name);
	price = aSoda.getPrice();
	sodasCount++;
}

// The destructor is defined with an empty block of code
Sodas::~Sodas() {
	cout << "\n\tThe " << getName() << " Sodas object has been destroyed.\n\n";
}

// The set methods DO NOT prompt the user for values or include any 
// cout or printf statements. You must validate the parameter's value
// for the price using the ternary operator, assign 0 if invalid.
void Sodas::setName(string aName) {
	name = aName;
	setNameSize(name);
}
void Sodas::setPrice(double aPrice) {
	price = aPrice < 0 ? 0 : aPrice;
	// price = aPrice > 0 ? aPrice : 0;
}
void Sodas::setNameSize(const string aName) {
	if (aName.size() + 1 > getNameSize())
		nameSize = aName.size() + 1;
}
// define the get methods, they should all be constant
string Sodas::getName() const {
	return name;
}
double Sodas::getPrice() const {
	return price;
}
int Sodas::getSodasCount() const {
	return sodasCount;
}
size_t Sodas::getNameSize() const {
	return nameSize;
}
// The printSoda method uses printf to output values formatted
// to be displayed in a table at 12 spaces per column aligned to
// the left of the column. The values to be displayed are: name 
// and price. All values must be printed in the same line. 
// For example, a Sodas object named Coca-Cola would display:
// Coca-Cola   $1.25
// Make sure to include the dollar sign in the output.
void Sodas::printSoda() const {
	//printf("%-12s$%.2f\n", getName().c_str(), getPrice());
	// alternative method using variable field size
	printf("%-*s$%.2f\n", getNameSize(), getName().c_str(), getPrice());
}

// The overload to the > operator receives a constant reference to a
// Sodas object as parameter and returns a boolean value. It compares
// the values of the price fields and returns true if the price of the 
// object is greater than the price of the parameter, false otherwise.
// This method cannot change the values of the object.
bool Sodas::operator>(const Sodas& aSoda) const {
	if (getPrice() > aSoda.getPrice())
		return true;
	else
		return false;
	// alternatively, return getPrice() > aSoda.getPrice();
}

// define the overload for the assignment operator
void Sodas::operator=(const Sodas& aSoda) {
	setName(aSoda.getName());
	setPrice(aSoda.getPrice());
}
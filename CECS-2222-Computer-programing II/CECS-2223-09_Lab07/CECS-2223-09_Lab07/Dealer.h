/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 18, 2023
* Topic: Lab 7
* File name: Dealer.h
* This file declares a class named Dealer
* Name: Coral S. Schmidt Montilla, ID#148830
* Name: Aleysha M. Rivera Cores, ID#108408
*/

#pragma once
#include "Car.h"

class Dealer
{
private:
	int cars; // The number of cars in inventory
	string name; // The name of the dealership
	Car** inventory; // The dealership’s inventory
	size_t brandLength; // the size of the brand field
	void setBrandLength(string, bool); // compares the length of the parameter +
	// 2 with the current value for brandLength. Changes the value of the field
	// if the value of the parameter + 2 is greater than the current value. If
	// the second parameter is true, checks the inventory array for the size of
	// the largest brand length, and assigns it to brandLength if the value found
	// is smaller
	size_t modelLength; // the size of the model field
	void setModelLength(string, bool); // compares the length of the parameter + 2
	// with the current value for modelLength. Changes the value of the field if
	// the value of the parameter + 2 is greater than the current value. If the
	// second parameter is true, checks the inventory array for the size of the
	// largest model length, and assigns it to modelLength if the value found is
	// smaller
	void orderInventory();// Orders the cars in inventory alphabetically, first by brand
	// name, then by model name, and then by serial number.

	//added to help setModelLength and setBrandLength
	size_t setBrandLengthHelper_ModelLengthHelper(bool);

public:
	Dealer(); // initializes numeric fields to 0, name to the
	// empty string, and inventory to the null pointer
	Dealer(string); // initializes numeric fields to 0, name to
	// the parameter’s value, and inventory to the null pointer
	Dealer(const Dealer&); // the copy constructor
	~Dealer(); // the destructor
	size_t getBrandLength() const; // returns the value of the brandLength field
	size_t getModelLength() const; // returns the value of the modelLength field
	int getCarCount() const; // returns the value of the cars field
	void addCar(string, string); // Receives a car’s brand and model as
	// parameters. Creates a new Car object and adds it to inventory, increments
	// count, and calls the setModelLength, setBrandLength, and orderInventory
	void sellCar(string, string); // Receives a car’s brand and model as
	// parameters. Calls findCar to make sure there is a car with the same brand
	// and model in inventory, if not the method ends and an error message is
	// displayed. If found, removes the car from inventory, decrements count,
	// invokes the Car object’s destructor and calls the setModelLength and 
	// setBrandLength methods passing true as argument for the second parameter.
	void sellCar(string); // Receives a car’s serial number as parameter. Calls
	// findCar to make sure there is a car with the same serial number in
	// inventory, if not the method ends. If found, removes the car from
	// inventory, decrements count, invokes the Car object’s destructor and calls
	// the setModelLength and setBrandLength methods passing true as argument for
	// the second parameter.
	int findCar(string, string) const; // receives a car’s brand and model as
	// parameters and searches the inventory for a car with the given brand and
	// model names. If found, returns the index number of the first instance,
	// otherwise, returns -1
	int findCar(string) const; // receives a car’s serial number as parameter and
	// searches the inventory for the serial number. If found, returns the
	// index number, otherwise, returns -1
	void printBrandInventory() const; // prints the count of cars per brand.
	// First, it prints the phrase “Dealer [name] has [quantity] of cars in
	// inventory.” It then prints a table with the headers BRAND and COUNT,
	// using the value of brand length as the size of the BRAND column. If there
	// are no cars in inventory, the table (including the headers), is not
	// printed. Align all values to the left of the columns. Make sure to add an
	// empty line after the values are printed.
	void printModelInventory() const; // prints the count of cars per model.
	// First, it prints the phrase “Dealer [name] has [quantity] of cars in
	// inventory.” It then prints a table with the headers BRAND, MODEL, and
	// COUNT, using the value of the brand length field as the size of the BRAND
	// column, and the value of the model length field as the size of the MODEL
	// column. If there are no cars in inventory, the table (including the
	// headers) is not printed. Align all values to the left of the columns. Make
	// sure to add an empty line after the values are printed.
	void printDetailedInventory() const; // Prints a detailed inventory. First, it
	// prints the phrase “Dealer [name] has [quantity] of cars in inventory.”
	// It then prints a table with the headers BRAND, MODEL, and SERIAL NUMBER,
	// using the value of the brand length field as the size of the BRAND column,
	// and the value of the model length field as the size of the MODEL column.
	// If there are no cars in inventory the table (including the headers) is not
	// printed. Align all values to the left of the columns. Make sure to add an
	// empty line after the values are printed.


};


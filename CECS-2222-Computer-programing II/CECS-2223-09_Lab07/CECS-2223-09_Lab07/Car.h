/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 18, 2023
* Topic : Lab 7
* File name : Car.h
* This file declares a class named Car
* Name : Coral S.Schmidt Montilla, ID#148830
* Name: Aleysha M.Rivera Cores, ID#108408
*/
#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace::std;
class Car {
private:
	static int count;
	// count is the number of Car objects created
	string brand;
	string model;
	string serialNumber;
	string assignSerialNumber();
	// assignSerialNumber is a private method which considers
	// the brand, model, and count to create a 9-symbol string.
	// The format is first three letters of the brand, first three
	// letters of the model and the 3-digit count value
	// If a Toyota Yaris is the first car added, the serial number
	// would be TOYYAR001
	// If the brand and model fields have not been assigned a
	// value, the method DOES NOT create a serial number, and
	// returns the empty string
public:
	Car(); // Assigns the empty string to all three fields, and
	// increments count by 1
	Car(string brand, string model);
	// The parameterized constructor increments count by 1
	// assigns the brand and model to the fields, and calls
	// the assignSerialNumber method to create the serial number
	Car(const Car& other); //copy constructor
	~Car();
	// The destructor prints the message
	// “The car [brand] [model] with serial number [serial number]
	// has been sold”
	bool operator>(const Car& other) const; //operator>
	void setBrand(string newBrand); // sets brand value IFF not set before
	void setModel(string newModel); // sets model value IFF not set before
	string getBrand() const;// If no brand, return empty string
	string getModel() const; // If no model, return empty string
	string getSerialNumber() const;
	// Returns the empty string if serial number not set
	void printCar(int brandSize, int modelSize);
	// printCar prints the car’s details in a table-like manner
	// using the format car_brand, car_model, serial number.
	// It uses the parameters as the size of the brand and model
	// fields, and prints N/A if the fields have no value
};
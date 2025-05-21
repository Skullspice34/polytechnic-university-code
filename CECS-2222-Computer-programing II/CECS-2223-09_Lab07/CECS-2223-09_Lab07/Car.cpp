/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 18, 2023
* Topic: Lab 7
* File name: Car.cpp
* This file defines a class named Car
* Name: Coral S. Schmidt Montilla, ID#148830
* Name: Aleysha M. Rivera Cores, ID#108408
*/
#include "Car.h"
int Car::count = 0;
// a private method which considers the brand,
// model, and count to create a 9-symbol string. The format is first three
// letters of the brand, first three letters of the model and the 3-digit
// count value. Make sure that your code considers the filler when the length
// of the brand or model fields is less than 3. For example, if a Toyota
// Yaris is the first car added, the serial number would be TOYYAR001
// If the brand and model fields have not been assigned a value, the method
// DOES NOT create a serial number, and returns the empty string
string Car::assignSerialNumber() {
	if (brand.empty() || model.empty()) {
		return "";
	}
	string serial = brand.substr(0, 3) + model.substr(0, 3) + to_string(count);
	count++;
	return serial;
}
// Assigns the empty string to all three fields, and
// increments count by 1
Car::Car() {
	brand = "";
	model = "";
	serialNumber = assignSerialNumber();
}
// The parameterized constructor increments count by 1
// assigns the brand and model to the fields, and calls the
// assignSerialNumber method to create the serial number
Car::Car(string brand, string model) {
	this->brand = brand;
	this->model = model;
	serialNumber = assignSerialNumber();
}
//copy constructor
Car::Car(const Car& other) {
	brand = other.brand;
	model = other.model;
	serialNumber = other.serialNumber;
}
// The destructor prints the message “The car [brand] [model] with
// serial number [serial number] has been sold”
Car::~Car() {
	cout << "The car " << brand << " " << model << "with serial number " <<
		serialNumber << " has been sold" << endl;
}
// overloads the greater than operator to
// compare two cars and determine if the first is greater than the second
bool Car::operator>(const Car& other) const {
	// Compare cars based on brand, model, and serial number
	if (brand != other.brand) {
		return brand > other.brand;
	}
	else if (model != other.model) {
		return model > other.model;
	}
	else {
		return serialNumber > other.serialNumber;
	}
}
// sets brand value IFF not set before
void Car::setBrand(string newBrand) {
	if (brand.empty()) {
		brand = newBrand;
		serialNumber = assignSerialNumber();

	}
}
// sets model value IFF not set before
void Car::setModel(string newModel) {
	if (model.empty()) {
		model = newModel;
		serialNumber = assignSerialNumber();
	}
}
// If no brand, return empty string
string Car::getBrand() const {
	return brand;
}
// If no model, return empty string
string Car::getModel() const {
	return model;
}
// Returns the empty string if serial number not set
string Car::getSerialNumber() const {
	return serialNumber;
}
// printCar prints the car’s details in a table-like
// manner using the format car_brand, car_model, serial number. It uses the
// parameters as the size of the brand and model fields, and prints N/A if
// the fields have no value
void Car::printCar(int brandSize, int modelSize) {
	printf("%-*s | %-*s | %s\n", brandSize, (brand.empty() ? "N/A" :
		brand.c_str()),
		modelSize, (model.empty() ? "N/A" : model.c_str()),
		(serialNumber.empty() ? "N/A" : serialNumber.c_str()));
}
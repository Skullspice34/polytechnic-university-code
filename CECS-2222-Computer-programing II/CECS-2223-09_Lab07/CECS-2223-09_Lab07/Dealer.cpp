/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 18, 2023
* Topic: Lab 7
* File name: Dealer.cpp
* This file defines a class named Dealer
* Name: Coral S. Schmidt Montilla, ID#148830
* Name: Aleysha M. Rivera Cores, ID#108408
*/

#include <iostream>
#include "Dealer.h"
using namespace::std;
void Dealer::setBrandLength(string crBrand, bool checkInventory) {
	// Compare brand length and update brandLength accordingly
	size_t newLength = crBrand.length() + 2;
	if (newLength > brandLength) {
		brandLength = newLength;
	}
	if (checkInventory) {
		// Check the inventory for the largest brand length and update brandLength if
		needed
			size_t maxBrandLengthInInventory =
			setBrandLengthHelper_ModelLengthHelper(true);
		if (maxBrandLengthInInventory > brandLength) {
			brandLength = maxBrandLengthInInventory;
		}
	}
}
void Dealer::setModelLength(string crModel, bool checkInventory) {
	// Compare model length and update modelLength accordingly
	size_t newLength = crModel.length() + 2;
	if (newLength > modelLength) {
		modelLength = newLength;
	}
	if (checkInventory) {
		// Check the inventory for the largest model length and update modelLength if
		needed
			size_t maxModelLengthInInventory =
			setBrandLengthHelper_ModelLengthHelper(false);
		if (maxModelLengthInInventory > modelLength) {
			modelLength = maxModelLengthInInventory;
		}
	}
}
// Orders the cars in inventory alphabetically, first by brand
// name, then by model name, and then by serial number.
void Dealer::orderInventory() {
	// Bubble sort to sort the cars in the inventory
	for (int i = 0; i < cars - 1; i++) {
		for (int j = 0; j < cars - i - 1; j++) {
			// Compare cars based on brand, model, and serial number
			if (*inventory[j] > *inventory[j + 1]) {
				// Swap the cars if they are out of order
				Car* temp = inventory[j];
				inventory[j] = inventory[j + 1];
				inventory[j + 1] = temp;
			}
		}
	}
}
// Helper function to find the maximum brand length in the inventory
size_t Dealer::setBrandLengthHelper_ModelLengthHelper(bool bORm) {
	if (bORm) {
		// We needed to implement this function to help setBrandLength() find the
		maximum brand length in the inventory.
			// Iterate through the inventory and find the longest brand name.
			// Return the length of the longest brand name.
			size_t maxLength = 0;
		for (int i = 0; i < cars; i++) {
			size_t brandLength = inventory[i]->getBrand().length();
			if (brandLength > maxLength) {
				maxLength = brandLength;
			}
		} return maxLength;
	}
	else {
		// We needed to implement this function to help setModelLength() find the
		maximum model length in the inventory.
			// Iterate through the inventory and find the longest model name.
			// Return the length of the longest model name.
			size_t maxLength = 0;
		for (int i = 0; i < cars; i++) {
			size_t modelLength = inventory[i]->getModel().length();
			if (modelLength > maxLength) {
				maxLength = modelLength;
			}
		} return maxLength;
	}
}
// initializes numeric fields to 0, name to the
// empty string, and inventory to the null pointer
Dealer::Dealer() {
	cars = 0;
	name = "";
	brandLength = 0;
	modelLength = 0;
	inventory = nullptr;
}
// initializes numeric fields to 0, name to
// the parameter’s value, and inventory to the null pointer
Dealer::Dealer(string name) {
	cars = 0;
	this->name = name;
	brandLength = 0;
	modelLength = 0;
	inventory = nullptr;
}
// the copy constructor
Dealer::Dealer(const Dealer& other) {
	cars = other.cars;
	name = other.name;
	brandLength = other.brandLength;
	modelLength = other.modelLength;
	// Allocate memory for the inventory array and deep copy the cars
	inventory = new Car * [cars];
	for (int i = 0; i < cars; i++) {
		inventory[i] = new Car(*(other.inventory[i]));
	}
}
// the destructor
Dealer::~Dealer() {
	// Delete each Car object in the inventory
	for (int i = 0; i < cars; i++) {
		delete inventory[i];
	}
	// Delete the array of Car pointers
	delete[] inventory;
}
// returns the value of the brandLength field
size_t Dealer::getBrandLength() const {
	return brandLength;
}
// returns the value of the modelLength field
size_t Dealer::getModelLength() const
{
	return modelLength;
}
// returns the value of the cars field
int Dealer::getCarCount() const {
	return cars;
}
// Receives a car’s brand and model as
// parameters. Creates a new Car object and adds it to inventory, increments
// count, and calls the setModelLength, setBrandLength, and orderInventory
void Dealer::addCar(string crBrand, string crModel) {
	// Create a new Car object with the provided brand and model
	Car* newCar = new Car(crBrand, crModel);
	// Add the new car to the inventory
	Car** newInventory = new Car * [cars + 1];
	for (int i = 0; i < cars; i++) {
		newInventory[i] = inventory[i];
	}
	newInventory[cars] = newCar;
	// Increment the cars count
	cars++;
	// Delete the old inventory (pointers only, not the Car objects they point to)
	delete[] inventory;
	// Update it with the new inventory
	inventory = newInventory;
	// Call the setModelLength and setBrandLength methods
	setModelLength(crModel, true);
	setBrandLength(crBrand, true);
	// Call the orderInventory method after adding a new car
	orderInventory();
}
// Receives a car’s brand and model as parameters.
// Calls findCar to make sure there is a car with the same brand
// and model in inventory, if not the method ends and an error message is displayed.
// If found, removes the car from inventory, decrements count,
// invokes the Car object’s destructor and calls the setModelLength and
// setBrandLength methods passing true as argument for the second parameter.
void Dealer::sellCar(string crBrand, string crModel) {
	// Find the index of the car with the given brand and model
	int carIndex = findCar(crBrand, crModel);
	if (carIndex == -1) {
		// Car not found, display an error message and return
		cout << "Error: Car with brand " << crBrand << " and model " << crModel << "
			not found in inventory." << endl;
			return;
	}
	// Car found, remove it from inventory
	delete inventory[carIndex];
	// Decrement the cars count
	cars--;
	// Shift the remaining cars in the inventory
	for (int i = carIndex; i < cars; i++) {
		inventory[i] = inventory[i + 1];

/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: September 27, 2023
* Topic: Lab 6 - Composition and Dynamic Memory
* File name: Lab06.cpp
* This file implements a class named Catalog
* Complete the code as required.
* Name: Aleysha M. Rivera Cores, ID# 108408
* Name: Coral S. Schmidt Montilla, ID# 148830
*
* To test your code, add at least 4 courses to the catalog, and remove at least 2.
* Start by selecting the option to print the catalog, then proceed to add courses,
* and finally remove courses. You should print the course list after every add or
* remove action.
*/
// preprocessor directives
#include "Catalog.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Initialize static variables
int menu();
bool execute(Catalog&, const int);
void personalInfo();
string code, name;
int credits = 0;
int main() {
	Catalog poli;
	poli.setUniversityName("Polytechnic University of Puerto Rico");
	personalInfo();
	int option;
	do {
		option = menu();
	} while (execute(poli, option));
	system("pause"); // For Visual Studio use only!
	return 0;
}
int menu() {
	int option = 0;
	cout << "Menu:" << endl;
	cout << "1. View all courses in the catalog" << endl;
	cout << "2. Add a course to the catalog" << endl;
	cout << "3. Remove a course from the catalog" << endl;
	cout << "4. Exit the program" << endl;
	cout << "Enter your choice: ";
	cin >> option;
	return option;
}
bool execute(Catalog& catalog, const int option) {
	switch (option) {
	case 1:
		// View all courses in the catalog
		if (catalog.getCount() == 0) {
			cout << "No courses have been added to the catalog yet." << endl <<
				endl;
		}
		else {
			catalog.printCatalog();
		} break;
	case 2: {
		// Add a course to the catalog
		// Get input for code
		printf("Enter course code: ");
		cin.ignore();
		getline(cin, code);
		// Get input for name
		printf("Enter course name: ");
		getline(cin, name);
		// Get input for credits
		printf("Enter course credits: ");
		cin >> credits;
		cout << endl << endl;
		catalog.addCourse(code, name, credits);
		catalog.sortCatalog(); // Sort the catalog after adding
	} break;
	case 3: {
		// Remove a course from the catalog
		printf("Enter course code to remove: ");
		cin.ignore();
		getline(cin, code);
		int index = catalog.findCourse(code);
		if (index != -1) {
			catalog.deleteCourse(index);
			catalog.sortCatalog(); // Sort the catalog after removal
			catalog.printCatalog(); // Print the updated catalog
		}
		else {
			printf("Course not found in the catalog.\n\n");
		}
	} break;
	case 4: {
		return false; // Exit the program
	}
	default:
		printf("Invalid option. Please choose a valid option.\n\n");
		break;
	} return true;
}
void personalInfo() {
	printf("Program developed by Aleysha M. Rivera Cores and Coral S. Schmidt Montilla.\n\n");
}
//Edit the solution developed for Lab 5 as follows:
//Make sure that duplicate courses can't be added
//Overload the greater than operator for use in the sorting method
//Change the sorting algorithm to Selection Sort
//Use the overloaded assignment operator in the copy constructor
//Test your code as follows:
//Add at least 4 courses
//Remove at least 2 courses
//Try adding a duplicate course
//Try removing a non-existent course
//Call the print method when the array is empty
//Use the CECS-2223_Lab6t.docx document to complete your lab report.*/

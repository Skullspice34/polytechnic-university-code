/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 10, 2023
* Topic: Lab 6 - Composition and Dynamic Memory
* File name: Catalog.h
* This file declares a class named Catalog
* Complete the declaration as required.
* Name: Coral S. Schmidt Montilla, ID#148830
* Name: Aleysha M. Rivera Cores, ID#108408
*/
#pragma once
// preprocessor directives
#include "Course.h"
class Catalog {
private:
	string universityName; // the name of the university
	int courseCount; // the number of courses in the catalog
	Course** courses; // the array which contains the courses
	void sortCatalog(); // sorts the courses in the catalog in alphabetical order

	friend bool execute(Catalog&, const int);
public:
	Catalog(); // the default constructor
	Catalog(const Catalog&); // the copy constructor
	~Catalog(); // the destructor

	void setUniversityName(string);
	string getUniversityName() const;
	void addCourse(string, string, int); // adds a course to the catalog
	// The addCourse method calls the sortCatalog method after a course is added.
	int findCourse(const string) const; // method to find a course in the catalog
	void deleteCourse(int); // removes a course from the catalog
	void printCatalog() const; // prints the course list for the university
	// printCatalog prints the header CODE, NAME, CREDITS using the column widths
	// from the Course class
	void operator=(const Catalog&); // overload of the assignment operator
	int getCount() const;
};
/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 10, 2023
* Topic: Lab 6 - Composition and Dynamic Memory
* File name: Course.h
* This file declares a class named Course
* Complete the declaration as required.
* Name: Aleysha M. Rivera Cores, ID# 108408
* Name: Coral S. Schmidt Montilla, ID# 148830
*/
#pragma once
// preprocessor directives
#include <string>
#include <iostream>
using namespace std;
class Course {
private:
	string courseCode; // the course's code, e.g. CECS 2223
	string courseName; // the course's name, e.g. Computer Programming II Laboratory
	int credits; // the number of credits for the course
	
	static size_t codeSize; // the size of the courseCode field
	void setCodeSize(string, bool); // private method to set the value for codeSize
	static size_t nameSize; // the size of the courseName field
	void setNameSize(string, bool); // private method to set the value for nameSize
public:
	Course(); // the default constructor
	Course(string, string, int); // parameterized constructor
	// the parameterized constructor must validate the value for credits
	Course(const Course&); // the copy constructor
	~Course(); // the destructor

	void setCourseCode(string);
	void setCourseName(string);
	void setCourseCredits(int); // validates the parameter to be 0 or greater
	
	string getCourseCode() const;
	string getCourseName() const;
	
	int getCourseCredits() const;

	size_t getCodeSize() const;
	size_t getNameSize() const;
	
	void displayCourse() const; // prints the course data ready for a table
	// the order is course code, course name, credits, and the size of the
	// course and name fields is variable
};

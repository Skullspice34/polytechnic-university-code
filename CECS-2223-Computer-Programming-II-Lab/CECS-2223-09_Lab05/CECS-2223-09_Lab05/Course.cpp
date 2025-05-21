/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 10, 2023
* Topic: Lab 6 - Composition and Dynamic Memory
* File name: Course.cpp
* This file declares a class named Catalog
* Complete the declaration as required.
* Name: Aleysha M. Rivera Cores, ID# 108408
* Name: Coral S. Schmidt Montilla, ID# 148830
*/
#include "Course.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace::std;

size_t Course::codeSize = 5;
size_t Course::nameSize = 5;
//set codeSize based on courseCode

void Course::setCodeSize(string aCode, bool reduce) {
	if (reduce) {
		codeSize = aCode.size() + 1 > 5 ? aCode.size() + 1 : 5;
	}
	else {
		if (aCode.size() + 1 > getCodeSize())
			codeSize = aCode.size() + 1;
	}
}
//nameSize based on courseName
void Course::setNameSize(string aName, bool reduce) {
	if (reduce) {
		nameSize = aName.size() + 1 > 5 ? aName.size() + 1 : 5;
	}
	else {
		if (aName.size() + 1 > getNameSize())
			nameSize = aName.size() + 1;
	}
}
//d.constructor
Course::Course() {
	courseCode = "";
	courseName = "";
	credits = -1;
}
//p.constructor
Course::Course(string code, string name, int credits) {
	courseCode = code;
	setCodeSize(code, false);
	courseName = name;
	setNameSize(name, false);
	this->credits = credits > -1 ? credits : -1;
}
//copy constructor
Course::Course(const Course& aCourse) {
	courseCode = aCourse.getCourseCode();
	courseName = aCourse.getCourseName();
	credits = aCourse.getCourseCredits();
}
//destructor
Course::~Course() {
	cout << "\n\tThe Course with code " << getCourseCode() << " has been eliminated.\n\n";
}
//Setter for crouseCode
void Course::setCourseCode(string code) {
	courseCode = code;
}
//Setter for courseName
void Course::setCourseName(string name) {
	courseName = name;
}
//setter for courseCredits
void Course::setCourseCredits(int c) {
	if (c >= 0) {
		credits = c;
	}
	else {
		cout << "Invalid credits value. Setting to 0." << endl;
		credits = 0;
	}
}
//Getter for courseCode
string Course::getCourseCode() const {
	return courseCode;
}
//Getter for courseName
string Course::getCourseName() const {
	return courseName;
}
//Getter for courseCredits
int Course::getCourseCredits() const {
	return credits;
}
//Getter for codeSize
size_t Course::getCodeSize() const {
	return codeSize;
}
//Getter for nameSize
size_t Course::getNameSize() const {
	return nameSize;
}
//Display course info
void Course::displayCourse() const {
	cout << left << setw(getCodeSize()) << getCourseCode() << setw(getNameSize()) << getCourseName() << getCourseCredits() << endl;
}

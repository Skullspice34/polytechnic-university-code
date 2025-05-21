/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 30, 2023
* Topic: Lab 3
* File name: Grades.h
* Coral S. Schmidt, #148830
*/
#pragma once
#include <iostream>
using namespace::std;

class Grades {
private:
	static const int TESTS = 3;//Class constant
	int* scores;//Integer array


public:
	Grades();
	//Class Destructor
	~Grades();

	//Class Setters
	void setScores(int);

	//Class Getters
	int getScores(int) const;
	int getAverage() const;
	char getGrades(int) const;

	//Print
	void printGrades(int) const;

};
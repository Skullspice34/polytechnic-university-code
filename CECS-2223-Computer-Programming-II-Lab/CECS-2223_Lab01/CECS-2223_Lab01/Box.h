/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 15, 2023
* Topic: OOD Review
* File name: Box.h
* This file declares a class named Box
* Name: Coral S. Schmidt, ID#148830
*
* This file contains errors, find and correct them!
*/
#pragma once
// write the required preprocessor directive
#include <iostream>

// write the using directive
using namespace std;

class Box {
private:
	int height;
	int width;
	int length;
public:
	Box();
	void setHeight(int);
	void setWidth(int);
	void setLength(int);
	int getHeight()const; 
	int getWidth()const;
	int getLength()const;
	int getArea()const;
	int getVolume()const;
	void printBox() const;
};
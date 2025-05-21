
/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 23, 2023
* Topic: Parameterized Constructors and Class Variables
* File name: Box.cpp
* Name: Coral S. Schmidt, ID#148830
* This file defines the Box class
*/
// do we need any preprocessor directives?
#include "Box.h"

// initialize the class variable to 0
int Box::boxCount = 0;

// Define the default constructor; assign -1 to all fields
// and increments the value of the class variable
Box::Box()
{
	height = -1;
	width = -1;
	length = -1;

	boxCount++;
}

// The parameterized constructors assign the parameter's value 
// to the fields only if the value is valid. Use the ternary, or
// conditional, operator for the assignment operation, using 0
// as the value to be assigned when the condition is false. The  
// parameters represent the values for the fields in the height, 
// width, and length order. For example, the constructor with one
// parameter receives the value for height, and the one with two
// parameters receives the values for height and width. 
// Recall that all constructors must increment the class variable

Box::Box(int aHeight)
{
	height = (aHeight > 0) ? aHeight : 0;
	width = -1;
	length = -1;

	boxCount++;
}

Box::Box(int aHeight, int aWidth)
{
	height = (aHeight > 0) ? aHeight : 0;
	width = (aWidth > 0) ? aWidth : 0;
	length = -1;

	boxCount++;
}

Box::Box(int aHeight, int aWidth, int aLength)
{
	height = (aHeight > 0) ? aHeight : 0;
	width = (aWidth > 0) ? aWidth : 0;
	length = (aLength > 0) ? aLength : 0;

	boxCount++;
}
// The copy constructor assigns the attribute values of the parameter 
// to the new object and increments the value of the class variable.

Box::Box(const Box& aBox)
{
	height = aBox.getHeight();
	width = aBox.getWidth();
	length = aBox.getLength();

	boxCount++;
}

// The destructor does not include any code, it is defined
Box::~Box() {}

// The set methods DO NOT prompt the user for values or include
// any cout or printf statements. Make sure that the values 
// received as parameters are valid. Use the ternary, or
// conditional, operator for the assignment operation, using the
// current value of the field as the option when the condition 
// is false. The setter methods have no return value.
void Box::setHeight(int aHeight)
{
		height = (aHeight > 0) ? aHeight : height;
}

void Box::setWidth(int aWidth)
{
		width = (aWidth > 0) ? aWidth : width;
}

void Box::setLength(int aLength)
{
		length = (aLength > 0) ? aLength : length;
}



// define the get methods, they should all be constant
int Box::getHeight() const
{
	return height;
}

int Box::getWidth() const
{
	return width;
}

int Box::getLength() const
{
	return length;
}

int Box::getVolume() const
{
	return getHeight() * getWidth() * getLength();
}

int Box::getBoxCount() const
{
	return boxCount;
}

// The printBox method uses printf to output values formatted
// to be displayed in a table at 8 spaces per column aligned to
// the left of the column. The values to be displayed are: height, 
// width, length, and volume. All values must be printed in the
// same line. 
void Box::printBox() const
{
	printf("%-8i%-8d%-8i%-8d\n", getHeight(), getWidth(), getLength(), getVolume());
}
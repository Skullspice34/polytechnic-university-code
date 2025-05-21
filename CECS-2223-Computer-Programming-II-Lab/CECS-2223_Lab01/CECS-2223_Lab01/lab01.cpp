/*
* CECS 2223, Computer Programming II Lab
* Fall 2023, Sec. 09
* Date: August 15, 2023
* Topic: OOD Review
* File name: lab01.cpp
* Name: Coral S. Schmidt, ID#148830
* Complete the C++ code as required
*/
// do we need any preprocessor directives?
#include "Box.h"
//#include <iostream>

// the main function returns an integer value, should be 0

int main() {
	// declare a Box object, named box1
	Box box1;

	// assign a height of 20, width of 7 and a length of 3 to box1
	box1.setHeight(20);
	box1.setWidth(7);
	box1.setLength(3);

	// declare a Box object, named box2
	Box box2;

	// assign a height of 5, width of 4,  and length of 12 to box2
	box2.setHeight(5);
	box2.setWidth(4);
	box2.setLength(12);

	// declare a Box object, named box3
	Box box3;
	
	// assign a height of 10, width of 9, and length of 8 to box3
	box3.setHeight(10);
	box3.setWidth(9);
	box3.setLength(8);

	printf("The boxes created have the following dimensions:\n");

	// table headers
	printf("%s          %s           %s          %s            %s\n", "HEIGHT", "WIDTH", "LENGTH", "AREA", "VOLUME");

	// using printBox method, print the dimensions for each Box object
	box1.printBox();
	box2.printBox();
	box3.printBox();

	// write a statement which prints the phrase
	// "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]"
	// where the square brackets and the text within is substitued with
	// your personal information. Make sure to include a blank line 
	// before and after the phrase.
	printf("\nProgram developed by Coral S. Schmidt, ID#148830\n");

	system("pause"); // for Visual Studio use only
	return 0; // this statement MUST be included at the end of main
}
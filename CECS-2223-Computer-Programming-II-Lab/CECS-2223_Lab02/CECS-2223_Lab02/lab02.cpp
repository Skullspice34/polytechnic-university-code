/*
* CECS 2223, Computer Programming II Lab
* Fall 2023, Sec. 09
* Date: August 23, 2023
* Topic: Parameterized Constructors and Class Variables
* File name: lab02.cpp
* Name: Coral S. Schmidt, ID#148830
* Complete the C++ code as required
*/
// do we need any preprocessor directives?
#include "Box.h"

// the main function returns an integer value, should be 0
int main() {
	// declare a Box object, named box1, using the default constructor
	Box box1;

	// assign a height of 1, width of 10 and a length of -20 to box1
	box1.setHeight(1);
	box1.setWidth(10);
	box1.setLength(-20);

	// declare a Box object, named box2, using the 1-parameter constructor
	// with a value of 2 for the height.
	Box box2(2);

	// assign a width of -5 and length of 10 to box2
	box2.setWidth(-5);
	box2.setLength(10);

	// declare a Box object, named box3, using the 2-parameter constructor
	// with a value of 3 for the height and 4 for the width
	Box box3(3, 4);

	// assign a length of 12 to box3
	box3.setLength(12);

	// declare a Box object, named box4, using the 3-parameter constructor
	// with values of -4 for height, 4 for width, and 4 for length
	Box box4(-4, 4, 4);

	// get the value of boxCount to complete the printf statement
	printf("The %i boxes created have the following dimensions:\n", box1.getBoxCount());

	// table headers
	printf("%-8s%-8s%-8s%-8s%\n", "HEIGHT", "WIDTH", "LENGTH", "VOLUME");

	// using printBox method, print the dimensions for each Box object
	box1.printBox();
	box2.printBox();
	box3.printBox();
	box4.printBox();
	cout << endl;

	// assign a length of 20 to box1
	box1.setLength(20);

	// assign a width of 5 to box2
	box2.setWidth(5);

	// assign a length of -8 to box3
	box3.setLength(-8);

	// assign a height of 4 to box4
	box4.setHeight(4);

	// get the value of boxCount to complete the printf statement
	printf("The %i boxes created have the following dimensions:\n", box1.getBoxCount());

	// table headers
	printf("%-8s%-8s%-8s%-8s\n", "HEIGHT", "WIDTH", "LENGTH", "VOLUME");
	// using printBox method, print the dimensions for each Box object
	box1.printBox();
	box2.printBox();
	box3.printBox();
	box4.printBox();

	// write a statement which prints the phrase
	// "Program developed by Coral S. Schmidt Montilla, ID#148830"
	// where the square brackets and the text within is substitued with
	// your personal information. Make sure to include a blank line 
	// before and after the phrase.
	printf("\nProgram developed by Coral S. Schmidt, ID#148830\n");

	system("pause"); // for Visual Studio use only
	return 0; // this statement MUST be included at the end of main
}
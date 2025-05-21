/*
* CECS 2203, Computer Programming I Lab
* Spring 2023, Sec. 06
* Date: April 20, 2023
* Topic: Lab 5 - Arrays
* File name: lab05.cpp
*
* Complete the program by writing the correct C++ statements.
*
* Name: Coral S. Schmidt, YOUR ID# 148830
*/
// write the appropriate include statement
#include <iostream>

// write the appropriate using statement
using namespace std;

void personalInfo(); // method prototype

int main() {
	// Write the statement that declares a constant integer variable named CUANTOS
	// and initializes it to 5.
	const int CUANTOS = 5;

	// Write the statement that declares an integer array named numbers and 
	// initializes all elements to 0. Use the constant as the size of the array.
	int numbers[CUANTOS] = {};

	// Call the srand method using the return value of the time method as argument
	// to seed the pseudo random number generator. Remember to cast the return 
	// value of time to an unsigned int
	srand(static_cast <unsigned int> (time(NULL)));

	// Develop a for iteration control structure which assigns a random value to 
	// each element of the array. The values to be assigned must be in the range
	// of 1 to 100. Use the rand method and a modulus operation to obtain the value.
	for (int i = 0; i < CUANTOS; i++) {

		numbers[i] = (rand() % 100) + 1;

	}

	// Print the phrase "The [quantity] values in the numbers array are: ", where 
	// [quantity] is substituted for the size of the array. DO NOT include a 
	// new line after the phrase.
	printf("The %i values in the numbers array are: ", CUANTOS);

	// Develop a for iteration control structure which prints the contents of the array.
	// Print a comma after each value, except the last one which is followed by a 
	// period and the endl operator. For example, if the contents pf the array are 
	// 1, 2, 3, 4, and 5, this code will print the values as 1, 2, 3, 4, 5. 

	for (int i = 0; i < CUANTOS; i++) {

		printf("%i", numbers[i]);

		if (i != CUANTOS - 1)
			printf(", ");
		 
		else
			printf(". \n");

	}

	// Write the statement that calls the personalInfo method
	personalInfo();

	system("pause"); // for Visual Studio only
	return 0;
}

// Method definitions
// The personalInfo method has no parameters or return value. It prints the phrase
// "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]", where the square brackets 
// and the text within is substituted with your personal information. Make sure to add
// a blank line before and after the phrase is printed.

void personalInfo() {

	cout << endl;
	cout << "Program developed by CORAL S. SCHMIDT MONTILLLA, ID#148830";
	cout << endl;
	cout << endl;
}

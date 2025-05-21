
/*
* CECS 2223, Computer Programming II Lab
* Fall 2023, Sec. 09
* Date: September 13, 2023
* Topic: Lab 4 - Arrays of objects and operator overload
* File name: lab04.cpp
* Name: Coral S. Schmidt, ID#148830
* This file implements the Sodas class using by creating an array
* Complete the C++ code as required
* NOTE: To properly test your code, the array must include at least
* 5 Sodas objects.
*/
// do we need any preprocessor directives?
#include "Sodas.h"

void setSodas(Sodas[], const int);
void arrange(Sodas[], const int);
void displaySodas(const Sodas[], const int);

int main() {
	// declare an integer constant named HOWMANY and initialize it to 5
	const int HOWMANY = 5;

	// declare a Sodas array named mySodas using the constant as the size
	Sodas mySodas[HOWMANY];

	// call the setSodas method
	setSodas(mySodas, HOWMANY);

	// call the displaySodas method
	displaySodas(mySodas, HOWMANY);

	// call the arrange method
	arrange(mySodas, HOWMANY);

	// call the displaySodas method
	displaySodas(mySodas, HOWMANY);

	// write a statement which prints the phrase
	// "+++++ Program developed by [YOUR NAME], ID#[YOUR ID NUMBER] +++++"
	// where the square brackets and the text within is substituted with
	// your personal information. Make sure to include a blank line 
	// after the phrase.

	printf("+++++ Program developed by Coral S. Schmidt, ID#148830 +++++\n\n");

	system("pause"); // for Visual Studio use only
	return 0; // this statement MUST be included at the end of main
}

// The setSodas method implements a for iteration control structure to prompt the
// user for the name and price of the sodas in the array, and assigns such values
// to each object. Declare the local string variable named name and initialize it 
// to the empty string. Declare a local double variable named price and initialize it to 0.
// Prompt the user for the name using the phrase "Enter the name for soda #[number]: ", 
// where [number] is substituted for the array element. For example, for the first Sodas 
// object in the array, the console would display "Enter the name for soda #1: "
// Similarly, prompt the user for the price for the Sodas object using the phrase
// "Enter the price for [soda name]: " The square brackets must not be printed.
// Make sure to end each cycle with an empty line.
void setSodas(Sodas sodasArray[], const int size)
{
	for (int i = 0; i < size; i++) {
		string name;
		double price;

		printf("Enter the name for soda #%i: ", i + 1);
		cin >> name;

		printf("Enter the price for %s: ", name.c_str());
		cin >> price;

		sodasArray[i].setName(name);
		sodasArray[i].setPrice(price);

		printf("\n");
	}
}




// The arrange method receives a Sodas array and its size as parameters and has no return value.
// It implements a Bubble Sort algorithm to order the values in the array from lowest to highest.
// This method cannot change the values of any Sodas object.
void arrange(Sodas sodasArray[], const int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (sodasArray[j] > sodasArray[j + 1]) {
				Sodas temp = sodasArray[j];
				sodasArray[j] = sodasArray[j + 1];
				sodasArray[j + 1] = temp;
			}
		}
	}
}



// The displaySodas method receives a Sodas array and its size as parameters and has no return value.
// It prints the values of the Sodas object in a table-like manner. It prints a phrase, then the
// table headers, and finally the data.
void displaySodas(const Sodas sodasArray[], const int size)
{
	// Substitute [count] for the value of the number of Sodas objects created
	printf("The %d Sodas objects created have the following characteristics:\n\n", size);

	// table headers, each column is 12 spaces wide and aligned to the left
	printf("%-12s%-12s\n", "NAME", "PRICE");

	// Develop a for control structure to print the state of each Sodas object
	for (int i = 0; i < size; i++) {
		printf("%-12s$%.2f\n", sodasArray[i].getName().c_str(), sodasArray[i].getPrice());
	}

	// Make sure to add an empty line at the end of the code block
	printf("\n");
}


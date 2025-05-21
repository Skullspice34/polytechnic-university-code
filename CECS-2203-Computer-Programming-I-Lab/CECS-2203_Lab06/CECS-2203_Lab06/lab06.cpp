/*
* CECS 2203, Computer Programming I Lab
* Spring 2023, Sec. 06
* Date: April 27, 2023
* Topic: Lab 7 - Static variables and arrays as arguments to functions
* File name: lab06.cpp
*
* Complete the program by writing the correct C++ statements.
*
* Name: CORAL S. SCHMIDT MONTILLA, YOUR ID# 148830
*/
// write the appropriate include statement
#include <iostream>

// write the appropriate using statement
using namespace std;

// declare a method named assignRandom which receives an integer array and a
// constant integer value as parameters and has no return value.
void assignRandom(int[], const int);

// declare a method named computeMean which receives a constant integer array 
// and a constant integer value as parameters and returns a double value.
double computeMean(const int[], const int);

// declare a method named addValues which receives a constant integer array 
// and a constant integer value as parameters and returns an integer value.
int addValues(const int[], const int);

// declare a method named displayValues which receives a constant integer array 
// and a constant integer value as parameters and has no return value.
void displayValues(const int[], const int);

void personalInfo(); // method prototype

int main() {
	// Write the statement that declares the constant integer variables LENGTH and
	// CAPACITY and initializes the first one to 7 and the second one to 10. 
	const int LENGTH = 7;
	const int CAPACITY = 10;

	// Write the statement that declares an integer array named numbers and 
	// initializes all elements to 0. Use the constant LENGTH as the size of the array.
	int numbers[LENGTH] = { 0 };

	// Print the phrase "After initialization, the values in the numbers array are: ", do not include an endl
	printf("After initialization, the values in the numbers array are: ");

	// call the displayValues method to print the values in the numbers array
	displayValues(numbers, LENGTH);

	// call the assignRandom method to set new values for the numbers array 
	assignRandom(numbers, LENGTH);

	// Print the phrase "After assignRandom, the values in the numbers array are: ", do not include an endl
	printf("After assignRandom, the values in the numbers array are: ");

	// call the displayValues method to print the values in the numbers array
	displayValues(numbers, LENGTH);

	// Print the phrase 
	// "The sum of the values in the numbers array is [sum], and their average is [average]"
	// Substitute [sum} for the return value of the addValues method and [average] for the
	// return value of the computeMean function. Make sure to add a blank line after the phrase.
	printf("The sum of the values in the numbers array is %i, and their average is %f\n", addValues(numbers, LENGTH), computeMean(numbers, LENGTH));

	// Write the statement that declares an integer array named digits and 
	// initializes all elements to 0. Use the constant CAPACITY as the size of the array.
	int digits[CAPACITY] = { 0 };

	// Print the phrase "After initialization, the values in the digits array are: ", do not include an endl
	printf("After initialization, the values in the digits array are: ");

	// call the displayValues method to print the values in the digits array
	displayValues(digits, CAPACITY);

	// call the assignRandom method to set new values for the digits array 
	assignRandom(digits, CAPACITY);

	// Print the phrase "After assignRandom, the values in the digits array are: ", do not include an endl
	printf("After assignRandom, the values in the digits array are: ");

	// call the displayValues method to print the values in the digits array
	displayValues(digits, CAPACITY);

	// Print the phrase 
	// "The sum of the values in the digits array is [sum], and their average is [average]"
	// Substitute [sum} for the return value of the addValues method and [average] for the
	// return value of the computeMean function. 
	printf("The sum of the values in the numbers array is %i, and their average is %f\n", addValues(digits, CAPACITY), computeMean(digits, CAPACITY));

	// Write the statement that calls the personalInfo method
	personalInfo();

	system("pause"); // for Visual Studio only
	return 0;
}
// Method definitions

// The assignRandom which receives an integer array and its size as parameters 
// and has no return value. It assigns a random value in the range of 2 to 99 to
// every element of the array. Declare a static unsigned integer variable named
// spark and initialize it to 0. Call the srand method using the value of spark as
// argument to seed the pseudo random number generator. Develop a for iteration
// control structure which assigns a random value to each element of the array.
// Increment the value of spark after the values have been assigned.
void assignRandom(int arr[], const int size) {

	static unsigned int spark = 0;

	srand(spark);
	
	for (int i = 0; i < size; i++) {

		arr[i] = rand() % 98 + 2;

	}

	spark++;

}

// The computeMean method receives an integer array and its size as parameters
// and returns a double value. It computes the average of the values in the array
// by returning the result of the return value of addValues divided by the size.
// Make sure that the value returned is a double!
// DO NOT declare variables in this method. 
double computeMean(const int array[], const int size) {

	return static_cast<double>(addValues(array, size)) / size;

}


// The addValues method receives an integer array and its size as parameters
// and returns an integer value. It computes the sum of the values in the array.
// Declare an integer variable named suma and initialize it to 0. Develop a for
// iteration control structure that adds all the values and stores the intermediate
// sum in suma. The method returns the value of suma.
int addValues(const int arrAy[], const int tamano) {

	int suma = 0;

	for (int i = 0; i < tamano; i++) {
		suma += arrAy[i];
	}

	return suma;

}

// The displayValues method receives an integer array and its size as parameters
// and has no return value. It prints the values in the array separated by colons, except
// for the last one which is followed by a period. For example, if the contents of the 
// array are 4, 5, and 6, this method would print "4 : 5 : 6."
// Make sure to add a blank line after the values are printed.
void displayValues(const int arr[], const int misurare) {

	for (int i = 0; i < misurare; i++) {

		printf("%i", arr[i]);

		if (i != misurare - 1)
			printf(" : ");

		else
			printf(". \n");
	}


}


// The personalInfo method has no parameters or return value. It prints the phrase
// "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]", where the square brackets 
// and the text within is substituted with your personal information. Make sure to add
// a blank line before and after the phrase is printed.
void personalInfo() {

	printf("\nProgram developed by CORAL S. SCHMIDT MONTILLLA, ID#148830\n\n");

}

/*
* CECS 2023, Computer Programming I Laboratory
* Spring 2023, Sec. 06
* Date: March 14, 2023
* Topic: Review
* File name: march14.cpp
*/
#include <iostream>
using namespace std;

int main() {
	
	//declare an integer variable named number and initialized to 10
	int number = 10;
	cout << "The value of number is " << number << "\n\n";
	//cout << endl;
	do {

		//promt the user to enter a whole number
		cout << "Enter a whole number: ";
		//store the imput value in number 
		cin >> number;
		//print the vaue of number
		cout << "The value of number is " << number << endl;
		cout << number << " is an ";

		if (number % 2 == 0)
			cout << "even";
		else
			cout << "odd";
		cout << "number. \n\n";
		cout << "Enter 0 to end or any other number to continue: ";
		cin >> number;
		cout << endl;

	} while (number != 0);

	system("pause"); //For Visual Studio only!
	return 0;
}
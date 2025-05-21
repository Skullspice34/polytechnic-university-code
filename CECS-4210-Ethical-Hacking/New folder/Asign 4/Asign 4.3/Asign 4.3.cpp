// Asign 4.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//declare variables
	double squareFeet;
	double yourAcres;


	std::cout << "Enter how manny square feet does your land have: "; //asks square feet of land

	//places numbers in a variable
	std::cin >> squareFeet;

	if (squareFeet > 0) {
		yourAcres = squareFeet / 43560; //sets up yourAcres
		//prints yourAcres
		std::cout << "The average of the 3 numbers is: "; 
		std::cout << yourAcres;
	}
	else { //if number isnt a positive
		std::cout << "Error! Your number isnt positive";
	}

	return 0;

}


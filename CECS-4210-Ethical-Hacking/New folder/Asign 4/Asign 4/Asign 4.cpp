// Asign 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

	//declare variables
	double numberOne;
	double numberTwo;
	double numberThree;
	double average;



	std::cout << "Enter 3 numbers between -10 & 10:\n"; //asks for three numbers between -10 & 10

	//places the three numbers in 3 seperate variables
	std::cin >> numberOne;
	std::cin >> numberTwo;
	std::cin >> numberThree;

	if (numberOne < 10 && numberTwo < 10 && numberThree < 10) { //checks if numers larger or equal to 10

		if (numberOne > -10 && numberTwo > -10 && numberThree > -10) { //checks if numers smaller or equal to -10
			average = ((numberOne + numberTwo + numberThree) / 3); //sets up the average
			//prints the average of the 3 numbers
			std::cout << "The average of the 3 numbers is: ", average;
			std::cout << average;
		}
		else { //if number smaller than -10 print an error
			std::cout << "Error! Some or all your numbers are equal or lower than -10";
		}
	}
	else { //if number larger than 10 print an error
		std::cout << "Error! Some or all your numbers are equal or higher than 10";
	}

	return 0;
}


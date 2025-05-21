// Asign 4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//declare variables
	double milesDriven;
	double gallonsGasUsed;
	double mPG;




	std::cout << "Enter miles driven: "; //asks for miles driven
	std::cin >> milesDriven;//puts number in variable

	std::cout << "Enter gallons of gas used :";//asks for gallons of gas used
	std::cin >> gallonsGasUsed;//puts number in variable

	if (milesDriven > 0 && gallonsGasUsed > 0) {
		mPG = milesDriven / gallonsGasUsed; //sets up the mPG
		//prints the MPG
		std::cout << "The average of the 3 numbers is: ";
		std::cout << mPG;
	}
	else { //if number is not positive
		std::cout << "Error! Some or all your numbers are not positive";
	}

	return 0;
}


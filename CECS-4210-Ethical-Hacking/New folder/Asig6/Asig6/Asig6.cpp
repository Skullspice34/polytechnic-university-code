// Asig6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//declarando variables
	double daysW;
	double sday = 0;
	double money = 0;
	double total = 0;
	
	
	//title of program
	std::cout << "----Program pennies without do----\n";
	std::cout << "---------by Coral Schmidt--------\n";

	//ask and saves how many days worked
	std::cout << "How many days did you work? ";
	std::cin >> daysW;

	//counts how much money you made in those amount of days
	if (daysW > 1){
		while (sday < daysW) {
			money = money + 0.01;
			sday = sday + 1;
			std::cout << "Day ";
			std::cout << sday;
			std::cout << ": $ ";
			std::cout << money;
			std::cout << "\n";
			total = total + money;


		}
		//prints the total earned
		std::cout << "Total earned was $ ";
		std::cout << total;
	}

}

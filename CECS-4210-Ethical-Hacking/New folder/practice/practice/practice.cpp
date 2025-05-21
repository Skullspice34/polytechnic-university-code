// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//Variables
	char input;
	
	//menu loop
	for (;;) {

		//prints menu
		std::cout << "a)	You choose option 'A'.\n";
		std::cout << "b)	You choose option 'B'.\n";
		std::cout << "c)	You choose option 'C'.\n";
		std::cout << "d)	Exit/n";
		std::cout << "Chose an option: ";
		
		//asks for option
		std::cin >> input;

		switch (input) {
		//print chosen option
		case 'a': 
			std::cout << "You type 'A'\n";
			break;
		//print chosen option
		case 'A':
			std::cout << "You type 'A'\n";
			break;
		//print chosen option
		case 'b':
			std::cout << "You type 'B'\n";
			break;
		//print chosen option
		case 'B':
			std::cout << "You type 'B'\n";
			break;
		//print chosen option
		case 'c':
			std::cout << "You type 'C'\n";
			break;
		//print chosen option
		case 'C':
			std::cout << "You type 'C'\n";
			break;
		// quits program
		case 'd':
			return 0;
		// quits program
		case 'D':
			return 0;
		//if enterd wrong choice print wrong choice
		default: 
			std::cout << "Wrong choice tried again!\n";

		}


	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

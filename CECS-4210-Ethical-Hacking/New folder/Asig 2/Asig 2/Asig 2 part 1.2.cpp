#include <iostream>


int main()
{
	//declare variables
	float a;
	float b;
	float sum;

	std::cout << "Addition \n";
	std::cout << "Please enter first number: ";
	std::cin >> a;//ask for first number
	std::cout << "\nPlease enter second number: ";
	std::cin >> b;//ask for second number

	sum = a + b;// adds both numbers together

	std::cout << "\nThis is the sum of both numbers: ";
	std::cout << sum;//prints the sum of both numbers
	
	return 0;




}

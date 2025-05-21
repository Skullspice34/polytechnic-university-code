#include <iostream>


int main()
{
	//declare variables
	double totalb = 52;
	double sst = totalb * 0.1; //gets first tax
	double cst = totalb * 0.015;//gets second tax
	double totalst = sst + cst; //gets total taxes

	std::cout << "Sales Tax \n";
	std::cout << "Your total amount is:";
	std::cout << totalb;
	std::cout << "\nYour state sale tax is: ";
	std::cout << sst;//prints state tax
	std::cout << "\n\nYour country sale tax is: ";
	std::cout << cst;//print country tax
	std::cout << "\n\nYour total sum of taxes is: ";
	std::cout << totalst; //prints total taxes

	return 0;








}

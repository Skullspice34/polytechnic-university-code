#include <iostream>


int main()
{
	//declare variables
	double item1 = 24.95;
	double item2 = 14.95;
	double item3 = 6.95;
	double item4 = 7.95;
	double item5 = 5.95;
	double totals = item1 + item2 + item3 + item4 + item5; //adds up all items prices
	double salet = totals * 0.06;//gets sale tax for the totals
	double fullt = totals + salet;//gets full total with taxes included


	std::cout << "Total Purchase \n";
	std::cout << "\nItem 1: ";
	std::cout << item1; //prints item1
	std::cout << "\nItem 2: ";
	std::cout << item2;//prints item2
	std::cout << "\nItem 3: ";
	std::cout << item3;//prints item3
	std::cout << "\nItem 4: ";
	std::cout << item4;//prints item4
	std::cout << "\nItem 5: ";
	std::cout << item5;//prints item5
	std::cout << "\n\nYour total is: ";
	std::cout << totals;//prints total sale price sum of all items
	std::cout << "\n\nYour sale tax is: ";
	std::cout << salet;//print sale tax
	std::cout << "\n\nYour full total is: ";
	std::cout << fullt; //prints total amount needed to pay

	return 0;








}

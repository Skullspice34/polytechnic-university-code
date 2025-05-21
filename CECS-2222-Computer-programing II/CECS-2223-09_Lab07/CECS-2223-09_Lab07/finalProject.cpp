/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: October 18, 2023
* Topic: Lab 7
* File name: finalProject.cpp
* Name: Aleysha M. Rivera Cores, ID# 108408
* Name: Coral S. Schmidt Montilla, ID# 148830
*
*/

#include "Dealer.h"
#include <iostream>
#include <string>

using namespace std;

//uses a series of methods to present the human user with
//an interface to add cars to inventory, sell cars from inventory, and print all versions of the
//inventory
int main() {
    Dealer poli("Poli Auto Sales");
    while (execute(menu(), poli));
    return 0;
}

//The menu method returns an integer value which should be used by the execute method to
//implement the selected option
int menu() {
    int choice;
    
    printf("Select one of the following:\n");
    printf("1. Add a car to inventory\n");
    printf("2. Sell a car from inventory\n");
    printf("3. Find a car by brand and model\n");
    printf("4. Print the brand inventory\n");
    printf("5. Print the model inventory\n");
    printf("6. Print the detailed inventory\n");
    printf("7. Exit the application\n");
    printf("Your selection: ");
    
    cin >> choice;
    return choice;
}

//The execute method receives an integer and the reference to a Dealer object as parameters
//and performs the requested action by calling upon methods of the Dealer object.If the value of the
//parameter is incorrect the execute method prints an error message.The execute method returns
//true unless the selected option is number 7. If the option selected is 7, the method prints the phrase
//“Program developed by[name of student 1] and [name of student 2].” Make sure to
//add an empty line after the phrase is printed.
bool execute(int choice, Dealer& dealer) {
    switch (choice) {
    case 1: {
        string brand, model;
        printf("Enter the car's brand: ");
        cin >> brand;
        printf("Enter the car's model: ");
        cin >> model;
        dealer.addCar(brand, model);
        break;
    }
    case 2: {
        printf("Select one of the following:\n");
        printf("1. Sell by brand and model\n");
        printf("2. Sell by serial number\n");
        int sellChoice;
        cin >> sellChoice;
        if (sellChoice == 1) {
            string brand, model;
            printf("Enter the car's brand: ");
            cin >> brand;
            printf("Enter the car's model: ");
            cin >> model;
            dealer.sellCar(brand, model);
        }
        else if (sellChoice == 2) {
            string serialNumber;
            printf("Enter the car's serial number: ");
            cin >> serialNumber;
            dealer.sellCar(serialNumber);
        }
        else {
            printf("Invalid option. Please try again.\n");
        }
        break;
    }
    case 3: {
        string brand, model;
        printf("Enter the car's brand: ");
        cin >> brand;
        printf("Enter the car's model: ");
        cin >> model;
        int index = dealer.findCar(brand, model);
        if (index != -1) {
            printf("Car found at index: %d\n", index);
        }
        else {
            printf("Car not found in inventory.\n");
        }
        break;
    }
    case 4:
        dealer.printBrandInventory();
        break;
    case 5:
        dealer.printModelInventory();
        break;
    case 6:
        dealer.printDetailedInventory();
        break;
    case 7:
        printf("Program developed by Coral S. Schmidt Montilla and Aleysha M. Rivera Cores.\n\n");
        return false;
    default:
        printf("Invalid option. Please try again.\n");
    }
    return true;
}

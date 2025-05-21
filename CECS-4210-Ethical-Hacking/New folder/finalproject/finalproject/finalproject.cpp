// Geometry calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>

void case1(double x) {
    //prints and calculates F(x) = x^2 + 5x + 6
    if (2 < x && x <= 8)
    {
        std::cout << "\nThe solution of " << "f(x) = (" << x << ")^2 + 5(" << x << ") + 6 is: ";
        
        double firstop = pow(x, 2) + 5 * x + 6;
        
        std::cout << firstop << "\n\n";
    }
    //if it isn't  2 < x <= 8 sends error
    else
    {
        std::cout << "Error! Invalid number.\n\n";
    }
}

void case2(double x, double y) {
    //prints and calculates  G(x, y) = xy – 4x(y – 5)

    if (2 < x && x <= 8 && 9 > y && y >= 2)
    {
        std::cout << "\nThe solution is: ";
        
        double secondOp = x * y - 4 * x * (y - 5);
        
        std::cout << secondOp << "\n\n";
       
    }
    //if it isn't  2 < x <= 8 and  9 > y >= 2 sends error
    else
    {
        std::cout << "Error! Invalid number. \n\n";
    }
}

void case3() {
    //value of variables
    double a = 1;
    double b = 5;
    double c = 6;
    double discriminant = pow(b, 2) - 4 * a * c;
    //gets roots of equation if not a negative
    if (discriminant >= 0) {

        double thirdOp1 = (-b + sqrt(discriminant) / 2 * a);
        double thirdOp2 = (-b - sqrt(discriminant) / 2 * a);

        std::cout << "The solution's to the equation is: " << thirdOp1 << ", " << thirdOp2 << "\n\n";

    }
    else {
        std::cout << "Error!!!Discriminant is negative.";
    }
}

void case4(int n) {
    //prints hello world n times
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            std::cout << " Hello World \n";
        }
    }
    else {
        std::cout << "Error! Number is less than 0.\n\n";
    }
}

void case5(int n) {
    //gets the factorial of n
    if (n > 2) {
        long fifthOp = 1.0;

        for (int i = 1; i <= n; i++) {
            fifthOp *= i;
        }
        std::cout << "Factorial of" << n << " = " << fifthOp;

    }
    else {
        std::cout << "Error!! Number is smaller or equal to 2";
    }
}

int main()
{
    //Variables
    int num;
    double x;
    double y;
    int n;
    std:: string exitop;


    do{
        //Prints Menu
        std::cout << "Menu\n";
        std::cout << "1. F(x) = x^2 + 5x + 6\n";
        std::cout << "2. G (x, y) = xy - 4x (y - 5)\n";
        std::cout << "3. Calculate the roots for x^2 + 5x + 6\n";
        std::cout << "4. Repeat the phrase Hello World n times.\n";
        std::cout << "6. Calculate the factorial of a number.\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        //Takes in the choice
        std::cin >> num;

        //menu program   
        switch (num)
        {

        //F(x) = x^2 + 5x + 6
        case 1:
            system("CLS");
            //asks for x
            std::cout << "\nType a number from 3 to 8 : ";
            std::cin >> x;

            case1(x);//calls function
            break;

        //G(x, y) = xy – 4x(y – 5)
        case 2:
            system("CLS");
            //asks for x and y
            std::cout << "\nType a number from 3 to 8 : ";
            std::cin >> x;
            std::cout << "\nType a number from 2 to 8 : ";
            std::cin >> y;
            
            case2(x, y);

            break;

        // Calculate the roots for x^2 + 5x + 6
        case 3:
            system("CLS");

            case3();

            break;

        // Repeat the phrase “Hello World” – n times.
        case 4:
            //Ask for n and repeat the phrase.
            system("CLS");
            std::cout << "Enter a number:";
            std::cin >> n;
            
            case4(n);

            break;

        // Calculate the factorial of a number.
        case 5:
            system("CLS");

            std::cout << "Enter a number greater than 2";
            std::cin >> n;

            case5(n);
            
            break;


        // Exit
        case 6:
            system("CLS");

            //asks if you are sure you wanna quit
            std::cout << "Are you sure (Y/N)";
            std::cin >> exitop;

            if (exitop == "y" || exitop == "yes" || exitop == "Yes" || exitop == "Y" || exitop == "yEs" || exitop == "YEs" || exitop == "YES" || exitop == "YeS" || exitop == "yeS") {
                return 0;
            }
            else if (exitop == "N" || exitop == "n" || exitop == "No" || exitop == "NO" || exitop == "no" || exitop == "nO") {
                break;
            }
            else {
                std::cout << "Error! isnt a (Y/N) anwer.";
                break;
            }

            


        default:
            std::cout << "\nINVALID INPUT\n\n";
            break;
        }

     

 


    } 
    while (true);

    return 0;


}

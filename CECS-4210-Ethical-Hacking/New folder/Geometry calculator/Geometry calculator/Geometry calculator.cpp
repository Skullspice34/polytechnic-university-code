// Geometry calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //Variables
    int num;
    double pi = 3.14159;
    double radius = 0;
    double length = 0;
    double height = 0;
    double width = 0;
    double base = 0;
    double areaCircle;
    double areaRectangle;
    double areaTriangle;


    for (;;) {
        //Prints Menu
        std::cout << "Geometry Calculator\n";
        std::cout << "1. Calculate the Area of Circle\n";
        std::cout << "2. Calculate the Area of Rectangle\n";
        std::cout << "3. Calculate the Area of Triangle\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice (1-4): ";
        //Takes in the choice
        std::cin >> num;
        
        //menu program   
        switch (num)
        {
            //Area of Circle
            case 1:
                //asks for radius
                std::cout << "\nWhats the radius of the circle: ";
                std::cin >> radius;

                //prints and calculates the area of circle
                if (radius > 0)
                {
                    std::cout << "\nThe area of the circle is: ";
                    areaCircle = pi * pow(radius, 2);
                    std::cout << areaCircle;
                    std::cout << "\n\n";
                }
                //if it isn't positive sends error
                else
                {
                    std::cout << "Error! Number isnt a positive.\n\n";
                }
                break;
                    
            //Area of Rectangle
            case 2:
                //asks for length & width
                std::cout << "\nWhats the length of the rectangle: ";
                std::cin >> length;
                std::cout << "\nWhats the width of the rectangle: ";
                std::cin >> width;
                std::cout << "\n";

                //prints and calculates the area of the rectangle
                if (length > 0 && width > 0)
                {
                    std::cout << "The area of the rectangle is: ";
                    areaRectangle = length * width;
                    std::cout << areaRectangle;
                    std::cout << "\n\n";
                }
                //if it isn't positive sends error
                else
                {
                    std::cout << "Error! Number isnt a positive.\n\n";
                }
                break;

            case 3:
                //asks for base & height
                std::cout << "\nWhats the base of the triangle: ";
                std::cin >> base;
                std::cout << "\nWhats the height of the triangle: ";
                std::cin >> height;
                std::cout << "\n";

                //prints and calculates the area of the triangle
                if (base > 0 && height > 0)
                {
                    std::cout << "The area of the Triangle is: ";
                    areaTriangle = base * height * 0.5;
                    std::cout << areaTriangle;
                    std::cout << "\n\n";
                }
                //if it isn't positive sends error
                else
                {
                    std::cout << "Error! Number isnt a positive.\n\n";
                }
                break;
            //Quit
            case 4:
                return 0;
                

            default:
                std::cout << "\nINVALID INPUT\n\n";
            
        }


    }
    return 0;
    

}

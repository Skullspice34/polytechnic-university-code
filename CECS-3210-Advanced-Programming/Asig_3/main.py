"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: main.py
This file demonstrates polymorphism with geometric shapes:
    It creates instances of `Cylinder`, prompts for information, 
    and prints out the details of each cylinder.
"""

from Cylinder import Cylinder

def main():
    shapes = []

    try:
        cylinder = Cylinder()
        cylinder.ask()
        shapes.append(cylinder)

    except ValueError:
        print("Invalid input. Please enter valid numeric values.")
    
    if shapes:
        print("\nShape Information:")

        for shape in shapes:
            print(shape)
            
    else:
        print("\nNo shape information entered.")

if __name__ == "__main__":
    main()

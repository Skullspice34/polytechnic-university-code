"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: main.py

This application calculates the equation of a line using point-slope:
    In this file main calls the class EqOfLine to calculate the equation 
    of a line using the users input of x1, x2, y1 and y2.
"""
from EqOfLine import EqOfLine

def main():
    """Asks for the users input of each point"""
    print ("Welcome!\n\nEnter first point:")
    x1 = int (input("x = "))
    y1 = int (input("y = "))
    print ("\nEnter secont point:")
    x2 = int (input("x = "))
    y2 = int (input("y = "))

    """Prints out the solution of the equation of a line"""
    eq_of_line = EqOfLine(x1, y1, x2, y2)
    eq_of_line.print_answer()


main()


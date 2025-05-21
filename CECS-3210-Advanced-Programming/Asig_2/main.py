"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: main.py

This application performs arithmetic operations with Rational numbers:
    In this file, main interacts with the Rational class to perform arithmetic operations
    and display the results.
"""

from Rational import Rational

def get_rational_input(prompt):
    # Function to get user input for rational numbers.
    while True:
        try:
            numerator, denominator = map(int, input(prompt).split('/'))
            return Rational(numerator, denominator)
        except ValueError:
            print("Invalid input. Please enter in the format numerator/denominator.")

def main():

    r1 = get_rational_input("Enter the first rational number (a/b): ")
    r2 = get_rational_input("Enter the second rational number (a/b): ")

    operation_input = input("Choose an operation (+, -, *, /): ")
    
    result = None
    if operation_input == '+':
        result = r1.addition(r2)

    elif operation_input == '-':
        result = r1.subtraction(r2)

    elif operation_input == '*':
        result = r1.multiplication(r2)

    elif operation_input == '/':
        if r2.numerator == 0:
            print("Error: Division by zero is not allowed.")
            return
        result = r1.division(r2)

    else:
        print("Error: Invalid operation.")
        return

    print(f"Result: {result} or {result.rational_to_float(2)} in floating-point.")

if __name__ == "__main__":
    main()

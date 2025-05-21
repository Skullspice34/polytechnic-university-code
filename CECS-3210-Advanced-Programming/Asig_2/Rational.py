"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: Rational.py

This application provides a class called Rational for performing arithmetic with fractions:
    The class Rational handles addition, subtraction, multiplication, and division of
    rational numbers. It also reduces fractions to their simplest form and supports 
    conversion to floating-point format.
"""

class Rational:
    def __init__(self, numerator=0, denominator=1):

        self.set_fraction(numerator, denominator)

    def set_fraction(self, numerator, denominator):

        if denominator == 0:
            print("Error: Denominator cannot be zero.")
            return
        
        self.numerator = numerator
        self.denominator = denominator
        self.simplest_form()

    def simplest_form(self):

        g = self.greatest_common_denominator(self.numerator, self.denominator)
        self.numerator //= g
        self.denominator //= g

    @staticmethod
    def greatest_common_denominator(a, b):
        
        while b != 0:
            a, b = b, a % b
        return a

    def __str__(self):
        
        return f"{self.numerator}/{self.denominator}"

    def rational_to_float(self, precision=None):

        if self.denominator == 0:
            return "Undefined"
        
        result = self.numerator / self.denominator

        if precision is not None:
            return f"{result:.{precision}f}"
        
        return str(result)

    def addition(self, other):

        new_numerator = self.numerator * other.denominator + other.numerator * self.denominator
        new_denominator = self.denominator * other.denominator

        return Rational(new_numerator, new_denominator)

    def subtraction(self, other):

        new_numerator = self.numerator * other.denominator - other.numerator * self.denominator
        new_denominator = self.denominator * other.denominator

        return Rational(new_numerator, new_denominator)

    def multiplication(self, other):

        new_numerator = self.numerator * other.numerator
        new_denominator = self.denominator * other.denominator
        
        return Rational(new_numerator, new_denominator)

    def division(self, other):

        if other.numerator == 0:
            print("Error: Attempt to divide by a fraction with a numerator of zero.")
            return
        
        new_numerator = self.numerator * other.denominator
        new_denominator = self.denominator * other.numerator
        
        return Rational(new_numerator, new_denominator)

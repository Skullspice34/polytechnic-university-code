"""
Author: Coral S. Schmidt Montilla
Student Number: 148830

This module provides a class called Raster for performing arithmetic with fractions.
The class Raster handles addition, subtraction, multiplication, and division of rational numbers.
It also reduces fractions to their simplest form and supports conversion to floating-point format.
"""


class Rational:
    def __init__(self, numerator=0, denominator=1):
        self.__denominator = None
        self.__numerator = None
        self.set_fraction(numerator, denominator)

    def set_fraction(self, numerator, denominator):
        if denominator == 0:
            raise ValueError("Denominator cannot be zero.")
        self.__numerator = numerator
        self.__denominator = denominator
        self.simplest_form()

    def simplest_form(self):
        gcd = self.greatest_common_denominator(self.__numerator, self.__denominator)
        self.__numerator //= gcd
        self.__denominator //= gcd

    def to_mixed_fraction(self):
        whole = self.__numerator // self.__denominator
        remainder = self.__numerator % self.__denominator
        if remainder == 0:
            return str(whole)
        elif whole == 0:
            return f"{remainder}/{self.__denominator}"
        else:
            return f"{whole} {abs(remainder)}/{self.__denominator}"

    @staticmethod
    def greatest_common_denominator(a, b):
        while b != 0:
            a, b = b, a % b
        return a

    def __str__(self):
        return f"{self.__numerator}/{self.__denominator}"

    def to_float(self, precision=None):
        if self.__denominator == 0:
            return "Undefined"
        result = self.__numerator / self.__denominator
        if precision is not None:
            return f"{result:.{precision}f}"
        return str(result)

    def add(self, other):
        new_numerator = self.__numerator * other.__denominator + other.__numerator * self.__denominator
        new_denominator = self.__denominator * other.__denominator
        return Rational(new_numerator, new_denominator)

    def subtract(self, other):
        new_numerator = self.__numerator * other.__denominator - other.__numerator * self.__denominator
        new_denominator = self.__denominator * other.__denominator
        return Rational(new_numerator, new_denominator)

    def multiply(self, other):
        new_numerator = self.__numerator * other.__numerator
        new_denominator = self.__denominator * other.__denominator
        return Rational(new_numerator, new_denominator)

    def divide(self, other):
        if other.__numerator == 0:
            raise ValueError("Division by zero is not allowed.")
        new_numerator = self.__numerator * other.__denominator
        new_denominator = self.__denominator * other.__numerator
        return Rational(new_numerator, new_denominator)

    def get_numerator(self):
        return self.__numerator

    def get_denominator(self):
        return self.__denominator

"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: Employee.py
This file defines the Employee class:
    It implements the `Employee` class, a subclass of `CommunityMember`, which 
    represents an employee and includes methods to manage employee-specific 
    data such as position.
"""

from CommunityMember import CommunityMember

class Employee(CommunityMember):
    def __init__(self, fullName="", ssn="", position=""):
        super().__init__(fullName, ssn)
        self._position = position
    
    def getPosition(self):
        return self._position
    
    def setPosition(self, position):
        self._position = position

    def ask(self):
        print("Please provide the information for the Employee:")
        self.setFullName(input("Full Name: "))
        self.setSSN(input("Social Security Number: "))
        self.setPosition(input("Position: "))

    def getPaymentAmount(self):
        return 0 
    
    def __str__(self):
        return f"\nEmployee: {self.getFullName()}, Social Security Number: {self.getSSN()}, Position: {self.getPosition()}"

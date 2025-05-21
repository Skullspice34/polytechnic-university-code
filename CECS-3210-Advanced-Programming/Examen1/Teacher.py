"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: Teacher.py
This file defines the Teacher class:
    It implements the `Teacher` class, a subclass of both `Employee` and `Faculty`, 
    which represents a teacher, inheriting attributes and methods from both parent
    classes and providing functionality specific to teachers, such as calculating 
    payment amount.
"""

from Employee import Employee
from Faculty import Faculty

class Teacher(Employee, Faculty):
    def __init__(self, fullName="", ssn="", position="", className="", credits=0, paymentByClass=0.0):
        Employee.__init__(self, fullName, ssn, position)
        Faculty.__init__(self, fullName, ssn, className)
        self._credits = credits
        self._paymentByClass = paymentByClass
    
    def getCredits(self):
        return self._credits
    
    def setCredits(self, credits):
        if credits <= 0:
           raise ValueError("Credits should be greater than zero.")
        self._credits = credits

    
    def getPaymentByClass(self):
        return self._paymentByClass
    
    def setPaymentByClass(self, paymentByClass):
        self._paymentByClass = paymentByClass
    
    def getPaymentAmount(self):
        return self._credits * self._paymentByClass
    
    def ask(self):
        print("Please provide the information for the Teacher:")
        self.setFullName(input("Full Name: "))
        self.setSSN(input("Social Security Number: "))
        self.setPosition(input("Position: "))
        self.setClassName(input("Class Name: "))
        self.setCredits(int(input("Credits: ")))
        self.setPaymentByClass(float(input("Payment By Class: ")))

    def __str__(self):
        return f"Teacher: {self.getFullName()}, SSN: {self.getSSN()}, Position: {self.getPosition()}, Class Name: {self.getClassName()}, Credits: {self.getCredits()}, Payment By Class: {self.getPaymentByClass()}"
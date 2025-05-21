"""Author: Prof. De La Torre
Filename: Employee.py

class Employee that holds 3 private attributes:
    firstname, lastname & salary
"""
class Employee:
    def __init__(self, firstname = "Juan", lastname = "Bobo", salary = 28000):
        self.__firstname = firstname
        self.__lastname = lastname
        self.__salary = salary

    def get_firstname(self):
        return self.__firstname
    
    def get_lastname(self):
        return self.__lastname
    
    def get_salary(self):
        return self.__salary
    
    def set_firstname(self, firstname):
        self.__firstname = firstname

    def set_lastname(self, lastname):
        self.__lastname = lastname

    def set_salsary(self, salary):
        self.__salary = salary

    def ask(self):
        self.__firstname = input("Enter employee first name: ")
        self.__lastname = input("Enter employee last name: ")
        self.__salary = input("Enter employee salary: ")

    def show(self):
        print()
        print("Name: ", self.__firstname, self.__lastname)
        print("Salary: $ ", self.__salary)
    


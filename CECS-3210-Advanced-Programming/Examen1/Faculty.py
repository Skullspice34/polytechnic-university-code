"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: Faculty.py
This file defines the Faculty class:
    It implements the `Faculty` class, a subclass of `CommunityMember`, which represents a faculty member 
    and includes methods to manage faculty-specific data such as the class they teach.
"""

from CommunityMember import CommunityMember

class Faculty(CommunityMember):
    def __init__(self, fullName="", ssn="", className=""):
        super().__init__(fullName, ssn)
        self._className = className
    
    def getClassName(self):
        return self._className
    
    def setClassName(self, className):
        self._className = className

    def __str__(self):
        return f"Faculty: {self.getFullName()}, Social Security Number: {self.getSSN()}, Class Name: {self.getClassName()}"
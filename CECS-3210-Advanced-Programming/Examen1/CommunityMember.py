"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: CommunityMember.py
This file defines the CommunityMember class:
    It defines an abstract base class `CommunityMember` with attributes
    and methods common to all community members.
"""

from abc import ABC, abstractmethod

class CommunityMember(ABC):
    def __init__(self, fullName, ssn):
        self._fullName = fullName
        self._ssn = ssn
    
    def getFullName(self):
        return self._fullName
    
    def setFullName(self, fullName):
        self._fullName = fullName
    
    def getSSN(self):
        return self._ssn
    
    def setSSN(self, ssn):
        self._ssn = ssn
    
    @abstractmethod
    def getPaymentAmount(self):
        pass
    
    @abstractmethod
    def ask(self):
        pass

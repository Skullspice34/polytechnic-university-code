"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: Shape.py
This file defines the abstract Shape class:
    It implements the `Shape` class, an abstract base class representing geometric shapes.
"""

from abc import ABC, abstractmethod

class Shape(ABC):
    def __init__(self, shapeName="", shapeColor=""):
        self._shapeName = shapeName
        self._shapeColor = shapeColor
    
    def getShapeName(self):
        return self._shapeName
    
    def setShapeName(self, shapeName):
        while not shapeName.isalpha():
            print("Error: Please enter a valid shape name (letters only).")
            shapeName = input("Enter the shape name: ")
        self._shapeName = shapeName
    
    def getShapeColor(self):
        return self._shapeColor
    
    def setShapeColor(self, shapeColor):
        while not shapeColor.isalpha():
            print("Error: Please enter a valid shape color (letters only).")
            shapeColor = input("Enter the shape color: ")
        self._shapeColor = shapeColor
    
    @abstractmethod
    def volume(self):
        pass
    
    @abstractmethod
    def ask(self):
        pass
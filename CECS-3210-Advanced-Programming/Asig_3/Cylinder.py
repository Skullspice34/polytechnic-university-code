"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: Cylinder.py
This file defines the Cylinder class:
    It implements the `Cylinder` class, a concrete subclass of `Shape`, representing a cylinder.
"""

from Shape import Shape

class Cylinder(Shape):
    def __init__(self, shape_name="", shape_color="", radius=0.0, height=0.0):
        super().__init__(shape_name, shape_color)
        self._radius = radius
        self._height = height
    
    def get_radius(self):
        return self._radius
    
    def set_radius(self, radius):
        if radius >= 0:
            self._radius = radius
        else:
            raise ArithmeticError("Radius cannot be negative.")
    
    def get_height(self):
        return self._height
    
    def set_height(self, height):
        if height >= 0:
            self._height = height
        else:
            raise ArithmeticError("Height cannot be negative.")
    
    def volume(self):
        return 3.141592653589793 * self._radius ** 2 * self._height
    
    def ask(self):
        while True:
            try:
                self.setShapeName(input("Enter the shape name: "))
                self.setShapeColor(input("Enter the shape color: "))
                while True:
                    radius_input = input("Enter the radius of the cylinder: ")
                    try:
                        self.set_radius(float(radius_input))
                        break
                    except ValueError:
                        print("Error: Please enter a valid numeric value for the radius.")
                while True:  # This loop is for the height input
                    height_input = input("Enter the height of the cylinder: ")
                    try:
                        self.set_height(float(height_input))
                        break
                    except ValueError:
                        print("Error: Please enter a valid numeric value for the height.")
                    except ArithmeticError as e:
                        print(f"Error: {e}")
                break  # Break out of the main input loop when everything is successfully entered
            except ValueError:
                print("Error: Please enter valid input.")
            except ArithmeticError as e:
                print(f"Error: {e}")
            except:
                print("An unexpected error occurred.")

    def __str__(self):
        return f"Cylinder (Name: {self.getShapeName()}, Color: {self.getShapeColor()}, Volume: {self.volume():.2f})"
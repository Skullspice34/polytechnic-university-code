"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: RationalCalculator.py
This file implements a Rational Calculator GUI using PyQt5:
It creates a GUI window that allows users to input rational numbers 
and select operations to perform, displaying the result.
"""

import sys
from PyQt5.QtWidgets import (
    QMainWindow,
    QApplication,
)
from PyQt5.uic import loadUi
from fractions import Fraction

class RationalCalculator(QMainWindow):
    def __init__(self):
        super(RationalCalculator, self).__init__()

        loadUi('asig4.ui', self)
        self.setWindowTitle("Rational Calculator")

        self.pushButton.clicked.connect(self.calculate_result)

    def calculate_result(self):
        rational1_input = self.lineEdit.text()
        rational2_input = self.lineEdit_2.text()

        try:
            rational1 = Fraction(rational1_input)
            rational2 = Fraction(rational2_input)

            if self.radioButton.isChecked():
                result = rational1 + rational2  
            elif self.radioButton_2.isChecked():
                result = rational1 - rational2  
            elif self.radioButton_3.isChecked():
                result = rational1 * rational2  
            elif self.radioButton_4.isChecked():
                result = rational1 / rational2 
            else:
                result = "No operation selected"

            self.label_3.setText(f'Result: {result}')
        except (ValueError, ZeroDivisionError) as e:
            self.label_3.setText('Error: Invalid input or division by zero.')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    calculator = RationalCalculator()
    calculator.show()
    sys.exit(app.exec_())


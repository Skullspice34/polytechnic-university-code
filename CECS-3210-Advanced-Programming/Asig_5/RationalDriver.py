"""
Author: Coral S. Schmidt Montilla
Student Number: 148830

This application provides a graphical user interface for performing arithmetic
operations on rational numbers. It accepts input as fractions,
performs addition, subtraction, multiplication, and division based on user selection,
and displays the results.
"""

import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QMainWindow, QApplication
from Rational import Rational


class RationalDriver(QMainWindow):
    def __init__(self):
        super().__init__()
        uic.loadUi('Asig_5.ui', self)
        self.GetResultButton.clicked.connect(self.calculate_result)

    def calculate_result(self):
        try:
            num1 = int(self.rational1_lineEdit.text().split('/')[0])
            den1 = int(self.rational1_lineEdit.text().split('/')[1])
            num2 = int(self.rational2_lineEdit.text().split('/')[0])
            den2 = int(self.rational2_lineEdit.text().split('/')[1])

            r1 = Rational(num1, den1)
            r2 = Rational(num2, den2)

            if self.addition_button.isChecked():
                result = r1.add(r2)
            elif self.subs_button.isChecked():
                result = r1.subtract(r2)
            elif self.multiplication_button.isChecked():
                result = r1.multiply(r2)
            elif self.div_button.isChecked():
                result = r1.divide(r2)
            else:
                raise ValueError("Please select an operation.")

            if result.get_numerator() == result.get_denominator():
                self.result_label.setText(str(result.get_numerator()))
            else:
                self.result_label.setText(str(result.to_mixed_fraction()))
        except Exception as e:
            self.result_label.setText("Error: " + str(e))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = RationalDriver()
    window.show()
    sys.exit(app.exec_())

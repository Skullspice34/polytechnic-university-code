"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: add_prisoner.py
 This file contains the dialog window for
 adding a new prisoner.
"""

from PyQt5 import uic
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QApplication, QWidget, QMessageBox, QFileDialog
from PyQt5.QtCore import Qt, QDir
from database import DatabaseConnection
from prisoner import Prisoner
import re

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


# Class that contains the widget GUI to add the info of a prisoner
class AddPrisonerUI(QWidget):
    def __init__(self):
        super().__init__()
        uic.loadUi("add_prisoner.ui", self)
        self.dir = ""  # Stores the entire directory of an image

    # Opens the directory of the user, and prompts them to select an image for the prisoner
    def open_image(self, filename=None):
        if not filename:
            filename, _ = QFileDialog.getOpenFileName(self, 'Select Photo', QDir.currentPath(), 'Images (*.png *.jpg)')
            if not filename:
                return
        self.image_label.setPixmap(QPixmap(filename))

        self.dir = filename

        image_str = self.image_name(str(filename))

        self.photo_lineEdit.setText(image_str)

    # Takes the directory of the image, and looks for the name of the image
    @staticmethod
    def image_name(directory):
        backslash_index = directory.rfind('/')
        return directory[backslash_index + 1:]

    # Checks that the height entered is valid
    def check_height(self):  # New solution
        if float(self.height_lineEdit.text()) <= 0:
            raise SyntaxError("Please make sure that the entered height is not negative")

        else:
            decimal = round((float(self.height_lineEdit.text()) % 1), 2)
            if decimal >= 0.12:
                raise SyntaxError("Please make sure that the entered height is valid and complies with the following "
                                  "format: 5'7\" as 5.07 (Refer to the help section for more info.)")

    # Adds the new prisoner's personal info into the database
    def add_prisoner_clicked(self):

        try:
            database = DatabaseConnection()

            # Boxes not empty check
            if not (self.lastName_lineEdit.text()) or not (self.firstName_lineEdit.text()) or \
                    not (self.birthDate_lineEdit.text()) or not (self.height_lineEdit.text()) or \
                    not (self.hair_lineEdit.text()) or not (self.eyes_lineEdit.text()) or \
                    not (self.placeOfBirth_lineEdit.text()) or not (self.sentence_lineEdit.text()) or \
                    not (self.dateOfConviction_lineEdit.text()):
                raise ArithmeticError("Please, fill in all of the corresponding boxes (Refer to the help section"
                                      f" for more info.)")

            # Height check
            self.check_height()


            pattern = "[0-9]+.?[0-9]*"
            numHair = re.findall(pattern, self.hair_lineEdit.text())
            numEyes = re.findall(pattern, self.eyes_lineEdit.text())

            if numHair != [] or numEyes != []:
                raise ArithmeticError("Please enter only the name of the color (no numbers)")

            # Image added check
            if not (self.photo_lineEdit.text()):
                raise ArithmeticError("Please, add an image of the prisoner")

            # Date to be Liberated check
            if not (self.dateToBeLiberated_lineEdit.text()) or self.dateToBeLiberated_lineEdit.text() == "None" \
                    or self.dateToBeLiberated_lineEdit.text() == "none":
                dateToBeLiberated = None

                lastName = self.lastName_lineEdit.text()
                firstName = self.firstName_lineEdit.text()
                photo = self.dir
                birthDate = str(self.birthDate_lineEdit.text())
                height = float(self.height_lineEdit.text())
                hair = self.hair_lineEdit.text()
                eyes = self.eyes_lineEdit.text()
                placeOfBirth = self.placeOfBirth_lineEdit.text()
                sentence = self.sentence_lineEdit.text()
                dateOfConviction = str(self.dateOfConviction_lineEdit.text())

            else:
                lastName = self.lastName_lineEdit.text()
                firstName = self.firstName_lineEdit.text()
                photo = self.dir
                birthDate = str(self.birthDate_lineEdit.text())
                height = float(self.height_lineEdit.text())
                hair = self.hair_lineEdit.text()
                eyes = self.eyes_lineEdit.text()
                placeOfBirth = self.placeOfBirth_lineEdit.text()
                sentence = self.sentence_lineEdit.text()
                dateOfConviction = str(self.dateOfConviction_lineEdit.text())
                dateToBeLiberated = str(self.dateToBeLiberated_lineEdit.text())

            prisoner = Prisoner(lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth,
                                sentence, dateOfConviction, dateToBeLiberated)

            rows, id = database.add_prisoner(prisoner)

            database.close()

            msgBox = QMessageBox()

            if rows == 1:
                msg = f"{rows} record inserted with ID {id}"
                msgBox.setText(msg)
                msgBox.exec()
                self.hide()
            else:
                msg = "Database error"
                msgBox.setText(msg)
                msgBox.exec()

        except ArithmeticError as ex:
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"{ex}")
            msgbox.exec_()
        except SyntaxError as ex:
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"{ex}")
            msgbox.exec_()
        except ValueError:
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"Enter an integer or decimal number for Height (Refer to the help section "
                           f"for more info.)")
            msgbox.exec_()

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
from PyQt5.QtCore import pyqtSignal, QDir
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QWidget, QMessageBox, QFileDialog
from PyQt5 import uic
import re
from database import DatabaseConnection
from prisoner import Prisoner


class AddPrisonerUI(QWidget):
    prisoner_added = pyqtSignal()

    def __init__(self, list_prisoners_ui):
        super().__init__()
        uic.loadUi("add_prisoner.ui", self)
        self.dir = ""
        self.list_prisoners_ui = list_prisoners_ui

        self.addImage_pushButton.clicked.connect(self.open_image)

    def open_image(self, filename=None):
        if not filename:
            filename, _ = QFileDialog.getOpenFileName(self, 'Select Photo', QDir.currentPath(), 'Images (*.png *.jpg '
                                                                                                '*.jpeg)')
            if not filename:
                return
        self.image_label.setPixmap(QPixmap(filename))

        self.dir = filename

        image_str = self.image_name(str(filename))

        self.photo_lineEdit.setText(image_str)

    @staticmethod
    def image_name(directory):
        backslash_index = directory.rfind('/')
        return directory[backslash_index + 1:]

    def check_height(self):
        if float(self.height_lineEdit.text()) <= 0:
            raise SyntaxError("Please make sure that the entered height is not negative")

        else:
            decimal = round((float(self.height_lineEdit.text()) % 1), 2)
            if decimal >= 0.12:
                raise SyntaxError("Please make sure that the entered height is valid and complies with the following "
                                  "format: 5'7\" as 5.07 (Refer to the help section for more info.)")

    def add_prisoner_clicked(self):
        try:
            print("Initializing database connection...")
            database = DatabaseConnection()

            if not (self.lastName_lineEdit.text()) or not (self.firstName_lineEdit.text()) or \
                    not (self.birthDate_lineEdit.text()) or not (self.height_lineEdit.text()) or \
                    not (self.hair_lineEdit.text()) or not (self.eyes_lineEdit.text()) or \
                    not (self.placeOfBirth_lineEdit.text()) or not (self.sentence_lineEdit.text()) or \
                    not (self.dateOfConviction_lineEdit.text()):
                raise ArithmeticError(
                    "Please, fill in all of the corresponding boxes (Refer to the help section for more info.)")

            print("Checking height...")
            self.check_height()

            pattern = "[0-9]+.?[0-9]*"
            numHair = re.findall(pattern, self.hair_lineEdit.text())
            numEyes = re.findall(pattern, self.eyes_lineEdit.text())
            if numHair or numEyes:
                raise ArithmeticError("Please enter only the name of the color (no numbers)")

            if not self.photo_lineEdit.text():
                raise ArithmeticError("Please, add an image of the prisoner")

            dateToBeLiberated = self.dateToBeLiberated_lineEdit.text() if self.dateToBeLiberated_lineEdit.text().lower() != "none" else None

            lastName = self.lastName_lineEdit.text()
            firstName = self.firstName_lineEdit.text()
            photo = self.dir
            birthDate = self.birthDate_lineEdit.text().strip()
            height_str = self.height_lineEdit.text().strip()  # Strip any extra spaces
            print(f"Raw height input: {height_str}")

            try:
                height = float(height_str)
                print(f"Parsed height: {height}")
            except ValueError as ve:
                print(f"ValueError: {ve}")
                raise ValueError("Height must be a valid number.")

            hair = self.hair_lineEdit.text()
            eyes = self.eyes_lineEdit.text()
            placeOfBirth = self.placeOfBirth_lineEdit.text()
            sentence = self.sentence_lineEdit.text()
            dateOfConviction = self.dateOfConviction_lineEdit.text().strip()
            dateToBeLiberated = self.dateToBeLiberated_lineEdit.text().strip()

            print(
                f"Data collected: {lastName}, {firstName}, {photo}, {birthDate}, {height}, {hair}, {eyes}, {placeOfBirth}, {sentence}, {dateOfConviction}, {dateToBeLiberated}")

            prisoner = Prisoner(None, lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth, sentence,
                                dateOfConviction, dateToBeLiberated)

            insert_values = prisoner.get_insert_values()
            print(f"Insert Values: {insert_values}")
            print(f"Number of Values: {len(insert_values)}")

            print("Inserting prisoner into the database...")
            rows, id = database.add_prisoner(prisoner)

            database.close()

            msgBox = QMessageBox()
            if rows == 1:
                msg = f"{rows} record inserted with ID {id}"
                print(msg)
                msgBox.setText(msg)
                msgBox.exec()
                self.prisoner_added.emit()
                self.list_prisoners_ui.load_prisoner_list()
                self.hide()
            else:
                msg = "Database error"
                print(msg)
                msgBox.setText(msg)
                msgBox.exec()

        except ArithmeticError as ex:
            print(f"ArithmeticError: {ex}")
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"{ex}")
            msgbox.exec_()
        except SyntaxError as ex:
            print(f"SyntaxError: {ex}")
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"{ex}")
            msgbox.exec_()
        except ValueError as ex:
            print(f"ValueError: {ex}")
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"Enter an integer or decimal number for Height (Refer to the help section for more info.)")
            msgbox.exec_()
        except Exception as ex:
            print(f"Exception: {ex}")
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Critical)
            msgbox.setText(f"An unexpected error occurred: {ex}")
            msgbox.exec_()

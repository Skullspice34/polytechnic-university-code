"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: modify_prisoner.py
This file contains the dialog window for modifying an existing prisoner.
"""

from PyQt5 import uic
from PyQt5.QtCore import Qt, QDir
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication, QFileDialog

from database import DatabaseConnection
from prisoner import Prisoner

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class ModifyPrisonerUI(QWidget):
    def __init__(self, prisoner_list_ui=None):
        super(ModifyPrisonerUI, self).__init__()
        uic.loadUi("modify_prisoner.ui", self)
        self.id = -1
        self.dir = ""
        self.prisoner_list_ui = prisoner_list_ui

    def fill_the_fields(self, id):
        database = DatabaseConnection()
        self.id = id
        flag = False

        prisoner = database.select_by_id(id)

        if prisoner is not None:
            flag = True
            self.prisonerID_lineEdit.setText(str(id))
            self.lastName_lineEdit.setText(prisoner.get_lastName())
            self.firstName_lineEdit.setText(prisoner.get_firstName())

            self.dir = prisoner.get_photo()
            image_str = self.image_name(prisoner.get_photo())

            self.photo_lineEdit.setText(image_str)
            self.birthDate_lineEdit.setText(str(prisoner.get_birthDate()))
            self.height_lineEdit.setText(str(prisoner.get_height()))
            self.hair_lineEdit.setText(prisoner.get_hair())
            self.eyes_lineEdit.setText(prisoner.get_eyes())
            self.placeOfBirth_lineEdit.setText(prisoner.get_placeOfBirth())
            self.sentence_lineEdit.setText(prisoner.get_sentence())
            self.dateOfConviction_lineEdit.setText(str(prisoner.get_dateOfConviction()))
            self.dateToBeLiberated_lineEdit.setText(str(prisoner.get_dateToBeLiberated()))
            self.image_label.setPixmap(QPixmap(prisoner.get_photo()))
        else:
            msg = QMessageBox()
            msg.setWindowTitle("Prisoner ID")
            msg.setText(f"ID {id} not found!")
            msg.exec()

        database.close()

        return flag

    def open_image(self, filename=None):
        if not filename:
            filename, _ = QFileDialog.getOpenFileName(self, 'Select Photo', QDir.currentPath(), 'Images (*.png *.jpg)')
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
                raise SyntaxError(
                    "Please make sure that the entered height is valid and complies with the following format: 5'7\" "
                    "as 5.07 (Refer to the help section for more info.)")

    def modify_prisoner_clicked(self):
        try:
            print("Initializing database connection...")
            database = DatabaseConnection()

            prisonerID = int(self.prisonerID_lineEdit.text())
            lastName = self.lastName_lineEdit.text()
            firstName = self.firstName_lineEdit.text()
            photo = self.photo_lineEdit.text()
            birthDate = self.birthDate_lineEdit.text().strip()
            height_str = self.height_lineEdit.text().strip()
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
                f"Data collected: {prisonerID}, {lastName}, {firstName}, {photo}, {birthDate}, {height}, {hair}, {eyes}"
                f" {placeOfBirth}, {sentence}, {dateOfConviction}, {dateToBeLiberated}")

            prisoner = Prisoner(prisonerID, lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth,
                                sentence, dateOfConviction, dateToBeLiberated)

            print("Modifying prisoner in the database...")
            rows = database.modify_prisoner(prisoner)

            database.close()

            msgBox = QMessageBox()
            if rows == 1:
                msg = "Prisoner details updated successfully."
                print(msg)
                msgBox.setText(msg)
                msgBox.exec()
                if self.prisoner_list_ui:
                    self.prisoner_list_ui.load_prisoner_list()  # Update the list if the UI is provided
                self.hide()
            else:
                msg = "Database error or no rows affected."
                print(msg)
                msgBox.setText(msg)
                msgBox.exec()

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

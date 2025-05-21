"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: search_prisoner.py
 This file contains the dialog window for
 searching for a prisoner.
"""

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication

from database import DatabaseConnection

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


# Class that contains the widget GUI to view the current info of a prisoner
class SearchPrisonerUI(QWidget):
    def __init__(self):
        super(SearchPrisonerUI, self).__init__()
        uic.loadUi("search_prisoner.ui", self)
        self.id = -1

    # Displays the prisoner's current info in the input boxes
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

    # Takes the directory of the image, and looks for the name of the image
    @staticmethod
    def image_name(directory):
        backslash_index = directory.rfind('/')
        return directory[backslash_index + 1:]

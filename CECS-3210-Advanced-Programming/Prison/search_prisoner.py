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
import sys

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class SearchPrisonerUI(QWidget):
    def __init__(self):
        super(SearchPrisonerUI, self).__init__()
        uic.loadUi("search_prisoner.ui", self)
        self.id = -1

        self.fill_the_fields_button.clicked.connect(self.search_prisoner)

    def fill_the_fields(self, id):
        print(f"Searching for prisoner with ID: {id}")
        database = DatabaseConnection()
        self.id = id
        flag = False

        prisoner = database.select_by_id(id)

        if prisoner is not None:
            print(f"Prisoner found: {prisoner}")
            flag = True

            try:
                print(f"Setting prisonerID: {id}")
                self.prisonerID_lineEdit.setText(str(id))

                last_name = prisoner.get_lastName()
                print(f"Setting last name: {last_name}")
                self.lastNamesearch.setText(last_name)

                first_name = prisoner.get_firstName()
                print(f"Setting first name: {first_name}")
                self.searchName.setText(first_name)

                photo = prisoner.get_photo()
                image_str = self.image_name(photo)
                print(f"Setting photo: {image_str}")
                self.image_label.setText(image_str)

                birth_date = prisoner.get_birthDate()
                print(f"Setting birth date: {birth_date}")
                self.searchBirthdate.setText(str(birth_date))

                height = prisoner.get_height()
                print(f"Setting height: {height}")
                self.searchFeet.setText(str(height))

                hair = prisoner.get_hair()
                print(f"Setting hair: {hair}")
                self.searchHair.setText(hair)

                eyes = prisoner.get_eyes()
                print(f"Setting eyes: {eyes}")
                self.searchEyes.setText(eyes)

                place_of_birth = prisoner.get_placeOfBirth()
                print(f"Setting place of birth: {place_of_birth}")
                self.searchBirthPlace.setText(place_of_birth)

                sentence = prisoner.get_sentence()
                print(f"Setting sentence: {sentence}")
                self.searchSentence.setText(sentence)

                date_of_conviction = prisoner.get_dateOfConviction()
                print(f"Setting date of conviction: {date_of_conviction}")
                self.searchConviction.setText(str(date_of_conviction))

                date_to_be_liberated = prisoner.get_dateToBeLiberated()
                print(f"Setting date to be liberated: {date_to_be_liberated}")
                self.searchLiberation.setText(str(date_to_be_liberated))

                print(f"Setting image: {photo}")
                self.image_label.setPixmap(QPixmap(photo))

            except Exception as e:
                print(f"An error occurred: {e}")
                msg = QMessageBox()
                msg.setWindowTitle("Error")
                msg.setText(f"An error occurred: {e}")
                msg.exec()


        database.close()
        return flag

    @staticmethod
    def image_name(directory):
        backslash_index = directory.rfind('/')
        return directory[backslash_index + 1:]

    def search_prisoner(self):
        try:
            prisonerID = int(self.prisonerID_lineEdit.text())
            if self.fill_the_fields(prisonerID):
                print(f"Prisoner with ID {prisonerID} loaded successfully")
            else:
                print(f"Prisoner with ID {prisonerID} not found")
        except ValueError:
            msgBox = QMessageBox()
            msgBox.setWindowTitle("Error")
            msgBox.setIcon(QMessageBox.Warning)
            msgBox.setText("Please enter a valid Prisoner ID.")
            msgBox.exec_()




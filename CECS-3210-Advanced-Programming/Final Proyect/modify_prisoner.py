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
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget, QMessageBox, QFileDialog
from PyQt5.QtCore import QDir
from database import DatabaseConnection
from prisoner import Prisoner

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class ModifyPrisonerUI(QWidget):
    def __init__(self, prisoner_id):
        super().__init__()
        uic.loadUi("modify_prisoner.ui", self)
        self.id = prisoner_id
        self.dir = ""  # Stores the entire directory of an image
        self.fill_the_fields(self.id)
        self.modifyButton.clicked.connect(self.modify_prisoner_clicked)
        self.backButton.clicked.connect(self.back_to_menu)

    def fill_the_fields(self, prisoner_id):
        database = DatabaseConnection()
        self.id = prisoner_id
        flag = False

        prisoner = database.select_by_id(prisoner_id)

        if prisoner is not None:
            flag = True
            self.prisonerID_lineEdit.setText(str(prisoner_id))
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
            msg.setText(f"ID {prisoner_id} not found!")
            msg.exec()

        database.close()

        return flag

    def modify_prisoner_clicked(self):
        try:
            last_name = self.lastName_lineEdit.text()
            first_name = self.firstName_lineEdit.text()
            birth_place = self.placeOfBirth_lineEdit.text()
            sentence = self.sentence_lineEdit.text()
            photo = self.dir
            birth_date = self.birthDate_lineEdit.text()
            conviction_date = self.dateOfConviction_lineEdit.text()
            liberation_date = self.dateToBeLiberated_lineEdit.text()
            hair = self.hair_lineEdit.text()
            eyes = self.eyes_lineEdit.text()
            feet = self.addFeet.currentText()
            inches = self.addInches.currentText()

            if not (last_name and first_name and birth_place and sentence and photo):
                raise ValueError("Full information not entered, please finish entering!")

            height = f"{feet}.{inches}"

            prisoner = Prisoner(
                first_name=first_name,
                last_name=last_name,
                birth_place=birth_place,
                sentence=sentence,
                photo=photo,
                birth_date=birth_date,
                conviction_date=conviction_date,
                liberation_date=liberation_date,
                hair=hair,
                eyes=eyes,
                height=height,
                id=self.id
            )

            database = DatabaseConnection()
            database.modify_prisoner(prisoner)

            self.prisonerModified.setText("Prisoner successfully modified!")

        except ValueError as ve:
            self.prisonerModified.setText(str(ve))
        except Exception as e:
            QMessageBox.critical(self, "Error", str(e))

    def back_to_menu(self):
        self.close()

    @staticmethod
    def image_name(directory):
        backslash_index = directory.rfind('/')
        return directory[backslash_index + 1:]


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    window = ModifyPrisonerUI(123)
    window.show()
    sys.exit(app.exec_())

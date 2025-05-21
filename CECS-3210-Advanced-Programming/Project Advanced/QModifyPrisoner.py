from PyQt5 import uic
from PyQt5.QtCore import Qt, QDir
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication, QFileDialog

from DatabaseConnection import DatabaseConnection
from Prisoner import Prisoner
import re

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)

# Class that contains the widget GUI to modify the info of a prisoner
class ModifyPrisonerWidget(QWidget):
    def __init__(self):
        super(ModifyPrisonerWidget, self).__init__()
        uic.loadUi("QModifyPrisoner.ui", self)
        self.id = -1
        self.dir = ""  # Stores the entire directory of an image

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

    # Opens a message box asking if the user is certain about modifying the prisoner's info
    def modify_prisoner_clicked(self):
        qm = QMessageBox
        ret = qm.question(self, '', "Are you sure you want to modify the prisoner's info?", qm.Yes | qm.No)

        if ret == qm.Yes:
            self.modify_prisoner()

    # Modifies the prisoner's personal info currently in the database
    def modify_prisoner(self):

        try:

            database = DatabaseConnection()

            # Boxes not empty check
            if not (self.lastName_lineEdit.text()) or not (self.firstName_lineEdit.text()) or \
                    not (self.photo_lineEdit.text()) or not (self.birthDate_lineEdit.text()) or \
                    not (self.height_lineEdit.text()) or not (self.hair_lineEdit.text()) or \
                    not (self.eyes_lineEdit.text()) or not (self.placeOfBirth_lineEdit.text()) or \
                    not (self.sentence_lineEdit.text()) or not (self.dateOfConviction_lineEdit.text()):
                raise ArithmeticError("Please, fill in all of the corresponding boxes (Refer to the help section "
                                      "for more info.)")

            # Height check
            self.check_height()

            # Hair and eye color check
            pattern = "[0-9]+.?[0-9]*"
            numHair = re.findall(pattern, self.hair_lineEdit.text())
            numEyes = re.findall(pattern, self.eyes_lineEdit.text())

            if numHair != [] or numEyes != []:
                raise ArithmeticError("Please enter only the name of the color (no numbers)")

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
                                sentence, dateOfConviction, dateToBeLiberated, self.id)

            rows = database.update(prisoner)

            database.close()

            msgBox = QMessageBox()

            if rows == 1:
                msg = f"{rows} record updated"
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
            msgbox.setText(f"Enter an integer or decimal number for Height (Refer to the help section"
                           f" for more info.)")
            msgbox.exec_()
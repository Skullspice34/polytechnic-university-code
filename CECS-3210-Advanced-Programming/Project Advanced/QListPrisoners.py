from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QStandardItemModel, QStandardItem
from PyQt5.QtWidgets import QWidget, QApplication

from DatabaseConnection import DatabaseConnection

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)

# Class that contains the widget GUI that displays a table with the info of all the prisoners in the database
class ListPrisonersWidget(QWidget):
    def __init__(self):
        super().__init__()
        uic.loadUi("QListPrisoners.ui", self)

        database = DatabaseConnection()

        all_prisoners_cursor = database.select_all_prisoners()
        tableWidget = self.list_prisoners_tableView

        model = QStandardItemModel()
        model.setHorizontalHeaderLabels(['Prisoner ID', 'Last Name', 'First Name', 'Photo', 'Birth Date', 'Height',
                                         'Hair Color', 'Eye Color', 'Place of Birth', 'Sentence', 'Conviction Date',
                                         'Liberation Date'])

        row = 0

        for (prisonerID, lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth, sentence,
             dateOfConviction, dateToBeLiberated) in all_prisoners_cursor:
            array_data = [str(prisonerID), lastName, firstName, photo, str(birthDate), str(float(height)), hair, eyes,
                          placeOfBirth, sentence, str(dateOfConviction), str(dateToBeLiberated)]

            for col in range(12):
                item = QStandardItem()

                if col == 3:
                    value = self.image_name(array_data[col])

                elif col == 5:
                    value = f"{array_data[col]}ft/in"

                else:
                    value = array_data[col]

                item.setData(value, Qt.DisplayRole)

                model.setItem(row, col, item)

            row = row + 1

        tableWidget.setModel(model)

        database.close()

    # Takes the directory of the image, and looks for the name of the image
    @staticmethod
    def image_name(directory):
        backslash_index = directory.rfind('/')
        return directory[backslash_index + 1:]
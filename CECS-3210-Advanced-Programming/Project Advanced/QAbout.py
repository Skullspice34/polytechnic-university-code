from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QApplication

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)

# Class that contains the widget GUI that displays the name of the creators of the program, and their logo
class AboutWidget(QWidget):
    def __init__(self):
        super().__init__()
        uic.loadUi("QAbout.ui", self)


"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: about.py
 This file contains the dialog window for
 displaying information about the program and its team members.
"""

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QApplication, QPushButton

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class AboutUI(QWidget):
    def __init__(self):
        super().__init__()
        uic.loadUi("about.ui", self)

        self.backButton = self.findChild(QPushButton, "backButton")
        self.backButton.clicked.connect(self.go_back)

    def go_back(self):
        self.prisoner_menu = uic.loadUi("prisoner_menu.ui")
        self.prisoner_menu.show()
        self.close()


if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    window = AboutUI()
    window.show()
    sys.exit(app.exec_())

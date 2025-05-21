"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: main.py
This file contains the main entry point of
the program and handles the menu actions.
"""

import sys
from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QMainWindow

from about import AboutUI
from add_prisoner import AddPrisonerUI
from help import HelpUI
from display_prisoner_list import ListPrisonersUI
from modify_prisoner import ModifyPrisonerUI
from search_prisoner import SearchPrisonerUI

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        uic.loadUi('prisoner_menu.ui', self)
        self.show()

        self.exitButton.clicked.connect(self.close)

        # Widget instances
        self.addPrisoner = AddPrisonerUI()
        self.modifyPrisoner = None  # Instantiate dynamically as needed
        self.searchPrisoner = SearchPrisonerUI()
        self.listPrisoners = ListPrisonersUI()
        self.help = HelpUI()
        self.about = AboutUI()

        # Connect actions
        self.actionAdd_Prisoner.triggered.connect(self.show_add_prisoner_ui)
        self.actionModify_Prisoner.triggered.connect(self.show_modify_prisoner_ui)
        self.actionSearch_Prisoner.triggered.connect(self.show_search_prisoner_ui)
        self.actionList_Prisoner.triggered.connect(self.show_list_prisoners_ui)
        self.actionHelp.triggered.connect(self.show_help_ui)
        self.actionAbout.triggered.connect(self.show_about_ui)

    def show_add_prisoner_ui(self):
        self.hide_all_ui()
        self.addPrisoner.show()

    def show_modify_prisoner_ui(self):
        self.hide_all_ui()

        self.modifyPrisoner.show()

    def show_search_prisoner_ui(self):
        self.hide_all_ui()
        self.searchPrisoner.show()

    def show_list_prisoners_ui(self):
        self.hide_all_ui()
        self.listPrisoners.show()

    def show_help_ui(self):
        self.hide_all_ui()
        self.help.show()

    def show_about_ui(self):
        self.hide_all_ui()
        self.about.show()

    def hide_all_ui(self):
        if self.addPrisoner:
            self.addPrisoner.hide()
        if self.modifyPrisoner:
            self.modifyPrisoner.hide()
        if self.searchPrisoner:
            self.searchPrisoner.hide()
        if self.listPrisoners:
            self.listPrisoners.hide()
        if self.help:
            self.help.hide()
        if self.about:
            self.about.hide()


def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

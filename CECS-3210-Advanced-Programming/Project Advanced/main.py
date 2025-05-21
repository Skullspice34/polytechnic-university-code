import sys

from PyQt5 import Qt, uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, qApp, QMainWindow, QLineEdit, QInputDialog, QStyleFactory

from QAbout import AboutWidget
from QAddPrisoner import AddPrisonerWidget
from QHelp import HelpWidget
from QListPrisoners import ListPrisonersWidget
from QModifyPrisoner import ModifyPrisonerWidget
from QViewPrisoner import ViewPrisonerWidget

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        uic.loadUi("QMenuPrisoner.ui", self)

        self.actionExit.triggered.connect(qApp.quit)

        # Widget instances
        self.addPrisoner = AddPrisonerWidget()
        self.modifyPrisoner = ModifyPrisonerWidget()
        self.viewPrisoner = ViewPrisonerWidget()
        self.listPrisoners = ListPrisonersWidget()
        self.help = HelpWidget()
        self.about = AboutWidget()

        self.addPrisoner.setWindowFlags(self.windowFlags() & ~Qt.WindowMaximizeButtonHint)
        self.listPrisoners.setWindowFlags(self.windowFlags() & ~Qt.WindowMaximizeButtonHint)
        self.help.setWindowFlags(self.windowFlags() & ~Qt.WindowMaximizeButtonHint)
        self.about.setWindowFlags(self.windowFlags() & ~Qt.WindowMaximizeButtonHint)

        # Depending on the action button clicked, it executes it's corresponding task
        self.actionAdd_Prisoner.triggered.connect(self.addPrisoner.show)
        self.actionModify_Prisoner.triggered.connect(self.modify_prisoner)
        self.actionSearch_Prisoner.triggered.connect(self.search_prisoner)
        self.actionList_Prisoners.triggered.connect(self.listPrisoners.show)
        self.actionHelp.triggered.connect(self.help.show)
        self.actionAbout.triggered.connect(self.about.show)

    # Asks the user to enter the prisoner's id, searches for it, and calls ModifyPrisonerWidget
    def modify_prisoner(self):
        id_str, ok = QInputDialog().getText(self, "Message", "Enter an ID:", QLineEdit.Normal, None)

        if ok:
            id = int(id_str)
            flag = self.modifyPrisoner.fill_the_fields(id)

            if flag:
                self.modifyPrisoner.setWindowFlags(self.windowFlags() & ~Qt.WindowMaximizeButtonHint)
                self.modifyPrisoner.show()

    # Asks the user to enter the prisoner's id, searches for it, and calls ViewPrisonerWidget
    def search_prisoner(self):
        id_str, ok = QInputDialog().getText(self, "Message", "Enter an ID:", QLineEdit.Normal, None)

        if ok:
            id = int(id_str)
            flag = self.viewPrisoner.fill_the_fields(id)

            if flag:
                self.viewPrisoner.setWindowFlags(self.windowFlags() & ~Qt.WindowMaximizeButtonHint)
                self.viewPrisoner.show()

# Displays the GUI program
def main():
    app = QApplication(sys.argv)
    QApplication.setStyle(QStyleFactory.create("windows"))
    window = MainWindow()
    window.setWindowFlags(window.windowFlags() & ~Qt.WindowMaximizeButtonHint)
    window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

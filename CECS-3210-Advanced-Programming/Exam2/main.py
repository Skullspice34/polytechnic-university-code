"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
This module provides 4 things. Force, calculates the force by multiplying a and m. Split, separates
the numerator & denominator.It also shows 4 radio buttons that change an image when you choose a
different one and a combo box that shows the animal yoy selected after it has been selected.
"""

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QMainWindow, QApplication, QStyleFactory

QApplication.setAttribute(Qt.AA_EnableHighDpiScaling, True)


class MainWindow(QMainWindow):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        uic.loadUi('Exam2.ui', self)

        self.current_index = 0

        self.calculatebutton.clicked.connect(self.force)

        self.splitbutton.clicked.connect(self.split)

        self.comboBox.currentIndexChanged.connect(self.name_change)

        self.imageChanged.setPixmap(QPixmap("bird.gif"))


        if self.bird.isChecked():
            self.imageChanged.setPixmap(QPixmap("bird.gif"))

        elif self.cat.isChecked():
            self.imageChanged.setPixmap(QPixmap("cat.gif"))

        elif self.dog.isChecked():
            self.imageChanged.setPixmap(QPixmap("dog.gif"))

        elif self.pig.isChecked():
            self.imageChanged.setPixmap(QPixmap("pig.gif"))

    def force(self):
        m = float(self.lineEdit.text())
        a = float(self.lineEdit_2.text())

        result = m * a

        self.forceresult.setText(f"F =\t\t{result:.3f}")

    def split(self):
        fraction = list(self.lineEdit_3.text())

        fraction = fraction.split("/")

        numerator = fraction[1]
        denominator = fraction[2]

        self.numerator.setText(f"Numerator: \t\t{numerator}")
        self.denominator.setText(f"Denominator: \t\t{denominator}")

    def name_change(self, index):
        names = ["Cotorrita", "Gatito", "Perrito", "Cerdito", "Conejito"]

        self.youChoose.setText(names[index])


if __name__ == '__main__':
    app = QApplication([])
    QApplication.setStyle(QStyleFactory.create("Fusion"))
    window = MainWindow()
    window.show()
    app.exec()

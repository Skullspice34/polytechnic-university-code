"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
This module provides 4 classes called Force .
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


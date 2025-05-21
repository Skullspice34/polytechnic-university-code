import sys

from PyQt5.QtCore import Qt 
from PyQt5.uic import loadUi 
from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QApplication, QMainWindow

QApplication.setAttribute (Qt.AA_EnableHighDpiScaling, True) # enable High-DPI scaling


class MainWindow (QMainWindow) :
    def _init__(self, *args, **kwargs): 
        super(). init (*args, **kwargs) 
        loadUi ('RadioButtonTest.ui', self)
    def radiobutton_checked_changed (self, state): 
        radio_button= self.sender () 
        font = QFont ("MS Serif", 10)
        
        if radio_button.objectName() == "bold_radioButton" and state:
            font.setBold (True)
        if radio_button.objectName() == "italic_radioButton" and state:
            font.setItalic (True)
        if radio_button.objectName() == "bold_italic_radioButton" and state:
            font.setBold(True)
            font.setItalic(True)

        self.output_lable.setFont(font)

if __name__ == "__main__":
    app = QApplication(sys.argv)

    win = MainWindow()
    win.show()

    sys.exit(app.exec())
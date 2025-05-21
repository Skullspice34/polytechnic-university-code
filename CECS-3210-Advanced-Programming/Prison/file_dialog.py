"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: file_dialog.py
 This file contains the `OpenFileDialog` class,
 which provides functionality for opening a file
 dialog to select prisoner photos.
"""

from PyQt5.QtWidgets import QFileDialog


class OpenFileDialog:
    @staticmethod
    def get_file_name(parent):
        options = QFileDialog.Options()
        fileName, _ = QFileDialog.getOpenFileName(parent, "Select Picture", "", "Images (*.png *.xpm *.jpg)",
                                                  options=options)
        return fileName

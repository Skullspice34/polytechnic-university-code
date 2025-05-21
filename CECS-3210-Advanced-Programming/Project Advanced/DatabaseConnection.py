from PyQt5.QtWidgets import QMessageBox
from mysql.connector import Error, DataError
import mysql.connector as connection

from Prisoner import Prisoner

# Class that contains the database connection of the program
class DatabaseConnection:
    def __init__(self):
        # Database cursor
        self.cursor = None

        try:
            # Opens the connection to the database
            self.database = connection.connect(
                host="localhost",
                user="root",
                password="mysql12",
                database="PrisonDB3"
            )

            # Queries
            self.select_all_query = "SELECT * FROM Prison3"
            self.select_by_id_query = "SELECT * FROM Prison3 where prisonerID = %s"
            self.insert_query = "INSERT INTO Prison3 (lastName, firstName, photo, birthDate, height," \
                                "hair, eyes, placeOfBirth, sentence, dateOfConviction, dateToBeLiberated)" \
                                " values(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
            self.update_query = "UPDATE Prison3 set lastName=%s, firstName=%s, photo=%s, birthDate=%s," \
                                "height=%s, hair=%s, eyes=%s, placeOfBirth=%s, sentence=%s, dateOfConviction=%s," \
                                "dateToBeLiberated=%s where prisonerID=%s"

            self.cursor = self.database.cursor()
        except Error as e:
            print(e)

    # Inserts the new prisoner's info into the database
    def add(self, prisoner):
        try:
            self.cursor.execute(self.insert_query, prisoner.get_insert_values())
            self.database.commit()
        except DataError:
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"You might have not entered the correct format for the Dates or may have exceeded the "
                           f"maximum character amount of a field (Refer to the help section for more info.)")
            msgbox.exec_()

        return self.cursor.rowcount, self.cursor.lastrowid  #rowcount - amount inserted

    # Selects all the current prisoners and their info from the database, and returns it to the program
    def select_all_prisoners(self):
        self.cursor.execute(self.select_all_query)

        return self.cursor

    # Selects the specified (by ID) prisoner and their info from the database, and returns it to the program
    def select_by_id(self, prisonerID):
        prisoner = None
        values = (prisonerID,)

        self.cursor.execute(self.select_by_id_query, values)
        results = self.cursor.fetchall()

        if len(results) > 0:
            for record in results:
                prisonerID, lastName, firstName, photo, birthDate, height, hair, eyes,\
                    placeOfBirth, sentence, dateOfConviction, dateToBeLiberated = record

            prisoner = Prisoner(lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth,
                                sentence, dateOfConviction, dateToBeLiberated, prisonerID)

        return prisoner

    # Inserts the modified info of a specified (by ID) prisoner into the database
    def update(self, prisoner):

        try:
            self.cursor.execute(self.update_query, prisoner.get_update_values())
            self.database.commit()

        except DataError:
            msgbox = QMessageBox()
            msgbox.setWindowTitle("Error")
            msgbox.setIcon(QMessageBox.Warning)
            msgbox.setText(f"You might have not entered the correct format for the Dates or may have exceeded the "
                           f"maximum character amount of a field (Refer to the help section for more info.)")
            msgbox.exec_()

        return self.cursor.rowcount

    # Closes the connection to the database
    def close(self):
        self.cursor.close()
        self.database.close()

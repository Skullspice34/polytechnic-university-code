"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: database.py
 This file handles database operations, such
 as connecting to the database, executing
 queries, and retrieving data.
"""

from mysql.connector import Error
import mysql.connector as connection
from prisoner import Prisoner


class DatabaseConnection:
    def __init__(self):
        self.cursor = None

        try:
            self.database = connection.connect(
                host="localhost",
                user="Gabriel",
                password="Prisoner35",
                database="prisondb2"
            )

            self.select_all_Query = "SELECT * FROM Prison"
            self.select_by_id_Query = "SELECT * FROM Prison WHERE prisonerID = %s"
            self.insert_Query = (
                "INSERT INTO Prison (lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth, "
                "sentence, dateOfConviction, dateToBeLiberated)"
                "VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
            )
            self.update_Query = (
                "UPDATE Prison SET lastName = %s, firstName = %s, photo = %s, birthDate = %s, height = %s, "
                "hair = %s, eyes = %s, placeOfBirth = %s, sentence = %s, dateOfConviction = %s, dateToBeLiberated = %s "
                "WHERE prisonerID = %s")

            self.cursor = self.database.cursor()

        except Error as e:
            print(e)

    def add_prisoner(self, prison):
        self.cursor.execute(self.insert_Query, prison.get_insert_values())
        self.database.commit()

        return self.cursor.rowcount, self.cursor.lastrowid

    def select_all_prisoners(self):
        if self.cursor:
            self.cursor.execute(self.select_all_Query)
            return self.cursor
        else:
            print("Database cursor is not initialized.")
            return None

    def select_by_id(self, id):
        try:
            query = "SELECT * FROM Prison WHERE prisonerID = %s"
            print(f"Executing query: {query} with ID: {id}")
            self.cursor.execute(query, (id,))
            result = self.cursor.fetchone()
            if result:
                print(f"Prisoner found in database: {result}")
                return Prisoner(*result)
            print("No prisoner found with the given ID.")
            return None
        except Error as e:
            print(f"Error while executing query: {e}")
            return None

    def modify_prisoner(self, prisoner):
        self.cursor.execute(self.update_Query, prisoner.get_update_values())
        self.database.commit()

        return self.cursor.rowcount

    def close(self):
        if self.cursor:
            self.cursor.close()
        if self.database:
            self.database.close()

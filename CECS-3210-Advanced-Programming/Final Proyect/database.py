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
                user="KQuintero",
                password="KQuintero",
                database="prison"
            )

            self.select_all_Query = "SELECT * FROM PrisonDB"
            self.select_by_id_Query = "SELECT * FROM PrisonDB WHERE id = %s"
            self.insert_Query = (
                "INSERT INTO PrisonDB (name, lastname, birthdate, height, hair, eyes, born, sentence, conviction, "
                "liberated) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
            )
            self.update_Query = ("UPDATE PrisonDB SET name = %s, lastname = %s, birthdate = %s, height = %s, "
                                 "hair = %s, eyes = %s, born = %s, sentence = %s, conviction = %s, liberated = %s "
                                 "WHERE id = %s")

            self.cursor = self.database.cursor()

        except Error as e:
            print(e)

    def add_prisoner(self, prison):
        self.cursor.execute(self.insert_Query, prison.get_insert_values())
        self.database.commit()

        return self.cursor.rowcount, self.cursor.lastrowid

    def select_all_prisoners(self):
        self.cursor.execute(self.select_all_Query)
        return self.cursor

    def select_by_id(self, id):
        prisoner = None
        values = (id,)
        self.cursor.execute(self.select_by_id_Query, values)
        myresult = self.cursor.fetchall()

        if len(myresult) > 0:
            for record in myresult:
                id, name, lastname, birthday, height, hair, eyes, born, sentence, conviction, liberated = record
                prisoner = Prisoner(id, name, lastname, birthday, height, hair, eyes, born, sentence, conviction,
                                    liberated)

        return prisoner

    def modify_prisoner(self, prisoner):
        self.cursor.execute(self.update_Query, prisoner.get_update_values())
        self.database.commit()

        return self.cursor.rowcount

    def close(self):
        self.cursor.close()
        self.database.close()

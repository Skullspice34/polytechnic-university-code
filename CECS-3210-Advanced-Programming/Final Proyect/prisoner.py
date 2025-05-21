"""
Author's: Coral S. Schmidt Montilla
          Gabriel O. Gonzales Rios
          Kevin Gabriel Quintero Ramires
Student Numbers: #148830
                 #141406
                 #133009
Filename: prisoner.py
 This file contains the `Prisoner` class, which
 encapsulates information about a single prisoner.
"""


class Prisoner:
    def __init__(self, id, name, lastname, birthday, height, hair, eyes, born, sentence, conviction, liberated):
        self.__id = id
        self.__name = name
        self.__lastname = lastname
        self.__birthday = birthday
        self.__height = height
        self.__hair = hair
        self.__eyes = eyes
        self.__born = born
        self.__sentence = sentence
        self.__conviction = conviction
        self.__liberated = liberated

    # Métodos para obtener los valores de los atributos privados
    def get_id(self):
        return self.__id

    def get_name(self):
        return self.__name

    def get_lastname(self):
        return self.__lastname

    def get_birthdate(self):
        return self.__birthday

    def get_height(self):
        return self.__height

    def get_hair(self):
        return self.__hair

    def get_eyes(self):
        return self.__eyes

    def get_born(self):
        return self.__born

    def get_sentence(self):
        return self.__sentence

    def get_conviction(self):
        return self.__conviction

    def get_liberated(self):
        return self.__liberated

    def set_id(self, id):
        self.__id = id

    def set_name(self, name):
        self.__name = name

    def set_lastname(self, lastname):
        self.__lastname = lastname

    def set_birthdate(self, birthday):
        self.__birthday = birthday

    def set_height(self, height):
        self.__height = height

    def set_hair(self, hair):
        self.__hair = hair

    def set_eyes(self, eyes):
        self.__eyes = eyes

    def set_born(self, born):
        self.__born = born

    def set_sentence(self, sentence):
        self.__sentence = sentence

    def set_conviction(self, conviction):
        self.__conviction = conviction

    def set_liberated(self, liberated):
        self.__liberated = liberated

    def get_insert_values(self):
        return (
            self.__name, self.__lastname, self.__birthday,
            self.__height, self.__hair, self.__eyes,
            self.__born, self.__sentence, self.__conviction,
            self.__liberated
        )

    def get_update_values(self):
        return (
            self.__name, self.__lastname, self.__birthday,
            self.__height, self.__hair, self.__eyes,
            self.__born, self.__sentence, self.__conviction,
            self.__liberated, self.__id
        )

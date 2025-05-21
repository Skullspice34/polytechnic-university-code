class Prisoner:
    def __init__(self, prisonerID, lastName, firstName, photo, birthDate, height, hair, eyes, placeOfBirth, sentence, dateOfConviction, dateToBeLiberated):
        self.__prisonerID = prisonerID
        self.__lastName = lastName
        self.__firstName = firstName
        self.__photo = photo
        self.__birthDate = birthDate  # Direct assignment
        self.__height = height
        self.__hair = hair
        self.__eyes = eyes
        self.__placeOfBirth = placeOfBirth
        self.__sentence = sentence
        self.__dateOfConviction = dateOfConviction  # Direct assignment
        self.__dateToBeLiberated = dateToBeLiberated  # Direct assignment

    # Getter methods
    def get_lastName(self):
        return self.__lastName

    def get_firstName(self):
        return self.__firstName

    def get_photo(self):
        return self.__photo

    def get_birthDate(self):
        return self.__birthDate

    def get_height(self):
        return self.__height

    def get_hair(self):
        return self.__hair

    def get_eyes(self):
        return self.__eyes

    def get_placeOfBirth(self):
        return self.__placeOfBirth

    def get_sentence(self):
        return self.__sentence

    def get_dateOfConviction(self):
        return self.__dateOfConviction

    def get_dateToBeLiberated(self):
        return self.__dateToBeLiberated

    # Setter methods
    def set_id(self, id):
        self.__id = id

    def set_firstName(self, name):
        self.__name = name

    def set_lastname(self, lastname):
        self.__lastname = lastname

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
            self.__firstName, self.__lastName, self.__photo, self.__birthDate,
            self.__height, self.__hair, self.__eyes,
            self.__placeOfBirth, self.__sentence, self.__dateOfConviction,
            self.__dateToBeLiberated,
        )

    def get_update_values(self):
        return (
            self.__lastName, self.__firstName, self.__photo, self.__birthDate,
            self.__height, self.__hair, self.__eyes,
            self.__placeOfBirth, self.__sentence, self.__dateOfConviction,
            self.__dateToBeLiberated, self.__prisonerID
        )
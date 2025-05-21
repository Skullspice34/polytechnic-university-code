
# Class called Prisoner that contains all the attributes of information of a prisoner
class Prisoner:
    def __init__(self, lastName="", firstName="", photo="", birthDate="", height=0.0, hair="",
                 eyes="", placeOfBirth="", sentence="", dateOfConviction="", dateToBeLiberated="",
                 prisonerID=-1):
        self.__lastName = lastName
        self.__firstName = firstName
        self.__photo = photo
        self.__birthDate = birthDate
        self.__height = height
        self.__hair = hair
        self.__eyes = eyes
        self.__placeOfBirth = placeOfBirth
        self.__sentence = sentence
        self.__dateOfConviction = dateOfConviction
        self.__dateToBeLiberated = dateToBeLiberated
        self.__prisonerID = prisonerID

    # Getters

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

    def get_prisonerID(self):
        return self.__prisonerID


    # Setters

    def set_lastName(self, lastName):
        self.__lastName = lastName

    def set_firstName(self, firstName):
        self.__firstName = firstName

    def set_photo(self, photo):
        self.__photo = photo

    def set_birthDate(self, birthDate):
        self.__birthDate = birthDate

    def set_height(self, height):
        self.__height = height

    def set_hair(self, hair):
        self.__hair = hair

    def set_eyes(self, eyes):
        self.__eyes = eyes

    def set_placeOfBirth(self, placeOfBirth):
        self.__placeOfBirth = placeOfBirth

    def set_sentence(self, sentence):
        self.__sentence = sentence

    def set_dateOfConviction(self, dateOfConviction):
        self.__dateOfConviction = dateOfConviction

    def set_dateToBeLiberated(self, dateToBeLiberated):
        self.__dateToBeLiberated = dateToBeLiberated

    def set_prisonerID(self, prisonerID):
        self.__prisonerID = prisonerID


    # Database getters
    def get_update_values(self):
        return self.__lastName, self.__firstName, self.__photo, self.__birthDate,\
            self.__height, self.__hair, self.__eyes, self.__placeOfBirth, self.__sentence,\
            self.__dateOfConviction, self.__dateToBeLiberated, self.__prisonerID

    def get_insert_values(self):
        return self.__lastName, self.__firstName, self.__photo, self.__birthDate,\
            self.__height, self.__hair, self.__eyes, self.__placeOfBirth, self.__sentence,\
            self.__dateOfConviction, self.__dateToBeLiberated

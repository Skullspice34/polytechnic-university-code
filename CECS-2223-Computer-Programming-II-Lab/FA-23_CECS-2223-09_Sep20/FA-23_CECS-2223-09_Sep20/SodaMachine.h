// SodaMachine.h
#pragma once
#include "Sodas.h"

class SodaMachine {
private:
    int sodas; // the size of the array
    Sodas** machine; // the Sodas array
    double totalEarnings; // total earnings of the machine

public:
    SodaMachine();
    SodaMachine(const SodaMachine&);
    ~SodaMachine();
    void addSoda(string, double);
    void sellSoda(const int);
    int getSize() const;
    Sodas** getArray() const;
    void copyArray(Sodas**, const int);
    int findSoda(string) const;
    void printMachine() const;
    double getTotalEarnings() const; // Added to get total earnings
};

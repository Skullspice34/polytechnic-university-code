// SodaMachine.cpp
#include "SodaMachine.h"

SodaMachine::SodaMachine() {
    sodas = 0;
    machine = nullptr;
    totalEarnings = 0.0; // Initialize total earnings to 0
}

SodaMachine::SodaMachine(const SodaMachine& aMachine) {
    sodas = aMachine.getSize();
    machine = new Sodas * [getSize()];
    copyArray(aMachine.getArray(), aMachine.getSize());
    totalEarnings = aMachine.getTotalEarnings(); // Copy total earnings
}

SodaMachine::~SodaMachine() {
    // First release memory allocated to Sodas objects and update total earnings
    for (int i = 0; i < getSize(); i++) {
        totalEarnings -= machine[i]->getPrice();
        machine[i]->~Sodas();
    }
    delete[] machine;
}

void SodaMachine::addSoda(string aName, double aPrice) {
    if (getSize() > 0) { // the array exists
        Sodas** temp = machine;
        machine = new Sodas * [++sodas];
        copyArray(temp, getSize() - 1);
        delete[] temp;
    }
    else { // must create the array
        machine = new Sodas * [++sodas];
    }
    machine[getSize() - 1] = new Sodas(aName, aPrice);
    totalEarnings += aPrice; // Update total earnings
}

void SodaMachine::sellSoda(const int index) {
    if (getSize() > 0 && index < getSize() && index > -1) {
        if (getSize() > 1) {
            totalEarnings -= machine[index]->getPrice(); // Deduct sold soda's price
            machine[index]->~Sodas();
            Sodas** temp = machine;
            machine = new Sodas * [--sodas];
            copyArray(temp, getSize() + 1);
            delete[] temp;
        }
        else {
            totalEarnings -= machine[0]->getPrice(); // Deduct sold soda's price
            machine[0]->~Sodas();
            delete[] machine;
        }
    }
}

double SodaMachine::getTotalEarnings() const {
    return totalEarnings;
}

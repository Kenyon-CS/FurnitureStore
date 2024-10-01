#ifndef TABLE_H
#define TABLE_H

#include "Furniture.h"

class Table : public Furniture {
private:
    int numOfLegs;

public:
    Table(std::string n, double p, int q, int legs)
        : Furniture(n, p, q), numOfLegs(legs) {}
    int getNumOfLegs() const { return numOfLegs; }
    void setNumOfLegs(int legs) { numOfLegs = legs; }
    void display() const override {
        Furniture::display();
        std::cout << "Number of Legs: " << numOfLegs << std::endl;
    }
};
#endif // TABLE_H

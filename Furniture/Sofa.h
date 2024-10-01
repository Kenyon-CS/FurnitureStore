#ifndef SOFA_H
#define SOFA_H
#include "Furniture.h"

class Sofa : public Furniture {
private:
    int numOfSeats;

public:
    Sofa(std::string n, double p, int q, int seats)
        : Furniture(n, p, q), numOfSeats(seats) {}
    int getNumOfSeats() const { return numOfSeats; }
    void setNumOfSeats(int seats) { numOfSeats = seats; }
    void display() const override {
        Furniture::display();
        std::cout << "Number of Seats: " << numOfSeats << std::endl;
    }
};
#endif // SOFA_H

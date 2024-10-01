#ifndef CHAIR_H
#define CHAIR_H
#include "Furniture.h"

class Chair : public Furniture {
private:
    bool hasArmrest;

public:
    Chair(std::string n, double p, int q, bool armrest)
        : Furniture(n, p, q), hasArmrest(armrest) {}

    bool getHasArmrest() const { return hasArmrest; }
    void setHasArmrest(bool armrest) { hasArmrest = armrest; }

    void display() const override {
        Furniture::display();  // Display inherited attributes
        std::cout << "Armrest: " << (hasArmrest ? "Yes" : "No") << std::endl;
    }
};
#endif // CHAIR_H

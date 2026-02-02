#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

/**
 * Level 1: Mammal class inheriting from Animal
 * Adds mammal-specific characteristics
 */
class Mammal : public Animal {
protected:
    bool hasFur;
    std::string furColor;
    int gestationPeriod; // in days

public:
    Mammal(std::string name, int age, double weight,
           bool hasFur, std::string furColor, int gestationPeriod);

    // Override/implement virtual methods
    void displayInfo() const override;
    void performCheckup() override;

    // Mammal-specific methods
    virtual void nurse();
    std::string getFurColor() const;
    bool getHasFur() const;
    int getGestationPeriod() const;
};

#endif // MAMMAL_H

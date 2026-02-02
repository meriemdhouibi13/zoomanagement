#ifndef LION_H
#define LION_H

#include "Mammal.h"

/**
 * Level 2: Lion class - carnivore with pride behavior
 */
class Lion : public Mammal {
private:
    int maneSize; // cm
    bool isAlpha;

public:
    Lion(std::string name, int age, double weight,
         bool hasFur, std::string furColor, int gestationPeriod,
         int maneSize, bool isAlpha);

    // Implement pure virtual methods
    void makeSound() const override;
    void eat() const override;
    std::string getSpecies() const override;

    // Override virtual methods
    void displayInfo() const override;
    void performCheckup() override;
    double calculateFoodRequirement() const override;

    // Lion-specific methods
    void roar() const;
    void hunt() const;

    int getManeSize() const;
    bool getIsAlpha() const;
};

#endif // LION_H

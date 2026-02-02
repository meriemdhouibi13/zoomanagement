#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Mammal.h"

/**
 * Level 2: Elephant class - herbivore with trunk behavior
 */
class Elephant : public Mammal {
private:
    double trunkLength; // meters
    int tuskLength;     // cm
    bool hasIvory;

public:
    Elephant(std::string name, int age, double weight,
             bool hasFur, std::string furColor, int gestationPeriod,
             double trunkLength, int tuskLength, bool hasIvory);

    // Implement pure virtual methods
    void makeSound() const override;
    void eat() const override;
    std::string getSpecies() const override;

    // Override virtual methods
    void displayInfo() const override;
    void performCheckup() override;
    double calculateFoodRequirement() const override;

    // Elephant-specific methods
    void trumpet() const;
    void useTrunk() const;
    void spray() const;

    double getTrunkLength() const;
    int getTuskLength() const;
};

#endif // ELEPHANT_H

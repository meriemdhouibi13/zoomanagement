#ifndef PENGUIN_H
#define PENGUIN_H

#include "Bird.h"

/**
 * Level 2: Penguin class - cannot fly, swimming behavior
 */
class Penguin : public Bird {
private:
    double swimSpeed; // km/h
    double divingDepth; // meters
    std::string species; // e.g., "Emperor", "Adelie"

public:
    Penguin(std::string name, int age, double weight,
            double wingspan, bool canFly, std::string beakType,
            double swimSpeed, double divingDepth, std::string species);

    // Implement pure virtual methods
    void makeSound() const override;
    void eat() const override;
    std::string getSpecies() const override;

    // Override virtual methods
    void displayInfo() const override;
    void performCheckup() override;
    double calculateFoodRequirement() const override;
    void fly() override;

    // Penguin-specific methods
    void swim() const;
    void dive() const;
    void waddle() const;
    void slide() const;

    double getSwimSpeed() const;
    double getDivingDepth() const;
};

#endif // PENGUIN_H

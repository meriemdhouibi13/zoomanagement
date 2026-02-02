#ifndef EAGLE_H
#define EAGLE_H

#include "Bird.h"

/**
 * Level 2: Eagle class - predator with hunting behavior
 */
class Eagle : public Bird {
private:
    double clawLength; // cm
    double visionRange; // meters
    bool isGoldenEagle;

public:
    Eagle(std::string name, int age, double weight,
          double wingspan, bool canFly, std::string beakType,
          double clawLength, double visionRange, bool isGoldenEagle);

    // Implement pure virtual methods
    void makeSound() const override;
    void eat() const override;
    std::string getSpecies() const override;

    // Override virtual methods
    void displayInfo() const override;
    void performCheckup() override;
    double calculateFoodRequirement() const override;
    void fly() override;

    // Eagle-specific methods
    void screech() const;
    void hunt() const;
    void dive() const;

    double getClawLength() const;
    double getVisionRange() const;
};

#endif // EAGLE_H

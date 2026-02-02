#ifndef MONKEY_H
#define MONKEY_H

#include "Mammal.h"

/**
 * Level 2: Monkey class - omnivore with climbing behavior
 */
class Monkey : public Mammal {
private:
    double tailLength; // cm
    bool isPrehensile; // can use tail for grasping
    std::string species; // e.g., "Capuchin", "Spider Monkey"

public:
    Monkey(std::string name, int age, double weight,
           bool hasFur, std::string furColor, int gestationPeriod,
           double tailLength, bool isPrehensile, std::string species);

    // Implement pure virtual methods
    void makeSound() const override;
    void eat() const override;
    std::string getSpecies() const override;

    // Override virtual methods
    void displayInfo() const override;
    void performCheckup() override;
    double calculateFoodRequirement() const override;

    // Monkey-specific methods
    void climb() const;
    void swing() const;
    void playful() const;

    double getTailLength() const;
    bool getIsPrehensile() const;
};

#endif // MONKEY_H

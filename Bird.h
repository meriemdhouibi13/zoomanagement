#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

/**
 * Level 1: Bird class inheriting from Animal
 * Adds bird-specific characteristics
 */
class Bird : public Animal {
protected:
    double wingspan;
    bool canFly;
    std::string beakType;

public:
    Bird(std::string name, int age, double weight,
         double wingspan, bool canFly, std::string beakType);

    void displayInfo() const override;
    void performCheckup() override;

    // Bird-specific methods
    virtual void fly();
    virtual void buildNest();

    double getWingspan() const;
    bool getCanFly() const;
    std::string getBeakType() const;
};

#endif // BIRD_H

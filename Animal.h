#ifndef ANIMAL_H
#define ANIMAL_H

#include "IAnimal.h"
#include <string>

/**
 * Abstract base class implementing common animal functionality
 * Demonstrates encapsulation with protected members and public interface
 */
class Animal : public IAnimal {
protected:
    std::string name;
    int age;
    double weight;
    bool isHealthy;

public:
    Animal(std::string name, int age, double weight);
    virtual ~Animal();

    // Getters and setters (encapsulation)
    std::string getName() const;
    void setName(const std::string& name);

    int getAge() const;
    void setAge(int age);

    double getWeight() const;
    void setWeight(double weight);

    bool getHealthStatus() const;
    void setHealthStatus(bool healthy);

    // Common implementation
    void sleep() const override;

    // Abstract methods (to be implemented by derived classes)
    virtual void makeSound() const override = 0;
    virtual void eat() const override = 0;
    virtual std::string getSpecies() const override = 0;

    // New virtual methods for the sanctuary
    virtual void displayInfo() const;
    virtual void performCheckup();
    virtual double calculateFoodRequirement() const;
};

#endif // ANIMAL_H

#ifndef VETERINARIAN_H
#define VETERINARIAN_H

#include "Animal.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * Observer interface for health notifications
 */
class IHealthObserver {
public:
    virtual void onAnimalSick(Animal* animal) = 0;
    virtual ~IHealthObserver() = default;
};

/**
 * Subject class - Observable Animal that can notify observers
 * Extends Animal functionality with observer pattern
 */
class ObservableAnimal {
private:
    std::vector<IHealthObserver*> observers;
    Animal* animal;

public:
    ObservableAnimal(Animal* a) : animal(a) {}

    void attach(IHealthObserver* observer) {
        observers.push_back(observer);
    }

    void detach(IHealthObserver* observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notifyHealthIssue() {
        std::cout << animal->getName() << " is showing signs of illness!" << std::endl;
        for (IHealthObserver* observer : observers) {
            observer->onAnimalSick(animal);
        }
    }

    Animal* getAnimal() const { return animal; }
};

/**
 * Veterinarian class implementing Observer Pattern
 * Gets notified when animals need medical attention
 */
class Veterinarian : public IHealthObserver {
private:
    std::string name;
    std::string specialization;
    int animalsTeated;

public:
    Veterinarian(const std::string& vetName, const std::string& spec)
        : name(vetName), specialization(spec), animalsTeated(0) {
        std::cout << "Veterinarian " << name << " (" << specialization 
                  << ") is now on duty!" << std::endl;
    }

    // Observer pattern implementation
    void onAnimalSick(Animal* animal) override {
        std::cout << "\n?? ALERT: Dr. " << name << " has been notified!" << std::endl;
        treatAnimal(animal);
    }

    // Treat a sick animal
    void treatAnimal(Animal* animal) {
        std::cout << "Dr. " << name << " is treating " << animal->getName() << "..." << std::endl;
        
        std::cout << "Performing examination..." << std::endl;
        std::cout << "Current health status: " 
                  << (animal->getHealthStatus() ? "Healthy" : "Needs Attention") << std::endl;
        
        std::cout << "Administering medication..." << std::endl;
        std::cout << "Running tests..." << std::endl;
        
        // Cure the animal
        animal->setHealthStatus(true);
        animalsTeated++;
        
        std::cout << "? " << animal->getName() << " has been successfully treated!" << std::endl;
        std::cout << "Health status: " 
                  << (animal->getHealthStatus() ? "Healthy" : "Needs Attention") << std::endl;
    }

    // Perform routine checkup
    void performCheckup(Animal* animal) {
        std::cout << "\nDr. " << name << " performing checkup on " 
                  << animal->getName() << "..." << std::endl;
        animal->performCheckup();
    }

    // Display veterinarian stats
    void displayStats() const {
        std::cout << "\n=== Veterinarian Stats ===" << std::endl;
        std::cout << "Name: Dr. " << name << std::endl;
        std::cout << "Specialization: " << specialization << std::endl;
        std::cout << "Animals treated: " << animalsTeated << std::endl;
    }

    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    int getTreatmentCount() const { return animalsTeated; }
};

#endif // VETERINARIAN_H

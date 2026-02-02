#include "Penguin.h"
#include <iostream>

Penguin::Penguin(std::string name, int age, double weight,
                 double wingspan, bool canFly, std::string beakType,
                 double swimSpeed, double divingDepth, std::string species)
    : Bird(name, age, weight, wingspan, canFly, beakType),
      swimSpeed(swimSpeed), divingDepth(divingDepth), species(species) {
}

void Penguin::makeSound() const {
    std::cout << name << " says: HONK HONK!" << std::endl;
}

void Penguin::eat() const {
    std::cout << name << " is eating fresh fish and krill." << std::endl;
}

std::string Penguin::getSpecies() const {
    return "Penguin (" + species + ")";
}

void Penguin::displayInfo() const {
    std::cout << "\n=== PENGUIN ===" << std::endl;
    Bird::displayInfo();
    std::cout << "Species: " << species << std::endl;
    std::cout << "Swim Speed: " << swimSpeed << " km/h" << std::endl;
    std::cout << "Diving Depth: " << divingDepth << " meters" << std::endl;
}

void Penguin::performCheckup() {
    Bird::performCheckup();
    std::cout << "Checking waterproofing of feathers and flipper strength..." << std::endl;
    if (weight < 10) {
        isHealthy = false;
        std::cout << name << " needs vitamin supplements!" << std::endl;
    } else {
        std::cout << "Penguin " << name << " is healthy!" << std::endl;
    }
}

double Penguin::calculateFoodRequirement() const {
    // Penguins need about 10% of body weight in fish
    return weight * 0.10;
}

void Penguin::fly() {
    std::cout << name << " cannot fly in the air, but flies through the water!" << std::endl;
}

void Penguin::swim() const {
    std::cout << name << " swims gracefully at " << swimSpeed << " km/h!" << std::endl;
}

void Penguin::dive() const {
    std::cout << name << " dives down to " << divingDepth << " meters to catch fish!" << std::endl;
}

void Penguin::waddle() const {
    std::cout << name << " waddles adorably on the ice!" << std::endl;
}

void Penguin::slide() const {
    std::cout << name << " slides on its belly across the ice! Wheee!" << std::endl;
}

double Penguin::getSwimSpeed() const {
    return swimSpeed;
}

double Penguin::getDivingDepth() const {
    return divingDepth;
}

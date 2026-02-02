#include "Eagle.h"
#include <iostream>

Eagle::Eagle(std::string name, int age, double weight,
             double wingspan, bool canFly, std::string beakType,
             double clawLength, double visionRange, bool isGoldenEagle)
    : Bird(name, age, weight, wingspan, canFly, beakType),
      clawLength(clawLength), visionRange(visionRange), isGoldenEagle(isGoldenEagle) {
}

void Eagle::makeSound() const {
    std::cout << name << " says: SCREEEECH!" << std::endl;
}

void Eagle::eat() const {
    std::cout << name << " is eating fresh fish and small mammals." << std::endl;
}

std::string Eagle::getSpecies() const {
    return isGoldenEagle ? "Golden Eagle" : "Eagle";
}

void Eagle::displayInfo() const {
    std::cout << "\n=== EAGLE ===" << std::endl;
    Bird::displayInfo();
    std::cout << "Type: " << (isGoldenEagle ? "Golden Eagle" : "Bald Eagle") << std::endl;
    std::cout << "Claw Length: " << clawLength << " cm" << std::endl;
    std::cout << "Vision Range: " << visionRange << " meters" << std::endl;
}

void Eagle::performCheckup() {
    Bird::performCheckup();
    std::cout << "Checking talons and eyesight..." << std::endl;
    std::cout << "Eagle " << name << " is ready to soar!" << std::endl;
}

double Eagle::calculateFoodRequirement() const {
    // Eagles need about 10% of body weight in meat
    return weight * 0.10;
}

void Eagle::fly() {
    std::cout << name << " soars majestically at high altitudes!" << std::endl;
}

void Eagle::screech() const {
    std::cout << name << " screeches powerfully: SCREEEECH!" << std::endl;
}

void Eagle::hunt() const {
    std::cout << name << " spots prey from " << visionRange << " meters away and prepares to strike!" << std::endl;
}

void Eagle::dive() const {
    std::cout << name << " dives at incredible speed to catch its prey!" << std::endl;
}

double Eagle::getClawLength() const {
    return clawLength;
}

double Eagle::getVisionRange() const {
    return visionRange;
}

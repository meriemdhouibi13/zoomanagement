#include "Elephant.h"
#include <iostream>

Elephant::Elephant(std::string name, int age, double weight,
                   bool hasFur, std::string furColor, int gestationPeriod,
                   double trunkLength, int tuskLength, bool hasIvory)
    : Mammal(name, age, weight, hasFur, furColor, gestationPeriod),
      trunkLength(trunkLength), tuskLength(tuskLength), hasIvory(hasIvory) {
}

void Elephant::makeSound() const {
    std::cout << name << " says: PAAAHROOOO!" << std::endl;
}

void Elephant::eat() const {
    std::cout << name << " is munching on hay, leaves, and fruits." << std::endl;
}

std::string Elephant::getSpecies() const {
    return "Elephant";
}

void Elephant::displayInfo() const {
    std::cout << "\n=== ELEPHANT ===" << std::endl;
    Mammal::displayInfo();
    std::cout << "Trunk Length: " << trunkLength << " meters" << std::endl;
    std::cout << "Tusk Length: " << tuskLength << " cm" << std::endl;
    std::cout << "Has Ivory: " << (hasIvory ? "Yes" : "No") << std::endl;
}

void Elephant::performCheckup() {
    Mammal::performCheckup();
    std::cout << "Checking trunk flexibility and foot health..." << std::endl;
    std::cout << "Elephant " << name << " is healthy!" << std::endl;
}

double Elephant::calculateFoodRequirement() const {
    // Elephants need about 4-5% of body weight in vegetation
    return weight * 0.045;
}

void Elephant::trumpet() const {
    std::cout << name << " raises trunk and trumpets loudly: PAAAHROOOO!" << std::endl;
}

void Elephant::useTrunk() const {
    std::cout << name << " uses its versatile trunk to pick up objects." << std::endl;
}

void Elephant::spray() const {
    std::cout << name << " sprays water with its trunk for a refreshing bath!" << std::endl;
}

double Elephant::getTrunkLength() const {
    return trunkLength;
}

int Elephant::getTuskLength() const {
    return tuskLength;
}

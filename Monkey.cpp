#include "Monkey.h"
#include <iostream>

Monkey::Monkey(std::string name, int age, double weight,
               bool hasFur, std::string furColor, int gestationPeriod,
               double tailLength, bool isPrehensile, std::string species)
    : Mammal(name, age, weight, hasFur, furColor, gestationPeriod),
      tailLength(tailLength), isPrehensile(isPrehensile), species(species) {
}

void Monkey::makeSound() const {
    std::cout << name << " says: Ooh ooh ah ah!" << std::endl;
}

void Monkey::eat() const {
    std::cout << name << " is eating bananas, fruits, and insects." << std::endl;
}

std::string Monkey::getSpecies() const {
    return "Monkey (" + species + ")";
}

void Monkey::displayInfo() const {
    std::cout << "\n=== MONKEY ===" << std::endl;
    Mammal::displayInfo();
    std::cout << "Species: " << species << std::endl;
    std::cout << "Tail Length: " << tailLength << " cm" << std::endl;
    std::cout << "Prehensile Tail: " << (isPrehensile ? "Yes" : "No") << std::endl;
}

void Monkey::performCheckup() {
    Mammal::performCheckup();
    std::cout << "Checking agility and tail flexibility..." << std::endl;
    std::cout << "Monkey " << name << " is energetic and healthy!" << std::endl;
}

double Monkey::calculateFoodRequirement() const {
    // Monkeys need about 3% of body weight in mixed diet
    return weight * 0.03;
}

void Monkey::climb() const {
    std::cout << name << " is climbing trees with incredible agility!" << std::endl;
}

void Monkey::swing() const {
    std::cout << name << " is swinging from branch to branch!" << std::endl;
}

void Monkey::playful() const {
    std::cout << name << " is playing and being mischievous!" << std::endl;
}

double Monkey::getTailLength() const {
    return tailLength;
}

bool Monkey::getIsPrehensile() const {
    return isPrehensile;
}

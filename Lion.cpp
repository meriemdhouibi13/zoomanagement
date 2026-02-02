#include "Lion.h"
#include <iostream>

Lion::Lion(std::string name, int age, double weight,
           bool hasFur, std::string furColor, int gestationPeriod,
           int maneSize, bool isAlpha)
    : Mammal(name, age, weight, hasFur, furColor, gestationPeriod),
      maneSize(maneSize), isAlpha(isAlpha) {
}

void Lion::makeSound() const {
    std::cout << name << " says: ROOOAAAR!" << std::endl;
}

void Lion::eat() const {
    std::cout << name << " is eating fresh meat." << std::endl;
}

std::string Lion::getSpecies() const {
    return "Lion";
}

void Lion::displayInfo() const {
    std::cout << "\n=== LION ===" << std::endl;
    Mammal::displayInfo();
    std::cout << "Mane Size: " << maneSize << " cm" << std::endl;
    std::cout << "Pride Status: " << (isAlpha ? "Alpha" : "Member") << std::endl;
}

void Lion::performCheckup() {
    Mammal::performCheckup();
    std::cout << "Checking teeth and mane condition..." << std::endl;
    std::cout << "Lion " << name << " is in good health!" << std::endl;
}

double Lion::calculateFoodRequirement() const {
    // Lions need about 5% of their body weight in meat
    return weight * 0.05;
}

void Lion::roar() const {
    std::cout << name << " lets out a mighty ROAR that echoes across the savanna!" << std::endl;
}

void Lion::hunt() const {
    std::cout << name << " is stalking prey with stealth and power..." << std::endl;
}

int Lion::getManeSize() const {
    return maneSize;
}

bool Lion::getIsAlpha() const {
    return isAlpha;
}

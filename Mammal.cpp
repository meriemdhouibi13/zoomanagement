#include "Mammal.h"
#include <iostream>

Mammal::Mammal(std::string name, int age, double weight,
               bool hasFur, std::string furColor, int gestationPeriod)
    : Animal(name, age, weight), hasFur(hasFur), furColor(furColor),
      gestationPeriod(gestationPeriod) {
}


void Mammal::displayInfo() const {
    Animal::displayInfo();
    std::cout << "Has Fur: " << (hasFur ? "Yes" : "No") << std::endl;
    if (hasFur) {
        std::cout << "Fur Color: " << furColor << std::endl;
    }
    std::cout << "Gestation Period: " << gestationPeriod << " days" << std::endl;
}

void Mammal::performCheckup() {
    Animal::performCheckup();
    std::cout << "Checking fur condition and temperature..." << std::endl;
}

void Mammal::nurse() {
    std::cout << name << " is nursing its young." << std::endl;
}

std::string Mammal::getFurColor() const {
    return furColor;
}

bool Mammal::getHasFur() const {
    return hasFur;
}

int Mammal::getGestationPeriod() const {
    return gestationPeriod;
}

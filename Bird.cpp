#include "Bird.h"
#include <iostream>

Bird::Bird(std::string name, int age, double weight,
           double wingspan, bool canFly, std::string beakType)
    : Animal(name, age, weight), wingspan(wingspan), canFly(canFly),
      beakType(beakType) {
}

void Bird::displayInfo() const {
    Animal::displayInfo();
    std::cout << "Wingspan: " << wingspan << " meters" << std::endl;
    std::cout << "Can Fly: " << (canFly ? "Yes" : "No") << std::endl;
    std::cout << "Beak Type: " << beakType << std::endl;
}

void Bird::performCheckup() {
    Animal::performCheckup();
    std::cout << "Checking feather condition and wing strength..." << std::endl;
}

void Bird::fly() {
    if (canFly) {
        std::cout << name << " is soaring through the sky!" << std::endl;
    } else {
        std::cout << name << " cannot fly." << std::endl;
    }
}

void Bird::buildNest() {
    std::cout << name << " is building a nest." << std::endl;
}

double Bird::getWingspan() const {
    return wingspan;
}

bool Bird::getCanFly() const {
    return canFly;
}

std::string Bird::getBeakType() const {
    return beakType;
}

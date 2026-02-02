#include "Animal.h"
#include <iostream>

Animal::Animal(std::string name, int age, double weight)
    : name(name), age(age), weight(weight), isHealthy(true) {
}

Animal::~Animal() {
    // Virtual destructor ensures proper cleanup in derived classes
}

std::string Animal::getName() const {
    return name;
}

void Animal::setName(const std::string& name) {
    this->name = name;
}

int Animal::getAge() const {
    return age;
}

void Animal::setAge(int age) {
    if (age >= 0) {
        this->age = age;
    }
}

double Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(double weight) {
    if (weight > 0) {
        this->weight = weight;
    }
}

bool Animal::getHealthStatus() const {
    return isHealthy;
}

void Animal::setHealthStatus(bool healthy) {
    isHealthy = healthy;
}

void Animal::sleep() const {
    std::cout << name << " is sleeping peacefully... Zzz" << std::endl;
}

void Animal::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Health Status: " << (isHealthy ? "Healthy" : "Needs Attention") << std::endl;
}

void Animal::performCheckup() {
    std::cout << "Performing checkup on " << name << "..." << std::endl;
    // Basic checkup logic
    isHealthy = true;
}

double Animal::calculateFoodRequirement() const {
    // Base calculation: 5% of body weight
    return weight * 0.05;
}

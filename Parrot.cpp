#include "Parrot.h"
#include <iostream>

Parrot::Parrot(std::string name, int age, double weight,
               double wingspan, bool canFly, std::string beakType,
               std::string plumageColor, int intelligenceLevel)
    : Bird(name, age, weight, wingspan, canFly, beakType),
      plumageColor(plumageColor), intelligenceLevel(intelligenceLevel) {
    // Initialize with basic vocabulary
    vocabulary.push_back("Hello!");
    vocabulary.push_back("Pretty bird!");
}

void Parrot::makeSound() const {
    std::cout << name << " says: SQUAWK! SQUAWK!" << std::endl;
}

void Parrot::eat() const {
    std::cout << name << " is eating seeds, nuts, and fruits." << std::endl;
}

std::string Parrot::getSpecies() const {
    return "Parrot";
}

void Parrot::displayInfo() const {
    std::cout << "\n=== PARROT ===" << std::endl;
    Bird::displayInfo();
    std::cout << "Plumage Color: " << plumageColor << std::endl;
    std::cout << "Intelligence Level: " << intelligenceLevel << "/10" << std::endl;
    std::cout << "Vocabulary Size: " << vocabulary.size() << " words" << std::endl;
}

void Parrot::performCheckup() {
    Bird::performCheckup();
    std::cout << "Checking beak condition and mental stimulation..." << std::endl;
    std::cout << "Parrot " << name << " is bright and healthy!" << std::endl;
}

double Parrot::calculateFoodRequirement() const {
    // Parrots need about 8% of body weight in seeds and fruits
    return weight * 0.08;
}

void Parrot::mimic(const std::string& phrase) {
    std::cout << name << " mimics: \"" << phrase << "\"" << std::endl;
}

void Parrot::learnWord(const std::string& word) {
    vocabulary.push_back(word);
    std::cout << name << " learned a new word: \"" << word << "\"" << std::endl;
}

void Parrot::showVocabulary() const {
    std::cout << name << "'s vocabulary: ";
    for (size_t i = 0; i < vocabulary.size(); ++i) {
        std::cout << vocabulary[i];
        if (i < vocabulary.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void Parrot::talk() const {
    if (!vocabulary.empty()) {
        int randomIndex = rand() % vocabulary.size();
        std::cout << name << " says: \"" << vocabulary[randomIndex] << "\"" << std::endl;
    }
}

std::string Parrot::getPlumageColor() const {
    return plumageColor;
}

int Parrot::getIntelligenceLevel() const {
    return intelligenceLevel;
}

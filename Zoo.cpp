#include "Zoo.h"
#include "Exceptions.h"
#include "Lion.h"
#include "Elephant.h"
#include "Monkey.h"
#include "Eagle.h"
#include "Penguin.h"
#include "Parrot.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Zoo::Zoo(std::string name, int capacity)
    : zooName(name), capacity(capacity) {
    std::cout << "Creating zoo: " << zooName << " (Capacity: " << capacity << ")" << std::endl;
}

Zoo::~Zoo() {
    cleanup();
}

// Copy constructor (Rule of Three)
Zoo::Zoo(const Zoo& other)
    : zooName(other.zooName + "_copy"), capacity(other.capacity) {
    deepCopy(other);
}

// Copy assignment operator (Rule of Three)
Zoo& Zoo::operator=(const Zoo& other) {
    if (this != &other) {
        cleanup();
        zooName = other.zooName + "_copy";
        capacity = other.capacity;
        deepCopy(other);
    }
    return *this;
}

void Zoo::deepCopy(const Zoo& other) {
    // Note: Deep copy would require cloneable interface
    // For simplicity, we'll do a shallow copy warning
    std::cout << "Warning: Zoo copy constructor performs shallow copy of animal pointers." << std::endl;
    animals = other.animals;
}

void Zoo::cleanup() {
    for (IAnimal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

void Zoo::addAnimal(IAnimal* animal) {
    if (animals.size() >= static_cast<size_t>(capacity)) {
        throw ZooFullException(capacity);
    }
    if (animal == nullptr) {
        throw InvalidOperationException("Cannot add null animal");
    }
    animals.push_back(animal);
    std::cout << "Added " << animal->getSpecies() << " named " 
              << dynamic_cast<Animal*>(animal)->getName() << " to the zoo." << std::endl;
}

void Zoo::removeAnimal(const std::string& name) {
    auto it = std::find_if(animals.begin(), animals.end(),
        [&name](IAnimal* animal) {
            Animal* a = dynamic_cast<Animal*>(animal);
            return a && a->getName() == name;
        });
    
    if (it == animals.end()) {
        throw AnimalNotFoundException(name);
    }
    
    std::cout << "Removing " << (*it)->getSpecies() << " named " << name << std::endl;
    delete *it;
    animals.erase(it);
}

void Zoo::makeAllSounds() const {
    std::cout << "\n=== All Animals Making Sounds ===" << std::endl;
    for (const IAnimal* animal : animals) {
        animal->makeSound();
    }
}

void Zoo::feedAllAnimals() const {
    std::cout << "\n=== Feeding Time ===" << std::endl;
    for (const IAnimal* animal : animals) {
        animal->eat();
    }
}

void Zoo::performDailyCheckups() {
    std::cout << "\n=== Daily Checkups ===" << std::endl;
    for (IAnimal* animal : animals) {
        Animal* a = dynamic_cast<Animal*>(animal);
        if (a) {
            a->performCheckup();
            std::cout << std::endl;
        }
    }
}

void Zoo::displayAllAnimals() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "=== Animals in " << zooName << " ===" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (animals.empty()) {
        std::cout << "No animals in the zoo yet." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < animals.size(); ++i) {
        const Animal* animal = dynamic_cast<const Animal*>(animals[i]);
        if (animal) {
            std::cout << "\n[" << (i + 1) << "] ";
            animal->displayInfo();
            std::cout << "Food required: " << animal->calculateFoodRequirement() << " kg" << std::endl;
        }
    }
    
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "Total animals: " << animals.size() << std::endl;
    std::cout << "Total food required today: " << calculateTotalFoodRequirement() << " kg" << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void Zoo::displayBySpecies(const std::string& species) const {
    std::cout << "\n=== " << species << "s in the zoo ===" << std::endl;
    bool found = false;
    
    for (const IAnimal* animal : animals) {
        if (animal->getSpecies() == species) {
            const Animal* a = dynamic_cast<const Animal*>(animal);
            if (a) {
                a->displayInfo();
                std::cout << std::endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        std::cout << "No " << species << "s found in the zoo." << std::endl;
    }
}

int Zoo::getAnimalCount() const {
    return animals.size();
}

int Zoo::countBySpecies(const std::string& species) const {
    int count = 0;
    for (const IAnimal* animal : animals) {
        if (animal->getSpecies() == species) {
            count++;
        }
    }
    return count;
}

double Zoo::calculateTotalFoodRequirement() const {
    double total = 0.0;
    for (const IAnimal* animal : animals) {
        const Animal* a = dynamic_cast<const Animal*>(animal);
        if (a) {
            total += a->calculateFoodRequirement();
        }
    }
    return total;
}

IAnimal* Zoo::findAnimal(const std::string& name) const {
    for (const IAnimal* animal : animals) {
        const Animal* a = dynamic_cast<const Animal*>(animal);
        if (a && a->getName() == name) {
            return const_cast<IAnimal*>(animal);
        }
    }
    throw AnimalNotFoundException(name);
}

void Zoo::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw InvalidOperationException("Cannot open file for writing: " + filename);
    }
    
    outFile << zooName << std::endl;
    outFile << capacity << std::endl;
    outFile << animals.size() << std::endl;
    
    for (const IAnimal* animal : animals) {
        const Animal* a = dynamic_cast<const Animal*>(animal);
        if (a) {
            outFile << a->getSpecies() << "|"
                    << a->getName() << "|"
                    << a->getAge() << "|"
                    << a->getWeight() << "|"
                    << a->getHealthStatus() << std::endl;
        }
    }
    
    outFile.close();
    std::cout << "Zoo data saved to " << filename << std::endl;
}

void Zoo::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw InvalidOperationException("Cannot open file for reading: " + filename);
    }
    
    cleanup();
    
    std::getline(inFile, zooName);
    inFile >> capacity;
    
    int animalCount;
    inFile >> animalCount;
    inFile.ignore(); // Ignore newline
    
    std::cout << "Loading " << animalCount << " animals from " << filename << "..." << std::endl;
    std::cout << "Note: Detailed animal attributes are not saved in this simple format." << std::endl;
    
    inFile.close();
    std::cout << "Zoo data loaded from " << filename << std::endl;
}

std::string Zoo::getZooName() const {
    return zooName;
}

int Zoo::getCapacity() const {
    return capacity;
}

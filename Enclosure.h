#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Animal.h"
#include <vector>
#include <string>
#include <type_traits>
#include <iostream>
#include <algorithm>

/**
 * Template-based Enclosure for type-specific animal management
 * Uses static_assert to ensure only Animal-derived types can be used
 * Demonstrates advanced C++ templates and type safety
 */
template <typename T>
class Enclosure {
    static_assert(std::is_base_of<Animal, T>::value, 
                  "T must derive from Animal");

private:
    std::string enclosureName;
    int capacity;
    std::vector<T*> animals;

public:
    Enclosure(const std::string& name, int cap) 
        : enclosureName(name), capacity(cap) {
        std::cout << "Creating " << name << " enclosure (Capacity: " << capacity << ")" << std::endl;
    }

    ~Enclosure() {
        for (T* animal : animals) {
            delete animal;
        }
        animals.clear();
    }

    // Add animal to enclosure
    void addAnimal(T* animal) {
        if (animals.size() >= static_cast<size_t>(capacity)) {
            throw std::runtime_error("Enclosure is full!");
        }
        if (animal == nullptr) {
            throw std::runtime_error("Cannot add null animal");
        }
        animals.push_back(animal);
        std::cout << "Added " << animal->getName() << " to " << enclosureName << std::endl;
    }

    // Remove animal by name
    void removeAnimal(const std::string& name) {
        auto it = std::find_if(animals.begin(), animals.end(),
            [&name](T* animal) {
                return animal->getName() == name;
            });
        
        if (it == animals.end()) {
            throw std::runtime_error("Animal not found in enclosure");
        }
        
        std::cout << "Removing " << (*it)->getName() << " from " << enclosureName << std::endl;
        delete *it;
        animals.erase(it);
    }

    // Get all animals in enclosure
    const std::vector<T*>& getAnimals() const {
        return animals;
    }

    // Display all animals in enclosure
    void displayAnimals() const {
        std::cout << "\n=== " << enclosureName << " ===" << std::endl;
        std::cout << "Animals: " << animals.size() << "/" << capacity << std::endl;
        
        if (animals.empty()) {
            std::cout << "No animals in this enclosure." << std::endl;
            return;
        }
        
        for (size_t i = 0; i < animals.size(); ++i) {
            std::cout << "\n[" << (i + 1) << "] ";
            animals[i]->displayInfo();
        }
    }

    // Count animals
    int getAnimalCount() const {
        return animals.size();
    }

    // Get enclosure name
    std::string getName() const {
        return enclosureName;
    }

    // Calculate total food requirement for all animals in enclosure
    double calculateTotalFoodRequirement() const {
        double total = 0.0;
        for (const T* animal : animals) {
            total += animal->calculateFoodRequirement();
        }
        return total;
    }

    // Make all animals in enclosure sound
    void makeAllSounds() const {
        std::cout << "\n=== Animals in " << enclosureName << " making sounds ===" << std::endl;
        for (const T* animal : animals) {
            animal->makeSound();
        }
    }

    // Feed all animals in enclosure
    void feedAll() const {
        std::cout << "\n=== Feeding animals in " << enclosureName << " ===" << std::endl;
        for (const T* animal : animals) {
            animal->eat();
        }
    }
};

#endif // ENCLOSURE_H

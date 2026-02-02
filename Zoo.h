#ifndef ZOO_H
#define ZOO_H

#include "IAnimal.h"
#include <vector>
#include <string>

/**
 * Zoo management class demonstrating polymorphism
 * Implements Rule of Three for proper resource management
 */
class Zoo {
private:
    std::vector<IAnimal*> animals;
    std::string zooName;
    int capacity;

    // Helper function for deep copy
    void deepCopy(const Zoo& other);
    void cleanup();

public:
    Zoo(std::string name, int capacity);
    ~Zoo();

    // Rule of Three: Copy constructor and copy assignment
    Zoo(const Zoo& other);
    Zoo& operator=(const Zoo& other);

    // Animal management
    void addAnimal(IAnimal* animal);
    void removeAnimal(const std::string& name);

    // Polymorphic operations
    void makeAllSounds() const;
    void feedAllAnimals() const;
    void performDailyCheckups();

    // Display functions
    void displayAllAnimals() const;
    void displayBySpecies(const std::string& species) const;

    // Statistics
    int getAnimalCount() const;
    int countBySpecies(const std::string& species) const;
    double calculateTotalFoodRequirement() const;

    // Find animal
    IAnimal* findAnimal(const std::string& name) const;

    // File I/O
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Getters
    std::string getZooName() const;
    int getCapacity() const;
};

#endif // ZOO_H

#ifndef ANIMALFACTORY_H
#define ANIMALFACTORY_H

#include "IAnimal.h"
#include "Lion.h"
#include "Elephant.h"
#include "Monkey.h"
#include "Eagle.h"
#include "Penguin.h"
#include "Parrot.h"
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <iostream>

/**
 * Factory Pattern implementation for creating animals
 * Centralizes animal creation logic and provides a clean interface
 * Supports creating animals from string input
 */
class AnimalFactory {
public:
    /**
     * Create an animal based on species name
     * Returns a pointer to the created animal
     */
    static IAnimal* createAnimal(const std::string& species, 
                                  const std::string& name,
                                  int age,
                                  double weight) {
        
        std::string lowerSpecies = toLower(species);
        
        if (lowerSpecies == "lion") {
            return new Lion(name, age, weight, 
                          true, "Golden", 110,    // hasFur, furColor, gestationPeriod
                          20, false);              // maneSize, isAlpha
        }
        else if (lowerSpecies == "elephant") {
            return new Elephant(name, age, weight,
                              false, "Gray", 660,  // hasFur, furColor, gestationPeriod
                              1.5, 100, true);     // trunkLength, tuskLength, isAfrican
        }
        else if (lowerSpecies == "monkey") {
            return new Monkey(name, age, weight,
                            true, "Brown", 160,    // hasFur, furColor, gestationPeriod
                            50, true, "Capuchin"); // tailLength, isArboreal, monkeyType
        }
        else if (lowerSpecies == "eagle") {
            return new Eagle(name, age, weight,
                           2.0, true, "Hooked",    // wingspan, canFly, beakType
                           7.0, 3000, false);      // clawLength, flyingAltitude, isBald
        }
        else if (lowerSpecies == "penguin") {
            return new Penguin(name, age, weight,
                             0.4, false, "Small",  // wingspan, canFly, beakType
                             8, 150, "Emperor");   // divingDepth, swimSpeed, penguinSpecies
        }
        else if (lowerSpecies == "parrot") {
            return new Parrot(name, age, weight,
                            0.5, true, "Curved",   // wingspan, canFly, beakType
                            "Green", 8);           // featherColor, vocabularySize
        }
        else {
            throw std::invalid_argument("Unknown species: " + species);
        }
    }

    /**
     * Create a random animal with default values
     */
    static IAnimal* createRandomAnimal(const std::string& species) {
        return createAnimal(species, "Random_" + species, 3, 50.0);
    }

    /**
     * Create an animal with custom attributes (advanced)
     */
    static Lion* createLion(const std::string& name, int age, double weight,
                           bool hasFur, const std::string& furColor,
                           int gestationPeriod, int maneSize, bool isAlpha) {
        return new Lion(name, age, weight, hasFur, furColor, 
                       gestationPeriod, maneSize, isAlpha);
    }

    static Elephant* createElephant(const std::string& name, int age, double weight,
                                   bool hasFur, const std::string& furColor,
                                   int gestationPeriod, double trunkLength,
                                   double tuskLength, bool isAfrican) {
        return new Elephant(name, age, weight, hasFur, furColor,
                          gestationPeriod, trunkLength, tuskLength, isAfrican);
    }

    static Monkey* createMonkey(const std::string& name, int age, double weight,
                               bool hasFur, const std::string& furColor,
                               int gestationPeriod, int tailLength,
                               bool isArboreal, const std::string& monkeyType) {
        return new Monkey(name, age, weight, hasFur, furColor,
                        gestationPeriod, tailLength, isArboreal, monkeyType);
    }

    static Eagle* createEagle(const std::string& name, int age, double weight,
                             double wingspan, bool canFly, const std::string& beakType,
                             double clawLength, int flyingAltitude, bool isBald) {
        return new Eagle(name, age, weight, wingspan, canFly, beakType,
                       clawLength, flyingAltitude, isBald);
    }

    static Penguin* createPenguin(const std::string& name, int age, double weight,
                                 double wingspan, bool canFly, const std::string& beakType,
                                 int divingDepth, int swimSpeed, const std::string& species) {
        return new Penguin(name, age, weight, wingspan, canFly, beakType,
                         divingDepth, swimSpeed, species);
    }

    static Parrot* createParrot(const std::string& name, int age, double weight,
                               double wingspan, bool canFly, const std::string& beakType,
                               const std::string& featherColor, int vocabularySize) {
        return new Parrot(name, age, weight, wingspan, canFly, beakType,
                        featherColor, vocabularySize);
    }

    /**
     * List all available species
     */
    static void listAvailableSpecies() {
        std::cout << "\n=== Available Species ===" << std::endl;
        std::cout << "1. Lion" << std::endl;
        std::cout << "2. Elephant" << std::endl;
        std::cout << "3. Monkey" << std::endl;
        std::cout << "4. Eagle" << std::endl;
        std::cout << "5. Penguin" << std::endl;
        std::cout << "6. Parrot" << std::endl;
    }

private:
    // Helper function to convert string to lowercase
    static std::string toLower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(),
                      [](unsigned char c) { return std::tolower(c); });
        return str;
    }
};

#endif // ANIMALFACTORY_H

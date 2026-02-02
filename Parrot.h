#ifndef PARROT_H
#define PARROT_H

#include "Bird.h"
#include <vector>

/**
 * Level 2: Parrot class - can mimic sounds
 */
class Parrot : public Bird {
private:
    std::vector<std::string> vocabulary;
    std::string plumageColor;
    int intelligenceLevel; // 1-10

public:
    Parrot(std::string name, int age, double weight,
           double wingspan, bool canFly, std::string beakType,
           std::string plumageColor, int intelligenceLevel);

    // Implement pure virtual methods
    void makeSound() const override;
    void eat() const override;
    std::string getSpecies() const override;

    // Override virtual methods
    void displayInfo() const override;
    void performCheckup() override;
    double calculateFoodRequirement() const override;

    // Parrot-specific methods
    void mimic(const std::string& phrase);
    void learnWord(const std::string& word);
    void showVocabulary() const;
    void talk() const;

    std::string getPlumageColor() const;
    int getIntelligenceLevel() const;
};

#endif // PARROT_H

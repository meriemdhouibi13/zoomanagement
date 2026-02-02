#ifndef IANIMAL_H
#define IANIMAL_H

#include <string>

/**
 * Interface (abstract class) defining what every animal must be able to do
 * Pure virtual functions enforce implementation in derived classes
 */
class IAnimal {
public:
    virtual void makeSound() const = 0;
    virtual void eat() const = 0;
    virtual void sleep() const = 0;
    virtual std::string getSpecies() const = 0;
    virtual ~IAnimal() = default;
};

#endif // IANIMAL_H

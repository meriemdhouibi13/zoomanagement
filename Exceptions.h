#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

/**
 * Custom exception for when an animal is not found in the zoo
 */
class AnimalNotFoundException : public std::exception {
private:
    std::string message;
public:
    explicit AnimalNotFoundException(const std::string& animalName)
        : message("Animal not found: " + animalName) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

/**
 * Custom exception for when the zoo is at full capacity
 */
class ZooFullException : public std::exception {
private:
    std::string message;
public:
    explicit ZooFullException(int capacity)
        : message("Zoo is full! Maximum capacity: " + std::to_string(capacity)) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

/**
 * Custom exception for invalid operations
 */
class InvalidOperationException : public std::exception {
private:
    std::string message;
public:
    explicit InvalidOperationException(const std::string& msg)
        : message("Invalid operation: " + msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // EXCEPTIONS_H

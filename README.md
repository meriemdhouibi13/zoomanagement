# Wildlife Sanctuary Simulator - C++ Zoo Management System

## Project Overview
This project is a comprehensive C++ application demonstrating Object-Oriented Programming principles including inheritance, polymorphism, encapsulation, and dynamic memory management. It simulates a wildlife sanctuary with various animal types and management operations.

## Features Implemented

### Core OOP Concepts
- **Interface (Abstract Class)**: `IAnimal` defines the contract for all animals
- **Multi-level Inheritance**: Animal → Mammal/Bird → Specific Animals
- **Polymorphism**: Virtual functions enable runtime behavior customization
- **Encapsulation**: Private/protected members with public getters/setters
- **Virtual Destructors**: Proper cleanup of derived classes

### Class Hierarchy
```
IAnimal (Interface)
    ↓
Animal (Abstract Base)
    ↓
    ├── Mammal
    │   ├── Lion (carnivore, pride behavior)
    │   ├── Elephant (herbivore, trunk behavior)
    │   └── Monkey (omnivore, climbing behavior)
    │
    └── Bird
        ├── Eagle (predator, hunting behavior)
        ├── Penguin (cannot fly, swimming behavior)
        └── Parrot (can mimic sounds)
```

### Zoo Management Features
- Add/remove animals
- Display all animals or filter by species
- Polymorphic operations (sounds, feeding, checkups)
- Calculate food requirements
- Search for animals by name
- Save/load zoo state to/from file
- Special care based on animal type (dynamic casting)

### Exception Handling
- `AnimalNotFoundException`
- `ZooFullException`
- `InvalidOperationException`

## File Structure
```
zoomanagement/
├── IAnimal.h              # Interface definition
├── Animal.h/cpp           # Base class
├── Mammal.h/cpp           # Intermediate class
├── Bird.h/cpp             # Intermediate class
├── Lion.h/cpp             # Concrete animal
├── Elephant.h/cpp         # Concrete animal
├── Monkey.h/cpp           # Concrete animal
├── Eagle.h/cpp            # Concrete animal
├── Penguin.h/cpp          # Concrete animal
├── Parrot.h/cpp           # Concrete animal
├── Zoo.h/cpp              # Zoo management
├── Exceptions.h           # Custom exceptions
├── main.cpp               # Main program
├── Makefile               # Build configuration
└── README.md              # This file
```

## Compilation Instructions

### Using Makefile (Recommended)
```bash
# Compile the project
make

# Run the executable
make run

# Clean build files
make clean
```

### Manual Compilation with g++
```bash
g++ -std=c++11 -Wall -Wextra -o zoo_simulator main.cpp Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Monkey.cpp Eagle.cpp Penguin.cpp Parrot.cpp Zoo.cpp

# Run
./zoo_simulator
```

### Using Visual Studio (Windows)
1. Open Visual Studio
2. Create a new C++ Console Application project
3. Add all .h and .cpp files to the project
4. Build and run (Ctrl+F5)

### Using MinGW (Windows)
```bash
g++ -std=c++11 -Wall -o zoo_simulator.exe main.cpp Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Monkey.cpp Eagle.cpp Penguin.cpp Parrot.cpp Zoo.cpp
zoo_simulator.exe
```

## Usage

### Main Menu Options
1. **Add Animal**: Add a new animal to the zoo
2. **Remove Animal**: Remove an animal by name
3. **Display All Animals**: Show information about all animals
4. **Make All Animals Sound**: Demonstrate polymorphic sound behavior
5. **Feed All Animals**: Feed all animals (shows diet differences)
6. **Perform Daily Checkups**: Run health checks on all animals
7. **Calculate Total Food**: Show total food requirements
8. **Find Animal by Name**: Search for specific animal
9. **Display by Species**: Filter animals by species
10. **Provide Special Care**: Use dynamic casting for type-specific care
11. **Demonstrate Polymorphism**: Show runtime polymorphism
12. **Save to File**: Export zoo data
13. **Load from File**: Import zoo data

### Sample Session
```
Would you like to populate the zoo with sample animals? (y/n): y
Sample zoo populated with 12 animals!

[Menu appears]
Enter choice: 3

=== Animals in Wildlife Paradise ===
[1] === LION ===
Name: Simba
Age: 5 years
...

Total animals: 12
Total food required today: 85.3 kg
```

## Design Patterns Used

### Polymorphism
- Virtual functions allow different animals to implement their own behaviors
- Base class pointers/references enable generic operations

### Dynamic Casting
- Safe type identification at runtime
- Used in `specialCare()` function to provide type-specific operations

### Rule of Three
- Zoo class implements:
  - Destructor (cleanup)
  - Copy constructor
  - Copy assignment operator

## Memory Management
- Dynamic allocation using `new` operator
- Proper cleanup with `delete` in destructor
- Virtual destructor ensures derived class cleanup
- No memory leaks when used correctly

### Memory Leak Testing (Linux/Mac)
```bash
# Install valgrind
sudo apt-get install valgrind  # Ubuntu/Debian
brew install valgrind          # macOS

# Run with memory check
valgrind --leak-check=full --show-leak-kinds=all ./zoo_simulator
```

## Advanced Features

### Dynamic Type Identification
The `specialCare()` function demonstrates dynamic casting:
```cpp
if (Lion* lion = dynamic_cast<Lion*>(animal)) {
    lion->roar();
    lion->hunt();
}
```

### Polymorphic Collections
The Zoo stores `IAnimal*` pointers, enabling storage of any animal type:
```cpp
std::vector<IAnimal*> animals;
```

## Learning Objectives Achieved

✅ **Inheritance Hierarchies**: 3-level hierarchy implemented  
✅ **Polymorphism**: Virtual functions throughout  
✅ **Encapsulation**: Protected/private members with accessors  
✅ **Interfaces**: Pure virtual base class (IAnimal)  
✅ **Dynamic Memory**: Proper allocation and deallocation  
✅ **Virtual Destructors**: Prevents memory leaks  
✅ **Exception Handling**: Custom exceptions with try-catch  
✅ **File I/O**: Save/load functionality  
✅ **Dynamic Casting**: Type-specific operations  

## Testing Scenarios

### Test Case 1: Add Multiple Animals
- Add 2 lions, 2 elephants, 2 monkeys
- Verify capacity checks
- Test duplicate names

### Test Case 2: Polymorphic Operations
- Call `makeAllSounds()` - each animal makes unique sound
- Call `feedAllAnimals()` - different diets displayed
- Verify correct override behavior

### Test Case 3: Exception Handling
- Try adding to full zoo → `ZooFullException`
- Try removing non-existent animal → `AnimalNotFoundException`
- Try invalid file operations → `InvalidOperationException`

### Test Case 4: Memory Management
- Add many animals, remove some, then exit
- Run with valgrind to check for leaks
- Verify proper destructor calls

## Known Limitations
- File I/O saves basic info only (species, name, age, weight)
- Deep copy in Zoo not fully implemented (noted in code)
- No GUI interface (console only)

## Future Enhancements
- Template-based Enclosure class
- Observer pattern for Veterinarian notifications
- Factory pattern for animal creation
- Smart pointers (unique_ptr/shared_ptr) for safer memory
- Serialization with full animal details
- Database integration

## Authors & Credits
Assignment: Wildlife Sanctuary Simulator  
Purpose: C++ OOP Learning Project  
Demonstrates: Inheritance, Polymorphism, Encapsulation, Memory Management

## License
Educational project for learning purposes.

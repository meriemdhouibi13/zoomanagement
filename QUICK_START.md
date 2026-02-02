# Quick Start Guide - Wildlife Sanctuary Simulator

## 🚀 Quick Compilation & Run

### Windows (MinGW)
```bash
# Double-click build.bat or run:
build.bat
```

### Windows (Manual)
```bash
g++ -std=c++11 -o zoo.exe main.cpp Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp Monkey.cpp Eagle.cpp Penguin.cpp Parrot.cpp Zoo.cpp
zoo.exe
```

### Linux/macOS
```bash
make
./zoo_simulator
```

---

## 📋 Key OOP Concepts Demonstrated

### 1. Inheritance Hierarchy
```
IAnimal (Interface)
    ↓
Animal (Abstract Base)
    ↓
Mammal / Bird (Intermediate)
    ↓
Lion, Elephant, Monkey / Eagle, Penguin, Parrot (Concrete)
```

### 2. Polymorphism Example
```cpp
IAnimal* animal = new Lion("Simba", 5, 190, ...);
animal->makeSound();  // Calls Lion's implementation: "ROOOAAAR!"
animal->eat();        // Calls Lion's implementation: "eating fresh meat"
```

### 3. Virtual Functions
```cpp
class Animal {
    virtual void makeSound() const = 0;  // Pure virtual (must override)
    virtual void displayInfo() const;     // Virtual (can override)
};
```

### 4. Dynamic Casting
```cpp
if (Lion* lion = dynamic_cast<Lion*>(animal)) {
    lion->roar();  // Lion-specific method
}
```

---

## 🎯 Assignment Checklist

### Part 1: Base Classes (30 points)
- [x] IAnimal interface with pure virtual functions
- [x] Animal abstract base class
- [x] Proper access specifiers (private/protected/public)
- [x] Virtual destructor
- [x] Getters and setters (encapsulation)

### Part 2: Inheritance (25 points)
- [x] Mammal class inherits from Animal
- [x] Bird class inherits from Animal
- [x] Lion inherits from Mammal
- [x] Elephant inherits from Mammal
- [x] Monkey inherits from Mammal
- [x] Eagle inherits from Bird
- [x] Penguin inherits from Bird
- [x] Parrot inherits from Bird

### Part 3: Zoo Management (25 points)
- [x] Zoo class with vector<IAnimal*>
- [x] addAnimal() and removeAnimal()
- [x] Polymorphic operations (makeAllSounds, feedAllAnimals)
- [x] Rule of Three (destructor, copy constructor, assignment)
- [x] displayAllAnimals(), findAnimal()

### Part 4: Advanced Features (20 points)
- [x] Dynamic casting in specialCare()
- [x] Runtime polymorphism demonstration
- [x] Exception handling (try-catch)
- [x] Custom exceptions

### Part 5: File I/O (10 points)
- [x] saveToFile()
- [x] loadFromFile()

### Bonus: Exception Handling (10 points)
- [x] AnimalNotFoundException
- [x] ZooFullException
- [x] InvalidOperationException
- [x] Try-catch blocks

---

## 📊 Class Responsibility Summary

| Class | Responsibility | Key Methods |
|-------|---------------|-------------|
| IAnimal | Define animal interface | makeSound(), eat(), sleep() |
| Animal | Common animal functionality | displayInfo(), performCheckup() |
| Mammal | Mammal-specific traits | nurse(), getFurColor() |
| Bird | Bird-specific traits | fly(), buildNest() |
| Lion | Lion behavior | roar(), hunt() |
| Elephant | Elephant behavior | trumpet(), useTrunk() |
| Monkey | Monkey behavior | climb(), swing() |
| Eagle | Eagle behavior | screech(), dive() |
| Penguin | Penguin behavior | swim(), waddle() |
| Parrot | Parrot behavior | mimic(), learnWord() |
| Zoo | Manage animals | addAnimal(), removeAnimal() |

---

## 🔧 Common Issues & Solutions

### Issue 1: "undefined reference to vtable"
**Cause:** Pure virtual function not implemented  
**Solution:** Ensure all pure virtual functions are implemented in concrete classes

### Issue 2: Memory leaks
**Cause:** Not deleting dynamically allocated objects  
**Solution:** Use destructor to delete all pointers

### Issue 3: Compilation errors with virtual functions
**Cause:** Missing `override` keyword or wrong signature  
**Solution:** Match base class signature exactly

### Issue 4: "cannot instantiate abstract class"
**Cause:** Trying to create object of abstract class  
**Solution:** Only create objects of concrete classes (Lion, Eagle, etc.)

---

## 💡 Understanding Key Concepts

### Virtual Functions
```cpp
// Base class
virtual void makeSound() const = 0;  // Pure virtual - MUST override

virtual void displayInfo() const;     // Virtual - CAN override

void sleep() const;                   // Non-virtual - cannot override
```

### Virtual Destructor (CRITICAL!)
```cpp
virtual ~Animal();  // Ensures derived destructors are called
```

**Without virtual destructor:**
```cpp
Animal* animal = new Lion(...);
delete animal;  // ❌ Only Animal destructor called, Lion leaks!
```

**With virtual destructor:**
```cpp
Animal* animal = new Lion(...);
delete animal;  // ✅ Lion destructor → Animal destructor called
```

### Polymorphism in Action
```cpp
vector<IAnimal*> animals;
animals.push_back(new Lion(...));
animals.push_back(new Eagle(...));

for (IAnimal* animal : animals) {
    animal->makeSound();  // Calls Lion's or Eagle's version!
}
```

---

## 🎮 Interactive Demo

### Scenario 1: Basic Operations
```
1. Start program
2. Choose 'y' to populate sample zoo
3. Select option 3 → See all 12 animals
4. Select option 4 → Hear all animal sounds
5. Select option 5 → Feed all animals
```

### Scenario 2: Polymorphism Demo
```
1. Select option 11 (Demonstrate Polymorphism)
2. Enter "Simba"
3. Observe: IAnimal pointer calling Lion's methods
```

### Scenario 3: Exception Handling
```
1. Select option 2 (Remove Animal)
2. Enter "FakeAnimal"
3. Observe: AnimalNotFoundException caught and displayed
```

### Scenario 4: Dynamic Casting
```
1. Select option 10 (Special Care)
2. Enter "Simba"
3. Observe: Dynamic cast to Lion*, calls roar() and hunt()
```

---

## 📚 Code Snippets for Understanding

### Creating Animals
```cpp
// Direct creation
Lion* simba = new Lion("Simba", 5, 190, true, "Golden", 110, 25, true);

// Polymorphic storage
IAnimal* animal = simba;
animal->makeSound();  // Calls Lion::makeSound()

// Don't forget to delete!
delete animal;
```

### Using the Zoo
```cpp
Zoo myZoo("Wildlife Paradise", 50);

// Add animals (polymorphically)
myZoo.addAnimal(new Lion("Simba", 5, 190, ...));
myZoo.addAnimal(new Eagle("Thor", 3, 5, ...));

// Polymorphic operations
myZoo.makeAllSounds();    // Each animal's unique sound
myZoo.feedAllAnimals();   // Each animal's diet
myZoo.displayAllAnimals(); // All info

// Zoo destructor automatically deletes all animals
```

### Exception Handling
```cpp
try {
    zoo.addAnimal(new Lion(...));
} catch (const ZooFullException& e) {
    cerr << "Error: " << e.what() << endl;
} catch (const exception& e) {
    cerr << "Unexpected error: " << e.what() << endl;
}
```

---

## 🏆 Grading Rubric Reference

| Category | Points | What to Check |
|----------|--------|---------------|
| Correctness | 30 | Compiles without errors, runs correctly |
| Design | 25 | Proper inheritance, polymorphism, encapsulation |
| Code Quality | 20 | Clean, readable, well-commented |
| Memory Management | 15 | No leaks (test with valgrind) |
| Robustness | 10 | Handles errors gracefully |

---

## ⚡ Performance Tips

1. **Compile with warnings:**
   ```bash
   g++ -std=c++11 -Wall -Wextra -Wpedantic ...
   ```

2. **Check for memory leaks:**
   ```bash
   valgrind --leak-check=full ./zoo_simulator
   ```

3. **Use virtual destructors** - Critical for polymorphic classes!

4. **Test edge cases:**
   - Empty zoo
   - Full zoo
   - Non-existent animals
   - Invalid inputs

---

## 📖 Additional Resources

### Understanding Polymorphism
- Virtual functions enable runtime binding
- Base class pointer can point to derived objects
- Correct derived method called at runtime

### Understanding Inheritance
- "Is-a" relationship: Lion IS-A Mammal IS-A Animal
- Derived class inherits all base class members
- Can override virtual functions

### Understanding Encapsulation
- Public: Interface for users
- Protected: For derived classes
- Private: Internal implementation

---

## 🎓 Learning Objectives Checklist

After completing this project, you should understand:

- [x] Multi-level inheritance hierarchies
- [x] Pure virtual functions (interfaces)
- [x] Virtual function overriding
- [x] Runtime polymorphism
- [x] Dynamic casting (dynamic_cast)
- [x] Virtual destructors
- [x] Memory management (new/delete)
- [x] Exception handling (try/catch)
- [x] Rule of Three
- [x] Encapsulation with access specifiers

---

## 🆘 Getting Help

### Compilation Issues
1. Check all header files included
2. Verify all .cpp files compiled
3. Ensure correct C++11 standard

### Runtime Issues
1. Check for null pointers
2. Verify memory allocation/deallocation
3. Use debugger (gdb/Visual Studio)

### Conceptual Questions
1. Review class hierarchy diagram
2. Trace polymorphic function calls
3. Draw memory diagrams

---

**Good luck with your assignment! 🦁🐘🐒🦅🐧🦜**

Remember: This project teaches you fundamental OOP concepts that apply to all object-oriented languages!

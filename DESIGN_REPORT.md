# Wildlife Sanctuary Simulator - Design Report

## Project Information
**Project Title:** Wildlife Sanctuary Simulator  
**Language:** C++  
**Standard:** C++11  
**Purpose:** Demonstrate OOP principles in C++

---

## 1. Design Decisions

### 1.1 Class Hierarchy Design

**Decision:** Implement a three-level inheritance hierarchy
- Level 0: `IAnimal` (interface)
- Level 1: `Animal` (abstract base)
- Level 2: `Mammal` and `Bird` (intermediate)
- Level 3: Concrete animals (Lion, Elephant, etc.)

**Rationale:**
- Provides clear separation of concerns
- Each level adds specific characteristics
- Enables code reuse and polymorphism
- Follows real-world taxonomy

### 1.2 Interface vs Abstract Class

**Decision:** Use both IAnimal interface and Animal abstract base class

**Rationale:**
- `IAnimal`: Pure interface defining animal contract
- `Animal`: Implements common functionality (sleep, getters/setters)
- Separation allows future flexibility
- Follows Interface Segregation Principle

### 1.3 Memory Management

**Decision:** Use raw pointers with manual memory management

**Rationale:**
- Educational purpose - demonstrates manual memory control
- Shows importance of Rule of Three
- Teaches proper use of virtual destructors
- In production, smart pointers would be preferred

**Alternative Considered:** Smart pointers (unique_ptr/shared_ptr)
- Pros: Automatic memory management, safer
- Cons: Less educational for learning manual control
- Future Enhancement: Refactor to use smart pointers

### 1.4 Polymorphism Implementation

**Decision:** Use virtual functions extensively

**Rationale:**
- `makeSound()`, `eat()`, `getSpecies()`: Pure virtual (must override)
- `displayInfo()`, `performCheckup()`: Virtual (can override)
- Enables runtime polymorphism
- Allows base class pointers to call derived implementations

### 1.5 Exception Handling

**Decision:** Create custom exception classes

**Classes:**
- `AnimalNotFoundException`
- `ZooFullException`
- `InvalidOperationException`

**Rationale:**
- Type-safe error handling
- Descriptive error messages
- Allows specific catch blocks
- Better than error codes or generic exceptions

---

## 2. Implementation Highlights

### 2.1 Rule of Three in Zoo Class

```cpp
~Zoo();                          // Destructor
Zoo(const Zoo& other);           // Copy constructor
Zoo& operator=(const Zoo& other); // Copy assignment
```

**Why:** Zoo manages dynamic memory (animal pointers), so we need:
- Custom destructor to delete animals
- Copy constructor for deep copying
- Assignment operator for proper copying

### 2.2 Dynamic Casting for Type-Specific Operations

```cpp
void specialCare(IAnimal* animal) {
    if (Lion* lion = dynamic_cast<Lion*>(animal)) {
        lion->roar();
        lion->hunt();
    }
}
```

**Benefits:**
- Safe runtime type identification
- Enables type-specific operations
- Falls back gracefully if cast fails

### 2.3 Encapsulation

**Protected Members:**
```cpp
protected:
    std::string name;
    int age;
    double weight;
```

**Benefits:**
- Accessible to derived classes
- Hidden from external code
- Controlled access via getters/setters

### 2.4 Virtual Destructor

```cpp
virtual ~Animal();
```

**Critical Importance:**
- Without virtual destructor, deleting derived objects through base pointer causes undefined behavior
- Ensures derived class destructors are called
- Prevents memory leaks

---

## 3. Testing Strategy

### 3.1 Test Scenarios Covered

1. **Basic Operations**
   - Add animals of each type
   - Remove animals by name
   - Display animals

2. **Polymorphism**
   - Store different types in same container
   - Call virtual functions through base pointers
   - Verify correct override behavior

3. **Exception Handling**
   - Test zoo capacity limit
   - Try removing non-existent animals
   - Invalid file operations

4. **Memory Management**
   - Add/remove multiple animals
   - Verify no memory leaks
   - Test with valgrind

### 3.2 Sample Test Results

**Test 1: Polymorphic Sound**
```
Simba says: ROOOAAAR!      [Lion]
Dumbo says: PAAAHROOOO!    [Elephant]
George says: Ooh ooh ah ah! [Monkey]
Thor says: SCREEEECH!      [Eagle]
```
✅ Each animal produces unique sound

**Test 2: Exception Handling**
```
Error: Zoo is full! Maximum capacity: 50
Error: Animal not found: Simba2
```
✅ Exceptions thrown and caught correctly

---

## 4. Challenges and Solutions

### Challenge 1: Deep Copy in Zoo
**Problem:** Copying Zoo requires cloning all animals  
**Solution:** Added warning message; recommend implementing Cloneable interface  
**Future Work:** Add virtual clone() method to IAnimal

### Challenge 2: File Serialization
**Problem:** Saving all animal-specific attributes  
**Solution:** Basic implementation saves core attributes  
**Future Work:** Implement full serialization with type identification

### Challenge 3: Multiple Inheritance Temptation
**Problem:** Some animals could inherit from multiple categories  
**Solution:** Stuck to single inheritance hierarchy  
**Rationale:** Simpler, more maintainable

---

## 5. Code Quality Measures

### 5.1 Naming Conventions
- Classes: PascalCase (Lion, Elephant)
- Functions: camelCase (makeSound, displayInfo)
- Member variables: camelCase
- Constants: Would use UPPER_CASE

### 5.2 Documentation
- Header comments for each class
- Function comments for complex logic
- Inline comments for non-obvious code

### 5.3 Error Handling
- Try-catch blocks around critical operations
- Descriptive error messages
- Graceful degradation

---

## 6. Performance Considerations

### 6.1 Memory Usage
- Each animal: ~100 bytes
- Zoo overhead: vector + metadata
- 50 animals ≈ 5-10 KB total

### 6.2 Time Complexity
- Add animal: O(1)
- Remove animal: O(n) - linear search
- Display all: O(n)
- Find by name: O(n)

**Optimization Opportunity:** Use std::map for O(log n) lookup

---

## 7. Learning Outcomes

### Concepts Mastered
✅ Multi-level inheritance  
✅ Pure virtual functions  
✅ Virtual function overriding  
✅ Dynamic casting  
✅ Virtual destructors  
✅ Exception handling  
✅ Memory management  
✅ Polymorphic collections  

### Skills Developed
- Designing class hierarchies
- Balancing abstraction and implementation
- Managing dynamic memory safely
- Writing maintainable OOP code

---

## 8. Future Enhancements

### 8.1 Smart Pointers
Replace raw pointers with:
```cpp
std::vector<std::unique_ptr<IAnimal>> animals;
```

### 8.2 Template Enclosure
```cpp
template<typename T>
class Enclosure {
    static_assert(std::is_base_of<Animal, T>::value);
    std::vector<T*> residents;
};
```

### 8.3 Observer Pattern
```cpp
class Veterinarian : public Observer {
    void onAnimalSick(Animal* animal) override;
};
```

### 8.4 Factory Pattern
```cpp
class AnimalFactory {
    static IAnimal* createAnimal(const std::string& type);
};
```

---

## 9. Conclusion

This project successfully demonstrates core OOP principles in C++. The design is extensible, maintainable, and educational. The multi-level inheritance hierarchy showcases how abstraction can model real-world relationships, while polymorphism enables flexible and reusable code.

The implementation balances academic learning goals with practical software engineering practices, making it an effective educational tool for understanding C++ object-oriented programming.

---

**Key Takeaway:** Proper use of inheritance, polymorphism, and encapsulation leads to clean, maintainable, and extensible code that accurately models real-world systems.

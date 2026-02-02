#include "Zoo.h"
#include "Lion.h"
#include "Elephant.h"
#include "Monkey.h"
#include "Eagle.h"
#include "Penguin.h"
#include "Parrot.h"
#include "Exceptions.h"
#include "AnimalFactory.h"
#include "Enclosure.h"
#include "Veterinarian.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Demonstrates polymorphism with dynamic casting
 * Provides special care based on specific animal type
 */
void specialCare(IAnimal* animal) {
    cout << "\n=== Providing Special Care ===" << endl;
    
    if (Lion* lion = dynamic_cast<Lion*>(animal)) {
        cout << "Special lion care for " << lion->getName() << ":" << endl;
        lion->roar();
        lion->hunt();
    } 
    else if (Eagle* eagle = dynamic_cast<Eagle*>(animal)) {
        cout << "Special eagle care for " << eagle->getName() << ":" << endl;
        eagle->screech();
        eagle->dive();
    } 
    else if (Penguin* penguin = dynamic_cast<Penguin*>(animal)) {
        cout << "Special penguin care for " << penguin->getName() << ":" << endl;
        penguin->waddle();
        penguin->swim();
    }
    else if (Elephant* elephant = dynamic_cast<Elephant*>(animal)) {
        cout << "Special elephant care for " << elephant->getName() << ":" << endl;
        elephant->trumpet();
        elephant->spray();
    }
    else if (Monkey* monkey = dynamic_cast<Monkey*>(animal)) {
        cout << "Special monkey care for " << monkey->getName() << ":" << endl;
        monkey->climb();
        monkey->playful();
    }
    else if (Parrot* parrot = dynamic_cast<Parrot*>(animal)) {
        cout << "Special parrot care for " << parrot->getName() << ":" << endl;
        parrot->talk();
        parrot->showVocabulary();
    }
    else {
        cout << "Providing general animal care." << endl;
    }
}

/**
 * Demonstrates polymorphic behavior with a pointer to base class
 */
void demonstratePolymorphism(IAnimal* animal) {
    cout << "\n=== Demonstrating Polymorphism ===" << endl;
    cout << "Working with IAnimal pointer..." << endl;
    
    animal->makeSound();
    animal->eat();
    animal->sleep();
    
    Animal* baseAnimal = dynamic_cast<Animal*>(animal);
    if (baseAnimal) {
        baseAnimal->displayInfo();
    }
}

/**
 * Populates the zoo with sample animals
 */
void populateSampleZoo(Zoo& zoo) {
    try {
        // Add Lions
        zoo.addAnimal(new Lion("Simba", 5, 190, true, "Golden", 110, 25, true));
        zoo.addAnimal(new Lion("Nala", 4, 130, true, "Tan", 110, 0, false));
        
        // Add Elephants
        zoo.addAnimal(new Elephant("Dumbo", 10, 5400, false, "Gray", 660, 1.8, 120, true));
        zoo.addAnimal(new Elephant("Ellie", 8, 4200, false, "Gray", 660, 1.5, 80, false));
        
        // Add Monkeys
        zoo.addAnimal(new Monkey("George", 3, 8, true, "Brown", 160, 55, true, "Capuchin"));
        zoo.addAnimal(new Monkey("Abu", 2, 5, true, "Brown", 160, 40, false, "Spider Monkey"));
        
        // Add Eagles
        zoo.addAnimal(new Eagle("Thor", 3, 5, 2.3, true, "Hooked", 7.5, 3200, true));
        zoo.addAnimal(new Eagle("Freedom", 4, 6, 2.5, true, "Hooked", 8.0, 3500, false));
        
        // Add Penguins
        zoo.addAnimal(new Penguin("Pingu", 2, 12, 0.4, false, "Small", 8, 150, "Emperor"));
        zoo.addAnimal(new Penguin("Skipper", 3, 11, 0.4, false, "Small", 9, 180, "Adelie"));
        
        // Add Parrots
        zoo.addAnimal(new Parrot("Polly", 5, 1.2, 0.6, true, "Curved", "Green", 9));
        zoo.addAnimal(new Parrot("Charlie", 4, 1.0, 0.5, true, "Curved", "Blue", 8));
        
        cout << "\nSample zoo populated with " << zoo.getAnimalCount() << " animals!" << endl;
    }
    catch (const exception& e) {
        cerr << "Error populating zoo: " << e.what() << endl;
    }
}

void displayMenu() {
    cout << "\n============================================" << endl;
    cout << "   Wildlife Sanctuary Simulator" << endl;
    cout << "============================================" << endl;
    cout << "1.  Add Animal" << endl;
    cout << "2.  Remove Animal" << endl;
    cout << "3.  Display All Animals" << endl;
    cout << "4.  Make All Animals Sound" << endl;
    cout << "5.  Feed All Animals" << endl;
    cout << "6.  Perform Daily Checkups" << endl;
    cout << "7.  Calculate Total Food Needed" << endl;
    cout << "8.  Find Animal by Name" << endl;
    cout << "9.  Display by Species" << endl;
    cout << "10. Provide Special Care" << endl;
    cout << "11. Demonstrate Polymorphism" << endl;
    cout << "12. Save to File" << endl;
    cout << "13. Load from File" << endl;
    cout << "14. Use Animal Factory" << endl;
    cout << "15. Manage Enclosures" << endl;
    cout << "16. Veterinarian Demo" << endl;
    cout << "\n0.  Exit" << endl;
    cout << "============================================" << endl;
    cout << "Enter choice: ";
}

void addAnimalMenu(Zoo& zoo) {
    cout << "\n=== Add Animal ===" << endl;
    cout << "1. Lion" << endl;
    cout << "2. Elephant" << endl;
    cout << "3. Monkey" << endl;
    cout << "4. Eagle" << endl;
    cout << "5. Penguin" << endl;
    cout << "6. Parrot" << endl;
    cout << "Enter type: ";
    
    int type;
    cin >> type;
    cin.ignore();
    
    string name;
    int age;
    double weight;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter weight (kg): ";
    cin >> weight;
    
    try {
        switch (type) {
            case 1:
                zoo.addAnimal(new Lion(name, age, weight, true, "Golden", 110, 20, false));
                break;
            case 2:
                zoo.addAnimal(new Elephant(name, age, weight, false, "Gray", 660, 1.5, 100, true));
                break;
            case 3:
                zoo.addAnimal(new Monkey(name, age, weight, true, "Brown", 160, 50, true, "Capuchin"));
                break;
            case 4:
                zoo.addAnimal(new Eagle(name, age, weight, 2.0, true, "Hooked", 7.0, 3000, false));
                break;
            case 5:
                zoo.addAnimal(new Penguin(name, age, weight, 0.4, false, "Small", 8, 150, "Emperor"));
                break;
            case 6:
                zoo.addAnimal(new Parrot(name, age, weight, 0.5, true, "Curved", "Green", 8));
                break;
            default:
                cout << "Invalid animal type!" << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void removeAnimalMenu(Zoo& zoo) {
    cout << "\n=== Remove Animal ===" << endl;
    cout << "Enter animal name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    
    try {
        zoo.removeAnimal(name);
        cout << "Animal removed successfully!" << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void findAnimalMenu(Zoo& zoo) {
    cout << "\n=== Find Animal ===" << endl;
    cout << "Enter animal name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    
    try {
        IAnimal* animal = zoo.findAnimal(name);
        Animal* a = dynamic_cast<Animal*>(animal);
        if (a) {
            cout << "\nAnimal found!" << endl;
            a->displayInfo();
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void displayBySpeciesMenu(Zoo& zoo) {
    cout << "\n=== Display by Species ===" << endl;
    cout << "Enter species (Lion/Elephant/Monkey/Eagle/Penguin/Parrot): ";
    string species;
    cin.ignore();
    getline(cin, species);
    
    zoo.displayBySpecies(species);
}

void specialCareMenu(Zoo& zoo) {
    cout << "\n=== Special Care ===" << endl;
    cout << "Enter animal name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    
    try {
        IAnimal* animal = zoo.findAnimal(name);
        specialCare(animal);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void demonstratePolymorphismMenu(Zoo& zoo) {
    cout << "\n=== Demonstrate Polymorphism ===" << endl;
    cout << "Enter animal name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    
    try {
        IAnimal* animal = zoo.findAnimal(name);
        demonstratePolymorphism(animal);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void saveToFileMenu(Zoo& zoo) {
    cout << "\n=== Save to File ===" << endl;
    cout << "Enter filename: ";
    string filename;
    cin.ignore();
    getline(cin, filename);
    
    try {
        zoo.saveToFile(filename);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void loadFromFileMenu(Zoo& zoo) {
    cout << "\n=== Load from File ===" << endl;
    cout << "Enter filename: ";
    string filename;
    cin.ignore();
    getline(cin, filename);
    
    try {
        zoo.loadFromFile(filename);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// ========================================
// BONUS FEATURE FUNCTIONS
// ========================================

void animalFactoryMenu(Zoo& zoo) {
    cout << "\n=== Animal Factory (Factory Pattern) ===" << endl;
    AnimalFactory::listAvailableSpecies();
    
    cout << "\nEnter species name: ";
    string species;
    cin.ignore();
    getline(cin, species);
    
    cout << "Enter name: ";
    string name;
    getline(cin, name);
    
    cout << "Enter age: ";
    int age;
    cin >> age;
    
    cout << "Enter weight (kg): ";
    double weight;
    cin >> weight;
    
    try {
        IAnimal* animal = AnimalFactory::createAnimal(species, name, age, weight);
        zoo.addAnimal(animal);
        cout << "\n✓ Animal created and added using Factory Pattern!" << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void enclosureMenu() {
    cout << "\n=== Enclosure Management (Template Pattern) ===" << endl;
    cout << "Creating specialized enclosures..." << endl;
    
    // Create lion enclosure
    Enclosure<Lion> lionEnclosure("Lion Pride", 5);
    
    cout << "\nAdding lions to enclosure..." << endl;
    lionEnclosure.addAnimal(new Lion("Leo", 5, 190, true, "Golden", 110, 25, true));
    lionEnclosure.addAnimal(new Lion("Luna", 4, 130, true, "Tan", 110, 0, false));
    
    lionEnclosure.displayAnimals();
    
    cout << "\nMaking all lions roar..." << endl;
    lionEnclosure.makeAllSounds();
    
    cout << "\nFood requirement: " << lionEnclosure.calculateTotalFoodRequirement() 
         << " kg" << endl;
    
    cout << "\n✓ Enclosure demo complete! (Animals will be cleaned up automatically)" << endl;
}

void veterinarianMenu(Zoo& zoo) {
    cout << "\n=== Veterinarian System (Observer Pattern) ===" << endl;
    
    // Create veterinarian
    Veterinarian vet("Rodriguez", "Exotic Animals");
    
    cout << "\nSelect an animal to examine:" << endl;
    cout << "Enter animal name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    
    try {
        IAnimal* animal = zoo.findAnimal(name);
        Animal* a = dynamic_cast<Animal*>(animal);
        
        if (a) {
            // Perform checkup
            vet.performCheckup(a);
            
            // Simulate getting sick
            cout << "\n>>> Simulating health issue..." << endl;
            a->setHealthStatus(false);
            
            // Create observable and attach veterinarian
            ObservableAnimal observable(a);
            observable.attach(&vet);
            
            // Notify (Observer Pattern in action!)
            observable.notifyHealthIssue();
            
            // Display stats
            vet.displayStats();
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    srand(time(0)); // Seed random number generator
    
    cout << "========================================" << endl;
    cout << "  Wildlife Sanctuary Simulator" << endl;
    cout << "     C++ OOP Demonstration" << endl;
    cout << "========================================\n" << endl;
    
    // Create zoo
    Zoo myZoo("Wildlife Paradise", 50);
    
    // Ask if user wants to populate with sample animals
    cout << "Would you like to populate the zoo with sample animals? (y/n): ";
    char choice;
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        populateSampleZoo(myZoo);
    }
    
    // Main menu loop
    int menuChoice;
    do {
        displayMenu();
        cin >> menuChoice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (menuChoice) {
            case 1:
                addAnimalMenu(myZoo);
                break;
            case 2:
                removeAnimalMenu(myZoo);
                break;
            case 3:
                myZoo.displayAllAnimals();
                break;
            case 4:
                myZoo.makeAllSounds();
                break;
            case 5:
                myZoo.feedAllAnimals();
                break;
            case 6:
                myZoo.performDailyCheckups();
                break;
            case 7:
                cout << "\nTotal food required: " << myZoo.calculateTotalFoodRequirement() 
                     << " kg" << endl;
                break;
            case 8:
                findAnimalMenu(myZoo);
                break;
            case 9:
                displayBySpeciesMenu(myZoo);
                break;
            case 10:
                specialCareMenu(myZoo);
                break;
            case 11:
                demonstratePolymorphismMenu(myZoo);
                break;
            case 12:
                saveToFileMenu(myZoo);
                break;
            case 13:
                loadFromFileMenu(myZoo);
                break;
            case 14:
                animalFactoryMenu(myZoo);
                break;
            case 15:
                enclosureMenu();
                break;
            case 16:
                veterinarianMenu(myZoo);
                break;
            case 0:
                cout << "\nThank you for visiting Wildlife Paradise!" << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (menuChoice != 0);
    
    return 0;
}

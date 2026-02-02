# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Target executable
TARGET = zoo_simulator

# Source files
SOURCES = main.cpp Animal.cpp Mammal.cpp Bird.cpp Lion.cpp Elephant.cpp \
          Monkey.cpp Eagle.cpp Penguin.cpp Parrot.cpp Zoo.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency)
HEADERS = IAnimal.h Animal.h Mammal.h Bird.h Lion.h Elephant.h Monkey.h \
          Eagle.h Penguin.h Parrot.h Zoo.h Exceptions.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Executable: $(TARGET)"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Clean and rebuild
rebuild: clean all

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Show help
help:
	@echo "Wildlife Sanctuary Simulator - Makefile Commands"
	@echo "=================================================="
	@echo "make          - Build the project"
	@echo "make run      - Build and run the program"
	@echo "make clean    - Remove build files"
	@echo "make rebuild  - Clean and rebuild"
	@echo "make memcheck - Run with valgrind (requires valgrind)"
	@echo "make help     - Show this help message"

# Phony targets (not actual files)
.PHONY: all run clean rebuild memcheck help

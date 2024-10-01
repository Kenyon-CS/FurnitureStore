# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = furniture_test

# Object files
OBJECTS = main.o

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile main.cpp
main.o: main.cpp Furniture.h Chair.h Table.h Sofa.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)

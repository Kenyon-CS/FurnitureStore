# Makefile for the Inventory program with derived Furniture classes defined in header files

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I.

# Source files
SRCS = testinventory.cpp Inventory.cpp Furniture.cpp

# Object files
OBJS = testinventory.o Inventory.o Furniture.o

# Executable name
TARGET = testinventory

# Default rule
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile testinventory.cpp
testinventory.o: testinventory.cpp Inventory.h Furniture/Furniture.h Furniture/Chair.h Furniture/Sofa.h Furniture/Table.h
	$(CXX) $(CXXFLAGS) -c testinventory.cpp

# Rule to compile Inventory.cpp
Inventory.o: Inventory.cpp Inventory.h Furniture/Furniture.h Furniture/Chair.h Furniture/Sofa.h Furniture/Table.h
	$(CXX) $(CXXFLAGS) -c Inventory.cpp

# Rule to compile Furniture.cpp
Furniture.o: Furniture/Furniture.cpp Furniture/Furniture.h
	$(CXX) $(CXXFLAGS) -c Furniture/Furniture.cpp -o Furniture.o

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

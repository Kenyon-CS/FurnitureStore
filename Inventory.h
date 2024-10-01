#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include "Furniture/Furniture.h" // Assuming Furniture class is declared in Furniture.h

class Inventory {
public:
    // Constructor to initialize the inventory with a specific size
    Inventory(int capacity);

    // Destructor to clean up dynamically allocated memory
    ~Inventory();

    // Method to add a furniture item to the inventory
    void addItem(Furniture* item);
    
    // Method to display all the furniture items in the inventory
    void displayInventory() const;
    
    // Method to compute and return the total retail value of all items in the inventory
    double calculateTotalValue() const;
    
    // Method to search the inventory for a furniture item by its ID
    Furniture* find(int furnID) const;
    
    // Method to write the inventory details to a file
    void writeToFile(const std::string& filename) const;
    
    // Method to read the inventory details from a file
    void readFromFile(const std::string& filename);

private:
    Furniture** items;    // Pointer to dynamically allocated array of Furniture pointers
    int capacity;         // Maximum number of items the inventory can hold
    int itemCount;        // Current number of items in the inventory

    // Method to check if inventory is full
    bool isFull() const;
};

#endif // INVENTORY_H

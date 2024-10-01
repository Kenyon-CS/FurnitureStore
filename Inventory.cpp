#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <iomanip>

// Constructor to initialize the inventory with a specific size
Inventory::Inventory(int capacity)
    : capacity(capacity), itemCount(0) {
    items = new Furniture*[capacity];
}

// Destructor to clean up dynamically allocated memory
Inventory::~Inventory() {
    for (int i = 0; i < itemCount; ++i) {
        delete items[i];
    }
    delete[] items;
}

// Method to check if inventory is full
bool Inventory::isFull() const {
    return itemCount >= capacity;
}

// Method to add a furniture item to the inventory
void Inventory::addItem(Furniture* item) {
    if (isFull()) {
        std::cout << "Inventory is full. Cannot add more items." << std::endl;
        return;
    }
    items[itemCount++] = item;
}

// Method to display all the furniture items in the inventory
void Inventory::displayInventory() const {
    std::cout << "Inventory List:" << std::endl;
    std::cout << std::setw(12) << "ID"
              << std::setw(20) << "Name"
              << std::setw(15) << "Price"
              << std::setw(10) << "Quantity"
              << std::setw(15) << "Total Value" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    for (int i = 0; i < itemCount; ++i) {
        double totalItemValue = items[i]->getPrice() * items[i]->getQuantity();
        std::cout << std::setw(12) << items[i]->getInventoryID()
                  << std::setw(20) << items[i]->getName()
                  << std::setw(15) << std::fixed << std::setprecision(2) << items[i]->getPrice()
                  << std::setw(10) << items[i]->getQuantity()
                  << std::setw(15) << totalItemValue
                  << std::endl;
    }
}

// Method to compute and return the total retail value of all items in the inventory
double Inventory::calculateTotalValue() const {
    double totalValue = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        totalValue += items[i]->getPrice() * items[i]->getQuantity();
    }
    return totalValue;
}

// Method to search the inventory for a furniture item by its ID
Furniture* Inventory::find(int furnID) const {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i]->getInventoryID() == furnID) {
            return items[i];
        }
    }
    return nullptr; // Item not found
}

// Method to write the inventory details to a file
void Inventory::writeToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outFile << itemCount << std::endl;
    for (int i = 0; i < itemCount; ++i) {
        outFile << items[i]->getInventoryID() << std::endl;
        outFile << items[i]->getName() << std::endl;
        outFile << items[i]->getPrice() << std::endl;
        outFile << items[i]->getQuantity() << std::endl;
    }

    outFile.close();
    std::cout << "Inventory successfully written to " << filename << std::endl;
}

// Method to read the inventory details from a file
void Inventory::readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    // Clean up existing items
    for (int i = 0; i < itemCount; ++i) {
        delete items[i];
    }
    itemCount = 0;

    int count;
    inFile >> count;
    inFile.ignore(); // Ignore the newline character

    int maxID = 0; // To update nextID in Furniture

    for (int i = 0; i < count; ++i) {
        if (isFull()) {
            std::cout << "Inventory is full. Cannot add more items from file." << std::endl;
            break;
        }

        int id;
        std::string name;
        double price;
        int quantity;

        inFile >> id;
        inFile.ignore();
        std::getline(inFile, name);
        inFile >> price;
        inFile >> quantity;
        inFile.ignore();

        // Create a new Furniture object
        Furniture* item = new Furniture(name, price, quantity);
        item->setInventoryID(id);

        // Update maxID
        if (id > maxID) {
            maxID = id;
        }

        addItem(item);
    }

    // Update nextID in Furniture
    Furniture::setNextID(maxID + 1);

    inFile.close();
    std::cout << "Inventory successfully read from " << filename << std::endl;
}

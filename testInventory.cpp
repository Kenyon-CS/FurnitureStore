// testinventory.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "Inventory.h"
#include "Furniture/Furniture.h"

int main() {
    // Create an Inventory with a capacity of 100 items
    Inventory storeInventory(100);

    // Add furniture items to the inventory
    Furniture* chair = new Furniture("Office Chair", 149.99, 10);
    Furniture* desk = new Furniture("Wooden Desk", 299.99, 5);
    Furniture* sofa = new Furniture("Leather Sofa", 899.99, 2);
    Furniture* table = new Furniture("Dining Table", 499.99, 3);

    storeInventory.addItem(chair);
    storeInventory.addItem(desk);
    storeInventory.addItem(sofa);
    storeInventory.addItem(table);

    // Display the inventory
    std::cout << "\nDisplaying Inventory:\n";
    storeInventory.displayInventory();

    // Calculate total inventory value
    double totalValue = storeInventory.calculateTotalValue();
    std::cout << "\nTotal Inventory Value: $" << std::fixed << std::setprecision(2) << totalValue << std::endl;

    // Find a furniture item by its inventory ID
    int searchID = 2; // For example, searching for item with inventoryID 2
    Furniture* foundItem = storeInventory.find(searchID);
    if (foundItem) {
        std::cout << "\nFound item with ID " << searchID << ":\n";
        foundItem->display();
    } else {
        std::cout << "\nItem with ID " << searchID << " not found.\n";
    }

    // Write inventory to a file
    std::string filename = "inventory.txt";
    storeInventory.writeToFile(filename);

    // Create a new Inventory and read from the file
    Inventory newInventory(100);
    newInventory.readFromFile(filename);

    // Display the new inventory
    std::cout << "\nDisplaying New Inventory (after reading from file):\n";
    newInventory.displayInventory();

    return 0;
}

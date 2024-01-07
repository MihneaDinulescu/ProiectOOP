//
// Created by dinul on 11/18/2023.
//
#include "../Headers/Inventory.h"

/**
 * @brief Constructor for the Inventory class.
 *
 * Initializes the inventory space by creating InventorySlot objects and setting them to default Item values.
 */
Inventory::Inventory() {
    for (int i = 0; i < this->getInventorySize(); i++) {
        inventorySpace.push_back(new InventorySlot());
        inventorySpace.at(i)->setItemType(new Item());
        inventorySpace.at(i)->emptyQuantity();
    }
}

/**
 * @brief Function to get the size of the inventory.
 *
 * @return Returns the size of the inventory.
 */
int Inventory::getInventorySize() {
    return inventorySize;
}

/**
 * @brief Function to retrieve the inventory space.
 *
 * @return Returns a vector containing pointers to InventorySlot objects representing the inventory.
 */
std::vector<InventorySlot *> Inventory::getInventorySpace() {
    return this->inventorySpace;
}

/**
 * @brief Function to check if the inventory is full.
 *
 * @return Returns true if the inventory is full; otherwise, returns false.
 */
bool Inventory::isFull() {
    for (int i = 0; i < this->inventorySize; i++) {
        if (this->inventorySpace.at(i)->isEmpty())
            return false;
    }
    return true;
}

/**
 * @brief Function to check if the inventory is empty.
 *
 * @return Returns true if the inventory is empty; otherwise, returns false.
 */
bool Inventory::isEmpty() {
    for (int i = 0; i < this->inventorySize; i++) {
        if (!this->inventorySpace.at(i)->isEmpty())
            return false;
    }
    return true;
}

/**
 * @brief Function to find an item by its name and its quantity , with its quantity smaller than the maximum
 * stack size of that item within the inventory.
 *
 * @param itemName The name of the item to search for.
 * @param stcksize The stack size of the item.
 * @return Returns a pointer to the InventorySlot containing the item; otherwise, returns nullptr.
 */
InventorySlot *Inventory::findItemByNameAndStackSize(const std::string &itemName, int stcksize) {
    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->getItemName() == itemName &&
            this->inventorySpace.at(i)->getQuantity() < stcksize &&
            this->inventorySpace.at(i)->getQuantity() > 0) {
            return this->inventorySpace.at(i);
        }
    }
    return nullptr;
}

/**
 * @brief Function to replaces the first empty slot in the inventory with a specific slot.
 *
 * @param toBeAdded A pointer to the InventorySlot that is to be added to the inventory.
 */
void Inventory::setFirstEmptySlot(InventorySlot *toBeAdded) {
    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->isEmpty()) {
            delete this->inventorySpace.at(i);
            this->inventorySpace.at(i) = toBeAdded;
            return;
        }
    }
    std::cout << "The inventory is full\n";
}

/**
 * @brief Function to display the contents of the inventory.
 */
void Inventory::displayInventory() {
    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->getQuantity() <= 0)
            std::cout << "SLOT " << i + 1 << ": " << "Empty\n";
        else if (this->inventorySpace.at(i)->getCurentItem()->getDamage())
            std::cout << "SLOT " << i + 1 << ": " << *(this->inventorySpace.at(i)) << " +"
                      << this->inventorySpace.at(i)->getCurentItem()->getPlusLevel() << "\n";
        else
            std::cout << "SLOT " << i + 1 << ": " << *(this->inventorySpace.at(i)) << "\n";
    }
}

/**
 * @brief Function to display available swords in the inventory.
 *
 * @return Returns the count of available swords.
 */
int Inventory::displaySwords() {
    std::cout << "Swords available from your inventory:\n";
    int counter = 0;
    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->getQuantity() > 0 &&
            this->inventorySpace.at(i)->getCurentItem()->getDamage() > 0) {
            std::cout << counter + 1 << ". "
                      << this->inventorySpace.at(i)->getCurentItem()->getName()
                      << " which has +" << this->inventorySpace.at(i)->getCurentItem()->getPlusLevel() << " Plus Level\n";
            counter++;
        }
    }
    return counter;
}

/**
 * @brief Function to free memory allocated for inventory slots.
 */
void Inventory::freeEverything() {
    for (int i = 0; i < this->getInventorySize(); i++) {
        delete this->inventorySpace.at(i);
    }
}



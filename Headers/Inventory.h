//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_INVENTORY_H
#define OOP_INVENTORY_H

#include<vector>
#include <iostream>
#include "InventorySlot.h"


/**
 * @brief The Inventory class represents a player's inventory containing inventory slots.
 *
 * The Inventory class provides functionalities for managing items within the player's inventory.
 */
class Inventory {
protected:
    std::vector<InventorySlot *> inventorySpace; ///< Vector to hold inventory slots.
    static const int inventorySize = 30;         ///< Constant representing the inventory size.

public:
    Inventory(); ///< Constructor to initialize the inventory.

    /**
     * @brief Static function to get the size of the inventory.
     * @return The size of the inventory.
     */
    static int getInventorySize();

    /**
     * @brief Function to retrieve the inventory
     * @return Vector containing inventory slots.
     */
    std::vector<InventorySlot *> getInventorySpace();

    /**
     * @brief Function to check if the inventory is full.
     * @return True if the inventory is full; otherwise, false.
     */
    bool isFull();

    /**
     * @brief Function to check if the inventory is empty.
     * @return True if the inventory is empty; otherwise, false.
     */
    bool isEmpty();

    /**
     * @brief Function to find an item by its name and its quantity , with its quantity smaller than the maximum
     * stack size of that item within the inventory.
     * @param itemName The name of the item to find.
     * @param stcksize The stack size of the item.
     * @return Pointer to the inventory slot containing the item; otherwise, nullptr.
     */
    InventorySlot *findItemByNameAndStackSize(const std::string &itemName, int stcksize);

    /**
     * @brief Function to replaces the first empty slot in the inventory with a specific slot.
     * @param toBeAdded Pointer to the inventory slot to be added.
     */
    void setFirstEmptySlot(InventorySlot *toBeAdded);

    /**
     * @brief Function to display the contents of the inventory.
     */
    void displayInventory();

    /**
     * @brief Function to display available swords in the inventory.
     * @return Count of available swords.
     */
    int displaySwords();

    /**
     * @brief Function to free all inventory slots.
     */
    void freeEverything();
};

#endif //OOP_INVENTORY_H

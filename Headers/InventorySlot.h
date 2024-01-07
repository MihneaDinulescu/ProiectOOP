//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_INVENTORYSLOT_H
#define OOP_INVENTORYSLOT_H

#include<iostream>
#include "Item.h"

/**
 * @brief The InventorySlot class represents an individual slot within an inventory system.
 *
 * This class encapsulates the behavior and attributes of an inventory slot, allowing for storage
 * and management of items and their respective quantities.
 */
class InventorySlot {
private:
    Item *curentItem;  ///< Pointer to the current item stored in the slot.
    int quantity;      ///< Integer representing the quantity of the stored item.

public:
    /**
     * @brief Default constructor for InventorySlot.
     *
     * Initializes a new InventorySlot object with no associated item and a quantity of zero.
     */
    InventorySlot();

    /**
     * @brief Destructor for InventorySlot.
     *
     * Frees any dynamically allocated memory, ensuring no memory leaks.
     */
    ~InventorySlot();

    /**
     * @brief Overloaded stream insertion operator for InventorySlot.
     *
     * Provides a mechanism to display the InventorySlot's details via the output stream.
     *
     * @param out Reference to the output stream.
     * @param ob Reference to the InventorySlot object to be displayed.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, InventorySlot &ob);

    /**
     * @brief Accessor method to retrieve the pointer to the current item.
     *
     * @return Pointer to the Item object stored in the InventorySlot.
     */
    Item *getCurentItem();

    /**
     * @brief Checks if the InventorySlot is empty.
     *
     * @return Boolean value indicating whether the slot is empty (true) or not (false).
     */
    bool isEmpty() const;

    /**
     * @brief Retrieves the name of the item stored in the InventorySlot.
     *
     * @return String representing the name of the item.
     */
    std::string getItemName();

    /**
     * @brief Increases the quantity of the item in the InventorySlot.
     *
     * @param addedQuantity Integer specifying the quantity to be added.
     */
    void addQuantity(int addedQuantity);

    /**
     * @brief Decreases the quantity of the item in the InventorySlot.
     *
     * @param removedQuantity Integer specifying the quantity to be removed.
     */
    void removeQuantity(int removedQuantity);

    /**
     * @brief Sets the type of item stored in the InventorySlot.
     *
     * @param itemType Pointer to the Item object to be stored.
     */
    void setItemType(Item *itemType);

    /**
     * @brief Resets the quantity of the InventorySlot to zero.
     */
    void emptyQuantity();

    /**
     * @brief Retrieves the quantity of the item stored in the InventorySlot.
     *
     * @return Integer representing the quantity of the item.
     */
    int getQuantity() const;

    /**
     * @brief Sets the quantity of the item in the InventorySlot.
     *
     * @param cnt Integer specifying the new quantity.
     */
    void setQuantity(int cnt);
};


#endif //OOP_INVENTORYSLOT_H

//
// Created by dinul on 11/18/2023.
//
#include "../Headers/InventorySlot.h"

/**
 * @brief Default constructor for the InventorySlot class.
 *
 * Initializes an InventorySlot object by setting the current item pointer to nullptr
 * and the quantity of the item to zero.
 */
InventorySlot::InventorySlot() {
    this->curentItem = nullptr;
    this->quantity = 0;
}

/**
 * @brief Destructor for the InventorySlot class.
 *
 * Ensures the proper cleanup of dynamically allocated memory, specifically
 * the associated current item pointer to prevent memory leaks.
 */
InventorySlot::~InventorySlot() {
    if (this->curentItem) // Checking if the current item pointer is not nullptr.
        delete (this->curentItem); // Deleting the dynamically allocated item object.
}

/**
 * @brief Overloaded stream insertion operator.
 *
 * Provides a mechanism to display the details of the InventorySlot via the output stream.
 *
 * @param out Reference to the output stream.
 * @param ob Reference to the InventorySlot object to be displayed.
 * @return Reference to the output stream after displaying the object's details.
 */
std::ostream &operator<<(std::ostream &out, InventorySlot &ob) {
    out << "x" << ob.getQuantity() << " " << ob.getItemName();
    return out;
}

/**
 * @brief Accessor method to retrieve the pointer to the current item.
 *
 * @return Pointer to the Item object stored in the InventorySlot.
 */
Item *InventorySlot::getCurentItem() {
    return (this->curentItem);
}

/**
 * @brief Checks if the InventorySlot is empty.
 *
 * @return Boolean value indicating whether the slot is empty (true) or not (false).
 */
bool InventorySlot::isEmpty() const {
    return (this->quantity == 0);
}

/**
 * @brief Retrieves the name of the item stored in the InventorySlot.
 *
 * @return String representing the name of the item.
 */
std::string InventorySlot::getItemName() {
    return (this->curentItem->getName());
}

/**
 * @brief Increases the quantity of the item in the InventorySlot.
 *
 * @param addedQuantity Integer specifying the quantity to be added.
 */
void InventorySlot::addQuantity(int addedQuantity) {
    this->quantity += addedQuantity;
}

/**
 * @brief Decreases the quantity of the item in the InventorySlot.
 *
 * @param removedQuantity Integer specifying the quantity to be removed.
 */
void InventorySlot::removeQuantity(int removedQuantity) {
    this->quantity -= removedQuantity;
}

/**
 * @brief Sets the type of item stored in the InventorySlot.
 *
 * @param itemType Pointer to the Item object to be stored.
 */
void InventorySlot::setItemType(Item *itemType) {
    delete this->curentItem; // Ensuring to release any previously allocated memory.
    this->curentItem = itemType;
}

/**
 * @brief Resets the quantity of the InventorySlot to zero.
 */
void InventorySlot::emptyQuantity() {
    this->quantity = 0;
}

/**
 * @brief Retrieves the quantity of the item stored in the InventorySlot.
 *
 * @return Integer representing the quantity of the item.
 */
int InventorySlot::getQuantity() const {
    return (this->quantity);
}

/**
 * @brief Sets the quantity of the item in the InventorySlot.
 *
 * @param cnt Integer specifying the new quantity.
 */
void InventorySlot::setQuantity(int cnt) {
    this->quantity = cnt;
}

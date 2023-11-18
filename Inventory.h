//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_INVENTORY_H
#define OOP_INVENTORY_H

#include<vector>
#include <iostream>
#include "InventorySlot.h"


class Inventory
{
protected:

    std::vector<InventorySlot*> inventorySpace;
    const int inventorySize = 30;

public:

    Inventory();

   int getInventorySize() const;

    std::vector<InventorySlot*> getInventorySpace();

    bool isFull();

    bool isEmpty();

    InventorySlot* findItemByNameAndStackSize(const std::string& itemName, int stcksize);

    void setFirstEmptySlot(InventorySlot* toBeAdded);

    void displayInventory();

    int displaySwords();

    void freeEverything();

};

#endif //OOP_INVENTORY_H

//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_INVENTORYSLOT_H
#define OOP_INVENTORYSLOT_H

#include<iostream>
#include "Item.h"

class InventorySlot
{
private:
    Item *curentItem;
    int quantity;


public:
    InventorySlot();

    ~InventorySlot();

    friend std::ostream& operator<<(std::ostream& out, InventorySlot& ob);

    Item* getCurentItem();


    bool isEmpty() const;

    std::string getItemName();

    void addQuantity(int addedQuantity);

    void removeQuantity(int removedQuantity);

    void setItemType(Item *itemType);

    void emptyQuantity();

    int getQuantity() const;

    void setQuantity(int cnt);

};


#endif //OOP_INVENTORYSLOT_H

//
// Created by dinul on 11/18/2023.
//
#include "Inventory.h"

Inventory::Inventory() {
    for (int i = 0; i < this->getInventorySize(); i++) {
        inventorySpace.push_back(new InventorySlot());
        inventorySpace.at(i)->setItemType(new Item());
        inventorySpace.at(i)->emptyQuantity();
    }
}

 int Inventory::getInventorySize() {
    return inventorySize;
}

std::vector<InventorySlot*> Inventory::getInventorySpace() {
    return this->inventorySpace;
}

bool Inventory::isFull() {

    for (int i = 0; i < this->inventorySize; i++) {
        if (this->inventorySpace.at(i)->isEmpty())
            return false;
    }

    return true;
}

bool Inventory::isEmpty(){
    for (int i = 0; i < this->inventorySize; i++)
        if(!this->inventorySpace.at(i)->isEmpty()) return false;
    return true;
}

InventorySlot* Inventory::findItemByNameAndStackSize(const std::string& itemName, int stcksize) {

    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->getItemName()==itemName && this->inventorySpace.at(i)->getQuantity() < stcksize
            && this->inventorySpace.at(i)->getQuantity() > 0) {
            return this->inventorySpace.at(i);
        }
    }

    return nullptr;

}


void Inventory::setFirstEmptySlot(InventorySlot* toBeAdded) {

    for (int i = 0; i < this->getInventorySize(); i++) {

        if (this->inventorySpace.at(i)->isEmpty()) {
            delete this->inventorySpace.at(i);
            this->inventorySpace.at(i) = toBeAdded;
            return;
        }

    }
    std::cout<<"The inventory is full\n";

}

void Inventory::displayInventory() {

    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->getQuantity() <= 0)
            std::cout << "SLOT " << i + 1 << ": " << "Empty\n";
        else
            if(this->inventorySpace.at(i)->getCurentItem()->getDamage())
            std::cout << "SLOT " << i + 1 << ": " << *(this->inventorySpace.at(i)) << " +"<< this->inventorySpace.at(i)->getCurentItem()->getPlusLevel() <<"\n";
            else
                std::cout << "SLOT " << i + 1 << ": " << *(this->inventorySpace.at(i)) <<"\n";
    }
}

int Inventory::displaySwords() {
    std::cout << "Swords available from your inventory:\n";
    int counter = 0;
    for (int i = 0; i < this->getInventorySize(); i++) {
        if (this->inventorySpace.at(i)->getQuantity() > 0 &&
            this->inventorySpace.at(i)->getCurentItem()->getDamage() > 0) {
            std::cout << counter + 1 << ". "
                      << this->inventorySpace.at(i)->getCurentItem()->getName()
                      << " which has +" << this->inventorySpace.at(
                    i)->getCurentItem()->getPlusLevel() << " Plus Level\n";
            counter++;
        }
    }
    return counter;
}

void Inventory::freeEverything() {

    for (int i = 0; i < this->getInventorySize(); i++) {
        delete this->inventorySpace.at(i);

    }

}



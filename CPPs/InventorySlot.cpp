//
// Created by dinul on 11/18/2023.
//
#include "../Headers/InventorySlot.h"

InventorySlot::InventorySlot() {
    this->curentItem = nullptr;
    this->quantity = 0;
}

InventorySlot::~InventorySlot() {
    if(this->curentItem)
    delete (this->curentItem);
}

std::ostream &operator<<(std::ostream &out, InventorySlot &ob) {
    out << "x" << ob.getQuantity() << " " << ob.getItemName();
    return out;
}


Item *InventorySlot::getCurentItem() {
    return (this->curentItem);
}


bool InventorySlot::isEmpty() const {
    if (this->quantity == 0) return (true);
    return (false);
}

std::string InventorySlot::getItemName() {
    return (this->curentItem->getName());

}

void InventorySlot::addQuantity(int addedQuantity) {
    this->quantity = this->quantity + addedQuantity;

}

void InventorySlot::removeQuantity(int removedQuantity) {
    this->quantity = this->quantity - removedQuantity;
}

void InventorySlot::setItemType(Item *itemType) {
    delete this->curentItem;
    this->curentItem = itemType;

}

void InventorySlot::emptyQuantity() {
    this->quantity = 0;
}

int InventorySlot::getQuantity() const {
    return (this->quantity);
}

void InventorySlot::setQuantity(int cnt) {
    this->quantity = cnt;
}


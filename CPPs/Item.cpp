//
// Created by dinul on 11/18/2023.
//
#include<iostream>
#include<string>
#include "../Headers/Item.h"

/**
 * @brief Default constructor for the Item class.
 *
 * Initializes all attributes of the Item class with default values.
 */
Item::Item() : name("Nothing"), givesHeal(false), damage(0), plusLevel(0), levelReq(0), healGain(0), stackSize(0), shopPrice(0) {}

/**
 * @brief Destructor for the Item class.
 *
 * Default destructor to handle cleanup for the Item class.
 */
Item::~Item() = default;

/**
 * @brief Overloaded insertion operator to display details about the Item.
 *
 * @param out Output stream to display item details.
 * @param item Reference to the Item object to be displayed.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &out, const Item &item) {
    out << "Details about this item:" << std::endl;
    out << "Name: " << item.name << std::endl;
    if (item.givesHeal)
        out << "Heal given by 1x " << item.name << " is + " << item.healGain << "HP" << std::endl;
    if (item.damage)
        out << "Damage: " << item.damage << std::endl;
    if (!item.givesHeal)
        out << "Plus Level: " << item.plusLevel << std::endl;
    out << "Level required for buying: " << item.levelReq << std::endl;
    out << "Price for x1 " << item.name << ": " << item.shopPrice;
    out << "\n\n";
    return out;
}

/**
 * @brief Method to increment the plus level of the item by 1.
 */
void Item::IncrementPlusLevel() {
    this->plusLevel += 1;
}

/**
 * @brief Getter method to check if the item provides healing.
 *
 * @return Boolean value indicating if the item gives healing.
 */
bool Item::getGivesHeal() const {
    return this->givesHeal;
}

/**
 * @brief Getter method to retrieve the plus level attribute of the item.
 *
 * @return Integer value representing the plus level of the item.
 */
int Item::getPlusLevel() const {
    return this->plusLevel;
}

/**
 * @brief Getter method to retrieve the level requirement of the item.
 *
 * @return Integer value representing the level requirement of the item.
 */
int Item::getLevelReq() const {
    return this->levelReq;
}

/**
 * @brief Getter method to retrieve the damage attribute of the item.
 *
 * @return Integer value representing the damage attribute of the item.
 */
int Item::getDamage() const {
    return this->damage;
}

/**
 * @brief Getter method to retrieve the name of the item.
 *
 * @return String value representing the name of the item.
 */
std::string Item::getName() {
    return this->name;
}

/**
 * @brief Getter method to retrieve the shop price of the item.
 *
 * @return Integer value representing the shop price of the item.
 */
int Item::getShopPrice() const {
    return this->shopPrice;
}

/**
 * @brief Getter method to retrieve the heal gain of the item.
 *
 * @return Integer value representing the heal gain of the item.
 */
int Item::getHealGain() const {
    return this->healGain;
}

/**
 * @brief Getter method to retrieve the stack size of the item.
 *
 * @return Integer value representing the stack size of the item.
 */
int Item::getStackSize() const {
    return this->stackSize;
}
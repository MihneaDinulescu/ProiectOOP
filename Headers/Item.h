//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>

/**
 * @brief The Item class represents a generic in-game item.
 *
 * The class encapsulates attributes and functionalities related to items,
 * including their name, damage, level requirements, and other properties.
 */
class Item {

protected:
    std::string name;       ///< The name of the item.
    bool givesHeal;         ///< Indicates if the item provides healing.
    int damage;             ///< The damage value of the item.
    int plusLevel;          ///< The additional level provided by the item.
    int levelReq;           ///< The level requirement for using the item.
    int healGain;           ///< The amount of healing provided by the item.
    int stackSize;          ///< The maximum stack size of the item.
    int shopPrice;          ///< The price of the item in the shop.

public:
    /**
     * @brief Default constructor for the Item class.
     *
     * Initializes all attributes of the Item class with default values.
     */
    Item();

    /**
     * @brief Destructor for the Item class.
     *
     * Default destructor to handle cleanup for the Item class.
     */
    virtual ~Item();

    /**
     * @brief Overloaded insertion operator to display details about the Item.
     *
     * @param out Output stream to display item details.
     * @param item Reference to the Item object to be displayed.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const Item &item);

    /**
     * @brief Method to increment the plus level of the item by 1.
     */
    void IncrementPlusLevel();

    /**
     * @brief Getter method to check if the item provides healing.
     *
     * @return Boolean value indicating if the item gives healing.
     */
    bool getGivesHeal() const;

    /**
     * @brief Getter method to retrieve the plus level attribute of the item.
     *
     * @return Integer value representing the plus level of the item.
     */
    int getPlusLevel() const;

    /**
     * @brief Getter method to retrieve the level requirement of the item.
     *
     * @return Integer value representing the level requirement of the item.
     */
    int getLevelReq() const;

    /**
     * @brief Getter method to retrieve the damage attribute of the item.
     *
     * @return Integer value representing the damage attribute of the item.
     */
    int getDamage() const;

    /**
     * @brief Getter method to retrieve the name of the item.
     *
     * @return String value representing the name of the item.
     */
    std::string getName();

    /**
     * @brief Getter method to retrieve the shop price of the item.
     *
     * @return Integer value representing the shop price of the item.
     */
    int getShopPrice() const;

    /**
     * @brief Getter method to retrieve the heal gain of the item.
     *
     * @return Integer value representing the heal gain of the item.
     */
    int getHealGain() const;

    /**
     * @brief Getter method to retrieve the stack size of the item.
     *
     * @return Integer value representing the stack size of the item.
     */
    int getStackSize() const;

};

#endif //OOP_ITEM_H

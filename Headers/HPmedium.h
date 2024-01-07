//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_HPMEDIUM_H
#define OOP_HPMEDIUM_H

#include "Item.h"

/**
 * @brief The HPmedium class represents a specific type of item known as a Medium HP Potion.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Medium HP Potion item within the game world.
 */
class HPmedium : public Item {
public:
    /**
     * @brief Default constructor for the HPmedium class.
     *
     * Initializes a Medium HP Potion with predefined attributes such as name, healing properties,
     * damage, plus level, level requirement, shop price, stack size, and healing gain.
     */
    HPmedium();
};


#endif //OOP_HPMEDIUM_H

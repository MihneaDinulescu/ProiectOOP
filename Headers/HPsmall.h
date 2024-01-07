//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_HPSMALL_H
#define OOP_HPSMALL_H

#include "Item.h"

/**
 * @brief The HPsmall class represents a specific type of item known as a Small HP Potion.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Small HP Potion item within the game world.
 */
class HPsmall : public Item {
public:
    /**
     * @brief Default constructor for the HPsmall class.
     *
     * Initializes a Small HP Potion with predefined attributes such as name, healing properties,
     * damage, plus level, level requirement, shop price, stack size, and healing gain.
     */
    HPsmall();
};


#endif //OOP_HPSMALL_H

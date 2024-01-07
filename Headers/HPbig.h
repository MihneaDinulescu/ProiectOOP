//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_HPBIG_H
#define OOP_HPBIG_H

#include "Item.h"

/**
 * @brief The HPbig class represents a specific type of item known as a Big HP Potion.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Big HP Potion item within the game world.
 */
class HPbig : public Item {
public:
    /**
     * @brief Default constructor for the HPbig class.
     *
     * Initializes a Big HP Potion with predefined attributes such as name, healing properties,
     * damage, plus level, level requirement, shop price, stack size, and healing gain.
     */
    HPbig();
};


#endif //OOP_HPBIG_H

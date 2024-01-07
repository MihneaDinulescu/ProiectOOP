//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_CRESCENTSWORD_H
#define OOP_CRESCENTSWORD_H

#include "Item.h"

/**
 * @brief The CrescentSword class represents a specific type of item called the Crescent Sword, which is a sword.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Crescent Sword item within the game world.
 */
class CrescentSword : public Item {
public:
    /**
     * @brief Default constructor for the CrescentSword class.
     *
     * Initializes a Crescent Sword with predefined attributes such as name, damage,
     * plus level, level requirement, shop price, stack size, and healing gain.
     */
    CrescentSword();
};


#endif //OOP_CRESCENTSWORD_H

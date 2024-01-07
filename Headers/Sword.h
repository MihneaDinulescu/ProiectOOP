//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SWORD_H
#define OOP_SWORD_H

#include "Item.h"

/**
 * @brief The Sword class represents a basic type of item categorized as a sword.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Sword within the game environment.
 */
class Sword : public Item {
public:
    /**
     * @brief Default constructor for the Sword class.
     *
     * Initializes a basic Sword with predefined attributes such as name, damage,
     * plus level, level requirement, shop price, stack size, and healing gain.
     */
    Sword();
};

#endif //OOP_SWORD_H

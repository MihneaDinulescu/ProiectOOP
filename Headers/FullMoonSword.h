//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_FULLMOONSWORD_H
#define OOP_FULLMOONSWORD_H

#include "Item.h"

/**
 * @brief The FullMoonSword class represents a specific type of item called the Full Moon Sword, which is a sword.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Full Moon Sword item within the game world.
 */
class FullMoonSword : public Item {
public:
    /**
     * @brief Default constructor for the FullMoonSword class.
     *
     * Initializes a Full Moon Sword with predefined attributes such as name, damage,
     * plus level, level requirement, shop price, stack size, and healing gain.
     */
    FullMoonSword();
};



#endif //OOP_FULLMOONSWORD_H

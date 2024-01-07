//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SILVERSWORD_H
#define OOP_SILVERSWORD_H

#include "Item.h"

/**
 * @brief The SilverSword class represents a specific type of item known as the Silver Sword, which is categorized as a sword.
 *
 * This class inherits from the Item class and defines properties and behaviors
 * specific to the Silver Sword within the game environment.
 */
class SilverSword : public Item {
public:
    /**
     * @brief Default constructor for the SilverSword class.
     *
     * Initializes a Silver Sword with predefined attributes such as name, damage,
     * plus level, level requirement, shop price, stack size, and healing gain.
     */
    SilverSword();
};


#endif //OOP_SILVERSWORD_H

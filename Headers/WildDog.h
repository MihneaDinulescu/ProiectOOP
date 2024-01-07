//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_WILDDOG_H
#define OOP_WILDDOG_H

#include "Monsters.h"

/**
 * @brief The WildDog class represents a specific type of monster known as Wild Dog.
 *
 * This class inherits from the Monsters class and encapsulates attributes and behaviors
 * that are unique to the Wild Dog monster within the game environment.
 */
class WildDog : public Monsters {
public:
    /**
     * @brief Default constructor for the WildDog class.
     *
     * Constructs a Wild Dog monster with predetermined attributes including damage,
     * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
     */
    WildDog();

    /**
     * @brief Overridden function for executing an attack by the Wild Dog.
     *
     * This function dictates the attack pattern of the Wild Dog against a player,
     * resulting in the decrement of the player's health points.
     *
     * @param player The player object being targeted by the Wild Dog's attack.
     */
    void attack(Player *player) override;
};


#endif //OOP_WILDDOG_H

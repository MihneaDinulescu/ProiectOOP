//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SOLDIER_H
#define OOP_SOLDIER_H

#include "Monsters.h"

/**
 * @brief The Soldier class represents a specific type of monster called Soldier.
 *
 * This class inherits from the Monsters class and defines properties and behaviors
 * specific to the Soldier monster within the game world.
 */
class Soldier : public Monsters {
public:
    /**
     * @brief Default constructor for the Soldier class.
     *
     * Initializes a Soldier monster with predefined attributes such as damage,
     * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
     */
    Soldier();

    /**
     * @brief Overridden function for attacking a player.
     *
     * This function defines the attack behavior of a Soldier monster towards a player,
     * causing damage to the player's health.
     *
     * @param player The player object that the Soldier is attacking.
     */
    void attack(Player *player) override;
};

#endif //OOP_SOLDIER_H

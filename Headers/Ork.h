//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_ORK_H
#define OOP_ORK_H

#include "Monsters.h"

/**
 * @brief The Ork class represents a specific type of monster called Ork.
 *
 * This class inherits from the Monsters class and defines properties and behaviors
 * specific to the Ork monster within the game world.
 */
class Ork : public Monsters {
public:
    /**
     * @brief Default constructor for the Ork class.
     *
     * Initializes an Ork monster with predefined attributes such as damage,
     * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
     */
    Ork();

    /**
     * @brief Overridden function for attacking a player.
     *
     * This function defines the attack behavior of an Ork monster towards a player,
     * causing damage to the player's health.
     *
     * @param player The player object that the Ork is attacking.
     */
    void attack(Player *player) override;
};

#endif //OOP_ORK_H

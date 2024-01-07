//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_TIGER_H
#define OOP_TIGER_H

#include "Monsters.h"

/**
 * @brief The Tiger class represents a specific type of monster known as Tiger.
 *
 * This class inherits from the Monsters class and provides characteristics and behaviors
 * particular to the Tiger monster within the game universe.
 */
class Tiger : public Monsters {
public:
    /**
     * @brief Default constructor for the Tiger class.
     *
     * Initializes a Tiger monster with predefined attributes such as damage,
     * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
     */
    Tiger();

    /**
     * @brief Overridden function for attacking a player.
     *
     * This function defines the attack behavior of a Tiger monster towards a player,
     * resulting in a reduction of the player's health.
     *
     * @param player The player object that the Tiger is attacking.
     */
    void attack(Player *player) override;
};

#endif //OOP_TIGER_H

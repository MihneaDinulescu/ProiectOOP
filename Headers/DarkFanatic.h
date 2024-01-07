//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_DARKFANATIC_H
#define OOP_DARKFANATIC_H

#include "Monsters.h"

/**
 * @brief The DarkFanatic class represents a specific type of monster called Dark Fanatic.
 *
 * This class inherits from the Monsters class and defines properties and behaviors
 * specific to the Dark Fanatic monster within the game world.
 */
class DarkFanatic : public Monsters {
public:
    /**
     * @brief Default constructor for the DarkFanatic class.
     *
     * Initializes a Dark Fanatic monster with predefined attributes such as damage,
     * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
     */
    DarkFanatic();

    /**
     * @brief Overridden function for attacking a player.
     *
     * This function defines the attack behavior of a Dark Fanatic monster towards a player,
     * causing damage to the player's health.
     *
     * @param player The player object that the Dark Fanatic is attacking.
     */
    void attack(Player *player) override;
};

#endif //OOP_DARKFANATIC_H

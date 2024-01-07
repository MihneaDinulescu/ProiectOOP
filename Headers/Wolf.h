//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_WOLF_H
#define OOP_WOLF_H

#include "Monsters.h"

/**
 * @brief The Wolf class represents a specific type of monster known as Wolf.
 *
 * This class extends the Monsters class and defines properties and behaviors
 * that are unique to the Wolf monster within the game environment.
 */
class Wolf : public Monsters {
public:
    /**
     * @brief Default constructor for the Wolf class.
     *
     * Constructs a Wolf monster with defined attributes including damage,
     * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
     */
    Wolf();

    /**
     * @brief Overridden function to execute an attack by the Wolf.
     *
     * This function outlines the attack behavior of the Wolf against a player,
     * resulting in a reduction of the player's health points.
     *
     * @param player The player object that is the target of the Wolf's attack.
     */
    void attack(Player *player) override;
};


#endif //OOP_WOLF_H

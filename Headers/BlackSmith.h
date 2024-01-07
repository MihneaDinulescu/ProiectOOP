//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_BLACKSMITH_H
#define OOP_BLACKSMITH_H

#include<iostream>
#include "Item.h"
#include "Player.h"

/**
 * @brief The Blacksmith class represents a blacksmith character in the game Metin2.
 *
 * This class provides functionalities to upgrade swords, display upgrade chances,
 * and interact with players within the game.
 */
class Blacksmith {
public:
    /**
     * @brief Default constructor for the Blacksmith class.
     *
     * Initializes a new instance of the Blacksmith class.
     */
    Blacksmith();

    /**
     * @brief Destructor for the Blacksmith class.
     *
     * Frees up any resources allocated for the Blacksmith instance.
     */
    ~Blacksmith();

    /**
     * @brief Upgrade the PlusLevel of a given sword for a player.
     *
     * @param sword The sword item to be upgraded.
     * @param player The player who owns the sword.
     * @return True if the upgrade is successful, otherwise false.
     */
    static bool UpgradePlusLevel(Item *sword, Player *player);

    /**
     * @brief Display the upgrade chances for various PlusLevels.
     *
     * This function provides the player with the chances of success
     * when attempting to upgrade a sword's PlusLevel.
     */
    static void displayChances();

    /**
     * @brief Interactive function for a player to interact with the blacksmith.
     *
     * @param player The player interacting with the blacksmith.
     * This function provides an interactive menu for players to
     * interact with the blacksmith.
     */
    void BlacksmithFunction(Player *player);
};


#endif //OOP_BLACKSMITH_H

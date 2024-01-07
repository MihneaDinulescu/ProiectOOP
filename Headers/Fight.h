//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_FIGHT_H
#define OOP_FIGHT_H

#include "Monsters.h"
#include "Player.h"
#include "WildDog.h"
#include "Wolf.h"
#include "Boar.h"
#include "Soldier.h"
#include "Tiger.h"
#include "Ork.h"
#include "DarkFanatic.h"
#include "Player.h"

/**
 * @brief Class representing a fight scenario between a player and multiple monsters.
 *
 * The Fight class encapsulates the logic and methods required to simulate a combat scenario.
 */
class Fight {
private:
    std::vector<Monsters *> fightMobsVector; /**< Vector to store pointers to the monsters involved in the fight. */
    Player *fightPlayer; /**< Pointer to the player participating in the fight. */

    /**
     * @brief Private method to generate monsters for the fight.
     *
     * Generates a set of monsters to be involved in the fight based on randomness.
     */
    void generateMobs();

public:
    /**
     * @brief Explicit constructor for the Fight class.
     *
     * Initializes a Fight instance with a given player.
     *
     * @param player Pointer to the player object participating in the fight.
     */
    explicit Fight(Player *player);

    /**
     * @brief Destructor for the Fight class.
     *
     * Ensures all dynamically allocated resources, such as monster pointers, are properly deallocated.
     */
    ~Fight();

    /**
     * @brief Method to print the monsters involved in the fight along with their current HP.
     */
    void printMobsWithHP();

    /**
     * @brief Method to execute the main fight logic.
     *
     * This method contains the core logic for the fight scenario, including turns and outcomes.
     */
    void fightFunction();

    /**
     * @brief Method to await player input during the fight.
     *
     * Waits for player actions or decisions during the fight, such as choosing an attack.
     */
    void awaitPlayerInput();

    /**
     * @brief Method to simulate the monsters attacking the player.
     *
     * Handles the logic where monsters attack the player during the fight.
     */
    void getAttacked();

    /**
     * @brief Method to execute the player's attack function.
     *
     * Handles the logic where the player initiates an attack against the monsters.
     */
    void hitFunction();
};


#endif //OOP_FIGHT_H

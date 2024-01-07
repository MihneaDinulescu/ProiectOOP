//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_DECISION_FUNCTION_H
#define OOP_DECISION_FUNCTION_H

#include "Player.h"

/**
 * @brief The decisionFunction is a utility function for handling player decisions within the game.
 *
 * This function presents a menu to the player, allowing them to choose between various actions
 * such as teleporting, accessing the inventory, checking health status, visiting the shop,
 * viewing their level, or exiting the game. Based on the player's choice, corresponding
 * functionalities are invoked.
 *
 * @param player Pointer to the Player object whose actions are to be determined.
 * @param maps A vector of Map objects containing the various maps available in the game.
 */
void decisionFunction(Player *player, const std::vector<Maps<std::string> *> &maps);


#endif //OOP_DECISION_FUNCTION_H

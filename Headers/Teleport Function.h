//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_TELEPORT_FUNCTION_H
#define OOP_TELEPORT_FUNCTION_H

#include "Player.h"

/**
 * @brief The TeleportFun function allows a player to teleport to different maps based on their level.
 *
 * This function presents the player with a list of available maps and their minimum level requirements.
 * The player can choose a map to teleport to if their current level meets the minimum level requirement.
 * If the player's level is insufficient, an appropriate message is displayed.
 *
 * @param player Pointer to the Player object initiating the teleportation.
 * @param maps A vector containing pointers to Map objects representing the available maps for teleportation.
 */
void TeleportFun(Player *player, std::vector<Maps<std::string> *> maps);


#endif //OOP_TELEPORT_FUNCTION_H

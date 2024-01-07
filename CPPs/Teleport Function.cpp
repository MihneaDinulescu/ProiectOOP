//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Teleport Function.h"
#include "../Headers/Correct Read Function.h"


/**
 * @brief Teleport function to allow a player to move between maps based on level requirements.
 *
 * This function presents the player with a list of available maps to teleport to. Each map
 * is displayed with its minimum level requirement. Based on the player's choice and level,
 * they are either allowed to teleport or notified about the level requirements.
 *
 * @param player A pointer to the Player object initiating the teleportation.
 * @param maps A vector containing pointers to Map objects representing available maps.
 */
void TeleportFun(Player *player, std::vector<Maps<std::string> *> maps) {
    int op; // Variable to store the user's choice.

    // Display available maps and their corresponding level requirements.
    std::cout << "Enter the number of the Map where you want to teleport\n";
    for (int i = 0; i < 3; i++) {
        std::cout << (i + 1) << ". Map " << maps.at(i)->getName() << " (minimum level requirement : "
                  << maps.at(i)->getLevelReq() << ")\n";
    }
    std::cout << "If you want to leave teleporter enter '0'\n";

    // Read user's choice with a specified range.
    op = read(0, 3);

    // Check if the user chooses to exit.
    if (op == 0) {
        return;
    }
    // Handle user's choice to teleport to specific maps based on level requirements.
    switch (op) {
        // Handle the case where the user chooses to teleport to the first map option.
        case 1: {
            // Check if the player's level meets the minimum level requirement of the chosen map.
            if (player->getLevel() >= maps.at(op - 1)->getLevelReq()) {
                player->setCurrentMap(maps.at(op - 1)); // Set the player's current map to the chosen map.
                player->mapFunction();                  // Execute the map-related function for the player.
            } else {
                // Notify the player if their level is below the minimum level required for the chosen map.
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return; // Return from the function as teleportation is not allowed.
            }
            break; // Exit the current switch case.
        }

// Handle the case where the user chooses to teleport to the second map option.
        case 2: {
            // Check if the player's level meets the minimum level requirement of the chosen map.
            if (player->getLevel() >= maps.at(op - 1)->getLevelReq()) {
                player->setCurrentMap(maps.at(op - 1)); // Set the player's current map to the chosen map.
                player->mapFunction();                  // Execute the map-related function for the player.
            } else {
                // Notify the player if their level is below the minimum level required for the chosen map.
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return; // Return from the function as teleportation is not allowed.
            }
            break; // Exit the current switch case.
        }

// Handle the case where the user chooses to teleport to the third map option.
        case 3: {
            // Check if the player's level meets the minimum level requirement of the chosen map.
            if (player->getLevel() >= maps.at(op - 1)->getLevelReq()) {
                player->setCurrentMap(maps.at(op - 1)); // Set the player's current map to the chosen map.
                player->mapFunction();                  // Execute the map-related function for the player.
            } else {
                // Notify the player if their level is below the minimum level required for the chosen map.
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return; // Return from the function as teleportation is not allowed.
            }
            break; // Exit the current switch case.
        }

// Handle the default case when the user's choice doesn't match any valid option.
        default:
            std::cout << "Invalid Option!\n"; // Display an error message for an invalid choice.
    }

}

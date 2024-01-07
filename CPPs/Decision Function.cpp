//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Decision Function.h"
#include "../Headers/Teleport Function.h"
#include "../Headers/Correct Read Function.h"

/**
 * @brief Implementation of the decisionFunction.
 *
 * This function continuously displays a menu of options to the player and reads their choice.
 * Depending on the selected option, specific functions related to the player's actions are called.
 * The loop continues until the player decides to exit the game.
 *
 * @param player Pointer to the Player object whose actions are being handled.
 * @param maps A vector of Map objects containing the various maps available in the game.
 */
void decisionFunction(Player *player, const std::vector<Maps<std::string> *> &maps) {

    while (true) {

        // Displaying the menu options to the player.
        std::cout << "1. Teleport \n2. Inventory \n3. Health \n4. Shop \n5. Level\n6. Exit\n";

        // Reading the player's decision.
        int decision = read(1, 6);

        // Switch case to handle different decisions.
        switch (decision) {
            case 1:
                TeleportFun(player, maps);
                break;
            case 2:
                player->inventoryFunction();
                break;
            case 3:
                player->healthFunction();
                break;
            case 4:
                player->shopFunction();
                break;
            case 5:
                player->levelFunction();
                break;
            case 6:
                player->endGame();
                return; // Exiting the function and loop.
            default:
                std::cout << "Unknown command!\n"; // Handling invalid input.
        }
    }
}

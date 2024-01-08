//
// Created by dinul on 1/4/2024.
//

#include "../Headers/GameManager.h"

/**
 * @brief Default constructor for the GameManager class.
 *
 * Initializes the player pointer to nullptr.
 */
GameManager::GameManager() {
    player = nullptr;
}

/**
 * @brief Copy constructor for the GameManager class.
 *
 * Deep copies the player and maps from the provided GameManager object to a new GameManager object.
 *
 * @param other Reference to the GameManager object to be copied from.
 */
GameManager::GameManager(const GameManager& other) {
    // Copying the player object if it exists.
    if (other.player) {
        player = new Player(*other.player);
    } else {
        player = nullptr;
    }

    // Copying the maps vector.
    for (auto map : other.maps) {
        maps.push_back(map);
    }
}

/**
 * @brief Assignment operator overload for the GameManager class.
 *
 * Assigns the content of one GameManager object to another GameManager object.
 *
 * @param other Reference to the GameManager object to be assigned from.
 * @return Reference to the updated GameManager object.
 */
GameManager& GameManager::operator=(const GameManager& other) {
    if (this != &other) {
        // Deleting existing maps and player.
        for (auto map : maps) {
            delete map;
        }
        delete player;

        // Copying the player object if it exists.
        if (other.player) {
            player = new Player(*other.player);
        } else {
            player = nullptr;
        }

        // Clearing and copying the maps vector.
        maps.clear();
        for (auto map : other.maps) {
            maps.push_back(map);
        }
    }
    return *this;
}

/**
 * @brief Adds a map to the GameManager's maps vector.
 *
 * @param map Pointer to the Maps object to be added.
 */
void GameManager::addMap(Maps<std::string> *map) {
    maps.push_back(map);
}

/**
 * @brief Sets the player for the GameManager.
 *
 * @param p Pointer to the Player object to be set.
 */
void GameManager::setPlayer(Player *p) {
    player = p;
}

/**
 * @brief Executes the game logic using the set player and maps.
 *
 * Checks if the player and maps are set and then executes the game logic using the decisionFunction.
 * If either is missing, displays an error message.
 */
void GameManager::executeGameLogic() {
    if (player && !maps.empty()) {
        decisionFunction(player, maps);       // Calling decisionFunction
    } else {
        std::cout << "Unable to execute game logic due to missing components." << std::endl;
    }
}

/**
 * @brief Destructor for the GameManager class.
 *
 * Ensures the proper cleanup of dynamically allocated memory for player and maps.
 */
GameManager::~GameManager() {
    delete player;            // Deleting the player object.
    for (auto map : maps) {   // Deleting each Maps object in the maps vector.
        delete map;
    }
}

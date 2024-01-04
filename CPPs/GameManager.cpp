//
// Created by dinul on 1/4/2024.
//

#include "../Headers/GameManager.h"
#include "../Headers/Decision Function.h"

GameManager::GameManager() { player = nullptr; }

GameManager::GameManager(const GameManager& other) {
    // Deep copy maps
    for (auto map : other.maps) {
        maps.push_back(new Maps(*map));
    }

    // Deep copy player
    player = new Player(*other.player); // Assuming Player has a copy constructor
}

// Copy Assignment Operator
GameManager& GameManager::operator=(const GameManager& other) {
    if (this != &other) { // Self-assignment check
        // Delete existing resources
        for (auto map : maps) {
            delete map;
        }
        delete player;

        // Deep copy maps
        maps.clear();
        for (auto map : other.maps) {
            maps.push_back(new Maps(*map)); // Assuming Maps has a copy constructor
        }

        // Deep copy player
        player = new Player(*other.player); // Assuming Player has a copy constructor
    }
    return *this;
}

void GameManager::addMap(Maps *map) {
    maps.push_back(map);
}

void GameManager::setPlayer(Player *p) {
    player = p;
}

void GameManager::executeGameLogic() {
    if (player && !maps.empty()) {
        srand((unsigned int) time(nullptr));
        decisionFunction(player, maps);
    } else {
        std::cout << "Unable to execute game logic due to missing components." << std::endl;
    }
}

GameManager::~GameManager() {
    delete player;
    for (auto map: maps) {
        delete map;
    }
}


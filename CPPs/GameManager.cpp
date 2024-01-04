//
// Created by dinul on 1/4/2024.
//

#include "../Headers/GameManager.h"

GameManager::GameManager() { player = nullptr; }

GameManager::GameManager(const GameManager &other) {

    for (auto map: other.maps) {
        maps.push_back(map->clone());
    }

    player = new Player(*other.player);
}


GameManager &GameManager::operator=(const GameManager &other) {
    if (this != &other) {

        for (auto map: maps) {
            delete map;
        }
        delete player;

        maps.clear();

        for (auto map: other.maps) {
            maps.push_back(map->clone());
        }

        // Deep copy player
        player = new Player(*other.player);
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


//
// Created by dinul on 1/4/2024.
//

#include "../Headers/GameManager.h"
#include "../Headers/Decision Function.h"

GameManager::GameManager() { player = nullptr; }

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


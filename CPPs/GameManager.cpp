//
// Created by dinul on 1/4/2024.
//

#include "../Headers/GameManager.h"

GameManager::GameManager() { player = nullptr; }

GameManager::GameManager(const GameManager& other) {

    if (other.player) {
        player = new Player(*other.player);
    } else {
        player = nullptr;
    }

    for (auto map : other.maps) {
        maps.push_back(map);
    }
}


GameManager& GameManager::operator=(const GameManager& other) {
    if (this != &other) {

        for (auto map : maps) {
            delete map;
        }
        delete player;


        if (other.player) {
            player = new Player(*other.player);
        } else {
            player = nullptr;
        }


        maps.clear();


        for (auto map : other.maps) {
            maps.push_back(map);
        }
    }
    return *this;
}

void GameManager::addMap(Maps<std::string> *map) {
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


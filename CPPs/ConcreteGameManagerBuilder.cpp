//
// Created by dinul on 1/4/2024.
//

#include "../Headers/ConcreteGameManagerBuilder.h"

ConcreteGameManagerBuilder() {
    gameManager = new GameManager();
}

void buildMaps() {
    gameManager->addMap(new Joan());
    gameManager->addMap(new Bakra());
    gameManager->addMap(new Seungryong());
}

void buildPlayer() {
    gameManager->setPlayer(new Player());
}

GameManager *getResult() {
    return gameManager;
}

~

ConcreteGameManagerBuilder() {
    delete gameManager;
}
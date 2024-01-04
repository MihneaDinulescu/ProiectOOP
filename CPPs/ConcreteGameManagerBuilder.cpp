//
// Created by dinul on 1/4/2024.
//

#include "../Headers/ConcreteGameManagerBuilder.h"

ConcreteGameManagerBuilder::ConcreteGameManagerBuilder() {
    gameManager = new GameManager();
}

void ConcreteGameManagerBuilder::buildMaps() {
    gameManager->addMap(new Joan());
    gameManager->addMap(new Bakra());
    gameManager->addMap(new Seungryong());
}

void ConcreteGameManagerBuilder::buildPlayer() {
    gameManager->setPlayer(new Player());
}

GameManager * ConcreteGameManagerBuilder::getResult() {
    return gameManager;
}


ConcreteGameManagerBuilder::~ConcreteGameManagerBuilder() {
    delete gameManager;
}
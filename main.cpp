#include <iostream>
#include "Headers/ConcreteGameManagerBuilder.h"

int main() {
    ConcreteGameManagerBuilder builder;
    builder.buildMaps();
    builder.buildPlayer();

    GameManager* gameManager = builder.getResult();
    gameManager->executeGameLogic();

    delete gameManager; // Clean up resources
    return 0;
}







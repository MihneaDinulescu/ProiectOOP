#include <iostream>
#include "Headers/ConcreteGameManagerBuilder.h"

int main() {
    GameManagerBuilder *builder = new ConcreteGameManagerBuilder();
    builder->buildMaps();
    builder->buildPlayer();
    GameManager *gameManager = builder->getResult();
    gameManager->executeGameLogic();
    delete builder;
    return 0;
}







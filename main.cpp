#include <iostream>
#include "Headers/Decision Function.h"
#include "Headers/Joan.h"
#include "Headers/Bakra.h"
#include "Headers/Seungryong.h"

int main() {
    srand((unsigned int) time(nullptr));
    std::vector<Maps *> maps;
    maps.push_back(new Joan("Joan", 1));
    maps.push_back(new Bakra("Bakra", 4));
    maps.push_back(new Seungryong("Seungryong", 10));
    Player *player = new Player();
    decisionFunction(player, maps);
    delete player;
    for (int i = 0; i < 3; i++)
        delete maps.at(i);
    return 0;
}






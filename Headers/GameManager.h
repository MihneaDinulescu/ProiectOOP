//
// Created by dinul on 1/4/2024.
//

#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#include "Player.h"
#include "Joan.h"
#include "Bakra.h"
#include "Seungryong.h"

class GameManager {
private:
    std::vector<Maps *> maps;
    Player *player;

public:
    GameManager();

    void addMap(Maps *map);

    void setPlayer(Player *p);

    void executeGameLogic();

    ~GameManager();

};

#endif //OOP_GAMEMANAGER_H

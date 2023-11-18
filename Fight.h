//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_FIGHT_H
#define OOP_FIGHT_H

#include "Monsters.h"
#include "Player.h"
#include "WildDog.h"
#include "Wolf.h"
#include "Boar.h"
#include "Soldier.h"
#include "Tiger.h"
#include "Ork.h"
#include "DarkFanatic.h"
#include "Health Functions.h"

class Fight {
private:

    std::vector<Monsters *> fightMobsVector;
    Player *fightPlayer;

    void generateMobs();

public:
    explicit Fight(Player *player);

    ~Fight();

    void printMobsWithHP();

    void fightFunction();

    void awaitPlayerInput();

    void getAttacked();

    void hitFunction();
};


#endif //OOP_FIGHT_H

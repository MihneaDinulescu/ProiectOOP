//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_SOLDIERFACTORY_H
#define OOP_SOLDIERFACTORY_H

#include "MonsterFactory.h"
#include "Soldier.h"

class SoldierFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new Soldier();
    }
};

#endif //OOP_SOLDIERFACTORY_H

//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_MONSTERFACTORY_H
#define OOP_MONSTERFACTORY_H

#include "Monsters.h"

class MonsterFactory {
public:
    virtual Monsters* createMonster() = 0;

    virtual ~MonsterFactory();
};

#endif //OOP_MONSTERFACTORY_H

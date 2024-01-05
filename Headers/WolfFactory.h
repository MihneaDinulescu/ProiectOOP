//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_WOLFFACTORY_H
#define OOP_WOLFFACTORY_H

#include "MonsterFactory.h"
#include "Wolf.h"

class WolfFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new Wolf();
    }
};

#endif //OOP_WOLFFACTORY_H

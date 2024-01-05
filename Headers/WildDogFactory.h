//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_WILDDOGFACTORY_H
#define OOP_WILDDOGFACTORY_H

#include "MonsterFactory.h"
#include "WildDog.h"

class WildDogFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new WildDog();
    }
};

#endif //OOP_WILDDOGFACTORY_H

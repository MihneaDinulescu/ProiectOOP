//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_BOARFACTORY_H
#define OOP_BOARFACTORY_H

#include "MonsterFactory.h"
#include "Boar.h"

class BoarFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new Boar();
    }
};

#endif //OOP_BOARFACTORY_H

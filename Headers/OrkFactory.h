//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_ORKFACTORY_H
#define OOP_ORKFACTORY_H

#include "MonsterFactory.h"
#include "Ork.h"

class OrkFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new Ork();
    }
};


#endif //OOP_ORKFACTORY_H

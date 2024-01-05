//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_TIGERFACTORY_H
#define OOP_TIGERFACTORY_H

#include "MonsterFactory.h"
#include "Tiger.h"

class TigerFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new Tiger();
    }
};

#endif //OOP_TIGERFACTORY_H

//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_DARKFANATICFACTORY_H
#define OOP_DARKFANATICFACTORY_H

#include "MonsterFactory.h"
#include "DarkFanatic.h"

class DarkFanaticFactory : public MonsterFactory {
public:
    Monsters* createMonster() override {
        return new DarkFanatic();
    }
};

#endif //OOP_DARKFANATICFACTORY_H

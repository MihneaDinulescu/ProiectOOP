//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_WILDDOG_H
#define OOP_WILDDOG_H

#include "Monsters.h"

class WildDog : public Monsters {
public:
    WildDog();

    void attack(Player *player) override;
};

#endif //OOP_WILDDOG_H

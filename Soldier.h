//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SOLDIER_H
#define OOP_SOLDIER_H

#include "Monsters.h"

class Soldier : public Monsters{
public:
    Soldier();

    void attack(Player *player) override;
};

#endif //OOP_SOLDIER_H

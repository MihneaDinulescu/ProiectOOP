//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_ORK_H
#define OOP_ORK_H

#include "Monsters.h"

class Ork : public Monsters {
public:
    Ork();

    void attack(Player *player) override;
};

#endif //OOP_ORK_H

//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_BOAR_H
#define OOP_BOAR_H

#include "Monsters.h"

class Boar : public Monsters{
public:
    Boar();

    void attack(Player *player) override;
};

#endif //OOP_BOAR_H

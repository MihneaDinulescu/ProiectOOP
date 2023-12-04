//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_WOLF_H
#define OOP_WOLF_H

#include "Monsters.h"

class Wolf : public Monsters {
public:
    Wolf();

    void attack(Player *player) override;
};

#endif //OOP_WOLF_H

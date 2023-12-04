//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_TIGER_H
#define OOP_TIGER_H

#include "Monsters.h"

class Tiger : public Monsters {
public:
    Tiger();

    void attack(Player *player) override;
};

#endif //OOP_TIGER_H

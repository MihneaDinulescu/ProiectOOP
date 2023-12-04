//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_DARKFANATIC_H
#define OOP_DARKFANATIC_H

#include "Monsters.h"

class DarkFanatic : public Monsters {
public:
    DarkFanatic();

    void attack(Player *player) override;
};

#endif //OOP_DARKFANATIC_H

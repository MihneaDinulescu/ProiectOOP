//
// Created by dinul on 11/18/2023.
//

#include "DarkFanatic.h"

DarkFanatic::DarkFanatic(){
        this->damage=16;
        this->hp=70;
        this->name="Dark Fanatic";
        this->level=20;
        this->region="Seungryong";
        this->xp_gain=130;
        this->yang_drop=250;

    }
    void DarkFanatic::attack(Player *player) {

        player->takedamage(this->damage);

    }

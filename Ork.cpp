//
// Created by dinul on 11/18/2023.
//

#include "Ork.h"

    Ork::Ork(){
        this->damage=13;
        this->hp=60;
        this->name="Ork";
        this->level=17;
        this->region="Seungryong";
        this->xp_gain=105;
        this->yang_drop=200;
    }
    void Ork::attack(Player *player) {

        player->takedamage(this->damage);

    }

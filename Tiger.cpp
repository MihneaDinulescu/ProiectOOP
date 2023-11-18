//
// Created by dinul on 11/18/2023.
//

#include "Tiger.h"

    Tiger::Tiger(){
        this->damage=11;
        this->hp=45;
        this->name="Tiger";
        this->level=12;
        this->region="Bakra";
        this->xp_gain=85;
        this->yang_drop=150;
    }
    void Tiger::attack(Player *player) {

        player->takedamage(this->damage);

    }

//
// Created by dinul on 11/18/2023.
//

#include "Soldier.h"

    Soldier::Soldier(){
        this->damage=8;
        this->hp=30;
        this->name="Soldier";
        this->level=10;
        this->region="Bakra";
        this->xp_gain=70;
        this->yang_drop=100;
    }
    void Soldier::attack(Player *player)  {

        player->takedamage(this->damage);

    }

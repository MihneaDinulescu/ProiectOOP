//
// Created by dinul on 11/18/2023.
//

#include "Wolf.h"

    Wolf::Wolf(){
        this->damage=3;
        this->hp=13;
        this->name="Wolf";
        this->level=3;
        this->region="Joan";
        this->xp_gain=15;
        this->yang_drop=35 + ( rand() % ( 45 - 35 + 1 ) );   //35
    }
    void Wolf::attack(Player *player) {

        player->takedamage(this->damage);

    }

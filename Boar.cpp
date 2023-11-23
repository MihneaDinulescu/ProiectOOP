//
// Created by dinul on 11/18/2023.
//

#include "Boar.h"

    Boar::Boar(){
        this->damage=5;
        this->hp=17;
        this->name="Boar";
        this->level=6;
        this->region="Joan";
        this->xp_gain=20;  // era 35
        this->yang_drop=50 + ( rand() % ( 60 - 50 + 1 ) );  //50
    }
    void Boar::attack(Player *player) {

        player->takedamage(this->damage);

    }
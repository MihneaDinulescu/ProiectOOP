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
        this->xpGain=85;
        this->yangDrop=150;
    }
    void Tiger::attack(Player *player) {

        player->takeDamage(this->damage);
        std::cout<<"Oh no! A Tiger is going to attack you!\n";

    }

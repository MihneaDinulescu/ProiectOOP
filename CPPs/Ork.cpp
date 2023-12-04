//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Ork.h"

Ork::Ork() {
    this->damage = 13;
    this->hp = 60;
    this->name = "Ork";
    this->level = 17;
    this->region = "Seungryong";
    this->xpGain = 105;
    this->yangDrop = 200;
}

void Ork::attack(Player *player) {

    player->takeDamage(this->damage);
    std::cout << "Oh no! An Ork is going to attack you!\n";

}

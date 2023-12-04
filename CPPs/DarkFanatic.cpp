//
// Created by dinul on 11/18/2023.
//

#include "../Headers/DarkFanatic.h"

DarkFanatic::DarkFanatic() {
    this->damage = 16;
    this->hp = 70;
    this->name = "Dark Fanatic";
    this->level = 20;
    this->region = "Seungryong";
    this->xpGain = 130;
    this->yangDrop = 250;

}

void DarkFanatic::attack(Player *player) {

    player->takeDamage(this->damage);
    std::cout << "Oh no! A Dark Fanatic is going to attack you!\n";

}

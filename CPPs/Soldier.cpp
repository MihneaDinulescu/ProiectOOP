//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Soldier.h"

Soldier::Soldier() {
    this->damage = 8;
    this->hp = 30;
    this->name = "Soldier";
    this->level = 10;
    this->region = "Bakra";
    this->xpGain = 70;
    this->yangDrop = 100;
}

void Soldier::attack(Player *player) {

    player->takeDamage(this->damage);
    std::cout << "Oh no! A Soldier is going to attack you!\n";

}

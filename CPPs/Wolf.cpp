//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Wolf.h"

Wolf::Wolf() {
    this->damage = 3;
    this->hp = 13;
    this->name = "Wolf";
    this->level = 3;
    this->region = "Joan";
    this->xpGain = 15;
    this->yangDrop = 35 + (rand() % (45 - 35 + 1));   //35
}

void Wolf::attack(Player *player) {

    player->takeDamage(this->damage);
    std::cout << "Oh no! A Wolf is going to attack you!\n";

}

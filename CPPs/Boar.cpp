//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Boar.h"

Boar::Boar() {
    this->damage = 5;
    this->hp = 17;
    this->name = "Boar";
    this->level = 6;
    this->region = "Joan";
    this->xpGain = 20;  // era 35
    this->yangDrop = 50 + (rand() % (60 - 50 + 1));  //50
}

void Boar::attack(Player *player) {

    player->takeDamage(this->damage);
    std::cout << "Oh no! A Boar is going to attack you!\n";

}
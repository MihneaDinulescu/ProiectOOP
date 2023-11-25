//
// Created by dinul on 11/18/2023.
//

#include "WildDog.h"

WildDog::WildDog(){
    this->damage=1;
    this->hp=10;
    this->name="Wild Dog";
    this->level=1;
    this->region="Joan";
    this->xpGain=7;
    this->yangDrop=20 + ( rand() % ( 30 - 20 + 1 ) );  // 20
}
void WildDog::attack(Player *player) {

player->takeDamage(this->damage);
    std::cout<<"Oh no! A Wild Dog is going to attack you!\n";

}
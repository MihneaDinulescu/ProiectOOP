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
    this->xp_gain=10;
    this->yang_drop=20 + ( rand() % ( 30 - 20 + 1 ) );  // 20
}
void WildDog::attack(Player *player) {

player->takedamage(this->damage);

}
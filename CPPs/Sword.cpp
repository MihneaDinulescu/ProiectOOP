//
// Created by dinul on 11/18/2023.
//
#include "../Headers/Sword.h"

Sword::Sword() {
    this->name = "Sword";
    this->givesHeal = false;
    this->damage = 4;
    this->plusLevel = 0;
    this->levelReq = 1;
    this->shopPrice = 30;
    this->stackSize = 1;
    this->healGain = 0;
}

//
// Created by dinul on 11/18/2023.
//
#include "../Headers/FullMoonSword.h"

FullMoonSword::FullMoonSword() {
    this->name = "Full Moon Sword";
    this->givesHeal = false;
    this->damage = 17;
    this->plusLevel = 0;
    this->levelReq = 8;
    this->shopPrice = 1300;
    this->stackSize = 1;
    this->healGain = 0;
}
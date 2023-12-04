//
// Created by dinul on 11/18/2023.
//
#include "../Headers/HPmedium.h"

HPmedium::HPmedium() {
    this->name = "Medium HP Potion";
    this->givesHeal = true;
    this->damage = 0;
    this->plusLevel = 0;
    this->levelReq = 3;
    this->shopPrice = 30;
    this->stackSize = 3; //era 30
    this->healGain = 10;
}
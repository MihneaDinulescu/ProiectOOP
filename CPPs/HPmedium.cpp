//
// Created by dinul on 11/18/2023.
//
#include "../Headers/HPmedium.h"

/**
 * @brief Implementation of the default constructor for the HPmedium class.
 *
 * Initializes a Medium HP Potion object with predefined attributes such as name, healing properties,
 * damage, plus level, level requirement, shop price, stack size, and healing gain.
 */
HPmedium::HPmedium() {
    this->name = "Medium HP Potion";
    this->givesHeal = true;
    this->damage = 0;
    this->plusLevel = 0;
    this->levelReq = 3;
    this->shopPrice = 30;
    this->stackSize = 3;
    this->healGain = 10;
}
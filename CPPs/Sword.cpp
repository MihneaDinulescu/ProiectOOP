//
// Created by dinul on 11/18/2023.
//
#include "../Headers/Sword.h"

/**
 * @brief Implementation of the default constructor for the Sword class.
 *
 * Initializes a basic Sword object with predefined attributes such as name, damage,
 * plus level, level requirement, shop price, stack size, and healing gain.
 *
 */
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


//
// Created by dinul on 11/18/2023.
//

#include "../Headers/HPsmall.h"

/**
 * @brief Implementation of the default constructor for the HPsmall class.
 *
 * Initializes a Small HP Potion object with predefined attributes such as name, healing properties,
 * damage, plus level, level requirement, shop price, stack size, and healing gain.
 */
HPsmall::HPsmall() {
    this->name = "Small HP Potion";
    this->givesHeal = true;
    this->damage = 0;
    this->plusLevel = 0;
    this->levelReq = 1;
    this->shopPrice = 10;
    this->stackSize = 5;
    this->healGain = 3;
}


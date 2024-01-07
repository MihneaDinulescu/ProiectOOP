//
// Created by dinul on 11/18/2023.
//

#include "../Headers/HPbig.h"

/**
 * @brief Implementation of the default constructor for the HPbig class.
 *
 * Initializes a Big HP Potion object with predefined attributes such as name, healing properties,
 * damage, plus level, level requirement, shop price, stack size, and healing gain.
 */
HPbig::HPbig() {
    this->name = "Big HP Potion";
    this->givesHeal = true;
    this->damage = 0;
    this->plusLevel = 0;
    this->levelReq = 5;
    this->shopPrice = 100;
    this->stackSize = 2;
    this->healGain = 100;
}

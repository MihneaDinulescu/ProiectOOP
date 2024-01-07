//
// Created by dinul on 11/18/2023.
//
#include "../Headers/FullMoonSword.h"

/**
 * @brief Implementation of the default constructor for the FullMoonSword class.
 *
 * Initializes a Full Moon Sword object with predefined attributes such as name, damage,
 * plus level, level requirement, shop price, stack size, and healing gain.
 *
 * Note: The Full Moon Sword is classified as a type of sword.
 */
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

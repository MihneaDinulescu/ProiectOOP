//
// Created by dinul on 11/18/2023.
//
#include "../Headers/SilverSword.h"

/**
 * @brief Implementation of the default constructor for the SilverSword class.
 *
 * Initializes a Silver Sword object with predefined attributes such as name, damage,
 * plus level, level requirement, shop price, stack size, and healing gain.
 *
 * Note: The Silver Sword is explicitly identified as a type of sword.
 */
SilverSword::SilverSword() {
    this->name = "Silver Sword";
    this->givesHeal = false;
    this->damage = 13;
    this->plusLevel = 0;
    this->levelReq = 5;
    this->shopPrice = 700;
    this->stackSize = 1;
    this->healGain = 0;
}

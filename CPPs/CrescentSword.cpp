//
// Created by dinul on 11/18/2023.
//
#include "../Headers/CrescentSword.h"

/**
 * @brief Implementation of the default constructor for the CrescentSword class.
 *
 * Initializes a Crescent Sword object with predefined attributes such as name, damage,
 * plus level, level requirement, shop price, stack size, and healing gain.
 *
 * Note: The Crescent Sword is classified as a type of sword.
 */
CrescentSword::CrescentSword() {
    this->name = "Crescent Sword";
    this->givesHeal = false;
    this->damage = 8;
    this->plusLevel = 0;
    this->levelReq = 4;
    this->shopPrice = 500;
    this->stackSize = 1;
    this->healGain = 0;
}




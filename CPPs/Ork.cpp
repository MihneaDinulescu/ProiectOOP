//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Ork.h"

/**
 * @brief Default constructor for the Ork class.
 *
 * Initializes an Ork monster with predefined attributes such as damage,
 * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
 */
Ork::Ork() {
    this->damage = 13;
    this->hp = 60;
    this->name = "Ork";
    this->level = 17;
    this->region = "Seungryong";
    this->xpGain = 105;
    this->yangDrop = 200;
}

/**
 * @brief Overridden function for attacking a player.
 *
 * This function defines the attack behavior of an Ork monster towards a player,
 * causing damage to the player's health.
 *
 * @param player The player object that the Ork is attacking.
 */
void Ork::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! An Ork is going to attack you!\n";
}
//
// Created by dinul on 11/18/2023.
//

#include "../Headers/DarkFanatic.h"

/**
 * @brief Default constructor for the DarkFanatic class.
 *
 * Initializes a Dark Fanatic monster with predefined attributes such as damage,
 * health points (hp), name, level, region, experience gain (xpGain), and yang drop.
 */
DarkFanatic::DarkFanatic() {
    this->damage = 16;
    this->hp = 70;
    this->name = "Dark Fanatic";
    this->level = 20;
    this->region = "Seungryong";
    this->xpGain = 130;
    this->yangDrop = 250;
}

/**
 * @brief Overridden function for attacking a player.
 *
 * This function defines the attack behavior of a Dark Fanatic monster towards a player,
 * causing damage to the player's health.
 *
 * @param player The player object that the Dark Fanatic is attacking.
 */
void DarkFanatic::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! A Dark Fanatic is going to attack you!\n";
}

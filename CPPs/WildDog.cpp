//
// Created by dinul on 11/18/2023.
//

#include "../Headers/WildDog.h"

/**
 * @brief Default constructor for the WildDog class.
 *
 * Constructs a Wild Dog monster with specific attributes such as damage, health points (hp), name, level, region,
 * experience gain (xpGain), and yang drop.
 */
WildDog::WildDog() {
    this->damage = 1;
    this->hp = 10;
    this->name = "Wild Dog";
    this->level = 1;
    this->region = "Joan";
    this->xpGain = 7;
    this->yangDrop = 20 + (rand() % (30 - 20 + 1));
}

/**
 * @brief Function to implement an attack by the Wild Dog monster on the player.
 *
 * This function is responsible for reducing the player's health based on the Wild Dog's damage attribute.
 *
 * @param player The player object that will experience a reduction in health due to the Wild Dog's attack.
 */
void WildDog::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! A Wild Dog is going to attack you!\n";
}
//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Tiger.h"

/**
 * @brief Default constructor for the Tiger class.
 *
 * Initializes a Tiger monster with specific attributes like damage, health points (hp), name, level, region,
 * experience gain (xpGain), and yang drop.
 */
Tiger::Tiger() {
    this->damage = 11;
    this->hp = 45;
    this->name = "Tiger";
    this->level = 12;
    this->region = "Bakra";
    this->xpGain = 85;
    this->yangDrop = 150;
}

/**
 * @brief Function to execute an attack by the Tiger monster on the player.
 *
 * This function reduces the player's health based on the Tiger's damage attribute.
 *
 * @param player The player object that will receive damage from the Tiger's attack.
 */
void Tiger::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! A Tiger is going to attack you!\n";
}

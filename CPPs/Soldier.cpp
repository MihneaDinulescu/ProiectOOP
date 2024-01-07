//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Soldier.h"

/**
 * @brief Default constructor for the Soldier class.
 *
 * Initializes a Soldier monster with specific attributes such as damage, health points (hp), name, level, region,
 * experience gain (xpGain), and yang drop.
 */
Soldier::Soldier() {
    this->damage = 8;
    this->hp = 30;
    this->name = "Soldier";
    this->level = 10;
    this->region = "Bakra";
    this->xpGain = 70;
    this->yangDrop = 100;
}

/**
 * @brief Function to execute an attack by the Soldier monster on the player.
 *
 * This function reduces the player's health based on the Soldier's damage attribute.
 *
 * @param player The player object that will receive damage from the Soldier's attack.
 */
void Soldier::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! A Soldier is going to attack you!\n";
}
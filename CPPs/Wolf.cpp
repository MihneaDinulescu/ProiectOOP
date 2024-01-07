//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Wolf.h"


/**
 * @brief Default constructor for the Wolf class.
 *
 * Initializes a Wolf monster with specific attributes like damage, health points (hp), name, level, region,
 * experience gain (xpGain), and yang drop.
 */
Wolf::Wolf() {
    this->damage = 3;
    this->hp = 13;
    this->name = "Wolf";
    this->level = 3;
    this->region = "Joan";
    this->xpGain = 15;
    this->yangDrop = 35 + (rand() % (45 - 35 + 1));  // 35
}

/**
 * @brief Function to simulate an attack by the Wolf monster on the player.
 *
 * This function triggers a reduction in the player's health based on the Wolf's damage attribute.
 *
 * @param player The player object that will suffer a decrease in health due to the Wolf's attack.
 */
void Wolf::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! A Wolf is going to attack you!\n";
}

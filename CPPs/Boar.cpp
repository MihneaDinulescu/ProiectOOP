//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Boar.h"

/**
 * @brief Construct a new Boar:: Boar object
 *
 * The constructor initializes the attributes of the boar such as its damage, health points,
 * name, level, region, experience points gain, and yang drop.
 */
Boar::Boar() {
    this->damage = 5;
    this->hp = 17;
    this->name = "Boar";
    this->level = 6;
    this->region = "Joan";
    this->xpGain = 20;
    this->yangDrop = 50 + (rand() % (60 - 50 + 1));  // Adjusted from 50 to a random value between 50 and 60
}

/**
 * @brief Attack behavior implementation for the Boar class.
 *
 * This function executes the attack behavior of the boar towards a player.
 * The boar inflicts damage on the player by calling the takeDamage method
 * from the Player class and provides a corresponding attack message.
 *
 * @param player Pointer to the Player object that the boar is attacking.
 */
void Boar::attack(Player *player) {
    player->takeDamage(this->damage);
    std::cout << "Oh no! A Boar is going to attack you!\n";
}

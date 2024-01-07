//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_BOAR_H
#define OOP_BOAR_H

#include "Monsters.h"

/**
 * @brief The Boar class represents a specific monster type, the boar, in the game Metin2.
 *
 * This class extends the functionalities of the Monsters class and defines
 * specific behaviors and characteristics unique to the boar monster within the game.
 */
class Boar : public Monsters {
public:
    /**
     * @brief Default constructor for the Boar class.
     *
     * Initializes a Boar object with predefined attributes such as damage, health points (hp),
     * name, level, region, experience points gain, and yang drop.
     */
    Boar();

    /**
     * @brief Method that implements the attack behavior of the boar towards a player.
     *
     * @param player Pointer to the Player object that the boar is attacking.
     * The boar inflicts damage on the player and displays a corresponding attack message.
     */
    void attack(Player *player) override;
};


#endif //OOP_BOAR_H

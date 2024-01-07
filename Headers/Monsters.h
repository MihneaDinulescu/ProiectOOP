//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_MONSTERS_H
#define OOP_MONSTERS_H

#include "Player.h"

/**
 * @brief The Monsters class represents the base class for various monsters in the game.
 *
 * The Monsters class defines the common attributes and behaviors that are shared among
 * different monster types in the game, such as damage, health points (hp), name, level, region,
 * experience gain (xpGain), and yang drop.
 */
class Monsters {
protected:
    int damage;           ///< Damage value of the monster.
    int hp;               ///< Health points of the monster.
    std::string name;     ///< Name of the monster.
    int level;            ///< Level of the monster.
    std::string region;   ///< Region where the monster is located.
    int xpGain;           ///< Experience points gained when the monster is defeated.
    double yangDrop;      ///< Amount of yang (in-game currency) dropped by the monster.

public:
    /**
     * @brief Default constructor for the Monsters class.
     *
     * Initializes all attributes with default values.
     */
    Monsters();

    /**
     * @brief Virtual destructor for the Monsters class.
     */
    virtual ~Monsters();

    /**
     * @brief Copy constructor for the Monsters class.
     *
     * @param copy Reference to the Monsters object being copied.
     */
    Monsters(const Monsters &copy);

    /**
     * @brief Assignment operator for the Monsters class.
     *
     * @param monster Reference to the Monsters object being assigned.
     * @return Reference to the assigned Monsters object.
     */
    Monsters &operator=(const Monsters &monster);

    /**
     * @brief Virtual function to define the attack behavior of the monster.
     *
     * @param player Pointer to the Player object being attacked.
     */
    virtual void attack(Player *player) = 0;

    /**
     * @brief Getter method to retrieve the experience gain of the monster.
     *
     * @return Experience points gained upon defeating the monster.
     */
    int getXpGain() const;

    /**
     * @brief Getter method to retrieve the damage value of the monster.
     *
     * @return Damage value of the monster.
     */
    int getDamage() const;

    /**
     * @brief Getter method to retrieve the health points of the monster.
     *
     * @return Health points of the monster.
     */
    int getHp() const;

    /**
     * @brief Getter method to retrieve the name of the monster.
     *
     * @return Name of the monster.
     */
    std::string getName();

    /**
     * @brief Function to reduce the health points of the monster by a specified amount.
     *
     * @param dmg Amount of damage to be inflicted on the monster.
     */
    void takeDamage(int dmg);

    /**
     * @brief Getter method to retrieve the yang drop value of the monster.
     *
     * @return Yang dropped by the monster.
     */
    double getYangDrop() const;
};

#endif //OOP_MONSTERS_H

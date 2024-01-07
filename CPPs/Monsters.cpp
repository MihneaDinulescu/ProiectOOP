//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Monsters.h"

/**
 * @brief Default constructor for the Monsters class.
 *
 * Initializes all attributes of the Monsters class with default values.
 */
Monsters::Monsters()
        : damage(0), hp(0), name("NULL"), level(0), region("NULL"), xpGain(0), yangDrop(0) {}

/**
 * @brief Destructor for the Monsters class.
 *
 * Default destructor to handle cleanup for the Monsters class.
 */
Monsters::~Monsters() = default;

/**
 * @brief Copy constructor for the Monsters class.
 *
 * Copies all attributes from the given Monsters object to the current object.
 *
 * @param copy Reference to the Monsters object to be copied.
 */
Monsters::Monsters(const Monsters &copy) {
    this->damage = copy.damage;
    this->hp = copy.hp;
    this->name = copy.name;
    this->level = copy.level;
    this->region = copy.region;
    this->xpGain = copy.xpGain;
    this->yangDrop = copy.yangDrop;
}

/**
 * @brief Assignment operator for the Monsters class.
 *
 * Assigns all attributes from the given Monsters object to the current object.
 * Checks for self-assignment before proceeding.
 *
 * @param monster Reference to the Monsters object to be assigned.
 * @return Reference to the current Monsters object after assignment.
 */
Monsters &Monsters::operator=(const Monsters &monster) {
    if (this != &monster) {  // Check for self-assignment
        this->damage = monster.damage;
        this->hp = monster.hp;
        this->name = monster.name;
        this->level = monster.level;
        this->region = monster.region;
        this->xpGain = monster.xpGain;
        this->yangDrop = monster.yangDrop;
    }
    return *this;
}

/**
 * @brief Getter method to retrieve the experience gain of the monster.
 *
 * @return Integer value representing the experience gain of the monster.
 */
int Monsters::getXpGain() const {
    return this->xpGain;
}

/**
 * @brief Getter method to retrieve the damage value of the monster.
 *
 * @return Integer value representing the damage value of the monster.
 */
int Monsters::getDamage() const {
    return this->damage;
}

/**
 * @brief Getter method to retrieve the health points of the monster.
 *
 * @return Integer value representing the health points of the monster.
 */
int Monsters::getHp() const {
    return this->hp;
}

/**
 * @brief Getter method to retrieve the name of the monster.
 *
 * @return String value representing the name of the monster.
 */
std::string Monsters::getName() {
    return this->name;
}

/**
 * @brief Function to reduce the health points of the monster by a specified amount.
 *
 * @param dmg Integer value representing the damage to be inflicted on the monster.
 */
void Monsters::takeDamage(int dmg) {
    this->hp -= dmg;
}

/**
 * @brief Getter method to retrieve the yang drop value of the monster.
 *
 * @return Double value representing the yang drop value of the monster.
 */
double Monsters::getYangDrop() const {
    return this->yangDrop;
}

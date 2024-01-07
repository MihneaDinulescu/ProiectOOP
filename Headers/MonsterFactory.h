//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_MONSTERFACTORY_H
#define OOP_MONSTERFACTORY_H

#include "Monsters.h"

/**
 * @brief Abstract class representing the Monster Factory.
 *
 * This abstract class follows the Abstract Factory design pattern to create instances of Monsters.
 */
class MonsterFactory {
public:
    /**
     * @brief Pure virtual function to create a Monster.
     *
     * @return Returns a pointer to the created Monster object.
     */
    virtual Monsters* createMonster() = 0;

    /**
     * @brief Virtual destructor for the MonsterFactory class.
     *
     * Provides a base class with a virtual destructor to ensure proper destruction of derived classes.
     */
    virtual ~MonsterFactory();
};

#endif //OOP_MONSTERFACTORY_H

//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_SOLDIERFACTORY_H
#define OOP_SOLDIERFACTORY_H

#include "MonsterFactory.h"
#include "Soldier.h"

/**
 * @brief Concrete derived class representing a Soldier Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Soldier monsters.
 */
class SoldierFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce a Soldier monster.
     *
     * @return Returns a pointer to a newly created Soldier monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_SOLDIERFACTORY_H

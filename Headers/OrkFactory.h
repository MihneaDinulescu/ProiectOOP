//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_ORKFACTORY_H
#define OOP_ORKFACTORY_H

#include "MonsterFactory.h"
#include "Ork.h"

/**
 * @brief Concrete derived class representing an Ork Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Ork monsters.
 */
class OrkFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce an Ork monster.
     *
     * @return Returns a pointer to a newly created Ork monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_ORKFACTORY_H

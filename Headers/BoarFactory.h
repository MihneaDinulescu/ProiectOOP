//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_BOARFACTORY_H
#define OOP_BOARFACTORY_H

#include "MonsterFactory.h"
#include "Boar.h"

/**
 * @brief Concrete derived class representing a Boar Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Boar monsters.
 */
class BoarFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce a Boar monster.
     *
     * @return Returns a pointer to a newly created Boar monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_BOARFACTORY_H

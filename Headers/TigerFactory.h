//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_TIGERFACTORY_H
#define OOP_TIGERFACTORY_H

#include "MonsterFactory.h"
#include "Tiger.h"

/**
 * @brief Concrete derived class representing a Tiger Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Tiger monsters.
 */
class TigerFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce a Tiger monster.
     *
     * @return Returns a pointer to a newly created Tiger monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_TIGERFACTORY_H

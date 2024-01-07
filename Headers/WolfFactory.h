//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_WOLFFACTORY_H
#define OOP_WOLFFACTORY_H

#include "MonsterFactory.h"
#include "Wolf.h"

/**
 * @brief Concrete derived class representing a Wolf Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Wolf monsters.
 */
class WolfFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce a Wolf monster.
     *
     * @return Returns a pointer to a newly created Wolf monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_WOLFFACTORY_H

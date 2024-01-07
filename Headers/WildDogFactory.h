//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_WILDDOGFACTORY_H
#define OOP_WILDDOGFACTORY_H

#include "MonsterFactory.h"
#include "WildDog.h"

/**
 * @brief Concrete derived class representing a Wild Dog Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Wild Dog monsters.
 */
class WildDogFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce a Wild Dog monster.
     *
     * @return Returns a pointer to a newly created Wild Dog monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_WILDDOGFACTORY_H

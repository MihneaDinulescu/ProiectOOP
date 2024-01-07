//
// Created by dinul on 1/5/2024.
//

#ifndef OOP_DARKFANATICFACTORY_H
#define OOP_DARKFANATICFACTORY_H

#include "MonsterFactory.h"
#include "DarkFanatic.h"

/**
 * @brief Concrete derived class representing a Dark Fanatic Factory.
 *
 * This class inherits from the MonsterFactory and provides an implementation to create Dark Fanatic monsters.
 */
class DarkFanaticFactory : public MonsterFactory {
public:
    /**
     * @brief Implementation of the createMonster method to produce a Dark Fanatic monster.
     *
     * @return Returns a pointer to a newly created Dark Fanatic monster object.
     */
    Monsters* createMonster() override;
};

#endif //OOP_DARKFANATICFACTORY_H

//
// Created by dinul on 1/7/2024.
//

#include "../Headers/SoldierFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the SoldierFactory.
 *
 * This method instantiates and returns a new Soldier object, representing a monster of type Soldier.
 *
 * @return Returns a pointer to a newly created Soldier monster object.
 */
Monsters* SoldierFactory::createMonster() {
    return new Soldier();  // Instantiating a new Soldier object and returning its pointer.
}
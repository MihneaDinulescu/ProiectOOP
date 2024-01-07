//
// Created by dinul on 1/7/2024.
//

#include "../Headers/OrkFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the OrkFactory.
 *
 * This method instantiates and returns a new Ork object, representing a monster of type Ork.
 *
 * @return Returns a pointer to a newly created Ork monster object.
 */
Monsters* OrkFactory::createMonster() {
    return new Ork();  // Instantiating a new Ork object and returning its pointer.
}
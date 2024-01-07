//
// Created by dinul on 1/7/2024.
//

#include "../Headers/TigerFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the TigerFactory.
 *
 * This method instantiates and returns a new Tiger object, representing a monster of type Tiger.
 *
 * @return Returns a pointer to a newly created Tiger monster object.
 */
Monsters* TigerFactory::createMonster() {
    return new Tiger();  // Instantiating a new Tiger object and returning its pointer.
}
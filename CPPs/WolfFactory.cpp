//
// Created by dinul on 1/7/2024.
//

#include "../Headers/WolfFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the WolfFactory.
 *
 * This method creates and returns a new Wolf object, representing a monster of type Wolf.
 *
 * @return Returns a pointer to a newly created Wolf monster object.
 */
Monsters* WolfFactory::createMonster() {
    return new Wolf();  // Instantiating a new Wolf object and returning its pointer.
}
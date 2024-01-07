//
// Created by dinul on 1/7/2024.
//

#include "../Headers/DarkFanaticFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the DarkFanaticFactory.
 *
 * This method instantiates and returns a new Dark Fanatic object, representing a monster of type Dark Fanatic.
 *
 * @return Returns a pointer to a newly created Dark Fanatic monster object.
 */
Monsters* DarkFanaticFactory::createMonster() {
    return new DarkFanatic();  // Instantiating a new Dark Fanatic object and returning its pointer.
}
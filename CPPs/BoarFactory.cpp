//
// Created by dinul on 1/7/2024.
//

#include "../Headers/BoarFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the BoarFactory.
 *
 * This method instantiates and returns a new Boar object, representing a monster of type Boar.
 *
 * @return Returns a pointer to a newly created Boar monster object.
 */
Monsters* BoarFactory::createMonster() {
    return new Boar();  // Instantiating a new Boar object and returning its pointer.
}
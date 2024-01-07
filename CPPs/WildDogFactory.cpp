//
// Created by dinul on 1/7/2024.
//


#include "../Headers/WildDogFactory.h"

/**
 * @brief Implementation of the createMonster method specific to the WildDogFactory.
 *
 * This method creates and returns a new WildDog object, representing a monster of type Wild Dog.
 *
 * @return Returns a pointer to a newly created Wild Dog monster object.
 */
Monsters* WildDogFactory::createMonster() {
    return new WildDog();  // Instantiating a new WildDog object and returning its pointer.
}
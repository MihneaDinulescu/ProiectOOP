//
// Created by dinul on 1/4/2024.
//

#include "../Headers/ConcreteGameManagerBuilder.h"

/**
 * @brief Default constructor for ConcreteGameManagerBuilder.
 *
 * Initializes the ConcreteGameManagerBuilder by creating a new GameManager instance.
 */
ConcreteGameManagerBuilder::ConcreteGameManagerBuilder() {
    gameManager = new GameManager();
}

/**
 * @brief Copy constructor for ConcreteGameManagerBuilder.
 *
 * Initializes the ConcreteGameManagerBuilder by creating a deep copy of another ConcreteGameManagerBuilder instance.
 *
 * @param other Another instance of ConcreteGameManagerBuilder to copy from.
 */
ConcreteGameManagerBuilder::ConcreteGameManagerBuilder(const ConcreteGameManagerBuilder& other) {
    gameManager = new GameManager(*other.gameManager);
}

/**
 * @brief Assignment operator for ConcreteGameManagerBuilder.
 *
 * Assigns the contents of one ConcreteGameManagerBuilder instance to another.
 * Ensures a deep copy to prevent shallow copying of dynamic memory.
 *
 * @param other Another instance of ConcreteGameManagerBuilder to assign from.
 * @return Reference to the assigned ConcreteGameManagerBuilder instance.
 */
ConcreteGameManagerBuilder& ConcreteGameManagerBuilder::operator=(const ConcreteGameManagerBuilder& other) {
    if (this != &other) {
        delete gameManager;
        gameManager = new GameManager(*other.gameManager);
    }
    return *this;
}

/**
 * @brief Method to build maps for the game within the GameManager.
 *
 * Constructs specific map instances and adds them to the GameManager.
 */
void ConcreteGameManagerBuilder::buildMaps() {
    gameManager->addMap(new Joan("Joan", 1));
    gameManager->addMap(new Bakra("Bakra", 4));
    gameManager->addMap(new Seungryong("Seungryong", 10));
}

/**
 * @brief Method to build a player for the game within the GameManager.
 *
 * Constructs a new Player instance and sets it within the GameManager.
 */
void ConcreteGameManagerBuilder::buildPlayer() {
    gameManager->setPlayer(new Player());
}

/**
 * @brief Retrieves the constructed GameManager object.
 *
 * @return Pointer to the constructed GameManager object.
 */
GameManager* ConcreteGameManagerBuilder::getResult() {
    return gameManager;
}

/**
 * @brief Destructor for ConcreteGameManagerBuilder.
 *
 * Ensures the dynamic memory allocated for the GameManager object is properly deallocated.
 */
ConcreteGameManagerBuilder::~ConcreteGameManagerBuilder() {
    delete gameManager;
}

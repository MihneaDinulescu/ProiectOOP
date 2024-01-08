#include <iostream>
#include "Headers/ConcreteGameManagerBuilder.h"

/**
 * @brief The entry point of the game application.
 *
 * The main function serves as the entry point for initializing and executing
 * the game's core functionalities. It follows a builder pattern to create and
 * configure the game manager, maps, and player components. The ConcreteGameManagerBuilder
 * is used to construct the GameManager instance by building maps and initializing
 * the player. Once the GameManager is constructed, the game logic is executed
 * through the executeGameLogic() method, facilitating the gameplay loop and
 * interactions between the player and the game environment. After executing
 * the game logic, the allocated resources associated with the builder are
 * deallocated to prevent memory leaks. Finally, the function returns 0,
 * indicating successful execution of the program.
 *
 * @note The main function orchestrates the initialization of essential game
 * components using the builder pattern, ensuring a structured and modular
 * approach to game setup. By constructing the GameManager, maps, and player
 * through the builder, it facilitates organized and configurable game initialization
 * and execution, promoting maintainability and extensibility of the game application.
 *
 * @return An integer value (0) indicating successful execution of the program.
 */
int main() {
    // Initialize the ConcreteGameManagerBuilder instance.
    GameManagerBuilder *builder = new ConcreteGameManagerBuilder();

    // Build the maps using the builder.
    builder->buildMaps();

    // Build and configure the player using the builder.
    builder->buildPlayer();

    // Obtain the constructed GameManager instance.
    GameManager *gameManager = builder->getResult();

    // Execute the core game logic through the GameManager.
    gameManager->executeGameLogic();

    // Deallocate the resources associated with the builder.
    delete builder;

    // Return 0 indicating successful execution.
    return 0;
}






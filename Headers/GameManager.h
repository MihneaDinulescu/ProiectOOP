//
// Created by dinul on 1/4/2024.
//

#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#include "Player.h"
#include "Joan.h"
#include "Bakra.h"
#include "Seungryong.h"
#include "Decision Function.h"

/**
 * @brief The GameManager class represents a component of the builder design pattern.
 *
 * The GameManager class serves as a game manager that handles various game-related functionalities
 * such as managing maps and players and executing game logic.
 */
class GameManager {
private:
    std::vector<Maps<std::string> *> maps;  // Vector to store pointers to Maps objects.
    Player *player;                          // Pointer to a Player object.

public:
    /**
     * @brief Default constructor for the GameManager class.
     *
     * Initializes a GameManager object with the player pointer set to nullptr.
     */
    GameManager();

    /**
     * @brief Copy constructor for the GameManager class.
     *
     * Constructs a new GameManager object by deep copying the elements from the provided GameManager object.
     *
     * @param other Reference to the GameManager object to be copied from.
     */
    GameManager(const GameManager& other);

    /**
     * @brief Assignment operator overload for the GameManager class.
     *
     * Assigns the content of one GameManager object to another GameManager object.
     *
     * @param other Reference to the GameManager object to be assigned from.
     * @return Reference to the updated GameManager object.
     */
    GameManager& operator=(const GameManager& other);

    /**
     * @brief Adds a map to the GameManager's map vector.
     *
     * @param map Pointer to the Maps object to be added.
     */
    void addMap(Maps<std::string> * map);

    /**
     * @brief Sets the player for the GameManager.
     *
     * @param p Pointer to the Player object to be set.
     */
    void setPlayer(Player *p);

    /**
     * @brief Executes the game logic using the set player and maps.
     *
     * If the player and maps are set, it executes the game logic by calling the decisionFunction.
     * Otherwise, it displays an error message indicating missing components.
     */
    void executeGameLogic();

    /**
     * @brief Destructor for the GameManager class.
     *
     * Ensures the proper cleanup of dynamically allocated memory for player and maps.
     */
    ~GameManager();

};

#endif //OOP_GAMEMANAGER_H

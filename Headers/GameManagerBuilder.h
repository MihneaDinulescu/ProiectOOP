//
// Created by dinul on 1/4/2024.
//

#ifndef OOP_GAMEMANAGERBUILDER_H
#define OOP_GAMEMANAGERBUILDER_H

#include "GameManager.h"

/**
 * @brief GameManagerBuilder class serves as an interface for the Builder design pattern.
 *
 * This class provides pure virtual methods that concrete builder classes must implement.
 * It defines methods to build maps, players, and obtain the constructed GameManager object.
 */
class GameManagerBuilder {
public:
    /**
     * @brief Pure virtual method to build maps for the GameManager.
     */
    virtual void buildMaps() = 0;

    /**
     * @brief Pure virtual method to build a player for the GameManager.
     */
    virtual void buildPlayer() = 0;

    /**
     * @brief Pure virtual method to get the constructed GameManager object.
     *
     * @return Pointer to the constructed GameManager object.
     */
    virtual GameManager *getResult() = 0;

    /**
     * @brief Virtual destructor for the GameManagerBuilder class.
     *
     * Ensures proper cleanup when derived classes are destroyed.
     */
    virtual ~GameManagerBuilder();
};

#endif //OOP_GAMEMANAGERBUILDER_H

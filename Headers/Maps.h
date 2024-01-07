//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_MAPS_H
#define OOP_MAPS_H

#include <iostream>
#include <utility>

/**
 * @brief The Maps class is a generic template representing a game map.
 *
 * This class defines properties and behaviors associated with a game map, such as its name and level requirements.
 * It serves as a base class for specific maps within the game, providing common functionalities.
 */
template<typename T>
class Maps {
private:
    /**
     * @brief The name associated with the map.
     *
     * This field holds the name of the map, represented by the template type T.
     */
    T name;

    /**
     * @brief The minimum level required to access the map.
     *
     * This field specifies the level requirement for accessing the map.
     */
    int levelReq;

public:
    /**
     * @brief Constructor for the Maps class.
     *
     * Initializes a Maps object with the specified name and required level.
     *
     * @param _name The name associated with the map.
     * @param _levelReq The minimum level required to access the map.
     */
    Maps(T _name = "", int _levelReq = 0);

    /**
     * @brief Virtual destructor for the Maps class.
     *
     * Provides a default virtual destructor to ensure proper cleanup for derived classes.
     */
    virtual ~Maps();

    /**
     * @brief Accessor method to retrieve the minimum level required for the map.
     *
     * @return An integer representing the minimum level required to access the map.
     */
    int getLevelReq() const;

    /**
     * @brief Accessor method to retrieve the name of the map.
     *
     * @return The name associated with the map.
     */
    T getName() const;

};

#endif //OOP_MAPS_H

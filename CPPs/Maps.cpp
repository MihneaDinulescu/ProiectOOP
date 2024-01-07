//
// Created by dinul on 11/18/2023.
//
#include "../Headers/Maps.h"

/**
 * @brief Constructor for the Maps class.
 *
 * Initializes a Maps object with the specified name and required level.
 *
 * @param _name The name associated with the map.
 * @param _levelReq The minimum level required to access the map.
 */
template<typename T>
Maps<T>::Maps(T _name, int _levelReq) : name(std::move(_name)), levelReq(_levelReq) {}

/**
 * @brief Virtual destructor for the Maps class.
 *
 * Provides a default virtual destructor to ensure proper cleanup for derived classes.
 */
template<typename T>
Maps<T>::~Maps() = default;

/**
 * @brief Accessor method to retrieve the minimum level required for the map.
 *
 * @return An integer representing the minimum level required to access the map.
 */
template<typename T>
int Maps<T>::getLevelReq() const {
    return this->levelReq;
}

/**
 * @brief Accessor method to retrieve the name of the map.
 *
 * @return The name associated with the map.
 */
template<typename T>
T Maps<T>::getName() const {
    return this->name;
}

// Explicit instantiation for the std::string type.
template class Maps<std::string>;
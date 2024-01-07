//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Seungryong.h"

#include <utility>

/**
 * @brief Constructor for the Seungryong class.
 *
 * Initializes a Seungryong object with the specified name and required level.
 *
 * @param _name The name associated with the Seungryong map.
 * @param _levelReq The minimum level required to access the Seungryong map.
 */
Seungryong::Seungryong(std::string _name, int _levelReq) : Maps(std::move(_name), _levelReq) {}

/**
 * @brief Destructor for the Seungryong class.
 *
 * Default destructor to handle cleanup for the Seungryong class.
 */
Seungryong::~Seungryong() = default;
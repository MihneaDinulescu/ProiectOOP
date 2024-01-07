//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Bakra.h"

/**
 * @brief Constructor for the Bakra class.
 *
 * Initializes a Bakra object by invoking the base class (Maps) constructor
 * with the provided name and level requirement.
 *
 * @param _name The name associated with the Bakra map.
 * @param _levelReq The minimum level required to access the Bakra map.
 */
Bakra::Bakra(std::string _name, int _levelReq) : Maps(std::move(_name), _levelReq) {}

/**
 * @brief Destructor for the Bakra class.
 *
 * Default destructor for the Bakra class. Uses the default behavior provided
 * by the compiler for destructor cleanup.
 */
Bakra::~Bakra() = default;

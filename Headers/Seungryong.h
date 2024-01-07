//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SEUNGRYONG_H
#define OOP_SEUNGRYONG_H

#include "Maps.h"

/**
 * @brief The Seungryong class represents a specific map, Seungryong, in the game.
 *
 * This class inherits functionalities from the Maps<std::string> class and is used to define
 * properties and behaviors specific to the Seungryong map within the game.
 */
class Seungryong : public Maps<std::string> {
public:
    /**
     * @brief Constructor for the Seungryong class.
     *
     * Initializes a Seungryong object with the specified name and required level.
     *
     * @param _name The name associated with the Seungryong map.
     * @param _levelReq The minimum level required to access the Seungryong map.
     */
    explicit Seungryong(std::string _name, int _levelReq);

    /**
     * @brief Destructor for the Seungryong class.
     *
     * Default destructor to handle cleanup for the Seungryong class.
     */
    ~Seungryong() override;
};

#endif //OOP_SEUNGRYONG_H


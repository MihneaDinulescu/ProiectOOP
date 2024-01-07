//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_BAKRA_H
#define OOP_BAKRA_H

#include "Maps.h"

/**
 * @brief The Bakra class represents a specific map, Bakra, in the game Metin2.
 *
 * This class inherits functionalities from the Maps class and is used to define
 * properties and behaviors specific to the Bakra map within the game.
 */
class Bakra : public Maps<std::string> {
public:
    /**
     * @brief Constructor for the Bakra class.
     *
     * Initializes a Bakra object with the specified name and required level.
     *
     * @param _name The name associated with the Bakra map.
     * @param _levelReq The minimum level required to access the Bakra map.
     */
    explicit Bakra(std::string _name, int _levelReq);

    /**
     * @brief Destructor for the Bakra class.
     *
     * Default destructor to handle cleanup for the Bakra class.
     */
    ~Bakra() override;
};


#endif //OOP_BAKRA_H

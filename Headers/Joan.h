//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_JOAN_H
#define OOP_JOAN_H

#include "BlackSmith.h"

/**
 * @brief The Joan class represents a specific map, Joan, in the game.
 *
 * This class inherits functionalities from the Maps class and is used to define
 * properties and behaviors specific to the Joan map within the game.
 */
class Joan : public Maps<std::string> {
private:
    /**
     * @brief Pointer to the Blacksmith associated with the Joan map.
     *
     * This field holds a pointer to the Blacksmith that exists within the Joan map.
     */
    Blacksmith *bs;

public:
    /**
     * @brief Explicit constructor for the Joan class.
     *
     * Initializes a Joan object with the specified name and required level, along with a Blacksmith.
     *
     * @param _name The name associated with the Joan map.
     * @param _levelReq The minimum level required to access the Joan map.
     */
    explicit Joan(const std::string &_name = "", int _levelReq = 0);

    /**
     * @brief Copy constructor for the Joan class.
     *
     * Performs a deep copy of another Joan object.
     *
     * @param other The Joan object to be copied.
     */
    Joan(const Joan &other);

    /**
     * @brief Assignment operator overload for the Joan class.
     *
     * Assigns the contents of another Joan object to this object.
     *
     * @param other The Joan object from which data will be assigned.
     * @return A reference to this Joan object after assignment.
     */
    Joan &operator=(const Joan &other);

    /**
     * @brief Destructor for the Joan class.
     *
     * Default destructor to handle cleanup for the Joan class, including the Blacksmith.
     */
    ~Joan() override;

    /**
     * @brief Accessor method to retrieve the Blacksmith associated with the Joan map.
     *
     * @return A pointer to the Blacksmith object within the Joan map.
     */
    Blacksmith *getBlackSmith();
};

#endif //OOP_JOAN_H

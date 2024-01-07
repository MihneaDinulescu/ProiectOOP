//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Joan.h"

/**
 * @brief Constructor for the Joan class.
 *
 * Initializes a Joan object with the specified name and required level, and creates a Blacksmith.
 *
 * @param _name The name associated with the Joan map.
 * @param _levelReq The minimum level required to access the Joan map.
 */
Joan::Joan(const std::string &_name, int _levelReq) : Maps(_name, _levelReq), bs(new Blacksmith()) {}

/**
 * @brief Destructor for the Joan class.
 *
 * Handles the cleanup by deleting the Blacksmith object.
 */
Joan::~Joan() {
    delete bs;
}

/**
 * @brief Copy constructor for the Joan class.
 *
 * Performs a deep copy of another Joan object, including the Blacksmith.
 *
 * @param other The Joan object to be copied.
 */
Joan::Joan(const Joan &other) : Maps(other), bs(nullptr) {
    if (other.bs != nullptr) {
        this->bs = new Blacksmith(*(other.bs));
    }
}

/**
 * @brief Assignment operator overload for the Joan class.
 *
 * Assigns the contents of another Joan object to this object, ensuring a deep copy.
 *
 * @param other The Joan object from which data will be assigned.
 * @return A reference to this Joan object after assignment.
 */
Joan &Joan::operator=(const Joan &other) {
    if (this != &other) {
        Maps::operator=(other);
        delete this->bs;

        if (other.bs != nullptr) {
            this->bs = new Blacksmith(*(other.bs));
        } else {
            this->bs = nullptr;
        }
    }
    return *this;
}

/**
 * @brief Accessor method to retrieve the Blacksmith associated with the Joan map.
 *
 * @return A pointer to the Blacksmith object within the Joan map.
 */
Blacksmith *Joan::getBlackSmith() {
    return this->bs;
}
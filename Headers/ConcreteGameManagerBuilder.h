//
// Created by dinul on 1/4/2024.
//

#ifndef OOP_CONCRETEGAMEMANAGERBUILDER_H
#define OOP_CONCRETEGAMEMANAGERBUILDER_H

#include "GameManagerBuilder.h"
#include "GameManager.h"

/**
 * @brief Concrete derived class representing a Concrete Game Manager Builder.
 *
 * This class inherits from the GameManagerBuilder interface and provides specific functionalities
 * to construct a GameManager object with predefined configurations for maps and players.
 */
class ConcreteGameManagerBuilder : public GameManagerBuilder {
private:
    GameManager *gameManager; ///< Pointer to the GameManager object being constructed.

public:
    /**
     * @brief Default constructor that initializes the ConcreteGameManagerBuilder.
     */
    ConcreteGameManagerBuilder();

    /**
     * @brief Copy constructor that initializes the ConcreteGameManagerBuilder by copying another instance.
     *
     * @param other Another instance of ConcreteGameManagerBuilder to copy from.
     */
    ConcreteGameManagerBuilder(const ConcreteGameManagerBuilder& other);

    /**
     * @brief Assignment operator that assigns the contents of one ConcreteGameManagerBuilder to another.
     *
     * @param other Another instance of ConcreteGameManagerBuilder to assign from.
     * @return Reference to the assigned ConcreteGameManagerBuilder instance.
     */
    ConcreteGameManagerBuilder& operator=(const ConcreteGameManagerBuilder& other);

    /**
     * @brief Implementation of the buildMaps method to set up game maps within the GameManager.
     */
    void buildMaps() override;

    /**
     * @brief Implementation of the buildPlayer method to set up the player within the GameManager.
     */
    void buildPlayer() override;

    /**
     * @brief Retrieves the constructed GameManager object.
     *
     * @return Pointer to the constructed GameManager object.
     */
    GameManager *getResult() override;

    /**
     * @brief Destructor for the ConcreteGameManagerBuilder class.
     *
     * Responsible for deallocating memory associated with the GameManager object.
     */
    ~ConcreteGameManagerBuilder() override;
};

#endif //OOP_CONCRETEGAMEMANAGERBUILDER_H

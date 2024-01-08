//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Item.h"
#include "Inventory.h"
#include "Maps.h"

/**
 * @brief Represents a player within the game environment, encapsulating attributes and functionalities.
 *
 * The Player class manages various aspects such as health, inventory, weapons, experience, and map locations.
 */
class Player {
private:
    int hp;                   ///< Current health points of the player.
    int damage;               ///< Damage points inflicted by the player.
    int xp;                   ///< Experience points earned by the player.
    Item *sword;              ///< Sword equipped by the player.
    double yang;              ///< In-game currency possessed by the player.
    Inventory *inventory;     ///< Inventory of the player.
    int level;                ///< Level of the player.
    Maps<std::string> *currentMap;  ///< Current map location of the player.

public:
    /**
     * @brief Default constructor for the Player class.
     *
     * Initializes a player with default attributes.
     */
    Player();

    /**
     * @brief Copy constructor for the Player class.
     *
     * Creates a new player object by copying the attributes of another player.
     *
     * @param other The player object to be copied.
     */
    Player(const Player &other);

    /**
     * @brief Assignment operator overload for the Player class.
     *
     * Assigns the attributes of another player object to this player.
     *
     * @param other The player object from which data will be assigned.
     * @return A reference to this player object after assignment.
     */
    Player &operator=(const Player &other);

    /**
    * @brief Method to add experience points to the player.
    *
    * Increases the player's experience points by the provided amount.
    *
    * @param _xp The amount of experience points to add.
    */
    void addXp(int _xp);

    /**
     * @brief Method to subtract experience points from the player.
     *
     * Decreases the player's experience points by the provided amount.
     *
     * @param _xp The amount of experience points to subtract.
     */
    void difXp(int _xp);

    /**
     * @brief Accessor method to retrieve the currently equipped sword of the player.
     *
     * @return A pointer to the Item object representing the equipped sword.
     */
    Item *getSword();

    /**
     * @brief Accessor method to retrieve the level of the player.
     *
     * @return An integer representing the current level of the player.
     */
    int getLevel() const;

    /**
     * @brief Method to increment the player's level by one.
     *
     * Increases the player's level by one.
     */
    void IncrementLevel();

    /**
     * @brief Accessor method to retrieve the current map location of the player.
     *
     * @return A pointer to the Maps object representing the current map location.
     */
    Maps<std::string> *getCurrentMap();

    /**
     * @brief Method to set the current map location of the player.
     *
     * @param map A pointer to the Maps object representing the new map location.
     */
    void setCurrentMap(Maps<std::string> *map);

    /**
     * @brief Method to unset the currently equipped sword of the player.
     *
     * Unequipes the currently equipped sword from the player's hand.
     */
    void setSwordNull();

    /**
     * @brief Method to equip a specific sword for the player.
     *
     * @param sw A pointer to the Item object representing the sword to be equipped.
     */
    void setSword(Item *sw);

    /**
     * @brief Method to heal the player by a specific amount.
     *
     * @param add The amount by which the player's health points should be increased.
     */
    void healPlayer(int add);

    /**
     * @brief Method to decrease the player's currency (yang).
     *
     * @param sum The amount to be subtracted from the player's current yang.
     */
    void difYang(double dif);

    /**
     * @brief Method to increase the player's currency (yang).
     *
     * @param sum The amount to be added to the player's current yang.
     */
    void sumYang(double sum);

    /**
     * @brief Method to set the player's health points.
     *
     * @param HP The value to set as the player's health points.
     */
    void setHp(int HP);

    /**
     * @brief Method to check if the player is dead.
     *
     * @return A boolean value indicating whether the player is dead or not.
     */
    bool isDead() const;

    /**
     * @brief Accessor method to retrieve the player's inventory.
     *
     * @return A pointer to the Inventory object representing the player's inventory.
     */
    Inventory *getInventory();

    /**
     * @brief Method to end the game.
     *
     * This method is used to conclude the game session and to free the allocated resources of the player.
     */
    void endGame();

    /**
     * @brief Accessor method to retrieve the damage the player can inflict.
     *
     * @return An integer representing the total damage potential of the player.
     */
    int getDamage() const;

    /**
     * @brief Method to inflict damage on the player.
     *
     * @param tkdmg The amount of damage to be inflicted on the player.
     */
    void takeDamage(int tkdmg);

    /**
     * @brief Method to display the player's current health points.
     *
     * Displays the player's current health points on the console.
     */
    void displayHp();

    /**
     * @brief Method to display the player's health resources.
     *
     * @return An integer representing the player's number of health resources available.
     */
    int displayHpResource();

    /**
     * @brief Method to regenerate the player's health points.
     *
     * Regenerates a portion of the player's health points over time.
     */
    void regenHp();

    /**
     * @brief Method related to the health functionality of the player.
     */
    void healthFunction();

    /**
     * @brief Method to equip an available sword for the player.
     */
    void equipSword();

    /**
     * @brief Method to unequip the player's currently equipped sword.
     */
    void unequipSword();

    /**
     * @brief Method to restack the player's inventory.
     *
     * Rearranges the health potions in the player's inventory for better organization.
     */
    void restack();

    /**
     * @brief Method related to leveling functionality of the player.
     */
    void levelFunction();

    /**
     * @brief Method related to inventory management functionality of the player.
     */
    void inventoryFunction();

    /**
     * @brief Method related to map functionalities of the player.
     */
    void mapFunction();

    /**
     * @brief Method to allow the player to buy items.
     */
    void buyItems();

    /**
     * @brief Method to allow the player to sell items.
     */
    void sellItems();

    /**
     * @brief Method related to the shop functionality for the player.
     */
    void shopFunction();

};

#endif //OOP_PLAYER_H

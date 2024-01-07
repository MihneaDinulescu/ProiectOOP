//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H

#include "Sword.h"
#include "CrescentSword.h"
#include "SilverSword.h"
#include "FullMoonSword.h"
#include "HPsmall.h"
#include "HPmedium.h"
#include "HPbig.h"
#include <iostream>

/**
 * @brief The Shop class represents an in-game shop containing various items.
 *
 * The Shop class holds instances of different items available for purchase within the game.
 * It provides functionalities to display available items and detailed information about each item.
 */
class Shop {
private:
    Sword s;               ///< Instance of Sword available in the shop.
    CrescentSword cs;     ///< Instance of CrescentSword available in the shop.
    SilverSword ss;       ///< Instance of SilverSword available in the shop.
    FullMoonSword fms;    ///< Instance of FullMoonSword available in the shop.
    HPsmall hps;          ///< Instance of Small HP potion available in the shop.
    HPmedium hpm;         ///< Instance of Medium HP potion available in the shop.
    HPbig hpb;            ///< Instance of Big HP potion available in the shop.

public:
    /**
     * @brief Overloaded insertion operator to display items available in the shop.
     *
     * @param out Output stream to display items.
     * @param shop Reference to the Shop object.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, Shop &shop);

    /**
     * @brief Retrieves the Sword item available in the shop.
     *
     * @return Sword object from the shop.
     */
    Sword getSword();

    /**
     * @brief Retrieves the CrescentSword item available in the shop.
     *
     * @return CrescentSword object from the shop.
     */
    CrescentSword getCrescentSword();

    /**
     * @brief Retrieves the SilverSword item available in the shop.
     *
     * @return SilverSword object from the shop.
     */
    SilverSword getSilverSword();

    /**
     * @brief Retrieves the FullMoonSword item available in the shop.
     *
     * @return FullMoonSword object from the shop.
     */
    FullMoonSword getFullMoonSword();

    /**
     * @brief Retrieves the Small HP potion item available in the shop.
     *
     * @return HPsmall object from the shop.
     */
    HPsmall getHpSmall();

    /**
     * @brief Retrieves the Medium HP potion item available in the shop.
     *
     * @return HPmedium object from the shop.
     */
    HPmedium getHpMedium();

    /**
     * @brief Retrieves the Big HP potion item available in the shop.
     *
     * @return HPbig object from the shop.
     */
    HPbig getHpBig();

    /**
     * @brief Displays the list of available items in the shop to the console.
     */
    void displayItems();

    /**
     * @brief Displays detailed information about selected items from the shop.
     *
     * This function prompts the user to select an item by number and displays its details.
     */
    void detailsItems();

};



#endif //OOP_SHOP_H

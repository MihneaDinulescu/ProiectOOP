//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Shop.h"
#include "../Headers/Correct Read Function.h"

/**
 * @brief Overloaded insertion operator to display items available in the shop.
 *
 * This operator is overloaded to provide a concise display of items available
 * in the shop by listing their names.
 *
 * @param out Output stream to display items.
 * @param shop Reference to the Shop object containing items.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &out, Shop &shop) {
    out << "1. " << shop.s.getName() << std::endl
        << "2. " << shop.cs.getName() << std::endl
        << "3. " << shop.ss.getName() << std::endl
        << "4. " << shop.fms.getName() << std::endl
        << "5. " << shop.hps.getName() << std::endl
        << "6. " << shop.hpm.getName() << std::endl
        << "7. " << shop.hpb.getName() << std::endl;
    return out;
}

/**
 * @brief Retrieves the Sword item available in the shop.
 *
 * @return Sword object from the shop.
 */
Sword Shop::getSword() {
    return s;
}

/**
 * @brief Retrieves the CrescentSword item available in the shop.
 *
 * @return CrescentSword object from the shop.
 */
CrescentSword Shop::getCrescentSword() {
    return cs;
}

/**
 * @brief Retrieves the SilverSword item available in the shop.
 *
 * @return SilverSword object from the shop.
 */
SilverSword Shop::getSilverSword() {
    return ss;
}

/**
 * @brief Retrieves the FullMoonSword item available in the shop.
 *
 * @return FullMoonSword object from the shop.
 */
FullMoonSword Shop::getFullMoonSword() {
    return fms;
}

/**
 * @brief Retrieves the Small HP potion item available in the shop.
 *
 * @return HPsmall object from the shop.
 */
HPsmall Shop::getHpSmall() {
    return hps;
}

/**
 * @brief Retrieves the Medium HP potion item available in the shop.
 *
 * @return HPmedium object from the shop.
 */
HPmedium Shop::getHpMedium() {
    return hpm;
}

/**
 * @brief Retrieves the Big HP potion item available in the shop.
 *
 * @return HPbig object from the shop.
 */
HPbig Shop::getHpBig() {
    return hpb;
}

/**
 * @brief Displays the list of available items in the shop to the console.
 *
 * This function creates a temporary Shop object to utilize the overloaded << operator
 * and display available items.
 */
void Shop::displayItems() {
    Shop sh;
    std::cout << sh;
    std::cout << "\n";
}

/**
 * @brief Displays detailed information about selected items from the shop.
 *
 * This function prompts the user to select an item by number and displays its details
 * using a switch-case structure.
 */
void Shop::detailsItems() {
    Shop::displayItems();
    std::cout << "Enter the number of the specific item for more details : \n";
    int x;
    x = read(1, 7);  // Assuming the read function reads an integer between 1 and 7
    Shop sh;
    switch (x) {
        case 1:
            std::cout << sh.getSword();
            break;
        case 2:
            std::cout << sh.getCrescentSword();
            break;
        case 3:
            std::cout << sh.getSilverSword();
            break;
        case 4:
            std::cout << sh.getFullMoonSword();
            break;
        case 5:
            std::cout << sh.getHpSmall();
            break;
        case 6:
            std::cout << sh.getHpMedium();
            break;
        case 7:
            std::cout << sh.getHpBig();
            break;
        default:
            std::cout << "Invalid option!";
    }
}


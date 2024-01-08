//
// Created by dinul on 11/18/2023.
//
#define MAX_LEVEL 10

#include "../Headers/Player.h"
#include "../Headers/Correct Read Function.h"
#include "../Headers/Fight.h"
#include "../Headers/Joan.h"
#include "../Headers/Shop.h"

/**
 * @brief Default constructor for the Player class.
 *
 * Initializes a Player object with default values for health points (hp), damage,
 * inventory, currency (yang), equipped sword, level, current map, and experience points (xp).
 */
Player::Player() {
    this->hp = 50;
    this->damage = 1;
    this->inventory = new Inventory();
    this->yang = 50;
    this->sword = nullptr;
    this->level = 1;
    this->currentMap = nullptr;
    this->xp = 0;
}

/**
 * @brief Copy constructor for the Player class.
 *
 * Creates a deep copy of another Player object, including its attributes such as hp, damage,
 * experience points (xp), currency (yang), equipped sword, level, inventory, and current map.
 *
 * @param other The Player object to be copied.
 */
Player::Player(const Player &other) {
    hp = other.hp;
    damage = other.damage;
    xp = other.xp;
    yang = other.yang;
    level = other.level;

    // Copy the sword item if it exists in the other Player object.
    if (other.sword) {
        sword = new Item(*other.sword);
    } else {
        sword = nullptr;
    }

    // Copy the inventory if it exists in the other Player object.
    if (other.inventory) {
        inventory = new Inventory(*other.inventory);
    } else {
        inventory = nullptr;
    }

    // Copy the current map if it exists in the other Player object.
    if (other.currentMap) {
        currentMap = new Maps<std::string>(*other.currentMap);
    } else {
        currentMap = nullptr;
    }
}

/**
 * @brief Overloaded assignment operator for the Player class.
 *
 * Assigns the attributes of another Player object to this Player object by creating
 * a deep copy of its attributes such as hp, damage, experience points (xp), currency (yang),
 * equipped sword, level, inventory, and current map.
 *
 * @param other The Player object from which data will be assigned.
 * @return A reference to this Player object after assignment.
 */
Player& Player::operator=(const Player &other) {
    if (this != &other) {
        // Clear existing dynamic memory allocations.
        delete sword;
        delete inventory;
        delete currentMap;

        // Assign attributes from the other Player object.
        hp = other.hp;
        damage = other.damage;
        xp = other.xp;
        yang = other.yang;
        level = other.level;

        // Copy the sword item if it exists in the other Player object.
        if (other.sword) {
            sword = new Item(*other.sword);
        } else {
            sword = nullptr;
        }

        // Copy the inventory if it exists in the other Player object.
        if (other.inventory) {
            inventory = new Inventory(*other.inventory);
        } else {
            inventory = nullptr;
        }

        // Copy the current map if it exists in the other Player object.
        if (other.currentMap) {
            currentMap = new Maps<std::string>(*other.currentMap);
        } else {
            currentMap = nullptr;
        }
    }
    return *this;
}

/**
 * @brief Increases the experience points (xp) of the player by a specified amount.
 *
 * @param _xp Amount of experience points to be added.
 */
void Player::addXp(int _xp) {
    this->xp += _xp;
}

/**
 * @brief Decreases the experience points (xp) of the player by a specified amount.
 *
 * @param _xp Amount of experience points to be subtracted.
 */
void Player::difXp(int _xp) {
    this->xp -= _xp;
}

/**
 * @brief Retrieves the sword currently equipped by the player.
 *
 * @return A pointer to the Item object representing the equipped sword.
 */
Item *Player::getSword() {
    return this->sword;
}

/**
 * @brief Retrieves the current level of the player.
 *
 * @return The level of the player.
 */
int Player::getLevel() const {
    return this->level;
}

/**
 * @brief Increments the level of the player by one.
 */
void Player::IncrementLevel() {
    this->level++;
}

/**
 * @brief Retrieves the current map where the player is located.
 *
 * @return A pointer to the Maps object representing the current map.
 */
Maps<std::string> *Player::getCurrentMap() {
    return this->currentMap;
}

/**
 * @brief Sets the current map for the player.
 *
 * @param map Pointer to the Maps object representing the map to be set.
 */
void Player::setCurrentMap(Maps<std::string> *map) {
    this->currentMap = map;
}

/**
 * @brief Sets the equipped sword of the player to nullptr, indicating no sword is equipped.
 */
void Player::setSwordNull() {
    this->sword = nullptr;
}

/**
 * @brief Sets a specific sword item as the equipped sword for the player.
 *
 * @param sw Pointer to the Item object representing the sword to be equipped.
 */
void Player::setSword(Item *sw) {
    this->sword = sw;
}

/**
 * @brief Increases the health points (hp) of the player by a specified amount.
 *
 * @param add Amount of health points to be added.
 */
void Player::healPlayer(int add) {
    this->hp += add;
}

/**
 * @brief Decreases the currency (yang) of the player by a specified amount.
 *
 * @param dif Amount of currency to be subtracted.
 */
void Player::difYang(double dif) {
    this->yang -= dif;
}

/**
 * @brief Increases the currency (yang) of the player by a specified amount.
 *
 * @param sum Amount of currency to be added.
 */
void Player::sumYang(double sum) {
    this->yang += sum;
}

/**
 * @brief Sets the health points (hp) of the player to a specified value.
 *
 * @param HP Value to set the health points to.
 */
void Player::setHp(int HP) {
    this->hp = HP;
}

/**
 * @brief Checks if the player is dead based on their health points (hp).
 *
 * @return True if the player is dead, otherwise false.
 */
bool Player::isDead() const {
    return (this->hp <= 0);
}

/**
 * @brief Retrieves the inventory of the player.
 *
 * @return Pointer to the Inventory object representing the player's inventory.
 */
Inventory *Player::getInventory() {
    return this->inventory;
}

/**
 * @brief Ends the game session for the player by freeing all inventory items and deleting the inventory.
 */
void Player::endGame() {
    this->inventory->freeEverything();
    delete this->inventory;
}

/**
 * @brief Retrieves the damage value of the player.
 *
 * @return The damage value of the player.
 */
int Player::getDamage() const {
    return this->damage;
}

/**
 * @brief Reduces the health points (hp) of the player by a specified amount.
 *
 * @param tkdmg Amount of damage to be taken by the player.
 */
void Player::takeDamage(int tkdmg) {
    this->hp -= tkdmg;
}

/**
 * @brief Displays the health bar of the player based on their current health points (hp).
 *
 * This function visually represents the player's health using a series of '=' characters,
 * where each '=' represents a single health point. The total health points are also displayed as a percentage.
 */
void Player::displayHp() {
    std::cout << "HEALTH BAR : ";
    for (int i = 0; i < this->hp; i++) {
        std::cout << "=";
    }
    std::cout << "   " << this->hp << "%\n";
}

/**
 * @brief Displays available healing items in the player's inventory.
 *
 * This function iterates over the player's inventory to identify and display items that can heal the player.
 * Each healing item's quantity and name are presented if they are available in the inventory.
 *
 * @return The number of available healing items in the inventory.
 */
int Player::displayHpResource() {
    std::cout << "Heal items available from your inventory:\n";
    int counter = 0;
    for (int i = 0; i < this->inventory->getInventorySize(); i++) {
        if (this->inventory->getInventorySpace().at(i)->getCurentItem()->getGivesHeal() &&
            this->inventory->getInventorySpace().at(i)->getQuantity() > 0) {
            std::cout << counter + 1 << ". " << this->inventory->getInventorySpace().at(i)->getQuantity() << "x "
                      << this->inventory->getInventorySpace().at(i)->getCurentItem()->getName() << std::endl;
            counter++;
        }
    }
    std::cout << std::endl;
    if (counter == 0) {
        std::cout << "You don't have heal potions!\n";
    }
    return counter;
}

/**
 * @brief Allows the player to regenerate their health points (hp) using available health potions.
 *
 * This function prompts the player to select a health potion from their inventory to use for healing.
 * If the player's health is less than the maximum (50 in this case), the selected health potion
 * is used to restore the player's health. The function also provides feedback messages to inform
 * the player about their healing status.
 */
void Player::regenHp() {
    std::cout << "You need to use only health potions\n";
    int cnt = displayHpResource();
    if (cnt == 0) {
        std::cout << "You do not have any HP potions\n";
        return;
    }
    int nrop;
    std::cout << "Enter the number of the item with which you want to heal :";
    nrop = read(1, 30);
    int nr = 0;
    for (int i = 0; i < this->inventory->getInventorySize(); i++) {
        if (this->inventory->getInventorySpace().at(i)->getCurentItem()->getGivesHeal() &&
            this->inventory->getInventorySpace().at(i)->getQuantity() > 0)
            nr++;
        if (nr == nrop) {
            if (this->hp + this->inventory->getInventorySpace().at(i)->getCurentItem()->getHealGain() > 50)
                healPlayer(50 - (this->hp));
            else
                healPlayer(this->inventory->getInventorySpace().at(i)->getCurentItem()->getHealGain());
            this->inventory->getInventorySpace().at(i)->removeQuantity(1);
            std::cout << "You have successfully healed!\n";
            return;
        }
    }
    std::cout << "Invalid option!\n";
}

/**
 * @brief Provides an interface for the player to manage and view their health-related functionalities.
 *
 * This function presents the player with a menu that allows them to:
 * 1. View their current health points.
 * 2. Display available healing resources in their inventory.
 * 3. Regenerate their health by using available health potions.
 * 4. Exit the health management system.
 * The function handles the selected option accordingly and loops until the player chooses to exit.
 */
void Player::healthFunction() {
    while (true) {
        int op;
        std::cout << "1. See HP\n2. See heal resources available\n3. Regenerate your HP\n4. Exit\n";
        op = read(1, 4);
        switch (op) {
            case 1:
                Player::displayHp();
                break;
            case 2:
                Player::displayHpResource();
                break;
            case 3:
                if (this->hp < 50)
                    Player::regenHp();
                else
                    std::cout << "You have Full HP\n";
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid option!\n";
        }
    }
}

/**
 * @brief Allows the player to equip a sword from their inventory.
 *
 * This function presents the player with a list of swords available in their inventory
 * and prompts them to select a sword to equip. Once a valid sword is selected, it becomes
 * the player's active sword for combat.
 * The function provides feedback messages based on the player's action.
 */
void Player::equipSword() {
    int op;
    int x;
    if (this->sword != (nullptr)) {
        std::cout << "You already have equipped a sword\n";
        return;
    }
    op = this->inventory->displaySwords();
    if (op == 0) {
        std::cout << "You don't have any swords in your inventory!\n";
        return;
    }
    std::cout << "Enter the number of the sword you want to equip :";
    x = read(1, 30);
    int counter = 0;
    for (int i = 0; i < this->inventory->getInventorySize(); i++) {
        if (this->inventory->getInventorySpace().at(i)->getQuantity() > 0 &&
            this->inventory->getInventorySpace().at(i)->getCurentItem()->getDamage() > 0)
            counter++;
        if (counter == x) {
            this->setSword(this->inventory->getInventorySpace().at(i)->getCurentItem());
            std::cout << "You have successfully equipped your sword!\n";
            return;
        }
    }
    std::cout << "Invalid option!\n";
}

/**
 * @brief Allows the player to unequip their currently equipped sword.
 *
 * This function allows the player to remove the currently equipped sword, if any,
 * making them unarmed. Upon successful unequipping, a feedback message is displayed.
 */
void Player::unequipSword() {
    if (this->sword == (nullptr)) {
        std::cout << "You don't have any sword equipped\n";
        return;
    }
    this->setSwordNull();
    std::cout << "You have successfully unequipped your sword!\n";
}

/**
 * @brief Automatically restacks health potions in the player's inventory.
 *
 * This function automates the process of restacking health potions in the inventory
 * by combining stacks of similar potions. If restacking is successful, the player is
 * informed; otherwise, they are notified that restacking is not possible due to certain conditions.
 */
void Player::restack() {
    int nr = 0;
    for (int i = 0; i < this->inventory->getInventorySize(); i++) {
        if (this->inventory->getInventorySpace().at(i)->getQuantity() > 0 &&
            this->inventory->getInventorySpace().at(i)->getQuantity() <
            this->inventory->getInventorySpace().at(i)->getCurentItem()->getStackSize() &&
            this->inventory->getInventorySpace().at(i)->getCurentItem()->getGivesHeal())
            for (int j = i + 1; j < this->inventory->getInventorySize(); j++) {
                if (this->inventory->getInventorySpace().at(j)->getCurentItem()->getGivesHeal() &&
                    this->inventory->getInventorySpace().at(j)->getCurentItem()->getName() ==
                    this->inventory->getInventorySpace().at(i)->getCurentItem()->getName())
                    while (this->inventory->getInventorySpace().at(j)->getQuantity() > 0 &&
                           (this->inventory->getInventorySpace().at(i)->getQuantity() <
                            this->inventory->getInventorySpace().at(i)->getCurentItem()->getStackSize())) {
                        this->inventory->getInventorySpace().at(i)->addQuantity(1);
                        this->inventory->getInventorySpace().at(j)->removeQuantity(1);
                        nr++;
                    }
            }
    }
    if (nr)
        std::cout << "You have successfully restacked your Health Potions!\n";
    else
        std::cout << "You do not have any Health Potions or your Health Potions are already stacked normally!\n";
}

/**
 * @brief Provides an interactive menu for level-related functionalities of the player.
 *
 * This function presents a menu to the player allowing them to view their current level,
 * XP, and the option to level up if sufficient XP is available. The player's level and
 * XP details are displayed accordingly. If the player attempts to level up without sufficient
 * XP or reaches the maximum level, appropriate messages are displayed.
 */
void Player::levelFunction() {
    while (true) {
        int op;
        std::cout << "1. Display your level\n2. Display your XP\n3. Level up\n4. Exit\n";
        op = read(1, 4);
        switch (op) {
            case 1:
                std::cout << "You have level " << this->level << "\n";
                break;
            case 2:
                std::cout << "You have " << this->xp << " XP\n";
                break;
            case 3: {
                if (this->level == MAX_LEVEL) {
                    std::cout << "You have MAX level!\n";
                    break;
                }
                if (this->xp < (this->level + 1) * 50)
                    std::cout << "You need more " << ((this->level + 1) * 50) - this->xp << " XP to level up " <<
                              "at level " << this->level + 1 << "\n";
                else {
                    difXp(((this->level + 1) * 50));
                    IncrementLevel();
                    std::cout << "You have successfully leveled up to level " << this->level << "\n";
                }
                break;
            }
            case 4:
                return;
            default:
                std::cout << "Invalid Option!\n";
        }
    }
}

/**
 * @brief Provides an interactive menu for inventory-related functionalities of the player.
 *
 * This function displays a menu to the player, offering options to view their inventory,
 * current yang amount, equip or unequip a sword, restack health potions, or exit the menu.
 * Depending on the chosen option, the corresponding functionality is executed.
 */
void Player::inventoryFunction() {
    while (true) {
        int op;
        std::cout
                << "1. Display inventory\n2. Display yang\n3. Equip sword\n4. Unequip sword\n5. Restack HP potions\n6. Exit\n";
        op = read(1, 6);
        switch (op) {
            case 1:
                this->inventory->displayInventory();
                break;
            case 2:
                std::cout << "You have " << this->yang << " YANG\n";
                break;
            case 3:
                equipSword();
                break;
            case 4:
                unequipSword();
                break;
            case 5:
                restack();
                break;
            case 6:
                return;
            default:
                std::cout << "Invalid Option!\n";
        }
    }
}

/**
 * @brief Allows the player to purchase items from the shop.
 *
 * This function presents the player with a list of items available in the shop and prompts
 * them to select an item by its corresponding number. Depending on the choice made, various
 * validations are performed including checking the player's current yang (currency) balance
 * and level requirement. If the player meets all criteria and has sufficient yang, the item
 * is added to their inventory. Additionally, specific item types are created and populated
 * into inventory slots accordingly. This function is designed to handle the purchase of
 * various items such as swords and health potions.
 *
 * The items available for purchase are determined based on the Shop's inventory, and each
 * item has its price and level requirement. If the player's inventory is full or if they do
 * not meet the level requirement, appropriate messages are displayed, and the purchase is
 * declined. Upon successful purchase, the player's yang is deducted, and the item is added
 * to their inventory. Furthermore, if an item of the same type already exists in the
 * inventory, the quantity of that item is incremented instead of creating a new inventory slot.
 *
 * @note This function utilizes specific classes and their respective member functions such
 * as Shop's displayItems() to show available items and various getter functions to retrieve
 * item details (e.g., price, level requirement). It also interacts with the Player's
 * inventory and manages item additions and validations.
 */
void Player::buyItems() {
    Shop sh;
    sh.displayItems();
    std::cout << "Enter the number of the specific item which you want to buy : ";
    int x;
    x = read(1, 7);
    std::cout << std::endl;
    if (this->inventory->isFull()) {
        std::cout << "Your inventory is full!\n";
        return;
    }
    switch (x) {
        case 1: {
            if (this->yang < sh.getSword().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n";
                return;
            }
            if (this->level < sh.getSword().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new Sword());
            tmpslot->setQuantity(1);
            difYang(sh.getSword().getShopPrice());
            this->inventory->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 2: {
            if (this->yang < sh.getCrescentSword().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if (this->level < sh.getCrescentSword().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new CrescentSword());
            tmpslot->setQuantity(1);
            difYang(sh.getCrescentSword().getShopPrice());
            this->inventory->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 3: {
            if (this->yang < sh.getSilverSword().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if (this->level < sh.getSilverSword().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new SilverSword());
            tmpslot->setQuantity(1);
            difYang(sh.getSilverSword().getShopPrice());
            this->inventory->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 4: {
            if (this->yang < sh.getFullMoonSword().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if (this->level < sh.getFullMoonSword().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new FullMoonSword());
            tmpslot->setQuantity(1);
            difYang(sh.getFullMoonSword().getShopPrice());
            this->inventory->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 5: {
            if (this->yang < sh.getHpSmall().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if (this->level < sh.getHpSmall().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            difYang(sh.getHpSmall().getShopPrice());
            InventorySlot *ptr = this->inventory->findItemByNameAndStackSize("Small HP Potion",
                                                                             sh.getHpSmall().getStackSize());
            if (ptr != nullptr) {
                ptr->addQuantity(1);
            } else {
                InventorySlot *tmpslot = new InventorySlot();
                tmpslot->setItemType(new HPsmall());
                tmpslot->setQuantity(1);
                this->inventory->setFirstEmptySlot(tmpslot);
            }

            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 6: {
            if (this->yang < sh.getHpMedium().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if (this->level < sh.getHpMedium().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            difYang(sh.getHpMedium().getShopPrice());
            InventorySlot *ptr = this->inventory->findItemByNameAndStackSize("Medium HP Potion",
                                                                             sh.getHpMedium().getStackSize());
            if (ptr != nullptr) {
                ptr->addQuantity(1);
            } else {
                InventorySlot *tmpslot = new InventorySlot();
                tmpslot->setItemType(new HPmedium());
                tmpslot->setQuantity(1);
                this->inventory->setFirstEmptySlot(tmpslot);
            }
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 7: {
            if (this->yang < sh.getHpBig().getShopPrice()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if (this->level < sh.getHpBig().getLevelReq()) {
                std::cout << "You don't have enough level to buy this item!\n";
                return;
            }
            difYang(sh.getHpBig().getShopPrice());
            InventorySlot *ptr = this->inventory->findItemByNameAndStackSize("Big HP Potion",
                                                                             sh.getHpMedium().getStackSize());
            if (ptr != nullptr) {
                ptr->addQuantity(1);
            } else {
                InventorySlot *tmpslot = new InventorySlot();
                tmpslot->setItemType(new HPbig());
                tmpslot->setQuantity(1);
                this->inventory->setFirstEmptySlot(tmpslot);
            }
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        default:
            std::cout << "Invalid option!\n";
    }

}

/**
 * @brief Allows the player to sell items from their inventory.
 *
 * This function first displays the player's inventory and then prompts the player
 * to select an item they wish to sell. Upon selection, the player receives 95% of
 * the original shop price for the item sold. If the sold item is currently equipped
 * as the player's sword, the sword is unequipped. After the transaction, the item
 * quantity in the inventory is decremented by one. The function provides feedback
 * on successful or unsuccessful sales, including notifications if an invalid item
 * slot is selected or if the inventory does not contain the item to be sold.
 *
 * @note The player's yang (currency) increases by 95% of the item's original shop price
 * when an item is sold. The item's quantity in the inventory is reduced by one after
 * the sale, and if the sold item was equipped as a sword, it gets unequipped.
 */
void Player::sellItems() {
    this->inventory->displayInventory();
    std::cout << "You will receive 95% from the original shop price of the item when you sell something\n";
    std::cout << "If you don't want to sell anything , enter '0'\n";
    std::cout << "Enter the number of the item from your inventory which you want to sell : ";
    int op;
    op = read(1, 30);
    std::cout << "\n";
    if (op == 0) { return; }
    if (op < 0 || op > this->inventory->getInventorySize()) {
        std::cout << "Invalid option\n";
        return;
    }
    if (this->inventory->getInventorySpace().at(op - 1)->getQuantity() < 1) {
        std::cout << "You do not have an item on that slot\n\n";
        return;
    }
    sumYang(0.95 * (this->inventory->getInventorySpace().at(op - 1)->getCurentItem()->getShopPrice()));
    if (this->sword == this->inventory->getInventorySpace().at(op - 1)->getCurentItem())
        setSwordNull();
    this->inventory->getInventorySpace().at(op - 1)->removeQuantity(1);
    std::cout << "You have successfully sold the item!\n\n";

}

/**
 * @brief Provides a menu-driven interface for interacting with the shop functionalities.
 *
 * This function presents the player with a series of options to interact with the shop.
 * The options include displaying available items, viewing details about specific items,
 * purchasing items, selling items, or exiting the shop. Based on the selected option,
 * corresponding functionalities such as displaying items, providing item details, buying
 * items, or selling items are executed. The function ensures a seamless interaction
 * between the player and the shop, allowing for a straightforward shopping experience
 * within the game.
 *
 * @note This function integrates various functionalities like displaying items, viewing
 * item details, buying items using the buyItems() function, and selling items using the
 * sellItems() function. It offers a comprehensive interface for players to manage their
 * inventory and interact with the shop.
 */
void Player::shopFunction() {
    Shop sh;
    while (true) {
        int op;
        std::cout
                << "1. Display items from shop\n2. See details about a specific item\n3. Buy items\n4. Sell items\n5. Exit\n";
        op = read(1, 5);
        switch (op) {
            case 1:
                sh.displayItems();
                break;
            case 2:
                sh.detailsItems();
                break;
            case 3:
                buyItems();
                break;
            case 4:
                sellItems();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid Option!\n";
        }
    }
}

/**
 * @brief Manages the player's actions and interactions within a map environment.
 *
 * This function provides a menu-driven interface for players to interact with the map.
 * Players have the option to engage in fights, leave the map, or, in specific map scenarios
 * (e.g., "Joan" map), upgrade their equipped sword's plus level at a blacksmith. Depending
 * on the selected options and map conditions, the function allows players to engage in
 * fights, exit the map, or upgrade their sword at a blacksmith, ensuring dynamic gameplay
 * and map-specific interactions.
 *
 * @note This function facilitates interactions within different map environments, such as
 * initiating fights using the Fight class, exiting the current map, or upgrading the sword
 * plus level at a blacksmith in specific scenarios. It ensures that players have varied
 * interactions and engagements while exploring different maps within the game.
 */
void Player::mapFunction() {
    Fight *currentFight;
    int op;

    while (true) {
        std::cout << " WARNING --> Once you enter a fight, you can't escape until you eliminate all the monsters\n";
        std::cout << "1. Fight\n2. Leave the map\n";

        if (this->currentMap->getName() == "Joan") {
            std::cout << "3. Upgrade Plus Level of your sword at Blacksmith\n";
            op = read(1, 3);
            switch (op) {
                case 1: {
                    currentFight = new Fight(this);
                    delete currentFight;
                    break;
                }
                case 2:
                    return;
                case 3: {
                    if (this->sword != nullptr) {
                        Joan *p = dynamic_cast<Joan *>(this->currentMap);
                        p->getBlackSmith()->BlacksmithFunction(this);

                    } else {
                        std::cout << "You need to have a sword equipped to be upgraded\n";
                    }
                    break;
                }
                default:
                    std::cout << "Invalid Option!\n";
            }
        } else {
            op = read(1, 2);
            switch (op) {
                case 1: {
                    currentFight = new Fight(this);
                    delete currentFight;
                    break;
                }
                case 2:
                    return;
                default:
                    std::cout << "Invalid Option!\n";
            }
        }
    }
}


//
// Created by dinul on 11/18/2023.
//
#define MAX_LEVEL 10

#include "../Headers/Player.h"
#include "../Headers/Correct Read Function.h"
#include "../Headers/Fight.h"
#include "../Headers/Joan.h"
#include "../Headers/Shop.h"

Player::Player() {
    this->hp = 50; // era 50
    this->damage = 1;
    this->inventory = new Inventory();
    this->yang = 50; //era 50
    this->sword = nullptr;
    this->level = 1;  // level 1 de start
    this->currentMap = nullptr;
    this->xp = 0;
}

Player::Player(const Player &other) {
    // Copy simple members
    this->hp = other.hp;
    this->damage = other.damage;
    this->xp = other.xp;
    this->yang = other.yang;
    this->level = other.level;

    this->sword = (other.sword != nullptr) ? new Item(*(other.sword)) : nullptr;
    this->inventory = (other.inventory != nullptr) ? new Inventory(*(other.inventory)) : nullptr;
    this->currentMap = (other.currentMap != nullptr) ? new Maps(*(other.currentMap)) : nullptr;
}

Player &Player::operator=(const Player &other) {
    if (this != &other) {

        delete this->sword;
        delete this->inventory;
        delete this->currentMap;

        this->hp = other.hp;
        this->damage = other.damage;
        this->xp = other.xp;
        this->yang = other.yang;
        this->level = other.level;

        this->sword = (other.sword != nullptr) ? new Item(*(other.sword)) : nullptr;
        this->inventory = (other.inventory != nullptr) ? new Inventory(*(other.inventory)) : nullptr;
        this->currentMap = (other.currentMap != nullptr) ? new Maps(*(other.currentMap)) : nullptr;
    }

    return *this;
}

void Player::addXp(int _xp) {
    this->xp += _xp;
}

void Player::difXp(int _xp) {
    this->xp -= _xp;
}

Item *Player::getSword() {
    return this->sword;
}

int Player::getLevel() const {
    return this->level;
}

void Player::IncrementLevel() {
    this->level++;
}

Maps *Player::getCurrentMap() {
    return this->currentMap;
}

void Player::setCurrentMap(Maps *map) {
    this->currentMap = map;
}

void Player::setSwordNull() {
    this->sword = nullptr;
}

void Player::setSword(Item *sw) {
    this->sword = sw;
}

void Player::healPlayer(int add) {
    this->hp += add;
}

void Player::difYang(double sum) {
    this->yang = this->yang - sum;
}

void Player::sumYang(double sum) {
    this->yang = this->yang + sum;
}

void Player::setHp(int HP) {
    this->hp = HP;
}

bool Player::isDead() const {
    if (this->hp <= 0) return (true);
    return (false);
}

Inventory *Player::getInventory() {
    return this->inventory;
}

void Player::endGame() {
    this->inventory->freeEverything();
    delete this->inventory;
}

int Player::getDamage() const {
    return (this->damage);
}

void Player::takeDamage(int tkdmg) {
    this->hp = this->hp - tkdmg;
}


void Player::displayHp() {
    std::cout << "HEALTH BAR : ";
    for (int i = 0; i < this->hp; i++) {
        std::cout << "=";
    }
    std::cout << "   " << this->hp << "%\n";
}

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

void Player::equipSword() {
    int op;
    int x;
    if (this->sword != (nullptr)) {
        std::cout << "You already have equiped a sword\n";
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
            std::cout << "You have successfully equiped your sword!\n";
            return;
        }

    }
    std::cout << "Invalid option!\n";

}

void Player::unequipSword() {
    if (this->sword == (nullptr)) {
        std::cout << "You don't have any sword equiped\n";
        return;
    }
    this->setSwordNull();
    std::cout << "You have successfully unequiped your sword!\n";
}


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
        std::cout << "You do not have any Health Potions or your Health Potions are already stacked normal!\n";
}

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


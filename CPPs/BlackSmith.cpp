//
// Created by dinul on 11/18/2023.
//

#include "../Headers/BlackSmith.h"
#include "../Headers/Correct Read Function.h"

Blacksmith::Blacksmith() = default;

Blacksmith::~Blacksmith() = default;

bool Blacksmith::UpgradePlusLevel(Item *sword, Player *player) {
    int chance = rand() % 101;
    switch (sword->getPlusLevel()) {
        case 0: {
            if (chance > 0 && chance <= 90) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 1: {
            if (chance > 0 && chance <= 85) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 2: {
            if (chance > 0 && chance <= 80) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 3: {
            if (chance > 0 && chance <= 75) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 4: {
            if (chance > 0 && chance <= 70) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 5: {
            if (chance > 0 && chance <= 65) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 6: {
            if (chance > 0 && chance <= 50) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 7: {
            if (chance > 0 && chance <= 40) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        case 8: {
            if (chance > 0 && chance <= 30) {
                sword->IncrementPlusLevel();
                std::cout << "You have successfully upgraded your PlusLevel of your sword\n";
                return true;
            } else {
                for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
                    if (player->getInventory()->getInventorySpace().at(i)->getCurentItem() == sword) {
                        player->getInventory()->getInventorySpace().at(i)->setQuantity(0);
                        player->setSwordNull();
                        std::cout << "You failed to upgrade your sword and it has been destroyed!\n";
                        return false;
                    }
            }
            break;
        }
        default: {
            std::cout << "Unexpected PlusLevel value!\n";
            return false;  // You may want to return a default value or handle this case appropriately
        }

    }
    return false;
}

void Blacksmith::displayChances() {
    std::cout << "Increasing from +0 Plus level to +1 (90% chances of success)\n";
    std::cout << "Increasing from +1 Plus level to +2 (85% chances of success)\n";
    std::cout << "Increasing from +2 Plus level to +3 (80% chances of success)\n";
    std::cout << "Increasing from +3 Plus level to +4 (75% chances of success)\n";
    std::cout << "Increasing from +4 Plus level to +5 (70% chances of success)\n";
    std::cout << "Increasing from +5 Plus level to +6 (65% chances of success)\n";
    std::cout << "Increasing from +6 Plus level to +7 (50% chances of success)\n";
    std::cout << "Increasing from +7 Plus level to +8 (40% chances of success)\n";
    std::cout << "Increasing from +8 Plus level to +9 (30% chances of success)\n";
}

void Blacksmith::BlacksmithFunction(Player *player) {
    int op;
    while (true) {
        std::cout
                << "1. See chances of success at upgrades\n2. Upgrade your sword\n3. Display your sword's plus level"
                << "\n4. Exit\n";
        op = read(1, 4);
        switch (op) {
            case 1:
                displayChances();
                break;
            case 2: {
                if (player->getSword()->getPlusLevel() >= 9) {
                    std::cout << "Your sword has the maximum Plus Level!\n";
                    break;
                } else {
                    std::cout << "If you are sure enter '1' , else enter '0'\n";
                    int rsp;
                    rsp = read(0, 1);
                    switch (rsp) {
                        case 1: {
                            if (UpgradePlusLevel(player->getSword(), player))
                                break;
                            else
                                return;
                        }
                        case 0:
                            break;
                        default: {
                            std::cout << "Invalid option\n";
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    std::cout << "Your " << player->getSword()->getName() << " has +"
                              << player->getSword()->getPlusLevel() << " level\n";
                    break;
                }
                case 4:
                    return;
                default: {
                    std::cout << "Invalid option\n";
                    break;
                }

            }
        }
    }
}

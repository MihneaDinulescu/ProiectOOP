//
// Created by dinul on 11/18/2023.
//

#include "Map Functions.h"
#include "Fight.h"
#include "Joan.h"
#include "Correct Read Function.h"

void Mapfun(Player *player) {
    Fight *currentFight;
    int op;

    while (true) {
        std::cout << " WARNING --> Once you enter a fight, you can't escape until you eliminate all the monsters\n";
        std::cout << "1. Fight\n2. Leave the map\n";

        if (player->getcurrentMap()->getname() == "Joan") {
            std::cout << "3. Upgrade Plus Level of your sword at Blacksmith\n";
            op=read(1,3);
            switch (op) {
                case 1: {
                    currentFight = new Fight(player);
                    delete currentFight;
                    break;
                }
                case 2:
                    return;
                case 3: {
                    if (player->getSword() != nullptr) {
                        Joan *p = dynamic_cast<Joan*>(player->getcurrentMap());
                        p->getBlacksmith()->BlacksmithFun(player);

                    } else {
                        std::cout << "You need to have a sword equipped to be upgraded\n";
                    }
                    break;
                }
                default:
                    std::cout << "Invalid Option!\n";
            }
        } else {
            op = read(1,2);
            switch (op) {
                case 1: {
                    currentFight = new Fight(player);
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
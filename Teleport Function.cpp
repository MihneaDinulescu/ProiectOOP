//
// Created by dinul on 11/18/2023.
//

#include "Teleport Function.h"
#include "Correct Read Function.h"

void TeleportFun(Player *player, std::vector<Maps *> maps) {
    int op;
    std::cout << "Enter the number of the Map where you want to teleport\n";
    for (int i = 0; i < 3; i++) {
        std::cout << (i + 1) << ". Map " << maps.at(i)->getname() << " (minimum level requirement : "
                  << maps.at(i)->getlevelReq() << ")\n";
    }
    std::cout << "If you want to leave teleporter enter '0'\n";
    op= read(0,3);
    if (op == 0) { return; }
    switch (op) {
        case 1: {
            if (player->getlevel() >= maps.at(op - 1)->getlevelReq()) {
                player->setcurrentMap(maps.at(op - 1));
                player->Mapfun();
            } else {
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return;
            }
            break;
        }
        case 2: {
            if (player->getlevel() >= maps.at(op - 1)->getlevelReq()) {
                player->setcurrentMap(maps.at(op - 1));
                player->Mapfun();
            } else {
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return;
            }
            break;
        }
        case 3: {
            if (player->getlevel() >= maps.at(op - 1)->getlevelReq()) {
                player->setcurrentMap(maps.at(op - 1));
                player->Mapfun();
            } else {
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return;
            }
            break;
        }
        default:
            std::cout << "Invalid Option!\n";

    }

}

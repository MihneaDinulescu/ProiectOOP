//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Teleport Function.h"
#include "../Headers/Correct Read Function.h"

void TeleportFun(Player *player, std::vector<Maps<std::string> *> maps) {
    int op;
    std::cout << "Enter the number of the Map where you want to teleport\n";
    for (int i = 0; i < 3; i++) {
        std::cout << (i + 1) << ". Map " << maps.at(i)->getName() << " (minimum level requirement : "
                  << maps.at(i)->getLevelReq() << ")\n";
    }
    std::cout << "If you want to leave teleporter enter '0'\n";
    op = read(0, 3);
    if (op == 0) { return; }
    switch (op) {
        case 1: {
            if (player->getLevel() >= maps.at(op - 1)->getLevelReq()) {
                player->setCurrentMap(maps.at(op - 1));
                player->mapFunction();
            } else {
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return;
            }
            break;
        }
        case 2: {
            if (player->getLevel() >= maps.at(op - 1)->getLevelReq()) {
                player->setCurrentMap(maps.at(op - 1));
                player->mapFunction();
            } else {
                std::cout << "Your level is lower than the map's minimum level requirement\n";
                return;
            }
            break;
        }
        case 3: {
            if (player->getLevel() >= maps.at(op - 1)->getLevelReq()) {
                player->setCurrentMap(maps.at(op - 1));
                player->mapFunction();
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

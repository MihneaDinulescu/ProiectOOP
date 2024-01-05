//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Decision Function.h"
#include "../Headers/Teleport Function.h"
#include "../Headers/Correct Read Function.h"

void decisionFunction(Player *player, const std::vector<Maps<std::string> *> &maps) {

    while (true) {

        std::cout << "1. Teleport \n2. Inventory \n3. Health \n4. Shop \n5. Level\n6. Exit\n";

        int decision = read(1, 6);
        switch (decision) {
            case 1:
                TeleportFun(player, maps);
                break;
            case 2:
                player->inventoryFunction();
                break;
            case 3:
                player->healthFunction();
                break;
            case 4:
                player->shopFunction();
                break;
            case 5:
                player->levelFunction();
                break;
            case 6:
                player->endGame();
                return;
            default:
                std::cout << "Unknown command!\n";
        }


    }

}

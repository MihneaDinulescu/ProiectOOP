//
// Created by dinul on 11/18/2023.
//

#include "Decision Function.h"
#include "Teleport Functions.h"
#include "Inventory Functions.h"
#include "Health Functions.h"
#include "Shop Functions.h"

void decisionFunction(Player *player, const std::vector<Maps*>& maps) {

    while (true) {

        std::cout << "1. Teleport \n2. Inventory \n3. Health \n4. Shop \n5. Level\n6. Exit\n";

        int decision;
        std::cin >> decision;

        switch (decision) {
            case 1:
                TeleportFun(player, maps);
                break;
            case 2:
                inventoryfun(player);
                break;
            case 3:
                HealthFun(player);
                break;
            case 4:
                ShopFun(player);
                break;
            case 5:
                Levelfun(player);
                break;
            case 6:
                player->endGame();
                return;
            default:
                std::cout << "Unknown command!\n";
        }


    }

}

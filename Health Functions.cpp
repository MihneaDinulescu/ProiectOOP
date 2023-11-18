//
// Created by dinul on 11/18/2023.
//

#include "Health Functions.h"

void displayhp(Player *player){
    std::cout<<"HEALTH BAR : ";
    for(int i=0 ; i < player->gethp() ; i++)
    {
        std::cout<<"=";
    }
    std::cout<<"   "<<player->gethp()<<"%\n";
}

int displayhpres(Player* player){
    std::cout<<"Heal items available from your inventory:\n";
    int counter=0;
    for (int i = 0; i < player->getInventory()->getInventorySize(); i++) {
        if (player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getgivesHeal() && player->getInventory()->getInventorySpace().at(i)->getQuantity() > 0 ) {
            std::cout << counter + 1 << ") " << player->getInventory()->getInventorySpace().at(i)->getQuantity() << "x "
                      << player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getname() << std::endl;
            counter++;
        }
    }
    if(counter==0) {
        std::cout << "You don't have heal potions!\n";
    }
    return counter;
}

void regenhp(Player *player) {
    std::cout << "You need to use only health potions\n";
    int cnt = displayhpres(player);
    if (cnt == 0) {std::cout<<"You do not have any HP potions\n";  return; }
    int nrop;
    std::cout << "Enter the number of the item with which you want to heal :";
    std::cin >> nrop;
    int nr=0;
    for (int i = 0; i < player->getInventory()->getInventorySize(); i++) {

        if (player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getgivesHeal() && player->getInventory()->getInventorySpace().at(i)->getQuantity() > 0 )
            nr++;
        if (nr == nrop) {
            if(player->gethp()+player->getInventory()->getInventorySpace().at(i)->getCurentItem()->gethealgain() > 50 )
                player->healplayer(50 - (player->gethp()));
            else
                player->healplayer(player->getInventory()->getInventorySpace().at(i)->getCurentItem()->gethealgain());
            player->getInventory()->getInventorySpace().at(i)->removeQuantity(1);
            std::cout<<"You have successfully healed!\n";
            return;

        }
    }
    std::cout<<"Invalid option!\n";
}



void HealthFun(Player* player) {

    int op;
    while (true) {
        std::cout
                << "1. See HP\n2. See heal resources available\n3. Regenerate your HP\n4. Exit\n";
        std::cin >> op;
        switch (op) {
            case 1:
                displayhp(player);
                break;
            case 2:
                displayhpres(player);
                break;
            case 3:
                if (player->gethp() < 50)
                    regenhp(player);
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

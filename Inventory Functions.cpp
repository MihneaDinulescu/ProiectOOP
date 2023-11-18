//
// Created by dinul on 11/18/2023.
//

#include "Inventory Functions.h"
#include "Correct Read Function.h"

void equipsword(Player *player){
    int op;
    int x;
    op=player->getInventory()->displaySwords();
    if(op == 0) { std::cout<<"You don't have any swords in your inventory!\n"; return; }
    if(player->getSword() != (nullptr)){
        std::cout<<"You already have equiped a sword\n";
        return;}
    std::cout<<"Enter the number of the sword you want to equip :";
    x=read(1,30);
    int counter=0;
    for (int i = 0; i < player->getInventory()->getInventorySize(); i++) {
        if(player->getInventory()->getInventorySpace().at(i)->getQuantity() > 0 && player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getdamage() > 0)
            counter++;
        if(counter==x) {
            player->setSword(player->getInventory()->getInventorySpace().at(i)->getCurentItem());
            std::cout << "You have successfully equiped your sword!\n";
            return;
        }

    }
    std::cout<<"Invalid option!\n";

}

void unequipsword(Player *player){
    if(player->getSword() == (nullptr)){
        std::cout<<"You don't have any sword equiped\n";
        return;}
    player->setSwordNull();
    std::cout << "You have successfully unequiped your sword!\n";
}


void restack(Player *player){
    int nr=0;
    for (int i = 0; i < player->getInventory()->getInventorySize(); i++)
    {
        if(player->getInventory()->getInventorySpace().at(i)->getQuantity() > 0 &&  player->getInventory()->getInventorySpace().at(i)->getQuantity() < player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getstacksize() &&
           player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getgivesHeal())
            for(int j = i+1 ; j < player->getInventory()->getInventorySize(); j++) {
                if(player->getInventory()->getInventorySpace().at(j)->getCurentItem()->getgivesHeal() && player->getInventory()->getInventorySpace().at(j)->getCurentItem()->getname().compare(player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getname()) == 0)
                    while(player->getInventory()->getInventorySpace().at(j)->getQuantity() > 0 && (player->getInventory()->getInventorySpace().at(i)->getQuantity() < player->getInventory()->getInventorySpace().at(i)->getCurentItem()->getstacksize()))
                    { player->getInventory()->getInventorySpace().at(i)->addQuantity(1);
                        player->getInventory()->getInventorySpace().at(j)->removeQuantity(1);
                        nr++;
                    }
            }
    }
    if(nr)
        std::cout<<"You have successfully restacked your Health Potions!\n";
    else
        std::cout<<"You do not have any Health Potions or your Health Potions are already stacked normal!\n";
}

void Levelfun(Player *player){
    int op;
    while (true) {
        std::cout<<"1. Display your level\n2. Display your XP\n3. Level up\n4. Exit\n";
        op=read(1,4);
        switch (op){
            case 1:
                std::cout<<"You have level " << player->getlevel()<<"\n";
                break;
            case 2:
                std::cout<<"You have "<< player->getXp() <<" XP\n";
                break;
            case 3:{
                if(player->getlevel() == MAX_LEVEL)
                {std::cout<<"You have MAX level!\n"; break;}
                if(player->getXp() < (player->getlevel() + 1) * 50)
                    std::cout<<"You need more " << ((player->getlevel() + 1) * 50) - player->getXp()  <<" XP to level up "<<
                             "at level " << player->getlevel()+1 <<"\n";
                else
                {
                    player->difXp(((player->getlevel() + 1) * 50));
                    player->IncrementLevel();
                    std::cout<<"You have successfully leveled up to level "<< player->getlevel() <<"\n";
                }
                break;
            }
            case 4: return;
            default:
                std::cout << "Invalid Option!\n";
        }
    }
}

void inventoryfun(Player *player){
    int op;
    while (true) {
        std::cout<<"1. Display inventory\n2. Display yang\n3. Equip sword\n4. Unequip sword\n5. Restack HP potions\n6. Exit\n";
        op=read(1,6);
        switch (op){
            case 1:
                player->getInventory()->displayInventory();
                break;
            case 2:
                std::cout<<"You have " << player->getYang()<< " YANG\n";
                break;
            case 3:
                equipsword(player);
                break;
            case 4:
                unequipsword(player);
                break;
            case 5:
                restack(player);
                break;
            case 6:
                return;
            default:
                std::cout << "Invalid Option!\n";
        }
    }

}

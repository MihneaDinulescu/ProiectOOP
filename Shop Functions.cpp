//
// Created by dinul on 11/18/2023.
//

#include "Shop Functions.h"
#include "Correct Read Function.h"

void displayitems() {
    Shop sh;
    std::cout << sh;
    std::cout<<"\n";
}

void detailsitems(){
    displayitems();
    std::cout << "Enter the number of the specific item for more details : \n";
    int x;
    x = read(1,7);
    Shop sh;
    switch(x)
    {
        case 1:
            std::cout << sh.getSword();
            break;
        case 2:
            std::cout << sh.getCrescentSword();
            break;
        case 3:
            std::cout << sh.getSilverSword();
            break;
        case 4:
            std::cout << sh.getFullMoonSword();
            break;
        case 5:
            std::cout << sh.getHPSmall();
            break;
        case 6:
            std::cout << sh.getHPMedium();
            break;
        case 7:
            std::cout << sh.getHPBig();
            break;
        default:
            std::cout <<"Invalid option!";

    }

}


void buyitems(Player *player){
    displayitems();
    std::cout << "Enter the number of the specific item which you want to buy : ";
    int x;
    Shop sh;
    x=read(1,7);
    std::cout<<std::endl;
    if(player->getInventory()->isFull())
    {
        std::cout<<"Your inventory is full!\n";
        return;
    }
    switch(x)
    {
        case 1: {
            if (player->getYang() < sh.getSword().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n";
                return;
            }
            if(player->getlevel() < sh.getSword().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new Sword());
            tmpslot->setQuantity(1);
            player->difYang(sh.getSword().getshop_price());
            player->getInventory()->setFirstEmptySlot(tmpslot);
            std::cout<< "You've successfully bought the item!\n\n";
            break;
        }
        case 2: {
            if (player->getYang() < sh.getCrescentSword().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if(player->getlevel() < sh.getCrescentSword().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new CrescentSword());
            tmpslot->setQuantity(1);
            player->difYang(sh.getCrescentSword().getshop_price());
            player->getInventory()->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 3: {
            if (player->getYang() < sh.getSilverSword().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if(player->getlevel() < sh.getSilverSword().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new SilverSword());
            tmpslot->setQuantity(1);
            player->difYang(sh.getSilverSword().getshop_price());
            player->getInventory()->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 4: {
            if (player->getYang() < sh.getFullMoonSword().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if(player->getlevel() < sh.getFullMoonSword().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            InventorySlot *tmpslot = new InventorySlot();
            tmpslot->setItemType(new FullMoonSword());
            tmpslot->setQuantity(1);
            player->difYang(sh.getFullMoonSword().getshop_price());
            player->getInventory()->setFirstEmptySlot(tmpslot);
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 5: {
            if (player->getYang() < sh.getHPSmall().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if(player->getlevel() < sh.getHPSmall().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            player->difYang(sh.getHPSmall().getshop_price());
            InventorySlot *ptr = player->getInventory()->findItemByNameAndStackSize("Small HP Potion",
                                                                                    sh.getHPSmall().getstacksize());
            if (ptr != nullptr) {
                ptr->addQuantity(1);
            } else {
                InventorySlot *tmpslot = new InventorySlot();
                tmpslot->setItemType(new HPsmall());
                tmpslot->setQuantity(1);
                player->getInventory()->setFirstEmptySlot(tmpslot);
            }

            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 6: {
            if (player->getYang() < sh.getHPMedium().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if(player->getlevel() < sh.getHPMedium().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            player->difYang(sh.getHPMedium().getshop_price());
            InventorySlot *ptr = player->getInventory()->findItemByNameAndStackSize("Medium HP Potion",
                                                                                    sh.getHPMedium().getstacksize());
            if (ptr != nullptr) {
                ptr->addQuantity(1);
            } else {
                InventorySlot *tmpslot = new InventorySlot();
                tmpslot->setItemType(new HPmedium());
                tmpslot->setQuantity(1);
                player->getInventory()->setFirstEmptySlot(tmpslot);
            }
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        case 7: {
            if (player->getYang() < sh.getHPBig().getshop_price()) {
                std::cout << "You don't have sufficient young to buy this item!\n\n";
                return;
            }
            if(player->getlevel() < sh.getHPBig().getlevelreq())
            {
                std::cout << "You don't have enough level to buy this item!\n";
                return ;
            }
            player->difYang(sh.getHPBig().getshop_price());
            InventorySlot *ptr = player->getInventory()->findItemByNameAndStackSize("Big HP Potion",
                                                                                    sh.getHPMedium().getstacksize());
            if (ptr != nullptr) {
                ptr->addQuantity(1);
            } else {
                InventorySlot *tmpslot = new InventorySlot();
                tmpslot->setItemType(new HPbig());
                tmpslot->setQuantity(1);
                player->getInventory()->setFirstEmptySlot(tmpslot);
            }
            std::cout << "You've successfully bought the item!\n\n";
            break;
        }
        default:
            std::cout<<"Invalid option!\n";
    }

}

void sellitems(Player *player){
    player->getInventory()->displayInventory();
    std::cout <<"You will receive 95% from the original shop price of the item when you sell something\n";
    std::cout<< "If you don't want to sell anything , enter '0'\n";
    std::cout << "Enter the number of the item from your inventory which you want to sell : ";
    int op;
    op= read(1,30);
    std::cout<<"\n";
    if(op==0) { return;}
    if(op<0 || op > player->getInventory()->getInventorySize()) {std::cout<<"Invalid option\n"; return;}
    if(player->getInventory()->getInventorySpace().at(op-1)->getQuantity() < 1)
    {
        std::cout<<"You do not have an item on that slot\n\n";
        return;
    }
    player->sumYang(0.95 * (player->getInventory()->getInventorySpace().at(op-1)->getCurentItem()->getshop_price() ) );
    if(player->getSword() == player->getInventory()->getInventorySpace().at(op-1)->getCurentItem())
        player->setSwordNull();
    player->getInventory()->getInventorySpace().at(op-1)->removeQuantity(1);
    std::cout<<"You have successfully sold the item!\n\n";

}

void ShopFun(Player* player) {

    int op;
    while (true) {
        std::cout << "1. Display items from shop\n2. See details about a specific item\n3. Buy items\n4. Sell items\n5. Exit\n";
        op= read(1,5);
        switch (op) {
            case 1:
                displayitems();
                break;
            case 2:
                detailsitems();
                break;
            case 3:
                buyitems(player);
                break;
            case 4:
                sellitems(player);
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid Option!\n";
        }
    }
}


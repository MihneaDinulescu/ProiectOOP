//
// Created by dinul on 11/18/2023.
//

#include "Shop.h"
#include "Correct Read Function.h"

std::ostream &operator<<(std::ostream &out, Shop &shop) {
    out << "1. " << shop.s.getName() << std::endl
        << "2. " << shop.cs.getName() << std::endl
        << "3. " << shop.ss.getName() << std::endl
        << "4. " << shop.fms.getName() << std::endl
        << "5. " << shop.hps.getName() << std::endl
        << "6. " << shop.hpm.getName() << std::endl
        << "7. " << shop.hpb.getName() << std::endl;
    return out;
}

Sword Shop::getSword() {
    return s;
}

CrescentSword Shop::getCrescentSword() {
    return cs;
}

SilverSword Shop::getSilverSword() {
    return ss;
}

FullMoonSword Shop::getFullMoonSword() {
    return fms;
}

HPsmall Shop::getHpSmall() {
    return hps;
}

HPmedium Shop::getHpMedium() {
    return hpm;
}

HPbig Shop::getHpBig() {
    return hpb;
}

void Shop::displayItems() {
    Shop sh;
    std::cout << sh;
    std::cout<<"\n";
}

void Shop::detailsItems(){
    Shop::displayItems();
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
            std::cout << sh.getHpSmall();
            break;
        case 6:
            std::cout << sh.getHpMedium();
            break;
        case 7:
            std::cout << sh.getHpBig();
            break;
        default:
            std::cout <<"Invalid option!";

    }

}


//
// Created by dinul on 11/18/2023.
//

#include "Shop.h"
#include "Correct Read Function.h"

std::ostream &operator<<(std::ostream &out, Shop &shop) {
    out << "1. " << shop.s.getname() << std::endl
        << "2. " << shop.cs.getname() << std::endl
        << "3. " << shop.ss.getname() << std::endl
        << "4. " << shop.fms.getname() << std::endl
        << "5. " << shop.hps.getname() << std::endl
        << "6. " << shop.hpm.getname() << std::endl
        << "7. " << shop.hpb.getname() << std::endl;
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

HPsmall Shop::getHPSmall() {
    return hps;
}

HPmedium Shop::getHPMedium() {
    return hpm;
}

HPbig Shop::getHPBig() {
    return hpb;
}

void Shop::displayitems() {
    Shop sh;
    std::cout << sh;
    std::cout<<"\n";
}

void Shop::detailsitems(){
    Shop::displayitems();
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


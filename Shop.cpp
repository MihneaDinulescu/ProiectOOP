//
// Created by dinul on 11/18/2023.
//

#include "Shop.h"

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


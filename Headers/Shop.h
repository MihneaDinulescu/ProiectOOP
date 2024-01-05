//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H

#include "Sword.h"
#include "CrescentSword.h"
#include "SilverSword.h"
#include "FullMoonSword.h"
#include "HPsmall.h"
#include "HPmedium.h"
#include "HPbig.h"
#include <iostream>

class Shop {
private:
    Sword s;
    CrescentSword cs;
    SilverSword ss;
    FullMoonSword fms;
    HPsmall hps;
    HPmedium hpm;
    HPbig hpb;
public:
    friend std::ostream &operator<<(std::ostream &out, Shop &shop);

    Sword getSword();

    CrescentSword getCrescentSword();

    SilverSword getSilverSword();

    FullMoonSword getFullMoonSword();

    HPsmall getHpSmall();

    HPmedium getHpMedium();

    HPbig getHpBig();

    void displayItems();

    void detailsItems();

};


#endif //OOP_SHOP_H

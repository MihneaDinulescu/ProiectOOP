//
// Created by dinul on 11/18/2023.
//

#include "HPsmall.h"

    HPsmall::HPsmall(){
        this->name="Small HP Potion";
        this->givesheal=true;
        this->damage=0;
        this->pluslevel=0;
        this->levelreq=1;
        this->shop_price=10;
        this->stacksize=5; // era 50
        this->heal_gain=3;
    }

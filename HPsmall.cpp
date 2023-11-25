//
// Created by dinul on 11/18/2023.
//

#include "HPsmall.h"

    HPsmall::HPsmall(){
        this->name="Small HP Potion";
        this->givesHeal=true;
        this->damage=0;
        this->plusLevel=0;
        this->levelReq=1;
        this->shopPrice=10;
        this->stackSize=5; // era 50
        this->healGain=3;
    }

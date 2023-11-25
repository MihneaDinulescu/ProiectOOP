//
// Created by dinul on 11/18/2023.
//

#include "HPbig.h"

HPbig::HPbig(){
    this->name="Big HP Potion";
    this->givesHeal=true;
    this->damage=0;
    this->plusLevel=0;
    this->levelReq=5;
    this->shopPrice=100;
    this->stackSize=2; //era 10
    this->healGain=100;
}
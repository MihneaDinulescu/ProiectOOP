//
// Created by dinul on 11/18/2023.
//

#include "HPbig.h"

HPbig::HPbig(){
    this->name="Big HP Potion";
    this->givesheal=true;
    this->damage=0;
    this->pluslevel=0;
    this->levelreq=5;
    this->shop_price=100;
    this->stacksize=2; //era 10
    this->heal_gain=100;
}
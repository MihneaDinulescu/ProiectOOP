//
// Created by dinul on 11/18/2023.
//
#include "HPmedium.h"

HPmedium::HPmedium(){
    this->name="Medium HP Potion";
    this->givesheal=true;
    this->damage=0;
    this->pluslevel=0;
    this->levelreq=3;
    this->shop_price=30;
    this->stacksize=3; //era 30
    this->heal_gain=10;
}
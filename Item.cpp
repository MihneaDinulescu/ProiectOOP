//
// Created by dinul on 11/18/2023.
//
#include<iostream>
#include<string>
#include "Item.h"

    Item::Item(){
        this->name="Nothing";
        this->givesheal=false;
        this->damage=0;
        this->pluslevel=0;
        this->levelreq=0;
        this->heal_gain=0;
        this->stacksize=0;
        this->shop_price=0;

    }
    Item::~Item() = default;

std::ostream &operator<<(std::ostream &out, const Item &item) {
    out << "Details about this item:" << std::endl;
    out << "Name: " << item.name << std::endl;
    if(item.givesheal)
        out << "Heal given by 1x "<< item.name << "is + " << item.heal_gain << "HP" << std::endl;
    if(item.damage)
        out << "Damage: " << item.damage << std::endl;
    if(!item.givesheal)
        out << "Plus Level: " << item.pluslevel << std::endl;
    out << "Level required for buying: " << item.levelreq << std::endl;
    out << "Price for x1 " << item.name <<" " << "is : " << item.shop_price ;
    out << "\n\n";
    return out;
}

 void Item::IncrementPluslevel(){
        this->pluslevel+=1;
    }
 bool Item::getgivesHeal() const{
        return this->givesheal;
    }
 int Item::getpluslevel() const{
        return this->pluslevel;
    }
 int Item::getlevelreq() const{
        return this->levelreq;
    }
 int Item::getdamage() const{
        return this->damage;
    }
 std::string Item::getname(){
        return this->name;
    }
 int Item::getshop_price() const{
        return this->shop_price;
    }
 int Item::gethealgain() const{
        return this->heal_gain;
    }
    int Item::getstacksize() const{
        return this->stacksize;
    }



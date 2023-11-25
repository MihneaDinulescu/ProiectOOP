//
// Created by dinul on 11/18/2023.
//
#include<iostream>
#include<string>
#include "Item.h"

    Item::Item(){
        this->name="Nothing";
        this->givesHeal=false;
        this->damage=0;
        this->plusLevel=0;
        this->levelReq=0;
        this->healGain=0;
        this->stackSize=0;
        this->shopPrice=0;

    }
    Item::~Item() = default;

std::ostream &operator<<(std::ostream &out, const Item &item) {
    out << "Details about this item:" << std::endl;
    out << "Name: " << item.name << std::endl;
    if(item.givesHeal)
        out << "Heal given by 1x "<< item.name << "is + " << item.healGain << "HP" << std::endl;
    if(item.damage)
        out << "Damage: " << item.damage << std::endl;
    if(!item.givesHeal)
        out << "Plus Level: " << item.plusLevel << std::endl;
    out << "Level required for buying: " << item.levelReq << std::endl;
    out << "Price for x1 " << item.name <<" " << "is : " << item.shopPrice ;
    out << "\n\n";
    return out;
}

 void Item::IncrementPlusLevel(){
        this->plusLevel+=1;
    }
 bool Item::getGivesHeal() const{
        return this->givesHeal;
    }
 int Item::getPlusLevel() const{
        return this->plusLevel;
    }
 int Item::getLevelReq() const{
        return this->levelReq;
    }
 int Item::getDamage() const{
        return this->damage;
    }
 std::string Item::getName(){
        return this->name;
    }
 int Item::getShopPrice() const{
        return this->shopPrice;
    }
 int Item::getHealGain() const{
        return this->healGain;
    }
    int Item::getStackSize() const{
        return this->stackSize;
    }



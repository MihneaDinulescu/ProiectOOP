//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_BLACKSMITH_H
#define OOP_BLACKSMITH_H

#include<iostream>
#include "Item.h"
#include "Player.h"

class Blacksmith{
public:
    Blacksmith();

    ~Blacksmith();

    bool UpgradePlusLevel(Item  *sword, Player *player);

    void displayChances();

    void BlacksmithFunction(Player *player);
};

#endif //OOP_BLACKSMITH_H

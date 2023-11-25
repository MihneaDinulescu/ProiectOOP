//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_MONSTERS_H
#define OOP_MONSTERS_H

#include<iostream>
#include "Player.h"

class Monsters{
protected:
    int damage;
    int hp;
    std::string name;
    int level;
    std::string region;
    int xpGain;
    double yangDrop;
public:
    Monsters();

    virtual ~Monsters();

    Monsters(const Monsters &copy);

    Monsters& operator=(const Monsters& monster);

    virtual void attack(Player *player);

    int getXpGain() const;

    int getDamage() const;

    int getHp() const;

    std::string getName();

    void takeDamage(int dmg);

    double getYangDrop() const;
};

#endif //OOP_MONSTERS_H

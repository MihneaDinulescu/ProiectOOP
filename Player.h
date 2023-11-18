//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Item.h"
#include "Inventory.h"
#include "Maps.h"

class Player
{
private:
    int hp;
    int damage;
    int xp;
    Item *sword;
    double yang;
    Inventory *inventory;
    int level;
    Maps *currentMap;

public:

    Player();

    [[nodiscard]] int getXp() const;

    void addXp(int _xp);

    void difXp(int _xp);

    Item * getSword();

    [[nodiscard]] int getlevel() const;

    void IncrementLevel();

    Maps * getcurrentMap();

    void setcurrentMap(Maps *map);

    void setSwordNull();

    void setSword(Item * sw);

    void healplayer(int add);

    [[nodiscard]] double getYang() const;

    void difYang(double sum);

    void sumYang(double sum);

    [[nodiscard]] int gethp() const;

    void sethp(int HP);

    [[nodiscard]] bool isdead() const;

    Inventory * getInventory();

    void endGame();

    [[nodiscard]] int getdamage() const;

    void takedamage(int tkdmg);

};


#endif //OOP_PLAYER_H

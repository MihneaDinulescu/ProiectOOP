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

    Player(const Player& other);

    Player& operator=(const Player& other);

    int getXp() const;

    void addXp(int _xp);

    void difXp(int _xp);

    Item * getSword();

    int getlevel() const;

    void IncrementLevel();

    Maps * getcurrentMap();

    void setcurrentMap(Maps *map);

    void setSwordNull();

    void setSword(Item * sw);

    void healplayer(int add);

    void difYang(double sum);

    void sumYang(double sum);

    void sethp(int HP);

    bool isdead() const;

    Inventory * getInventory();

    void endGame();

    int getdamage() const;

    void takedamage(int tkdmg);

    void displayhp();

    int displayhpres();

    void regenhp();

    void HealthFun();

    void equipsword();

    void unequipsword();

    void restack();

    void Levelfun();

    void inventoryfun();

    void Mapfun();

    void buyitems();

    void sellitems();

    void ShopFun();



};


#endif //OOP_PLAYER_H

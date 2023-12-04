//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Item.h"
#include "Inventory.h"
#include "Maps.h"

class Player {
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

    Player(const Player &other);

    Player &operator=(const Player &other);

    int getXp() const;

    void addXp(int _xp);

    void difXp(int _xp);

    Item *getSword();

    int getLevel() const;

    void IncrementLevel();

    Maps *getCurrentMap();

    void setCurrentMap(Maps *map);

    void setSwordNull();

    void setSword(Item *sw);

    void healPlayer(int add);

    void difYang(double sum);

    void sumYang(double sum);

    void setHp(int HP);

    bool isDead() const;

    Inventory *getInventory();

    void endGame();

    int getDamage() const;

    void takeDamage(int tkdmg);

    void displayHp();

    int displayHpResource();

    void regenHp();

    void healthFunction();

    void equipSword();

    void unequipSword();

    void restack();

    void levelFunction();

    void inventoryFunction();

    void mapFunction();

    void buyItems();

    void sellItems();

    void shopFunction();

};


#endif //OOP_PLAYER_H

//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>

class Item{

protected:
    std::string name;
    bool givesHeal;
    int damage;
    int plusLevel;
    int levelReq;
    int healGain;
    int stackSize;
    int shopPrice;

public:
    Item();

    virtual ~Item();

    friend std::ostream& operator<<(std::ostream& out, const Item& item);

    void IncrementPlusLevel();

    bool getGivesHeal() const;

    int getPlusLevel() const;

    int getLevelReq() const;

    int getDamage() const;

    std::string getName();

    int getShopPrice() const;

    int getHealGain() const;

    int getStackSize() const;

};

#endif //OOP_ITEM_H

//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>

class Item{

protected:
    std::string name;
    bool givesheal;
    int damage;
    int pluslevel;
    int levelreq;
    int heal_gain;
    int stacksize;
    int shop_price;

public:
    Item();

    virtual ~Item();

    friend std::ostream& operator<<(std::ostream& out, const Item& item);

    void IncrementPluslevel();

    [[nodiscard]] bool getgivesHeal() const;

    [[nodiscard]] int getpluslevel() const;

    [[nodiscard]] int getlevelreq() const;

    [[nodiscard]] int getdamage() const;

    std::string getname();

    [[nodiscard]] int getshop_price() const;

    [[nodiscard]] int gethealgain() const;

    [[nodiscard]] int getstacksize() const;

};

#endif //OOP_ITEM_H

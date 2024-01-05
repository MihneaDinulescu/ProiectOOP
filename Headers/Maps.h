//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_MAPS_H
#define OOP_MAPS_H

#include <iostream>
#include <utility>

template<typename T>
class Maps {
private:
    T name;
    int levelReq;

public:
    Maps(T _name = "", int _levelReq = 0);

    virtual ~Maps();

    int getLevelReq() const;

    T getName() const;
};

#endif //OOP_MAPS_H

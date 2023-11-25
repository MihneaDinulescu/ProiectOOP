//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_MAPS_H
#define OOP_MAPS_H

#include<iostream>
#include <utility>

class Maps{
protected:
    std::string name;
    int levelReq;
public:
    explicit Maps(std::string _name = "", int _levelReq = 0);

    virtual ~Maps();

    int getLevelReq() const;

    std::string getName();
};

#endif //OOP_MAPS_H

//
// Created by dinul on 11/18/2023.
//
#include "Maps.h"

    Maps::Maps(std::string _name , int _levelReq) : name(std::move(_name)) , levelReq(_levelReq){}

    Maps::~Maps()=default;

    int Maps::getlevelReq() const{
        return this->levelReq;
    }

    std::string Maps::getname(){
        return this->name;
    }

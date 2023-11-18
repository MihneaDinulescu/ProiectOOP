//
// Created by dinul on 11/18/2023.
//

#include "Joan.h"

#include <utility>

 Joan::Joan(std::string _name , int _levelReq ) : Maps(std::move(_name),_levelReq) , bs(new Blacksmith()){}

Joan::~Joan(){
delete bs;
}
Blacksmith * Joan::getBlacksmith(){
    return this->bs;
}
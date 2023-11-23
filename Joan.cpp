//
// Created by dinul on 11/18/2023.
//

#include "Joan.h"

 Joan::Joan(const std::string& _name , int _levelReq ) : Maps(_name,_levelReq) , bs(new Blacksmith()){}

Joan::~Joan(){
delete bs;
}
Joan::Joan(const Joan& other) : Maps(other), bs(nullptr) {

    if (other.bs != nullptr) {
        this->bs = new Blacksmith(*(other.bs));
    }
}


Joan& Joan::operator=(const Joan& other) {
    if (this != &other) {
        Maps::operator=(other);

        delete this->bs;

        if (other.bs != nullptr) {
            this->bs = new Blacksmith(*(other.bs));
        } else {
            this->bs = nullptr;
        }
    }

    return *this;
}

Blacksmith * Joan::getBlacksmith(){
    return this->bs;
}
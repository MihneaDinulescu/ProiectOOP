//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Bakra.h"

Bakra::Bakra(std::string _name, int _levelReq) : Maps(std::move(_name), _levelReq) {}

Maps* Bakra::clone() const  {
return new Bakra(*this);
}

Bakra::~Bakra() = default;

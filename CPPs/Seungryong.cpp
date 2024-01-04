//
// Created by dinul on 11/18/2023.
//

#include "../Headers/Seungryong.h"

#include <utility>

Seungryong::Seungryong(std::string _name, int _levelReq) : Maps(std::move(_name), _levelReq) {}

Maps* Seungryong::clone() const  {
return new Seungryong(*this);
}

Seungryong::~Seungryong() = default;
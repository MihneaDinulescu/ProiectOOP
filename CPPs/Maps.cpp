//
// Created by dinul on 11/18/2023.
//
#include "../Headers/Maps.h"

template<typename T>
Maps<T>::Maps(T _name, int _levelReq) : name(std::move(_name)), levelReq(_levelReq) {}

template<typename T>
Maps<T>::~Maps() = default;

template<typename T>
int Maps<T>::getLevelReq() const {
    return this->levelReq;
}

template<typename T>
T Maps<T>::getName() const {
    return this->name;
}


template class Maps<std::string>;

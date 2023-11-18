//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_SEUNGRYONG_H
#define OOP_SEUNGRYONG_H

#include "Maps.h"

class Seungryong : public Maps{
public:
    explicit Seungryong(std::string _name = "", int _levelReq = 0);

    ~Seungryong() override;
};

#endif //OOP_SEUNGRYONG_H

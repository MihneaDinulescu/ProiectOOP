//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_BAKRA_H
#define OOP_BAKRA_H

#include "Maps.h"

class Bakra : public Maps {
public:
    explicit Bakra(std::string _name = "", int _levelReq = 0);

    ~Bakra() override;
};

#endif //OOP_BAKRA_H

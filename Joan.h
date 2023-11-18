//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_JOAN_H
#define OOP_JOAN_H

#include "BlackSmith.h"

class Joan : public Maps{
private:
    Blacksmith *bs;
public:
    explicit Joan(std::string _name = "", int _levelReq = 0);

    ~Joan() override;

    Blacksmith * getBlacksmith();
};

#endif //OOP_JOAN_H
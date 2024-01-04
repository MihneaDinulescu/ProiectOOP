//
// Created by dinul on 1/4/2024.
//

#ifndef OOP_GAMEMANAGERBUILDER_H
#define OOP_GAMEMANAGERBUILDER_H

#include "GameManager.h"

class GameManagerBuilder {
public:
    virtual void buildMaps() = 0;
    virtual void buildPlayer() = 0;
    virtual GameManager* getResult() = 0;
};


#endif //OOP_GAMEMANAGERBUILDER_H

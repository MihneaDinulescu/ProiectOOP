//
// Created by dinul on 1/4/2024.
//

#ifndef OOP_CONCRETEGAMEMANAGERBUILDER_H
#define OOP_CONCRETEGAMEMANAGERBUILDER_H

#include "GameManagerBuilder.h"
#include "GameManager.h"

class ConcreteGameManagerBuilder : public GameManagerBuilder {
private:
    GameManager *gameManager;

public:
    ConcreteGameManagerBuilder();

    ConcreteGameManagerBuilder(const ConcreteGameManagerBuilder& other);

    ConcreteGameManagerBuilder& operator=(const ConcreteGameManagerBuilder& other);

    void buildMaps() override;

    void buildPlayer() override;

    GameManager *getResult() override;

    ~ConcreteGameManagerBuilder() override;
};


#endif //OOP_CONCRETEGAMEMANAGERBUILDER_H

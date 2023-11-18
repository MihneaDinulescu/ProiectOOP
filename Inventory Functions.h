//
// Created by dinul on 11/18/2023.
//

#ifndef OOP_INVENTORY_FUNCTIONS_H
#define OOP_INVENTORY_FUNCTIONS_H

#define MAX_LEVEL 10

#include "Player.h"

void equipsword(Player *player);

void unequipsword(Player *player);

void restack(Player *player);

void Levelfun(Player *player);

void inventoryfun(Player *player);

#endif //OOP_INVENTORY_FUNCTIONS_H

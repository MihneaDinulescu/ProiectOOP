//
// Created by dinul on 11/18/2023.
//

#include "Monsters.h"

    Monsters::Monsters() : damage(0), hp(0), name("NULL"), level(0), region("NULL"), xp_gain(0) , yang_drop(0) {}
Monsters::~Monsters()=default;
Monsters::Monsters(const Monsters &copy){
        this->damage=copy.damage;
        this->hp=copy.hp;
        this->name=copy.name;
        this->level=copy.level;
        this->region=copy.region;
        this->xp_gain=copy.xp_gain;
        this->yang_drop=copy.yang_drop;
    }
Monsters& Monsters::operator=(const Monsters& monster){
        this->damage=monster.damage;
        this->hp=monster.hp;
        this->name=monster.name;
        this->level=monster.level;
        this->region=monster.region;
        this->xp_gain=monster.xp_gain;
        this->yang_drop=monster.yang_drop;
        return *this;
    }

void Monsters::attack(Player *player) {
    (void)player;
    }

    int Monsters::getXpGain() const{
        return this->xp_gain;
    }
    int Monsters::getdamage() const{
        return this->damage;
    }
    int Monsters::gethp() const{
        return this->hp;
    }
    std::string Monsters::getname(){
        return this->name;
    }
    void Monsters::takedamage(int dmg){
        this->hp=this->hp-dmg;
    }
    double Monsters::getYang_drop() const{
        return this->yang_drop;
    }


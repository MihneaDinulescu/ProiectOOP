//
// Created by dinul on 11/18/2023.
//

#include "Monsters.h"

    Monsters::Monsters() : damage(0), hp(0), name("NULL"), level(0), region("NULL"), xpGain(0) , yangDrop(0) {}
Monsters::~Monsters()=default;
Monsters::Monsters(const Monsters &copy){
        this->damage=copy.damage;
        this->hp=copy.hp;
        this->name=copy.name;
        this->level=copy.level;
        this->region=copy.region;
        this->xpGain=copy.xpGain;
        this->yangDrop=copy.yangDrop;
    }
Monsters& Monsters::operator=(const Monsters& monster){
        this->damage=monster.damage;
        this->hp=monster.hp;
        this->name=monster.name;
        this->level=monster.level;
        this->region=monster.region;
        this->xpGain=monster.xpGain;
        this->yangDrop=monster.yangDrop;
        return *this;
    }

void Monsters::attack(Player *player) {
    (void)player;
    }

    int Monsters::getXpGain() const{
        return this->xpGain;
    }
    int Monsters::getDamage() const{
        return this->damage;
    }
    int Monsters::getHp() const{
        return this->hp;
    }
    std::string Monsters::getName(){
        return this->name;
    }
    void Monsters::takeDamage(int dmg){
        this->hp=this->hp-dmg;
    }
    double Monsters::getYangDrop() const{
        return this->yangDrop;
    }


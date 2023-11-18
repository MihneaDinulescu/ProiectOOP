//
// Created by dinul on 11/18/2023.
//

#include "Player.h"

Player::Player() {
    this->hp = 50; // era 50
    this->damage = 1;
    this->inventory = new Inventory();
    this->yang = 50; //era 50
    this->sword = nullptr;
    this->level = 1;  // level 1 de start
    this->currentMap = nullptr;
    this->xp=0;
}

Player::Player(const Player& other) {
    // Copy simple members
    this->hp = other.hp;
    this->damage = other.damage;
    this->xp = other.xp;
    this->yang = other.yang;
    this->level = other.level;

    this->sword = (other.sword != nullptr) ? new Item(*(other.sword)) : nullptr;
    this->inventory = (other.inventory != nullptr) ? new Inventory(*(other.inventory)) : nullptr;
    this->currentMap = (other.currentMap != nullptr) ? new Maps(*(other.currentMap)) : nullptr;
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {

        delete this->sword;
        delete this->inventory;
        delete this->currentMap;

        this->hp = other.hp;
        this->damage = other.damage;
        this->xp = other.xp;
        this->yang = other.yang;
        this->level = other.level;

        this->sword = (other.sword != nullptr) ? new Item(*(other.sword)) : nullptr;
        this->inventory = (other.inventory != nullptr) ? new Inventory(*(other.inventory)) : nullptr;
        this->currentMap = (other.currentMap != nullptr) ? new Maps(*(other.currentMap)) : nullptr;
    }

    return *this;
}

int Player::getXp() const{
    return this->xp;
}
void Player::addXp(int _xp){
    this->xp += _xp;
}
void Player::difXp(int _xp){
    this->xp -= _xp;
}
Item * Player::getSword(){
    return this->sword;
}
int Player::getlevel() const{
    return this->level;
}
void Player::IncrementLevel(){
    this->level ++;
}
Maps * Player::getcurrentMap(){
    return this->currentMap;
}
void Player::setcurrentMap(Maps *map){
    this->currentMap=map;
}
void Player::setSwordNull(){
    this->sword=nullptr;
}
void Player::setSword(Item * sw){
    this->sword=sw;
}
void Player::healplayer(int add) {
    this->hp += add;
}
double Player::getYang() const{
    return this->yang;
}
void Player::difYang(double sum){
    this->yang = this->yang - sum;
}
void Player::sumYang(double sum) {
    this->yang = this->yang + sum;
}

int Player::gethp() const {
    return(this->hp);
}
void Player::sethp(int HP){
    this->hp = HP;
}

bool Player::isdead() const {
    if (this->hp <= 0) return(true);
    return(false);
}

Inventory * Player::getInventory() {
    return this->inventory;
}

void Player::endGame() {
    this->inventory->freeEverything();
    delete this->inventory;
}

int Player::getdamage() const {
    return(this->damage);
}

void Player::takedamage(int tkdmg) {
    this->hp = this->hp - tkdmg;
}
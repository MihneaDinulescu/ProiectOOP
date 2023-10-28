#include <iostream>

class Monsters{
protected:
    int damage;
    int hp;
    std::string name;
    std::string region;
    int xp_gain;
    int yang_drop;
public:
    friend std::ostream& operator<<(std::ostream&,const Monsters&);
    Monsters() : damage(0), hp(0), name("NULL"), region("NULL"), xp_gain(0) , yang_drop(0) {}
    ~Monsters()=default;
    Monsters(const Monsters &copie){
        this->damage=copie.damage;
        this->hp=copie.hp;
        this->name=copie.name;
        this->region=copie.region;
        this->xp_gain=copie.xp_gain;
        this->yang_drop=copie.yang_drop;
    }
    Monsters& operator=(const Monsters& monster){
        this->damage=monster.damage;
        this->hp=monster.hp;
        this->name=monster.name;
        this->region=monster.region;
        this->xp_gain=monster.xp_gain;
        this->yang_drop=monster.yang_drop;
        return *this;
    }
    int getdamage(){
        return this->damage;
    }
    int gethp(){
        return this->hp;
    }
    std::string getname(){
        return this->name;
    }
    void takedamage(int dmg){
        this->hp=this->hp-dmg;
    }
    int dead(){
        if(this->hp<=0) return 1;
        return 0;
    }
    int getyang(){
        return this->yang_drop;
    }
    std::string getregion(){
        return this->region;
    }
};

std::ostream &operator<<(std::ostream &out,const Monsters& m){
    out<<m.damage<<" "<<m.hp<<" "<<m.name<<" "<<m.region<<" "<<m.xp_gain<<" "<<m.yang_drop;
    return out;
}

class Caine : public Monsters{
public:
    Caine(){
        this->damage=1;
        this->hp=5;
        this->name="Caine";
        this->region="Joan";
        this->xp_gain=15;
        this->yang_drop=5;
    }
};

class Lup : public Monsters{
public:
    Lup(){
        this->damage=3;
        this->hp=10;
        this->name="Lup";
        this->region="Joan";
        this->xp_gain=25;
        this->yang_drop=7;
    }
};

class Mistret : public Monsters{
public:
    Mistret(){
        this->damage=5;
        this->hp=15;
        this->name="Mistret";
        this->region="Joan";
        this->xp_gain=40;
        this->yang_drop=20;
    }

};

class Amazoana : public Monsters{
public:
    Amazoana(){
        this->damage=10;
        this->hp=30;
        this->name="Amazoana";
        this->region="Bakra";
        this->xp_gain=70;
        this->yang_drop=40;
    }

};

class Tigru : public Monsters{
public:
    Tigru(){
        this->damage=13;
        this->hp=40;
        this->name="Tigru";
        this->region="Bakra";
        this->xp_gain=85;
        this->yang_drop=60;
    }

};

class Ork : public Monsters{
public:
    Ork(){
        this->damage=18;
        this->hp=60;
        this->name="Ork";
        this->region="Seungryong";
        this->xp_gain=110;
        this->yang_drop=80;
    }

};

class Luptator : public Monsters{
public:
   Luptator(){
       this->damage=21;
       this->hp=75;
       this->name="Luptator";
       this->region="Seungryong";
       this->xp_gain=130;
       this->yang_drop=100;

   }
};



int main() {
   Monsters m;
   Monsters a(m);
   std::cout<<m<<std::endl;
   Monsters x;
   x=m;
   Caine c;
   std::cout<<c.getdamage()<<" "<<c.gethp()<<" "<<c.getname()<<" "<<c.getregion()<<" "<<c.getyang()<<" "<<c.dead();
c.takedamage(2);
std::cout<<std::endl;
std::cout<<c.gethp();
return 0;
}

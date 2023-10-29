#include <iostream>
#include<string>

class Item{

protected:
    std::string name;
    bool givesheal;
    int damage;
    int pluslevel;
    int levelreq;
    int heal_gain;
    int stacksize;
    int shop_price;



public:
    Item(){
        this->name="NULL";
        this->givesheal=false;
        this->damage=0;
        this->pluslevel=0;
        this->levelreq=0;
        this->heal_gain=0;
        this->stacksize=0;
        this->shop_price=0;

    }
    ~Item()=default;

    friend std::ostream& operator<<(std::ostream& out, const Item& item);

    bool getgivesHeal(){
        return this->givesheal;
    }
    int getlevelreq(){
        return this->levelreq;
    }
    int getdamage(){
        return this->damage;
    }
    std::string getname(){
        return this->name;
    }
    int getshop_price(){
        return this->shop_price;
    }
    int gethealgain(){
        return this->heal_gain;
    }
    int getstacksize(){
        return this->stacksize;
    }

};

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << "Detaliile acestui item:" << std::endl;
    out << "Nume: " << item.name << std::endl;
    if(item.givesheal)
        out << "Heal oferit de 1x "<< item.name << "este + " << item.heal_gain << "HP";
    if(item.damage)
        out << "Damage: " << item.damage << std::endl;
    if(!item.givesheal)
        out << "Plus Level: " << item.pluslevel << std::endl;
    out << "Level necesar pentru achizitionare: " << item.levelreq << std::endl;
    out << "Pret x" << item.stacksize << ": " << item.shop_price << std::endl;
    return out;
}

class Sabie : public Item {

private:

public:
    Sabie(){
        this->name="Sabie";
        this->givesheal=false;
        this->damage=3;
        this->pluslevel=0;
        this->levelreq=1;
        this->shop_price=10;
        this->stacksize=1;
        this->heal_gain=0;
    }

};

class Iatagan : public Item {

private:

public:
    Iatagan(){
        this->name="Iatagan";
        this->givesheal=false;
        this->damage=5;
        this->pluslevel=0;
        this->levelreq=3;
        this->shop_price=50;
        this->stacksize=1;
        this->heal_gain=0;
    }

};

class Sabie_argint : public Item {

private:

public:
    Sabie_argint(){
        this->name="Sabie de argint";
        this->givesheal=false;
        this->damage=10;
        this->pluslevel=0;
        this->levelreq=10;
        this->shop_price=150;
        this->stacksize=1;
        this->heal_gain=0;
    }

};

class FMS : public Item {

private:

public:
    FMS(){
        this->name="Sabie luna plina";
        this->givesheal=false;
        this->damage=15;
        this->pluslevel=0;
        this->levelreq=17;
        this->shop_price=300;
        this->stacksize=1;
        this->heal_gain=0;
    }

};

class HP_small : public Item {

private:

public:
    HP_small(){
        this->name="Potiune HP mica";
        this->givesheal=true;
        this->damage=0;
        this->pluslevel=0;
        this->levelreq=1;
        this->shop_price=20;
        this->stacksize=10;
        this->heal_gain=3;
    }

};

class HP_medium : public Item {

private:

public:
    HP_medium(){
        this->name="Potiune HP medie";
        this->givesheal=true;
        this->damage=0;
        this->pluslevel=0;
        this->levelreq=1;
        this->shop_price=50;
        this->stacksize=5;
        this->heal_gain=10;
    }

};


class HP_big : public Item {

private:

public:
    HP_big(){
        this->name="Potiune HP mare";
        this->givesheal=true;
        this->damage=0;
        this->pluslevel=0;
        this->levelreq=1;
        this->shop_price=100;
        this->stacksize=1;
        this->heal_gain=100;
    }

};


class Shop{
private:
    Sabie sa;
    Iatagan ia;
    Sabie_argint sa_a;
    FMS fms;
public:
    friend std::ostream& operator<<(std::ostream&,const Shop&);
};
std::ostream &operator<<(std::ostream &out,const Shop& sh){
    out<<"1. "<<sh.fms.getname()<< std::endl <<"2. "<<sh.ia.getname() << std::endl <<"3. "<<sh.sa_a.getname() << std::endl<<"4. "<<sh.fms.getname();
    return out;
}


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
Shop s;
std::cout<<s;
std::cout<<std::endl;
Item P;
std::cout<<P;
P.getgivesHeal();
P.gethealgain();
P.getlevelreq();
P.getshop_price();
P.getname();
P.getdamage();
P.getstacksize();
P.getlevelreq();
return 0;
}

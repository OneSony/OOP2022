#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

Pokemon::Pokemon(int _hp,int _atk,string _name){
    tot_hp=_hp;
    hp=_hp;
    atk=_atk;
    name=_name;
}

Pokemon::~Pokemon(){

}

string Pokemon::get_name(){
    return name;
}

bool Pokemon::alive(){
    if(hp<=0){
        return false;
    }else{
        return true;
    }
}

int Pokemon::get_hp(){
    return hp;
}

int Pokemon::get_atk(){
    return atk;
}

void Squirtle::use_skill(int idx,Pokemon* target){
    switch(idx){
        case 0://回血
            hp+=tot_hp*0.2;
            if(hp>tot_hp){
                hp=tot_hp;
            }
            cout<<this->name<<" used Regen"<<endl;
        return;

        case 1://喷射
            cout<<this->name<<" used Splash to "<<target->get_name()<<endl;
            target->hurt(atk,this);
        return;

        default:
        return;
    }
}

void Squirtle::hurt(int dmg,Pokemon* from){
    if(hp<=tot_hp*0.2){
        dmg*=0.5;
        if(dmg==0){
            dmg=1;
        }
    }
    hp-=dmg;
    cout<<this->name<<" received "<<dmg<<" damage from "<<from->get_name()<<endl;
    alive();
}

void Charizard::use_skill(int idx,Pokemon* target){
    switch(idx){
        case 0://点燃
            fire+=1;
            atk*=2;
            cout<<this->name<<" used Ignite"<<endl;
            hurt(fire*10,this);
        return;

        case 1://喷火
            cout<<this->name<<" used Flame to "<<target->get_name()<<endl;
            target->hurt(atk,this);
        return;

        default:
        return;
    }
}

void Charizard::hurt(int dmg,Pokemon* from){
    hp-=dmg;
    cout<<this->name<<" received "<<dmg<<" damage from "<<from->get_name()<<endl;
    alive();
    if(dmg>10&&from!=this){
        from->hurt(dmg*0.2,this);
    }
}
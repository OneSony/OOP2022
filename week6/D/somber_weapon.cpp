#include<iostream>
#include"somber_weapon.h"
using namespace std;

void SomberWeapon::levelup(){
    upgrade();

    switch(get_level()-1){
        case 0:
        cout<<"Somber weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
        break;

        default:
        cout<<"Somber weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
        break;
    }
}
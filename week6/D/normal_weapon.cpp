#include<iostream>
#include"normal_weapon.h"
using namespace std;

void NormalWeapon::levelup(){
    upgrade();

    switch(get_level()-1){
        case 0:
        cout<<"Normal weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
        break;

        default:
        cout<<"Normal weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
        break;
    }
}
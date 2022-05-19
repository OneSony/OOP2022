#include<iostream>
#include"normal_smithing_stone.h"

using namespace std;

void NormalSmithingStone::add(int amount){
    this->add_amount(amount);

    if(amount>=0){
        cout<<"Normal smithing stone "<<get_level()<<" was added with "<<amount<<"."<<endl;
    }else{
        cout<<"Normal smithing stone "<<get_level()<<" was substracted with "<<-amount<<"."<<endl;
    }
}
#include<iostream>
#include"somber_smithing_stone.h"

using namespace std;

void SomberSmithingStone::add(int amount){
    this->add_amount(amount);

    if(amount>=0){
        cout<<"Somber smithing stone "<<get_level()<<" was added with "<<amount<<"."<<endl;
    }else{
        cout<<"Somber smithing stone "<<get_level()<<" was substracted with "<<-amount<<"."<<endl;
    }
}
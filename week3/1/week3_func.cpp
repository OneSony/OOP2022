#include<iostream>

#ifndef _WEEK3_
#define _WEEK3_
#include"week3.h"
#endif

double Move::calc(){
    return x*y;
}

void Move::display(){
    std::cout<<Move::calc()<<std::endl;
}

double Move::get_x(){
    return x;
}

double Move::get_y(){
    return y;
}

void Move::reset(double a,double b){
    x=a;
    y=b;
}

Move::Move(double a,double b){
    x=a;
    y=b;
}
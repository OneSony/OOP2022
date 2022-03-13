#include<iostream>

#ifndef _WEEK3_
#define _WEEK3_
#include"week3.h"
#endif

using namespace std;
int main(){
    
    Move obj;
    obj.reset(10,20);
    cout<<obj.get_x()<<endl;
    cout<<obj.get_y()<<endl;
    obj.display();

}
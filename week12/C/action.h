#pragma once
#include <vector>
using namespace std;

void action(Animal* animal,vector<Dog> &dogzone,vector<Bird> &birdzone){
    Dog* d=dynamic_cast<Dog*>(animal);
    Bird* b=dynamic_cast<Bird*>(animal);

    if(d!=nullptr){
        dogzone.push_back(move(*d));
        return;
    }
    
    if(b!=nullptr){
        birdzone.push_back(move(*b));
        return;
    }
}
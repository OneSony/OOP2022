#include"Map.h"
#include"Pair.h"
#include<iostream>
#include<string>

Map::Map(int n){
    data=new Pair[n];
    sz=0;
}

Map::~Map(){
    delete[] data;
}

int& Map::operator[](const string &s){
    //printf("non-const!\n");
    for(int i=0;i<sz;i++){
        //cout<<"*"<<i<<" is "<<data[i].puts()<<endl;
        if(data[i].hasKey(s)==true){
            return data[i].getVal();
        }
    }

    //没找到
    data[sz].reset(s,0);
    sz++;
    return data[sz-1].getVal();

}

const int Map::operator[](const string &s)const{
    for(int i=0;i<sz;i++){
        if(data[i].hasKey(s)==true){
            //printf("const!\n");
            return data[i].getVal();//const to non-const?
        }
    }
    return 0;
}

int& Map::size(){
    return sz;
}


#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    ~Map();
    // TODO
    
    //const string& operator[](const string &s)const;

    int& operator[](const string &s);
    const int operator[](const string &s)const;
    int& size();
};
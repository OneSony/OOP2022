#pragma once

#include <string>

#include "Hash.h"

template <typename T1, typename T2>
class HashTable
{
private:
    int n;
    T2** table;
public:
    HashTable(int _n):n(_n){
        table=new T2*[_n];
        for(int i=0;i<_n;i++){
            table[i]=nullptr;
        }
    }
    ~HashTable(){
        for(int i=0;i<n;i++){
            if(table[i]!=nullptr){
                delete table[i];
            }
        }
        delete[] table;
    }
    void addItem(const T1 &key, const T2 &value);
    void removeItem(const T1 &key);
    T2 *findByKey(const T1 &key);
};


/*template<>
void HashTable<int,int>::addItem(const int &key,const int &value){
    Hash<int> h(n);
    int h_temp=h(key);
    if(table[h_temp]==nullptr){
        table[h_temp]=new int(value);
    }else{
        *table[h_temp]=value;
    }
}*/

template<typename T1,typename T2>
void HashTable<T1,T2>::addItem(const T1 &key,const T2 &value){
    Hash<T1> h(n);
    int h_temp=h(key);
    if(table[h_temp]==nullptr){
        table[h_temp]=new T2(value);
    }else{
        *table[h_temp]=value;
    }
}

template<typename T1,typename T2>
void HashTable<T1,T2>::removeItem(const T1 &key){
    Hash<T1> h(n);
    int h_temp=h(key);
    if(table[h_temp]!=nullptr){
        delete table[h_temp];
        table[h_temp]=nullptr;
    }
}

template<typename T1,typename T2>
T2* HashTable<T1,T2>::findByKey(const T1 &key){
    Hash<T1> h(n);
    int h_temp=h(key);
    return table[h_temp];
}
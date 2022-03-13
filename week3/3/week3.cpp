#include<iostream>
#include<ctime>
using namespace std;
int f1(int a,int b){
    return a+b;
}

inline int f2(int a,int b){
    return a+b;
}

int main(){
    
    double start,end;

    start=clock();
    for(int i=0;i<100000000;i++){
        f1(1,1);
    }
    end=clock();
    cout<<"f1="<<end-start<<endl;
    
    start=clock();
    for(int i=0;i<100000000;i++){
        f2(1,1);
    }
    end=clock();
    cout<<"inline f2="<<end-start<<endl;
}
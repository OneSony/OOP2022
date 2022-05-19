#include<iostream>
#include<stdlib.h>
using namespace std;
class A{
    //const char* s;
    public:
    const char* s;
    A(){
        s="test";
        cout<<"A()"<<endl;
    }
    A(int i){
        cout<<"A(int)"<<endl;
    }
};
class C{
    public:
    C(){
        cout<<"C()"<<endl;
    }
};

class B{
    //A a;
    public:
    A a;
    B(int x=1){
        //初始化a
        C c;
    }
};

int main(){

    B b;
    b.a.s="123";
    printf("%s\n",b.a.s);
    return 0;
}
#include<iostream>
using namespace std;
static int outtest;
class A{
    public:
    int intest;
    A(int n=0){
        cout<<"class"<<endl;
    }
};

class B{
    public:
    static A a1;
    A a2;
    B(){
        a2(1);
    }
};

class C{
    public:
    static int inc;
};

int C::inc=0;
int main(){
    //printf("%d",B::a1.intest);
    //cout<<"hello"<<endl;
    //B b1;
    //printf("out:%d\n",outtest);
    //printf("in:%d\n",b1.a1.intest);
    cout<<C::inc<<endl;

    return 0;
}
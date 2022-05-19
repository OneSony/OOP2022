#include <iostream>
using namespace std;

class Base{
public:
    Base(){}
    void func1() {cout << "Base::func1()" << endl;}
    virtual void func2() {cout << "Base::func2()" << endl;}
    virtual void func2(int) {cout << "Base::func2(int)" << endl;}
    virtual void func2(float) {cout << "Base::func2(float)" << endl;} // (1)
};
class Derived1: public Base{
public:
    //void func1() final {cout << "Derived1::func1()" << endl;} // (2)
    void func2(float) {cout << "Derived1::func2(float)" << endl;}
};
class Derived2: public Base{
public:
    void func2(int) final override {cout << "Derived2::func2(int)" << endl;} // (3)
};

int main(){
    Derived1 obj;
    //obj.func2(); // (4)
    int a;
    obj.func2(a);
    return 0;
}
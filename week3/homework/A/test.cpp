#include<iostream>
class A {
    int a;
public:
  void set(int a) {this->a = a;}
  bool get(int b) {return b > a;}
  //bool get(int b, int c=1) {return (b + c) > a;}
};

int main() {
  auto a_test = new A();
  a_test->set(10);
  std::cout << a_test->get(2) << std::endl;
  return 0;
}
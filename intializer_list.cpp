#include <iostream>
using namespace std;

class A {
    int a;
  public:
  A(): A(0) {
      cout << "Default Constructing A\n";
  }
  A(int _a) : a{_a} {
      cout << "Constructing A\n";
  }
  ~A(){
      cout << "Destroying A\n";
  }
};

class B {
  int b;
  public:
  B() {
      cout << "Default Constructing B\n";
  }
  B(int _b) : b{_b} {
      cout << "Constructing B\n";
  }
  ~B(){
      cout << "Destroying B\n";
  }
};

class C {
  int c;
  B b = B(10);
  A a;
  public:
  C(int _c) : c{_c} {
      cout << "Constructing C\n";
  }
  ~C(){
      cout << "Destroying C\n";
  }
};

int main (void)
{
  C c(10);
  return 0;
}
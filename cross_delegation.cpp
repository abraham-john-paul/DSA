#include <iostream>

using namespace std;

struct A {
    virtual ~A() = default;
    virtual void operation1() = 0;
    virtual void operation2() = 0;
};

struct B : virtual A {
    virtual ~B() = default;
    virtual void operation1() {
        cout << "\nOperation 1 done by B";
    }
};

struct C : virtual A {
    virtual ~C() = default;
    virtual void operation2() {
        cout << "\nOperation 2 done by C";
    }
};

struct  D final : B, C {
};

int main() {
    D d;
    B& b = d;
    d.operation2(); 
    return 0;
}
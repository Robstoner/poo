#include <iostream>
using namespace std;
class A {
public:
    A () {cout << "A";}
    virtual ~A () {cout << "~A";}
};
class B: public A {
public:
    B () {cout << "B";}
    ~B () {cout << "~B";}
};
class C: public B {
public:
    C () {cout << "C";}
    ~C () {cout << "~C";}
};
int main () {
    A *pa = new C(); delete pa;
    return 0;
}

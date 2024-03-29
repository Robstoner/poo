#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A(int i = 0) { x = i; }
    A operator+(const A &a) { return x + a.x; }
    template <class T>
    ostream &operator<<(ostream &);
};

template <class T>
ostream &A::operator<<(ostream &o)
{
    o << x;
    return o;
}

int main()
{
    A a1(1), a2 = 2, a3;
    a3 = a1 + a2;
    return 0;
}
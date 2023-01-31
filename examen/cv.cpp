#include <iostream>
using namespace std;

class B {
protected:
    static int x;
    int offset;
public:
    B()
    {x++; offset = 100;}
    ~B() { x--; }
    static int get_x() { return x; }
    int get_offset() { return offset; }
    int f() { return (x + offset) / 2; }
};
int B::x = 0;

class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
    int f() { return ( (x + offset) / 2 + 1); }
};

void func(B* q, int n) {cout << q->get_x() << " ";
    for(int i = 0; i < n; i++) cout << q[i].f() << " ";
    cout<<"\n";
}

int main()
{
    B* p = new B[2]; func(p, 2); delete[] p;
    p = new D; func(p, 1); delete p;
    cout << D::get_x();    return 0;
}
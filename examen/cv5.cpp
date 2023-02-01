#include  <iostream>
using namespace std;
class A {
    int i;
    protected: static int x;

    public: A(int j = 7) {i = j; x=j;}
    int get_x() {return x;}
    int set_x(int j) {int y = x; x = j; return y;}
};
int A::x =15;
int main()
{
    A a(212), b;
}
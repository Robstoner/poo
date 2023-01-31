#include<iostream>
using namespace std;
class A
{ int x, *y;
public: A(int i) { x=i; y=new int[x]; }
A(A& a) { x=a.x; y=new int[x]; }
int get_x() const { return x; } };
int f(A a) { return a.get_x(); }
int main()
{ const A a(5);
cout<<(a.get_x()==f(a));
return 0;
}
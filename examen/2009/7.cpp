#include<iostream>
using namespace std;
class A;
class B
{ int x;
public: B(int i=107) { x=i; }
operator A(); };
B::operator A() { return x; }
class A
{ int x;
public: A(int i=6) { x=i; }
int get_x() { return x; } };
int main()
{ B b;
A a=b;
cout<<a.get_x();
return 0;
}
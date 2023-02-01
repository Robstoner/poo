#include <iostream>
using namespace std;
int x = 10;
void f(int x)
{
    cout << x << " \n";
    cout << ::x << " doua puncte\n";
    class A {
        protected : int x;
        public: A(int a = 30) {x = a; cout << x << " ";}
    };
    class B : public A {
        int x;
        public:
        B(int b = 40) {x = b; cout << x << " " << x << " ";}
        int afis() {cout << A::x << " x u lu A\n"; cout << x << " x u lu B\n";
            return x + A::x;}
    } ob2;
    cout << x + :: x + ob2.afis();
}

int main()
{
    f(20);
}
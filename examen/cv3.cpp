#include <iostream>
using namespace std;

class A
{
    int x;
public:
    A(int i = 25){ x = i; }
    const int& get_x() const  { return x;  }
    void set_x(int i) { x = i; }
    A& operator=(A a1)
    {
        set_x(a1.get_x());
        return *this;
    }
};

int main()
{
    A a(18), b(7);
    (b=a).set_x(27);
    int i;
    i=b.get_x();
    cout << i;
    return 0;
}

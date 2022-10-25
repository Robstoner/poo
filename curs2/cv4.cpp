#include <iostream>

using namespace std;

class Test
{
    int x, y, z;

public:
    void citire();
    void afis();
    Test(int a = 1, int b = 2, int c = 3);
    Test(const Test&); // constructor de copiere TREBUIE & altfel nu merge
    // poate fi si fara const, dar e mai bine cu, pentru a nu putea face modificari la obiectul transmis din functie
    ~Test();
} A, B(100);

Test C;

void f(Test D) {}

int main()
{
    Test E(4, 5, 6);
    f(E);
    for (int i = 0; i < 2; ++i)
    {
        Test F(i, i + 10);
    }
    Test G(B);
}

void Test :: citire()
{
    cin >> x >> y >> z;
}

void Test :: afis()
{
    cout << x << " " << y << " " << z << '\n';
}

Test :: Test(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
    afis();
}


// constructor de copiere, se apeleaza la returnare, la copiere ( Test G(B) ), sau la parametrizare ( in functia f ) 
Test :: Test(const Test& ob)
{
    x = ob.x;
    y = ob.y;
    z = ob.z;
    cout << "Copiere " << x << " " << y << " " << z << '\n';
}

Test :: ~Test()
{
    cout << "D " << x << " " << y << " " << z << '\n';
}
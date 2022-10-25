#include <iostream>

using namespace std;

class Test
{
    int x, y, z;

public:
    void citire()
    {
        cin >> x >> y >> z;
    }
    void afis()
    {
        cout << x << " " << y << " " << z << '\n';
    }
    Test() { afis(); }
    Test(int a) // constructor cu un parametru; constructor EXPLICIT, ascude orice varianta implicita
    {
        x = a;
        afis();
    }
    Test(int a, int b)
    {
        x = a;
        y = b;
        afis();
    }
    Test(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
        afis();
    }
    ~Test() {
        cout << "D " << x << " " << y << " " << z << '\n';
    }
};

int main()
{
    Test A; // apeleaza constr de initializare EXPLICIT
    A.afis();

    Test B(100);           // apeleaza constructorul cu un parametru
    Test C(200, 300);      // --""-- cu doi parametrii
    Test D(400, 500, 600); // --""-- cu trei parametrii

    
}

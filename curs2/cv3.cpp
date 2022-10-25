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

    /// putem inclocui toti constructorii separati cu un singur constructor care are valori implicite

    Test(int a = 1, int b = 2, int c = 3)
    {
        x = a;
        y = b;
        z = c;
        afis();
    }
    // argumentele cu valori implicite trebie puse la finalul argumentelor

    ~Test()
    {
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

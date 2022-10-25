#include <iostream>

using namespace std;

class Test
{
    int x, y, z;

public:
    void citire() {
        cin >> x >> y >> z;
    }
    void afis() {
        cout << x << " " << y << " " << z << '\n';
    }
};

int main()
{
    cout << "cv" << '\n';

    Test A; // construtor de initializare
    A.citire();
    A.afis();

    Test B{A}; // constructor de copiere
    Test C = A; // constructor de copiere
    B.afis();
    C.afis();

    Test D;
    D = A; // operator de atribuire =
    D.afis();

    // doar constructorul aloca memorie

    {
        Test E;
        E = A;
        E.afis();
    }

    // E.afis(); /// E nu exista aici, dispare dupa ce iese din acolade
}

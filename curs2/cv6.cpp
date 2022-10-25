#include <iostream>
#include <cstring>

using namespace std;

class Curs
{
protected: // pentru a putea fi accesata din functiile mostenite
    string denumire;

    friend void functie();
};

class Optional : public Curs
{
    int ore;

public:
    void afis();
    void citire();
}; /// mostenire, relatie de tip "is a" sau "is like a"

void Optional ::citire()
{
    cin >> denumire >> ore;
}

void Optional ::afis()
{
    cout << denumire << " " << ore << '\n';
}

void functie()
{
    Curs x;
    cout << x.denumire; // nu merge pentru ca este protected, merge doar daca functia este friend
}

int main()
{
    Optional o;
    o.citire();
    o.afis();
}
#include <iostream>
#include <cstring>

using namespace std;

class Profesor
{
    string nume;

public:
    void citire();
    void afis();

    // friend class Curs; /// pentru a da access altei clase la datele private ale acesteia
};

class Curs
{
    string denumire;
    Profesor P; // compunere/agregare, o relatie de tip "has a"

public:
    void citire();
    void afis();
};

class Optional : public Curs
{
    int ore;

public:
    void afis();
}; /// mostenire, relatie de tip "is a" sau "is like a"

void Profesor ::citire()
{
    cin >> nume;
}

void Profesor ::afis()
{
    cout << "Profesor: " << nume << '\n';
}

void Curs ::citire()
{
    cin >> denumire;
    P.citire();
}

void Curs ::afis()
{
    cout << "Curs: " << denumire << " ";
    P.afis();
}

void Optional ::afis()
{
    cout << "Din derivata  " << ore << '\n';
    Curs::afis();
    cout << "optional.afis\n";
}

int main()
{
    Curs T;
    T.citire();
    T.afis();

    Optional o;
    o.citire();
    o.afis();
    o.Curs::afis();
}
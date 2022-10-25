#include <iostream>
#include <cstring>

using namespace std;

/// Nu este bine pentru ca totul din struct este public = restanta
struct person
{
    char name[255];
    int group;

    person(char *name_, int group_)
    {
        strcpy(name, name_);
        group = group_;
    }
};

/// Folosim class, unde elementele sunt private by default, iar apoi folosim public: pentru functii si alte lucruri care nu trebuie private
class Person
{
    char *name;
    int group;

public:
    Person(char *name_, int group_)
    {
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
        group = group_;
    }
    
    /// constructor default, fara parametrii
    Person() {
        name = new char[8];
        strcpy(name, "default");
        group = 0;
    }

    void Afisare() {
        cout << "Nume: " << name << ' ' << group << '\n';
    }

    const char* getName() {
        return name;
    }

    void setName(char* name_) {
        delete name;
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
    }

    // destructor
    // poate exista un singur destructor, dar mai multi consctructori
    // el se apeleaza singur cand compilatorul vede ca nu mai este nevoie de datele din clasa

    ~Person() {
        delete[] name;
    }
};

int main()
{
    char ion_str[] = "Ion";

    person pers(ion_str, 264);

    Person pers_class(ion_str, 264);

    Person p_default[100];     // nu va merge daca ca nu avem un constructor fara parametrii (no default constructor exists for class "Person")

    /// Daca vrei sa facem un array fara sa avem un constructor default, facem un sir de pointeri :

    Person *p_pointer[100];
    p_pointer[0] = new Person("Paul", 264);

    delete p_pointer[0];

    /// Acest lucru nu este bun pentru ca it defeats the purpose

    int *v;

    // v = malloc(100 * sizeof(int));

    v = new int[100];

    // delete v; // gresit
    delete[] v; // corect

    pers_class.Afisare();

    Person *s = new Person(ion_str, 264);
    (*s).Afisare();
    // sau, mai bine
    s->Afisare();

    pers_class.setName("Andrei");

    // cout << pers_class.name // nu va merge pentru ca informatia este ascunsa in private

    cout << pers_class.getName();

    /// Daca avem pointer la getName ne va da adresa de memorie si vom putea modifica elementul fara sa avem un setter

    // strcpy(pers_class.getName(), "Paul");

    /// De aceea folosim const char* la getter

    /* cum functioneaza const

    const int *c; 
    int const *t2;
    int* const t3= //o adresa de memorie; 
    
    primele doua sunt la fel, si sunt pointeri care nu pot fi modificati
    al treilea este un pointer catre o adrea de memorie statica, dar valoare din el se poate schimba*/

    /// IMPORTANT!!!!
    /// Pentru fiecare new trebuie sa avem si un delete.


    // delete pers_class.name; // nu va merge pentru ca este privat


}
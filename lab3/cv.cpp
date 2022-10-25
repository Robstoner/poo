#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    char *name;
    int group;

public:
    // Person(char *name_, int group_)
    // {
    //     delete name;
    //     name = new char[strlen(name_) + 1];
    //     strcpy(name, name_);
    //     group = group_;
    // }

    // putem folosi this-> pentru a diferentia parametrii de datele pe care le avem in obiect, fara sa le dam alt nume (name_)

    Person(char *name, int group)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->group = group;
    }

    // Person(const Person &rhs) = delete;
    // varianta "dirty" prin a nu avea nevoie sa facem un constructor de copiere

    Person(Person &rhs)
    {
        name = new char[strlen(rhs.name)];
        strcpy(name, rhs.name);
        group = rhs.group;
    }

    /// constructor default, fara parametrii
    Person()
    {
        name = new char[8];
        strcpy(name, "default");
        group = 0;
    }

    void Afisare() const
    {
        cout << &name;

        cout << "Nume: " << name << ' ' << group << '\n';
    }

    const char *getName() const
    { // folosim const pentru a nu da optiunea de a modifica date in getteri/afisari
        return name;
    }

    void setName(char *name_)
    {
        cout << &name;
        delete[] name;
        cout << &name << '\n';
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
    }

    ~Person()
    {
        cout << &name << '\n';
        cout << name << '\n';
        delete[] name;
        cout << &name << '\n';
    }
};

// void f(Person &p)
// {
//     p.setName("Paul");
// }

// void g(Person p)
// {
//     p.setName("George");
// }

int main()
{
    // Person p("ion", 230);
    // {
    //     Person p2("paul", 230);
    // }
    // // pt obiectele normale destructorul se apeleaza automat cand nu mai este nevoie de el

    // Person *p_din = new Person("ion", 230);
    // delete p_din; // pentru ob alocate dinamic destructorul se apeleaza doar cand dam noi delete

    // Person b("ion", 230);
    // f(b);
    // g(b);
    // b.Afisare();

    Person p1("Ion", 230);
    p1.Afisare();
    Person p2 = p1;
    p2.Afisare();
    p2.setName("Paul");

    p1.Afisare();
    p2.Afisare();
}
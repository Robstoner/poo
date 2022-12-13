#include "../headers/Seminar.h"

Seminar::Seminar() : Sala()
{
    this->tip_tabla = Tip_tabla::alba;
}

Seminar::Seminar(const std::string &nume, int etaj, int nr_sala, int nr_locuri, Tip_tabla tip_tabla) : Sala(nume, etaj, nr_sala, nr_locuri)
{
    this->tip_tabla = tip_tabla;
}

Seminar::Seminar(const Seminar &seminar) : Sala(seminar)
{
    this->tip_tabla = seminar.tip_tabla;
}

Seminar &Seminar::operator=(const Seminar &seminar)
{
    Sala::operator=(seminar);
    this->tip_tabla = seminar.tip_tabla;
    return *this;
}

Seminar::~Seminar()
{
    this->tip_tabla = Tip_tabla::alba;
}

Tip_tabla Seminar::get_tip_tabla() const
{
    return this->tip_tabla;
}

void Seminar::set_tip_tabla(Tip_tabla tip_tabla_)
{
    this->tip_tabla = tip_tabla_;
}

std::ostream &operator<<(std::ostream &out, const Seminar &seminar)
{
    out << dynamic_cast<const Sala &>(seminar) << std::endl;
    out << "Tip tabla: ";
    switch (seminar.get_tip_tabla())
    {
    case Tip_tabla::alba:
        out << "alba";
        break;
    case Tip_tabla::neagra:
        out << "neagra";
        break;
    case Tip_tabla::smart:
        out << "smart";
        break;
    }
    out << std::endl;
    return out;
}

int Seminar::get_nr_echipamente() const
{
    return 2;
}

std::istream &operator>>(std::istream &in, Seminar &seminar)
{
    in >> dynamic_cast<Sala &>(seminar);
    std::cout << "Tip tabla: ";
    while (true)
    {
        std::string tip_tabla_string;
        std::cin >> tip_tabla_string;
        if (tip_tabla_string == "alba")
        {
            seminar.set_tip_tabla(Tip_tabla::alba);
            break;
        }
        else if (tip_tabla_string == "neagra")
        {
            seminar.set_tip_tabla(Tip_tabla::neagra);
            break;
        }
        else if (tip_tabla_string == "smart")
        {
            seminar.set_tip_tabla(Tip_tabla::smart);
            break;
        }
        else
        {
            std::cout << "Tipul de tabla nu este valid!" << std::endl;
            std::cout << "Alegeti unul dintre urmatoarele: alba, neagra, smart" << std::endl;
        }
    }
    return in;
}
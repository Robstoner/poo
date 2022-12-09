#include "../headers/Seminar.h"

Seminar::Seminar() : Sala()
{
    this->tip_tabla = Tip_tabla::alba;
}

Seminar::Seminar(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente, Tip_tabla tip_tabla) : Sala(nume, etaj, nr_sala, nr_locuri, echipamente)
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

std::string Seminar::get_nume() const
{
    return this->nume;
}

int Seminar::get_etaj() const
{
    return this->etaj;
}

int Seminar::get_nr_sala() const
{
    return this->nr_sala;
}

int Seminar::get_nr_locuri() const
{
    return this->nr_locuri;
}

std::vector<std::string> Seminar::get_echipamente() const
{
    return this->echipamente;
}

Tip_tabla Seminar::get_tip_tabla() const
{
    return this->tip_tabla;
}

void Seminar::set_nume(std::string nume)
{
    this->nume = nume;
}

void Seminar::set_etaj(int etaj)
{
    this->etaj = etaj;
}

void Seminar::set_nr_sala(int nr_sala)
{
    this->nr_sala = nr_sala;
}

void Seminar::set_nr_locuri(int nr_locuri)
{
    this->nr_locuri = nr_locuri;
}

void Seminar::set_echipamente(std::vector<std::string> echipamente)
{
    this->echipamente = echipamente;
}

void Seminar::set_tip_tabla(Tip_tabla tip_tabla)
{
    this->tip_tabla = tip_tabla;
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
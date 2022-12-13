#include "../headers/Sala.h"

Sala::Sala()
{
    this->nume = "";
    this->etaj = 0;
    this->nr_sala = 0;
    this->nr_locuri = 0;
}

Sala::Sala(const std::string &nume, int etaj, int nr_sala, int nr_locuri) : nume(nume)
{
    this->etaj = etaj;
    this->nr_sala = nr_sala;
    this->nr_locuri = nr_locuri;
}

Sala::Sala(const Sala &sala) : nume(sala.nume)
{
    this->etaj = sala.etaj;
    this->nr_sala = sala.nr_sala;
    this->nr_locuri = sala.nr_locuri;
}

Sala &Sala::operator=(const Sala &sala)
{
    this->nume = sala.nume;
    this->etaj = sala.etaj;
    this->nr_sala = sala.nr_sala;
    this->nr_locuri = sala.nr_locuri;
    return *this;
}

void Sala::set_etaj(int etaj_)
{
    this->etaj = etaj_;
}

void Sala::set_nr_sala(int nr_sala_)
{
    this->nr_sala = nr_sala_;
}

void Sala::set_nr_locuri(int nr_locuri_)
{
    this->nr_locuri = nr_locuri_;
}

void Sala::set_nume(const std::string &nume_)
{
    this->nume = nume_;
}

int Sala::get_etaj() const
{
    return this->etaj;
}

int Sala::get_nr_sala() const
{
    return this->nr_sala;
}

int Sala::get_nr_locuri() const
{
    return this->nr_locuri;
}

std::string Sala::get_nume() const
{
    return this->nume;
}

Sala::~Sala()
{
    this->nume = "";
    this->etaj = 0;
    this->nr_sala = 0;
    this->nr_locuri = 0;
}

std::ostream &operator<<(std::ostream &out, const Sala &sala)
{
    out << "Nume: " << sala.nume << std::endl;
    out << "Etaj: " << sala.etaj << std::endl;
    out << "Numar sala: " << sala.nr_sala << std::endl;
    out << "Numar locuri: " << sala.nr_locuri << std::endl;
    out << "Echipamente: ";

    return out;
}

std::istream &operator>>(std::istream &in, Sala &sala)
{
    std::cout << "Introduceti numele salii: ";
    in >> sala.nume;
    std::cout << "Etaj: ";
    in >> sala.etaj;
    std::cout << "Numar sala: ";
    in >> sala.nr_sala;
    std::cout << "Numar locuri: ";
    in >> sala.nr_locuri;

    return in;
}

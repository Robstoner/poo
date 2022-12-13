#include "../headers/Amfiteatru.h"

Amfiteatru::Amfiteatru() : Sala()
{
    this->nr_randuri = 0;
    this->nume_amf = "";
}

Amfiteatru::Amfiteatru(const std::string &nume, int etaj, int nr_sala, int nr_locuri, int nr_randuri, const std::string &nume_amf) : Sala(nume, etaj, nr_sala, nr_locuri)
{
    this->nr_randuri = nr_randuri;
    this->nume_amf = nume_amf;
}

Amfiteatru::Amfiteatru(const Amfiteatru &amfiteatru) : Sala(amfiteatru)
{
    this->nr_randuri = amfiteatru.nr_randuri;
    this->nume_amf = amfiteatru.nume_amf;
}

Amfiteatru &Amfiteatru::operator=(const Amfiteatru &amfiteatru)
{
    Sala::operator=(amfiteatru);
    this->nr_randuri = amfiteatru.nr_randuri;
    this->nume_amf = amfiteatru.nume_amf;
    return *this;
}

Amfiteatru::~Amfiteatru()
{
    this->nr_randuri = 0;
    this->nume_amf = "";
}

void Amfiteatru::set_nr_randuri(int nr_randuri_)
{
    this->nr_randuri = nr_randuri_;
}

void Amfiteatru::set_nume_amf(const std::string &nume_amf_)
{
    this->nume_amf = nume_amf_;
}

int Amfiteatru::get_nr_randuri() const
{
    return this->nr_randuri;
}

std::string Amfiteatru::get_nume_amf() const
{
    return this->nume_amf;
}

int Amfiteatru::get_nr_echipamente() const
{
    return 3;
}

std::ostream &operator<<(std::ostream &out, const Amfiteatru &amfiteatru)
{
    out << dynamic_cast<const Sala &>(amfiteatru) << std::endl;
    out << "Numar randuri: " << amfiteatru.get_nr_randuri() << std::endl;
    out << "Nume amfiteatru: " << amfiteatru.get_nume_amf() << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Amfiteatru &amfiteatru)
{
    in >> dynamic_cast<Sala &>(amfiteatru);
    std::cout << "Numar randuri: ";
    in >> amfiteatru.nr_randuri;
    std::cout << "Nume amfiteatru: ";
    in >> amfiteatru.nume_amf;
    return in;
}
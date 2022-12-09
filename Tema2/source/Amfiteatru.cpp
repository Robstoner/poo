#include "../headers/Amfiteatru.h"

Amfiteatru::Amfiteatru() : Sala()
{
    this->nr_randuri = 0;
    this->nume_amf = "";
}

Amfiteatru::Amfiteatru(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente, int nr_randuri, std::string nume_amf) : Sala(nume, etaj, nr_sala, nr_locuri, echipamente)
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

void Amfiteatru::set_nume(std::string nume)
{
    this->nume = nume;
}

void Amfiteatru::set_etaj(int etaj)
{
    this->etaj = etaj;
}

void Amfiteatru::set_nr_sala(int nr_sala)
{
    this->nr_sala = nr_sala;
}

void Amfiteatru::set_nr_locuri(int nr_locuri)
{
    this->nr_locuri = nr_locuri;
}

void Amfiteatru::set_echipamente(std::vector<std::string> echipamente)
{
    this->echipamente = echipamente;
}

void Amfiteatru::set_nr_randuri(int nr_randuri)
{
    this->nr_randuri = nr_randuri;
}

void Amfiteatru::set_nume_amf(std::string nume_amf)
{
    this->nume_amf = nume_amf;
}

std::string Amfiteatru::get_nume() const
{
    return this->nume;
}

int Amfiteatru::get_etaj() const
{
    return this->etaj;
}

int Amfiteatru::get_nr_sala() const
{
    return this->nr_sala;
}

int Amfiteatru::get_nr_locuri() const
{
    return this->nr_locuri;
}

std::vector<std::string> Amfiteatru::get_echipamente() const
{
    return this->echipamente;
}

int Amfiteatru::get_nr_randuri() const
{
    return this->nr_randuri;
}

std::string Amfiteatru::get_nume_amf() const
{
    return this->nume_amf;
}

std::ostream &operator<<(std::ostream &out, Amfiteatru &amfiteatru)
{
    out << dynamic_cast<Sala &>(amfiteatru) << std::endl;
    out << "Numar randuri: " << amfiteatru.nr_randuri << std::endl;
    out << "Nume amfiteatru: " << amfiteatru.nume_amf << std::endl;
    return out;
}

int main()
{
    std::vector<std::string> echipamente;
    echipamente.push_back("Proiector");
    echipamente.push_back("Microfon");
    Amfiteatru amfiteatru("Amfiteatru", 1, 1, 100, echipamente, 10, "Amfiteatrul 1");
    std::cout << amfiteatru;
    return 0;
}
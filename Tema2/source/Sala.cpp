#include "../headers/Sala.h"

Sala::Sala()
{
    this->nume = "";
    this->etaj = 0;
    this->nr_sala = 0;
    this->nr_locuri = 0;
    this->echipamente = {};
}

Sala::Sala(std::string nume, int etaj, int nr_sala, int nr_locuri, std::vector<std::string> echipamente)
{
    this->nume = nume;
    this->etaj = etaj;
    this->nr_sala = nr_sala;
    this->nr_locuri = nr_locuri;
    this->echipamente = echipamente;
}

Sala::Sala(const Sala &sala)
{
    this->nume = sala.nume;
    this->etaj = sala.etaj;
    this->nr_sala = sala.nr_sala;
    this->nr_locuri = sala.nr_locuri;
    this->echipamente = sala.echipamente;
}

Sala &Sala::operator=(const Sala &sala)
{
    this->nume = sala.nume;
    this->etaj = sala.etaj;
    this->nr_sala = sala.nr_sala;
    this->nr_locuri = sala.nr_locuri;
    this->echipamente = sala.echipamente;
    return *this;
}

Sala::~Sala()
{
    this->nume = "";
    this->etaj = 0;
    this->nr_sala = 0;
    this->nr_locuri = 0;
    this->echipamente.clear();
}

std::ostream &operator<<(std::ostream &out, const Sala &sala)
{
    out << "Nume: " << sala.nume << std::endl;
    out << "Etaj: " << sala.etaj << std::endl;
    out << "Numar sala: " << sala.nr_sala << std::endl;
    out << "Numar locuri: " << sala.nr_locuri << std::endl;
    out << "Echipamente: ";

    for (auto echipament : sala.echipamente)
    {
        out << echipament << " ";
    }

    return out;
}

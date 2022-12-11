#include "../headers/Sala.h"

Sala::Sala()
{
    this->nume = "";
    this->etaj = 0;
    this->nr_sala = 0;
    this->nr_locuri = 0;
    this->echipamente = {};
}

Sala::Sala(const std::string &nume, int etaj, int nr_sala, int nr_locuri, const std::vector<std::string> &echipamente) : nume(nume), echipamente(echipamente)
{
    this->etaj = etaj;
    this->nr_sala = nr_sala;
    this->nr_locuri = nr_locuri;
}

Sala::Sala(const Sala &sala) : nume(sala.nume), echipamente(sala.echipamente)
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

    out << sala.echipamente.size() << std::endl;

    for (auto echipament : sala.echipamente)
    {
        out << echipament << " ";
    }

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
    std::cout << "Introduceti numarul de echipamente: ";
    int nr_echipamente;
    std::cin >> nr_echipamente;
    for (int j = 0; j < nr_echipamente; ++j)
    {
        std::cout << "Introduceti numele echipamentului: ";
        std::string echipament;
        std::cin >> echipament;
        sala.echipamente.push_back(echipament);
    }

    return in;
}

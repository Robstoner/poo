#include "../headers/Laborator.h"

Laborator::Laborator() : Sala()
{
    this->tip_tabla = Tip_tabla::alba;
    this->nr_calculatoare = 0;
}

Laborator::Laborator(const std::string &nume, int etaj, int nr_sala, int nr_locuri, Tip_tabla tip_tabla, int nr_calculatoare) : Sala(nume, etaj, nr_sala, nr_locuri)
{
    this->tip_tabla = tip_tabla;
    this->nr_calculatoare = nr_calculatoare;
}

Laborator::Laborator(const Laborator &laborator) : Sala(laborator)
{
    this->tip_tabla = laborator.tip_tabla;
    this->nr_calculatoare = laborator.nr_calculatoare;
}

Laborator &Laborator::operator=(const Laborator &laborator)
{
    Sala::operator=(laborator);
    this->tip_tabla = laborator.tip_tabla;
    this->nr_calculatoare = laborator.nr_calculatoare;
    return *this;
}

Laborator::~Laborator()
{
    this->tip_tabla = Tip_tabla::alba;
    this->nr_calculatoare = 0;
}

Tip_tabla Laborator::get_tip_tabla() const
{
    return this->tip_tabla;
}

int Laborator::get_nr_calculatoare() const
{
    return this->nr_calculatoare;
}

void Laborator::set_tip_tabla(Tip_tabla tip_tabla_)
{
    this->tip_tabla = tip_tabla_;
}

void Laborator::set_nr_calculatoare(int nr_calculatoare_)
{
    this->nr_calculatoare = nr_calculatoare_;
}

int Laborator::get_nr_echipamente() const
{
    return this->nr_calculatoare + 2;
}

std::ostream &operator<<(std::ostream &out, const Laborator &laborator)
{
    out << dynamic_cast<const Sala &>(laborator) << std::endl;
    out << "Tip tabla: ";
    switch (laborator.get_tip_tabla())
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
    out << "Numar calculatoare: " << laborator.get_nr_calculatoare() << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Laborator &laborator)
{
    in >> dynamic_cast<Sala &>(laborator);
    std::cout << "Tip tabla: ";
    while (true)
    {
        std::string tip_tabla_string;
        std::cin >> tip_tabla_string;
        if (tip_tabla_string == "alba")
        {
            laborator.set_tip_tabla(Tip_tabla::alba);
            break;
        }
        else if (tip_tabla_string == "neagra")
        {
            laborator.set_tip_tabla(Tip_tabla::neagra);
            break;
        }
        else if (tip_tabla_string == "smart")
        {
            laborator.set_tip_tabla(Tip_tabla::smart);
            break;
        }
        else
        {
            std::cout << "Tipul de tabla nu este valid!" << std::endl;
            std::cout << "Alegeti unul dintre urmatoarele: alba, neagra, smart" << std::endl;
        }
    }
    std::cout << "Numar calculatoare: ";
    in >> laborator.nr_calculatoare;
    return in;
}

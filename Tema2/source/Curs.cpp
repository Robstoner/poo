#include "../headers/Curs.h"

Curs::Curs(std::string nume, std::vector<std::shared_ptr<Sala>> sali, std::vector<std::string> studenti) : studenti(studenti)
{
    this->nume = nume;
    this->sali = sali;
}

Curs::Curs(const Curs& curs) : studenti(curs.studenti)
{
    this->nume = curs.nume;
    this->sali = curs.sali;
}

Curs& Curs::operator=(const Curs& curs)
{
    this->nume = curs.nume;
    this->sali = curs.sali;
    this->studenti = curs.studenti;
    return *this;
}

Curs::~Curs()
{
    this->nume = "";
    this->sali.clear();
    this->studenti.clear();
}

std::string Curs::get_nume() const
{
    return this->nume;
}

std::vector<std::shared_ptr<Sala>> Curs::get_sali() const
{
    return this->sali;
}

std::vector<std::string> Curs::get_studenti() const
{
    return this->studenti;
}

void Curs::set_nume(std::string nume)
{
    this->nume = nume;
}

void Curs::set_sali(std::vector<std::shared_ptr<Sala>> sali)
{
    this->sali = sali;
}

void Curs::set_studenti(std::vector<std::string> studenti)
{
    this->studenti = studenti;
}

std::ostream& operator<<(std::ostream& out, const Curs& curs)
{
    out << "Nume: " << curs.nume << std::endl;
    for (auto& sala : curs.sali)
    {
        if ( dynamic_cast<Amfiteatru*>(sala.get()) )
            out << "Amfiteatru: " << *dynamic_cast<Amfiteatru*>(sala.get()) << std::endl;
        else if ( dynamic_cast<Laborator*>(sala.get()) )
            out << "Laborator: " << *dynamic_cast<Laborator*>(sala.get()) << std::endl;
        else if ( dynamic_cast<Seminar*>(sala.get()) )
            out << "Seminar: " << *dynamic_cast<Seminar*>(sala.get()) << std::endl;
        else
            out << "Sala: " << *sala << std::endl;
    }
    out << "Studenti: " << std::endl;
    for (auto& student : curs.studenti)
    {
        out << student << std::endl;
    }
    return out;
}
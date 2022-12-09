#include "../headers/Curs.h"

Curs::Curs(const std::string &nume, const std::vector<std::shared_ptr<Sala>> &sali, const std::vector<std::string> &studenti) : studenti(studenti)
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

void Curs::adauga_sala(std::shared_ptr<Sala> sala)
{
    this->sali.push_back(sala);
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

void Curs::set_nume(const std::string &nume_)
{
    this->nume = nume;
}

void Curs::set_sali(const std::vector<std::shared_ptr<Sala>> &sali_)
{
    this->sali = sali;
}

void Curs::set_studenti(const std::vector<std::string> &studenti_)
{
    this->studenti = studenti;
}

std::ostream& operator<<(std::ostream& out, const Curs& curs)
{
    out << "Nume: " << curs.nume << std::endl;
    for (const auto& sala : curs.sali)
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
    for (const auto& student : curs.studenti)
    {
        out << student << std::endl;
    }
    return out;
}
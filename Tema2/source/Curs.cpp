#include "Curs.h"

Curs::Curs(std::string nume, Amfiteatru Amf, std::shared_ptr<Seminar> Sem, std::shared_ptr<Laborator> Lab, std::vector<std::string> studenti) : Amf(Amf), Sem(Sem), Lab(Lab)
{
    this->nume = nume;
    this->Amf = Amf;
    this->Sem = Sem;
    this->Lab = Lab;
    this->studenti = studenti;
}

Curs::Curs(const Curs& curs) : Amf(Amf), Sem(Sem), Lab(Lab)
{
    this->nume = curs.nume;
    this->Amf = curs.Amf;
    this->Sem = curs.Sem;
    this->Lab = curs.Lab;
    this->studenti = curs.studenti;
}

Curs& Curs::operator=(const Curs& curs)
{
    this->nume = curs.nume;
    this->Amf = curs.Amf;
    this->Sem = curs.Sem;
    this->Lab = curs.Lab;
    this->studenti = curs.studenti;
    return *this;
}

Curs::~Curs()
{
    this->nume = "";
    this->Amf = Amfiteatru();
    this->Sem = nullptr;
    this->Lab = nullptr;
    this->studenti.clear();
}

std::string Curs::get_nume() const
{
    return this->nume;
}

Amfiteatru Curs::get_Amf() const
{
    return this->Amf;
}

std::shared_ptr<Seminar> Curs::get_Sem() const
{
    return this->Sem;
}

std::shared_ptr<Laborator> Curs::get_Lab() const
{
    return this->Lab;
}

std::vector<std::string> Curs::get_studenti() const
{
    return this->studenti;
}

void Curs::set_nume(std::string nume)
{
    this->nume = nume;
}

void Curs::set_Amf(Amfiteatru Amf)
{
    this->Amf = Amf;
}

void Curs::set_Sem(std::shared_ptr<Seminar> Sem)
{
    this->Sem = Sem;
}

void Curs::set_Lab(std::shared_ptr<Laborator> Lab)
{
    this->Lab = Lab;
}

void Curs::set_studenti(std::vector<std::string> studenti)
{
    this->studenti = studenti;
}

std::ostream& operator<<(std::ostream& out, const Curs& curs)
{
    out << "Nume: " << curs.nume << std::endl;
    out << "Amfiteatru: " << curs.Amf << std::endl;
    out << "Seminar: " << *curs.Sem << std::endl;
    out << "Laborator: " << *curs.Lab << std::endl;
    out << "Studenti: " << std::endl;
    for (auto& student : curs.studenti)
    {
        out << student << std::endl;
    }
    return out;
}
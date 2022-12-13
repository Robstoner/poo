#include "../headers/Curs.h"
#include "../errors/exceptions.h"
#include <algorithm>

Curs::Curs(const std::string &nume, const std::vector<std::shared_ptr<Sala>> &sali, const std::vector<std::string> &profesori) : profesori(profesori)
{
    this->nume = nume;
    this->sali = sali;
}

Curs::Curs(const Curs &curs) : profesori(curs.profesori)
{
    this->nume = curs.nume;
    this->sali = curs.sali;
}

Curs &Curs::operator=(const Curs &curs)
{
    this->nume = curs.nume;
    this->sali = curs.sali;
    this->profesori = curs.profesori;
    return *this;
}

Curs::~Curs()
{
    this->nume = "";
    this->sali.clear();
    this->profesori.clear();
}

void Curs::adauga_sala(std::shared_ptr<Sala> sala)
{
    if (dynamic_cast<Amfiteatru *>(sala.get()))
        if (std::find_if(this->sali.begin(), this->sali.end(), [](const std::shared_ptr<Sala> &sala)
                         { return dynamic_cast<Amfiteatru *>(sala.get()); }) != this->sali.end())
            throw SalaExistaException();
    if (dynamic_cast<Laborator *>(sala.get()))
        if (std::find_if(this->sali.begin(), this->sali.end(), [](const std::shared_ptr<Sala> &sala)
                         { return dynamic_cast<Laborator *>(sala.get()); }) != this->sali.end())
            throw SalaExistaException();
    if (dynamic_cast<Seminar *>(sala.get()))
        if (std::find_if(this->sali.begin(), this->sali.end(), [](const std::shared_ptr<Sala> &sala)
                         { return dynamic_cast<Seminar *>(sala.get()); }) != this->sali.end())
            throw SalaExistaException();

    this->sali.push_back(sala);
}

void Curs::adauga_profesor(const std::string &profesor)
{
    if (std::find(this->profesori.begin(), this->profesori.end(), profesor) != this->profesori.end())
        throw ProfesorExistaException();
    this->profesori.push_back(profesor);
}

std::string Curs::get_nume() const
{
    return this->nume;
}

std::vector<std::shared_ptr<Sala>> Curs::get_sali() const
{
    return this->sali;
}

std::vector<std::string> Curs::get_profesori() const
{
    return this->profesori;
}

void Curs::set_nume(const std::string &nume_)
{
    this->nume = nume_;
}

void Curs::set_sali(const std::vector<std::shared_ptr<Sala>> &sali_)
{
    this->sali = sali_;
}

void Curs::set_profesori(const std::vector<std::string> &profesori_)
{
    this->profesori = profesori_;
}

std::ostream &operator<<(std::ostream &out, const Curs &curs)
{
    out << "Nume: " << curs.nume << std::endl;
    std::cout << std::endl;
    try
    {
        for (const auto &sala : curs.sali)
        {
            
            if (dynamic_cast<Amfiteatru *>(sala.get()))
                out << "Amfiteatru: " << *dynamic_cast<Amfiteatru *>(sala.get()) << "Numar echipamente: " << sala->get_nr_echipamente() << std::endl;
            else if (dynamic_cast<Laborator *>(sala.get()))
                out << "Laborator: " << *dynamic_cast<Laborator *>(sala.get()) << "Numar echipamente: " << sala->get_nr_echipamente() << std::endl;
            else if (dynamic_cast<Seminar *>(sala.get()))
                out << "Seminar: " << *dynamic_cast<Seminar *>(sala.get()) << "Numar echipamente: " << sala->get_nr_echipamente() << std::endl;
            else
                throw InvalidSalaException();
        }
    }
    catch (const InvalidSalaException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    out << "Profesori: " << std::endl;
    for (const auto &profesor : curs.profesori)
    {
        out << profesor << std::endl;
    }
    return out;
}
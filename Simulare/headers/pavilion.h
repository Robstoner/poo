/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_PAVILION_H
#define SIMULARE_PAVILION_H

#include <iostream>
#include <memory>
#include "idGenerator.h"
#include "eveniment.h"
#include "ioStream.h"

class Pavilion : public IOStream {
    std::string id;
    std::string locatie;
    std::string program;
    std::string suprafata;
    std::string numeCoordonator;
    std::string tara;
    std::vector<std::shared_ptr<Eveniment>> evenimente;

public:
    Pavilion() = default;

    Pavilion(const std::string &locatie, const std::string &program, const std::string &suprafata,
             const std::string &numeCoordonator, const std::string &tara,
             const std::vector<std::shared_ptr<Eveniment>> &evenimente);

    friend std::istream &operator>>(std::istream &is, const Pavilion &pavilion);

    void Print(std::ostream &) const;
};


#endif //SIMULARE_PAVILION_H

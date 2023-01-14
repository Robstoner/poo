/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_SPECTACOL_H
#define SIMULARE_SPECTACOL_H

#include <ostream>
#include "eveniment.h"
#include "ioStream.h"

class Spectacol : public Eveniment, public IOStream {
    std::string tip;

public:
    Spectacol() = default;

    Spectacol(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
              int nrMaximVizitatori, const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
              const std::string &tip);

    friend std::ostream &operator<<(std::ostream &os, const Spectacol &spectacol);

    void print() override;
};


#endif //SIMULARE_SPECTACOL_H

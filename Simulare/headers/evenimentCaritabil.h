/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_EVENIMENTCARITABIL_H
#define SIMULARE_EVENIMENTCARITABIL_H

#include <ostream>
#include "eveniment.h"

class EvenimentCaritabil : public Eveniment {
    std::string beneficiar;
    int sursaBaniNecesara;

public:
    EvenimentCaritabil() = default;

    EvenimentCaritabil(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
                       int nrMaximVizitatori, const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
                       const std::string &beneficiar, int sursaBaniNecesara);

};


#endif //SIMULARE_EVENIMENTCARITABIL_H

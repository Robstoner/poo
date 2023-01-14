/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_EVENIMENT_H
#define SIMULARE_EVENIMENT_H

#include "pavilion.h"

#include <string>
#include <vector>
#include <ostream>

class Eveniment : public IOStream {
    std::string nume;
    std::string dataOra;
    int durata = 0;
    std::string sala;
    int nrMaximVizitatori = 0;
    std::vector<std::string> vizitatori;

public:
    Eveniment();

    Eveniment(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
              int nrMaximVizitatori, const std::vector<std::string> &vizitatori);

};


#endif //SIMULARE_EVENIMENT_H

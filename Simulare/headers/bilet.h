/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_BILET_H
#define SIMULARE_BILET_H

#include "idGenerator.h"
#include "ioStream.h"

#include <ctime>

class Bilet : public IOStream {
    std::string id;
    std::string nume;
    std::string prenume;
    int varsta = 0;
    std::string nationalitate;
    std::string dataInceput;
    std::string dataExpirare;

public:
    Bilet() = default;

    Bilet(const std::string &nume, const std::string &prenume, int varsta, const std::string &nationalitate,
          const std::string &dataInceput, const std::string &dataExpirare);

};


#endif //SIMULARE_BILET_H

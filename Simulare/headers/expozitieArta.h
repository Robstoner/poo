/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_EXPOZITIEARTA_H
#define SIMULARE_EXPOZITIEARTA_H

#include "eveniment.h"

class ExpozitieArta : public Eveniment {
    std::string numeLucrare;
    std::string numeArtist;

public:
    ExpozitieArta() = default;

    ExpozitieArta(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
                  int nrMaximVizitatori, const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
                  const std::string &numeLucrare, const std::string &numeArtist);

};


#endif //SIMULARE_EXPOZITIEARTA_H

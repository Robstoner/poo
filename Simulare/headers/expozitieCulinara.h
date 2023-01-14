/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_EXPOZITIECULINARA_H
#define SIMULARE_EXPOZITIECULINARA_H

#include "eveniment.h"

class ExpozitieCulinara : public Eveniment {
    std::vector<std::string> listaPreparate;
    std::string bucatar;

public:
    ExpozitieCulinara() = default;

    ExpozitieCulinara(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
                      int nrMaximVizitatori, const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
                      const std::vector<std::string> &listaPreparate, const std::string &bucatar);

};


#endif //SIMULARE_EXPOZITIECULINARA_H

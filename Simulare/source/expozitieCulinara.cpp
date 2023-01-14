/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/expozitieCulinara.h"

ExpozitieCulinara::ExpozitieCulinara(const std::string &nume, const std::string &dataOra, int durata,
                                     const std::string &sala, int nrMaximVizitatori,
                                     const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
                                     const std::vector<std::string> &listaPreparate, const std::string &bucatar)
        : Eveniment(nume, dataOra, durata, sala, nrMaximVizitatori, vizitatori, pavilion),
          listaPreparate(listaPreparate), bucatar(bucatar) {}

void ExpozitieCulinara::print() {

}

std::ostream &operator<<(std::ostream &os, const ExpozitieCulinara &culinara) {
    os << static_cast<const Eveniment &>(culinara) << " listaPreparate: " << culinara.listaPreparate << " bucatar: "
       << culinara.bucatar;
    return os;
}

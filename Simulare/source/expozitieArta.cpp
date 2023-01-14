/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/expozitieArta.h"


ExpozitieArta::ExpozitieArta(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
                             int nrMaximVizitatori, const std::vector<std::string> &vizitatori,
                             const Pavilion &pavilion, const std::string &numeLucrare, const std::string &numeArtist)
        : Eveniment(nume, dataOra, durata, sala, nrMaximVizitatori, vizitatori, pavilion), numeLucrare(numeLucrare),
          numeArtist(numeArtist) {}

void ExpozitieArta::print() {

}

std::ostream &operator<<(std::ostream &os, const ExpozitieArta &arta) {
    os << static_cast<const Eveniment &>(arta) << " numeLucrare: " << arta.numeLucrare << " numeArtist: "
       << arta.numeArtist;
    return os;
}

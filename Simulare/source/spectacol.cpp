/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/spectacol.h"

Spectacol::Spectacol(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
                     int nrMaximVizitatori, const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
                     const std::string &tip) : Eveniment(nume, dataOra, durata, sala, nrMaximVizitatori, vizitatori, pavilion), tip(tip) {}

void Spectacol::print() {

}

std::ostream &operator<<(std::ostream &os, const Spectacol &spectacol) {
    os << static_cast<const Eveniment &>(spectacol) << " tip: " << spectacol.tip;
    return os;
}

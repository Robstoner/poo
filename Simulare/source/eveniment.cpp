/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/eveniment.h"

Eveniment::Eveniment() = default;

Eveniment::Eveniment(const std::string &nume, const std::string &dataOra, int durata, const std::string &sala,
                     int nrMaximVizitatori, const std::vector<std::string> &vizitatori)
        : nume(nume), dataOra(dataOra), durata(durata), sala(sala), nrMaximVizitatori(nrMaximVizitatori),
          vizitatori(vizitatori) {}

std::ostream &operator<<(std::ostream &os, const Eveniment &eveniment) {
    os << "nume: " << eveniment.nume << " dataOra: " << eveniment.dataOra << " durata: " << eveniment.durata
       << " sala: " << eveniment.sala << " nrMaximVizitatori: " << eveniment.nrMaximVizitatori;

    os << "vizitatori:\n";
    for (auto vizitator : eveniment.vizitatori) {
        os << vizitator << "\n";
    }
    return os;
}

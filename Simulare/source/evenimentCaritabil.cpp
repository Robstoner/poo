/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/evenimentCaritabil.h"

EvenimentCaritabil::EvenimentCaritabil(const std::string &nume, const std::string &dataOra, int durata,
                                       const std::string &sala, int nrMaximVizitatori,
                                       const std::vector<std::string> &vizitatori, const Pavilion &pavilion,
                                       const std::string &beneficiar, int sursaBaniNecesara) : Eveniment(nume, dataOra,
                                                                                                         durata, sala,
                                                                                                         nrMaximVizitatori,
                                                                                                         vizitatori,
                                                                                                         pavilion),
                                                                                               beneficiar(beneficiar),
                                                                                               sursaBaniNecesara(
                                                                                                       sursaBaniNecesara) {}

void EvenimentCaritabil::print() {

}

std::ostream &operator<<(std::ostream &os, const EvenimentCaritabil &caritabil) {
    os << static_cast<const Eveniment &>(caritabil) << " beneficiar: " << caritabil.beneficiar << " sursaBaniNecesara: "
       << caritabil.sursaBaniNecesara;
    return os;
}

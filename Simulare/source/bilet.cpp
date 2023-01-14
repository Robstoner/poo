/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/bilet.h"

Bilet::Bilet(const std::string &nume, const std::string &prenume, int varsta, const std::string &nationalitate,
             const std::string &dataInceput, const std::string &dataExpirare) : nume(nume), prenume(prenume), varsta(varsta),
                                                              nationalitate(nationalitate), dataInceput(dataInceput),
                                                              dataExpirare(dataExpirare) {
    id = IDGenerator::generateID();
}

std::ostream &operator<<(std::ostream &os, const Bilet &bilet) {
    os << "id: " << bilet.id << " nume: " << bilet.nume << " prenume: " << bilet.prenume << " varsta: " << bilet.varsta
       << " nationalitate: " << bilet.nationalitate << " dataInceput: " << bilet.dataInceput << " dataExpirare: "
       << bilet.dataExpirare;
    return os;
}

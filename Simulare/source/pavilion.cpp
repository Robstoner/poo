/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/pavilion.h"


std::ostream &operator<<(std::ostream &os, const Pavilion &pavilion) {
    os << "id: " << pavilion.id << " locatie: " << pavilion.locatie << " program: " << pavilion.program
       << " suprafata: " << pavilion.suprafata << " numeCoordonator: " << pavilion.numeCoordonator << " tara: "
       << pavilion.tara;
    return os;
}

Pavilion::Pavilion(const std::string &locatie, const std::string &program, const std::string &suprafata,
                   const std::string &numeCoordonator, const std::string &tara,
                   const std::vector<std::shared_ptr<Eveniment>> &evenimente) : locatie(locatie), program(program),
                                                                                suprafata(suprafata),
                                                                                numeCoordonator(numeCoordonator),
                                                                                tara(tara), evenimente(evenimente) {
    id = IDGenerator::generateID();
}

void Pavilion::Print(std::ostream &) const {
    
}

std::istream &operator>>(std::istream &is, const Pavilion &pavilion) {


    return is;
}

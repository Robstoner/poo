/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#ifndef SIMULARE_IDGENERATOR_H
#define SIMULARE_IDGENERATOR_H
#include <random>
#include <string>

class IDGenerator {
private:
    static std::mt19937 rng;
    static std::uniform_int_distribution<std::mt19937::result_type> dist;

public:
    static std::string generateID() {
        return std::to_string(dist(rng));
    }
};


#endif //SIMULARE_IDGENERATOR_H

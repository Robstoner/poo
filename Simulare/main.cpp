/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include <iostream>

#include "headers/idGenerator.h"
#include "headers/bilet.h"
#include "headers/pavilion.h"
#include "headers/evenimentCaritabil.h"
#include "headers/expozitieArta.h"
#include "headers/expozitieCulinara.h"
#include "headers/spectacol.h"

std::mt19937 IDGenerator::rng;
std::uniform_int_distribution<std::mt19937::result_type> IDGenerator::dist = std::uniform_int_distribution<std::mt19937::result_type>(0, 1000000);

int main() {

    std::vector<Pavilion> pavilioane;



    return 0;
}

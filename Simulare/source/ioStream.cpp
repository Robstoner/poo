/*
    Nume Prenume: Schmidt Robert-Eduard
    Grupa: 264
    Tutore Laborator: Octavian Comanescu
    IDE: CLion
    Compilator: Mingw
*/

#include "../headers/ioStream.h"

std::ostream& operator<<(std::ostream &os, const IOStream &obj) {
    obj.Print(os);
    return os;
}

std::ostream& operator<<(std::ostream &os, const IOStream *obj) {
    obj->Print(os);
    return os;
}

IOStream::~IOStream() = default;